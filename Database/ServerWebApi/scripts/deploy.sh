dotnet publish -r linux-arm
scp -r ./bin/Debug/net6.0/linux-arm/ pi@10.77.77.77:/home/pi/deployment-location/