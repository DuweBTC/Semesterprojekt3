# ReadMe 


On the Raspberry Pi run the following command to install dotnet. 
```bash
curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin --channel Current
echo 'export DOTNET_ROOT=$HOME/.dotnet' >> ~/.bashrc
echo 'export PATH=$PATH:$HOME/.dotnet' >> ~/.bashrc
source ~/.bashrc
dotnet --version
```

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
The IP-adress for the Server is:
https://10.77.77.77:5001/{Endpoint}/{Action]

Endpoint: 
* Account
* Drink
* Container
* Recipe

Action on the Acouont is /Account/{id} or /Account/{id}/Balance
See more under [Web API Decription](https://github.com/DuweBTC/Semesterprojekt3/blob/main/Database/API-beskrivelse/index1.html) and download the html file and then render it.