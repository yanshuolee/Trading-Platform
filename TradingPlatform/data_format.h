#pragma once
#include <deque>
#include <iostream>
using namespace System;
#define MAX_ROW 10

struct SMA {
	std::deque<float> Dataset;
	int period;
	float sum = 0;
};

struct EMA {
	std::deque<float> Dataset;
	int period;
	//float alpha;
	float sum = 0;
};

struct Return {
	std::deque<float> Dataset;
	float sum = 0;
};

struct cs_data {	
	// candlestick
	std::deque<float> open;
	std::deque<float> close;
	std::deque<float> high;
	std::deque<float> low;

	// candlestick ma
	std::deque<float> ma3_arr; // size == 3
	std::deque<float> ma5_arr;
	std::deque<float> ma20_arr;

	SMA ma3;
	SMA ma5;
	SMA ma20;

	// return & volumn
	std::deque<float> Return_arr;
	std::deque<float> Volume_arr;
	int prev_vol;

	std::deque<float> ema12_arr;
	std::deque<float> ema26_arr;
	std::deque<float> DIF_arr;
	std::deque<float> DEM_arr;
	std::deque<float> MACD_bar_arr;

	EMA DIF_ema9;
	EMA ema12;
	EMA ema26;

	// account records
	Return buy_price;
	Return sell_price;

	// account
	float balance = 0;

	std::deque<float> delta_C_O;
};

struct Tick {
	float price = .0;
	int volume = 0;
};

cs_data generate_dummy(void);
cs_data init_data(void);
void update_candlestick(cs_data* data);
void update_candlestick_dummy(cs_data* data);

Tick get_realtime(void);
extern int prev_min, cur_min;
float cal_return(cs_data data);

