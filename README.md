# Medusa
### Introduction
Medusa is an open-source project that uses a small, easily assembled temperature sensor and Wi-Fi microcontroller to send data to either your own website or our easy-to-use interface, which will be described in detail below.
### Electronics
### [Link to printable casing and PCB](https://www.printables.com/model/394252-case-for-medusa-temperature-sensor/files)
#### Circuit Diagrams
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/wiring.png" width="50%" height="50%" /> <img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/sodering.png" width="30%" height="30%" /> <img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/wiring2.png" width="50%" height="50%" /> 

### Uploading the Program to the Microcontroller
#### Requirements
1. An application that can upload the program to the chip. We used the [Arduino IDE](https://www.arduino.cc/en/donate/) (download it from the link).
2. A "Board Manager" is also required for the ESP8266, which can be found in [this guide](https://arduino.esp8266.com/stable/package_esp8266com_index.json)
3. The program that needs to be uploaded to the ESP8266 is uploaded with the name [homersekletOlvaso](https://github.com/JosephTheSmartPers/Medusa/tree/main), download it and then open the file named homersekletOlvaso.ino.(https://github.com/JosephTheSmartPers/Medusa/blob/main/homersekletOlvaso/homersekletOlvaso.ino) nevű fájlt.
#### Uploading the Program
1. Then, in the Tools>Board>Boards Manager, select the ESP8266 and the application will download the necessary files.
2. Once you have plugged in the microcontroller and set it to programming mode (circuit diagram), press the upload button (an arrow pointing upward) and wait for the file to upload.
3. If the upload was successful, it will display "100%" in the console. Then unplug it, switch it to running mode, plug it back in, and open Tools>Serial Monitor. It will display the IP address, which should be saved because it will be used to configure sensors on our website.
#### Website Management
1. The current website link is [here](http://139.162.189.55/sensor/home.php), after registering, you will be logged in as an admin.
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/peldasignup.png" width="20%" height="20%" />
After that, create a floor by clicking the + button next to "Sensors," entering something in the "Floor Name" field, and clicking the "Create" button. The new floor will appear.
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/peldaaddfloor.png" width="30%" height="30%" />
2. Then, by clicking the + button next to the created floor, a window will appear where you need to set the sensor's name and IP address, which will be used to retrieve the measurements from the database.
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/addsensor.png" width="30%" height="30%" /> 
4. That's it! The measurements should appear on a very cool graph created using the data from the sensors. You can view the graphs by clicking on the floor that you added the sensor to and then clicking on the sensor's name. You can also view a summary of all the measurements on the homepage.

If you have any issues with the website or the Medusa device, please consult the documentation provided on the Medusa GitHub page or contact the Medusa team for support. Happy monitoring!
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/ujemelet.png" width="30%" height="30%" />
