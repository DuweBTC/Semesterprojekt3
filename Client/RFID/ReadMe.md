# ReadMe
## File Description
"Read.py" is an example of how to retrieve the id and save it in the text file "text.txt"of an rfid-card with python code and the mfrc552 python library.
"main.cpp" is an example of how to call Read.py and retrieve the id from "text.txt".

## Setup
### How to setup SPI on the raspberry pi.
1. Enable SPI communication in the raspberry pi configureation with this command: `sudo raspi-config` 
2. Select "5 Interfacing Options"
3. Select "P4 SPI"  and confirm
4. Once the SPI interface has succesfully been configured you need to reboot the raspberry pi with this command: `sudo reboot`.
5. Once your Raspberry pi has finished rebooting, you can check if it has been enabled succesfully, by running the folloeing command: `lsmod | grep spi`. if the file "spi_bcm2835" is listed spi was succesfully enabled.
6. If the SPI module has not activated, you can edit the boot configuration file manually by runnung this command: `sudo nano /boot/config.txt`.
7. Press "CTRL + W" to find "dtparam=spi=on", check if there is an "#" in front of it. Once you have made the changes, you can press "CTRL + X" then "Y" and then "Enter" to save the changes. Now reboot again.
 
### How to get pyhon ready for the mfrc522
1. Start by updating your Raspberry Pi. 
   `sudo apt-get update`
   `sudo apt-get upgrade`
   
2. Install python and pip:
   `sudo apt-get install python3-dev python3-pip`

3. Install spidev:
   `sudo pip3 install spidev`

4. Install the mfrc522 library:
   `suod pip3 install mfrc522` 



## Hardware
The hardware used is a raspberry pi 3b+ and a RFID-scanner (mfrc552). The connections are displayed below.

| Connector |   Pin   |
|-----------|---------|
| SDA | PIN 24 |
| SCK | PIN 23 |
| MOSI | PIN 19 |
| MISO | PIN 21 |
| GND | PIN 6 |
| RST | PIN 22 |
| 3.3v | PIN 1 |

