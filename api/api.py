from flask import Flask

app = Flask(__name__)
data = '13;1334'

@app.route('/')
def hello():
    return data

def run():
    app.run()

if __name__ == '__main__':
    
    run()