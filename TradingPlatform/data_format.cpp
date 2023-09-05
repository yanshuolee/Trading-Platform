#include "pch.h"
#include <stdlib.h>
#include "HTTPRequest.hpp"
#include "data_format.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace System;

void multiplyData(EMA* data, float num)
{
	data->Dataset.push_back(num);

	if (data->Dataset.size() <= data->period)
	{
		data->sum = data->sum + pow((1 - (2 / (data->period + 1))), (data->period - data->Dataset.size())) * num;
	}
	else
	{
		data->Dataset.pop_front();
		data->sum = 0;
		for (int i = 0; i < data->Dataset.size(); i++)
		{
			data->sum = data->sum + pow((1 - (2 / (data->period + 1))), (data->Dataset.size() - 1 - i)) * data->Dataset[i];
		}
	}
}

void update_information_Data(EMA* data, float num)
{
	data->sum -= pow((1 - (2 / (data->period + 1))), (data->period - data->Dataset.size())) * data->Dataset.back() * 2 / (data->period + 1);
	data->sum += pow((1 - (2 / (data->period + 1))), (data->period - data->Dataset.size())) * num * 2 / (data->period + 1);
	data->Dataset.pop_back();
	data->Dataset.push_back(num);
}

float getMultiply_Alpha(EMA* data) {
	return data->sum * 2 / (data->period + 1);
}

void addData(SMA *data, float num)
{
	data->sum += num;
	data->Dataset.push_back(num);

	if (data->Dataset.size() > data->period) {
		data->sum -= data->Dataset.front();
		data->Dataset.pop_front();
	}
}

void updateData(SMA* data, float num)
{
	data->sum -= data->Dataset.back();
	data->sum += num;
	data->Dataset.pop_back();
	data->Dataset.push_back(num);
}

float getMean(SMA* data) {
	return data->sum / data->period;
}

Tick get_realtime(void) {
	Tick tick;
	http::Request request{ "http://127.0.0.1:5000/price" };
	http::Request request_vol{ "http://127.0.0.1:5000/volume" };
	const auto response = request.send("GET");
	std::string data_price = std::string{ response.body.begin(), response.body.end() };
	tick.price = std::stof(data_price);

	const auto response_vol = request_vol.send("GET");
	std::string data_vol = std::string{ response_vol.body.begin(), response_vol.body.end() };
	tick.volume = std::stoi(data_vol);

	return tick;
}

cs_data generate_dummy(void) {
	cs_data data;
	data.ma20.period = 20;
	data.ma3.period = 3;
	data.ma5.period = 5;
	
	for (int i = 0; i < MAX_ROW; i++) {
		float open_d = rand() % 50;
		float close_d = rand() % 50;
		float high_d = rand() % 50;
		float low_d = rand() % 50;

		data.open.push_back(open_d);
		data.close.push_back(close_d);
		data.high.push_back(high_d);
		data.low.push_back(low_d);

		addData(&data.ma3, close_d);
		addData(&data.ma5, close_d);
		addData(&data.ma20, close_d);
		data.ma3_arr.push_back(getMean(&data.ma3));
		data.ma5_arr.push_back(getMean(&data.ma5));
		data.ma20_arr.push_back(getMean(&data.ma20));
	}

	return data;
}

cs_data init_data(void) {
	cs_data data;
	Tick tick;
	data.ma20.period = 20;
	data.ma3.period = 3;
	data.ma5.period = 5;

	//data.ema12.period = 12;
	//data.ema26.period = 26;
	data.DIF_ema9.period = 4;
	data.ema12.period = 3;
	data.ema26.period = 5;

	tick = get_realtime();
	// price
	data.open.push_back(tick.price);
	data.close.push_back(tick.price);
	data.high.push_back(tick.price);
	data.low.push_back(tick.price);

	addData(&data.ma3, tick.price);
	addData(&data.ma5, tick.price);
	addData(&data.ma20, tick.price);
	//data.ma3_arr.push_back(getMean(&data.ma3));
	//data.ma5_arr.push_back(getMean(&data.ma5));
	//data.ma20_arr.push_back(getMean(&data.ma20));

	multiplyData(&data.ema12, tick.price);
	multiplyData(&data.ema26, tick.price);

	// volume
	data.Volume_arr.push_back(0);
	data.prev_vol = tick.volume;

	// return
	data.Return_arr.push_back(0);

	return data;
}

