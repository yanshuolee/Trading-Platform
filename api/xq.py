import PyWinDDE
from flask import Flask
import threading

app = Flask(__name__)
price_d = ""
volumn_d = ""

def recTick(value,item):
    global price_d, volumn_d
    price_d = value.split(";")[0]
    volumn_d = value.split(";")[1].split(".")[0]
    # print(price_d)

@app.route('/price')
def price_fn():
    global price_d
    return price_d

@app.route('/volume')
def volume_fn():
    global volumn_d
    return volumn_d

def start_api():
    print("Start api...")
    app.run()

def start_xq():
    dde = PyWinDDE.DDEClient("XQLITE", "Quote")
    dde.advise("FITXN*1.TF-Price,TotalVolume", callback = recTick)
    PyWinDDE.WinMSGLoop()

if __name__ == '__main__':
    try:
        thread1 = threading.Thread(target=start_api)
        thread2 = threading.Thread(target=start_xq)

        # Start the threads
        thread1.start()
        thread2.start()

        # Wait for both threads to complete
        thread1.join()
        thread2.join()
    except KeyboardInterrupt:
        pass

# =XQLITE|Quote!'FITXN*1.TF-ID,price,Open,High,Low,TotalVolume'