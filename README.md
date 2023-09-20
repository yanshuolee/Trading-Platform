# Trading Platform
# User Interface
![Alt Text](./assets/trading-platform.png)

# Prerequisite
- Visual Studio 2022
- Python 3.7

To install the dependencies, use the provided `environment.yaml` file
```
conda env create -f environment.yaml
```

# Run the platform
### Step 1
To initialize realtime market data from XQ, run the commands:

```
cd api
python xq.py
```


### Step 2
Duble click `TradingPlatform/TradingPlatform.sln` to start the VS project.

Build project with "Local Windows Debugger". 

![Alt Text](./assets/vs-form.png)