void update_candlestick(cs_data *data) {
	if (data->close.size() > MAX_ROW) {
		data->close.pop_front();
		data->open.pop_front();
		data->high.pop_front();
		data->low.pop_front();
	}
	if (data->Volume_arr.size() > MAX_ROW) {
		data->Return_arr.pop_front();
		data->Volume_arr.pop_front();
	}
	Tick tick = get_realtime();
	float ret = cal_return(*data);

	if (cur_min != prev_min) {
		prev_min = cur_min;

		// price
		data->open.push_back(tick.price);
		data->close.push_back(tick.price);
		data->high.push_back(tick.price);
		data->low.push_back(tick.price);

		addData(&data->ma3, tick.price);
		addData(&data->ma5, tick.price);
		addData(&data->ma20, tick.price);

		if (data->ma3_arr.size() > MAX_ROW) {
			data->ma3_arr.pop_front();
		}
		if (data->ma5_arr.size() > MAX_ROW) {
			data->ma5_arr.pop_front();
		}
		if (data->ma20_arr.size() > MAX_ROW) {
			data->ma20_arr.pop_front();
		}
		if (data->ma3.Dataset.size() >= 3) { data->ma3_arr.push_back(getMean(&data->ma3)); }
		if (data->ma5.Dataset.size() >= 5) { data->ma5_arr.push_back(getMean(&data->ma5)); }
		if (data->ma20.Dataset.size() >= 20) { data->ma20_arr.push_back(getMean(&data->ma20)); }

		multiplyData(&data->ema12, tick.price);
		multiplyData(&data->ema26, tick.price);

		if (data->ema12_arr.size() > MAX_ROW) {
			data->ema12_arr.pop_front();
		}
		if (data->ema26_arr.size() > MAX_ROW) {
			data->ema26_arr.pop_front();
		}
		if (data->ema12.Dataset.size() >= data->ema12.period) { data->ema12_arr.push_back(getMultiply_Alpha(&data->ema12)); }
		if (data->ema26.Dataset.size() >= data->ema26.period) { data->ema26_arr.push_back(getMultiply_Alpha(&data->ema26)); }

		if (data->ema26_arr.size() >= data->ema26.period)
		{
			data->DIF_arr.push_back(data->ema26_arr.back() - data->ema12_arr.back());
			multiplyData(&data->DIF_ema9, data->DIF_arr.back());
		}
		if (data->DIF_ema9.Dataset.size() >= data->DIF_ema9.period) { data->DEM_arr.push_back(getMultiply_Alpha(&data->DIF_ema9)); }

		if (data->DIF_arr.size() > MAX_ROW) {
			data->DIF_arr.pop_front();
		}
		if (data->DEM_arr.size() > MAX_ROW) {
			data->DEM_arr.pop_front();
		}

		if (data->DEM_arr.size() > 0)
		{
			data->MACD_bar_arr.push_back(data->DIF_ema9.Dataset.back() - data->DEM_arr.back());
		}
		if (data->MACD_bar_arr.size() > MAX_ROW) {
			data->MACD_bar_arr.pop_front();
		}

		// volume
		data->prev_vol = tick.volume;
		int vol = tick.volume - data->prev_vol;
		data->Volume_arr.push_back(vol);

		// return 
		data->Return_arr.push_back(ret*50);

		// strategy 2
		if ((data->close.back() - data->open.back()) > 0) {
			data->delta_C_O.push_back(1);
		}
		else if ((data->close.back() - data->open.back()) == 0) {
			data->delta_C_O.push_back(0);
		}
		else {
			data->delta_C_O.push_back(-1);
		}

	}
	else {
		// price
		if (data->high[data->high.size() - 1] < tick.price) {
			data->high.pop_back();
			data->high.push_back(tick.price);
		}
		if (data->low[data->low.size() - 1] > tick.price) {
			data->low.pop_back();
			data->low.push_back(tick.price);
		}
		data->close.pop_back();
		data->close.push_back(tick.price);

		updateData(&data->ma3, tick.price);
		updateData(&data->ma5, tick.price);
		updateData(&data->ma20, tick.price);

		//if (data->ma3_arr.size() > 3) {
		//	data->ma3_arr.pop_front();
		//}
		//if (data->ma5_arr.size() > 5) {
		//	data->ma5_arr.pop_front();
		//}
		//if (data->ma20_arr.size() > 20) {
		//	data->ma20_arr.pop_front();
		//}
		//data->ma3_arr.push_back(getMean(&data->ma3));
		//data->ma5_arr.push_back(getMean(&data->ma5));
		//data->ma20_arr.push_back(getMean(&data->ma20));

		update_information_Data(&data->ema12, tick.price);
		update_information_Data(&data->ema26, tick.price);

		// volume
		int vol = tick.volume - data->prev_vol;
		data->Volume_arr.pop_back();
		data->Volume_arr.push_back(vol);

		// return
		data->Return_arr.pop_back();
		data->Return_arr.push_back(ret*50);

	}
}

float cal_return(cs_data data) {
	float cur_price = data.close.back();
	float buy_return = 0, sell_return = 0;
	for (std::deque<float>::iterator it = data.buy_price.Dataset.begin(); it != data.buy_price.Dataset.end(); ++it)
		buy_return += (cur_price-*it);

	for (std::deque<float>::iterator it = data.sell_price.Dataset.begin(); it != data.sell_price.Dataset.end(); ++it)
		sell_return += (*it - cur_price);

	return data.balance+buy_return+sell_return;
}

void update_candlestick_dummy(cs_data* data) {
	if (data->close.size() == MAX_ROW) {
		data->close.pop_front();
		data->open.pop_front();
		data->high.pop_front();
		data->low.pop_front();
	}

	// generate dummy
	float open_d = rand() % 50;
	float close_d = rand() % 50;
	float high_d = rand() % 50;
	float low_d = rand() % 50;
	data->open.push_back(open_d);
	data->close.push_back(close_d);
	data->high.push_back(high_d);
	data->low.push_back(low_d);

	addData(&data->ma3, close_d);
	addData(&data->ma5, close_d);
	addData(&data->ma20, close_d);

	if (data->ma3_arr.size() > 3) {
		data->ma3_arr.pop_front();
	}
	if (data->ma5_arr.size() > 5) {
		data->ma5_arr.pop_front();
	}
	if (data->ma20_arr.size() > 20) {
		data->ma20_arr.pop_front();
	}
	data->ma3_arr.push_back(getMean(&data->ma3));
	data->ma5_arr.push_back(getMean(&data->ma5));
	data->ma20_arr.push_back(getMean(&data->ma20));


}
