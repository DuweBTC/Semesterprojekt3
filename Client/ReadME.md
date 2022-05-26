# ReadMe
## Client

# How to cross compile Qt5 for Rasbperry Pi 3 with remote debugging

## Introduction 
This is a gudie to cross compile Qt5 code for Raspberry pi 3 using Linux PC. 
Once you have finished you will be able to write code with Qt as nomally would.
When you want to build ready to buildt it for the Raspberry Pi, then just select the build option for Raspberry and then compile for the Pi. The guide follows [Heavy Bare Metal](http://heavybaremetal.com/index.php/blog/6-how-to-cross-compile-qt-5-for-raspberry-pi-3)'s guide. 

## Install Reaspberry Pi OS (Buster)
First you have to install the [Raspberry image (Buster)](https://www.raspberrypi.com/software/operating-systems/) with desktop. The image is the legacy image. After that you have get it on WIFI and then enable ssh in Raspberry Pi Configuration. Then run the command 
```bash
ifconfig
```
And then find the ip for the wlan0. It's under the inet. For me it is 
```bash
172.16.0.7
```
Then connect thourgh SSH
```bash
ssh <username>@<pi ip adress>
```
```bash
ssh pi@172.16.0.7
```
**If it won't work** then use the ssh-kygen command
```bash
ssh-keygen
```
You are going to connect to the pi thourgh SSH a few time. So you may wish to enable key based login without a password. So if you run the command.
```bash
ssh-copy-id <username>@<pi ip adress>
```
**If** you are not out of the pi when you run the command. So run **exit** and then run the command above. Now you have ssh access to the Raspberry Pi.

### In Raspberry
The first thing you wanna on is run the command below, and the remove the '#' on the third line and enable the deb-src. 

```bash
sudo nano /etc/apt/sources.list
```
### Setup 

## Install all software and tools needed in Linux 

## Create a sysroot folder in the Linux
dsd
## Build Qt from source, and any Qt modules we migth need 

## Copy the Qt libraries over to the Pi

## Build a Qt example, and deploy and run it on the Pi

## Change the Server Projekt to be able to cross compile

## Run the Server with Qt
