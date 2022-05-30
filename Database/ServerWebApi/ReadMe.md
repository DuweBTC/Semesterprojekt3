# ReadMe 
## Setup Windoes, Mac or Linux

### Windows 
The way to make dotnet work on Windows is that you have to check out this [Website]](https://code.visualstudio.com/docs/languages/dotnet). You have to install these extension [1](https://dotnet.microsoft.com/en-us/download), [2](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.csharp) and [3](https://marketplace.visualstudio.com/items?itemName=Ionide.Ionide-fsharp), After that close the VS Code and then open it up again. To run it you have to change the terminal to be cmd and then you can run the command
```bash
dotnet run
```

### Linux
This about the setup and last we will show how we use the database. 
On linux you first add the repository
```bash
wget https://packages.microsoft.com/config/ubuntu/21.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
rm packages-microsoft-prod.deb
```
After that you install in as SDK Installation 	
```bash
sudo apt-get update
sudo apt-get install -y apt-transport-https
sudo apt-get update
sudo apt-get install -y dotnet-sdk-6.0
```

## Setup Rasberry
Firstly the Raspberry have to be on the same Internet as your Client or PC. After that you have to find out the IP-Adress for the Pi.

On the Raspberry Pi run the following command to install dotnet. 
```bash
curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin --channel Current
echo 'export DOTNET_ROOT=$HOME/.dotnet' >> ~/.bashrc
echo 'export PATH=$PATH:$HOME/.dotnet' >> ~/.bashrc
source ~/.bashrc
dotnet --version
```

## Run it on Raspberry
After the installation the run the following command on the PC. It create the publish files of for the raspberry and copies it over to the raspberry thourgh the dedicated ssh connection. 
```bash
sh scripts/deploy.sh 

```
On the raspberry if the ports aren't automatic open, we will frist run the command:  
```bash
export ASPNETCORE_URLS="http://*:5000;https://*:5001"
```

If the ports are open or if you just run the command above, the find the direction where you put the project. Here it is:
```bash
cd  ~/deployment-location/linux-arm 
```
After that you can run the Server with the command
```bash
dotnet ServerWebApi.dll
```

## Run it on PC
You are in the ServerWebApi folder and the the following command
```bash
dotnet run 
```

## General for the database
The IP-adress for the Server is:
https://{host}:{port}/{Endpoint}/{Action]
https://10.77.77.77:5001/Account


Endpoint: 
* Account
* Drink
* Container
* Recipe

Action on the Acouont is /Account/{id} or /Account/{id}/Balance
See more under [Web API Decription](https://github.com/DuweBTC/Semesterprojekt3/blob/main/Database/API-beskrivelse/index1.html) and download the html file and then render it.


## SQL database setup
Setup for SQLite3 on a RPI
```bash
pi@raspberrypi:~ $ sudo apt install sqlite3
```
Creating tables 
```bash
pi@raspberrypi:~ $ sqlite3 3semesterdatabase.db 
sqlite> CREATE TABLE AccountItem(AccountId STRING, 
Name STRING, Balance DOUBLE, Favourit DrinkItem);
```
Showing tables and selecting items
```bash
sqlite> .tables 
AccountItem  ContainerItem   DrinkItem  IngredientItem  
RecipeItem 
sqlite> SELECT * FROM AccountItem;
1|My-Thanh Thi Le|1.0e+22|Rom og cola
```
