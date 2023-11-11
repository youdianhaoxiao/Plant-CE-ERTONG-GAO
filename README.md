# Plant-CE-ERTONG-GAO



## Construction of the physical prototype sensor

| Hardware | Description |
| --- | --- |
| ESP8266 | For connecting to wifi and publish data to MQTT server |
| DHT22 | Sensor for temperature and humidity |
| ultrasonic rangefinder | detect movement of any approaches within certain distance |
| LED bulb | connect with ultrasonic rangefinder to flash |
| resistor | Limit the voltage to tolerant range |
| nails | measure resistance between for moisture |
| Raspberry Pi | Store and visualise the data |
| Buzzer | sound an alarm |

### Detailed assembly pictures
![0bf0253ed899834b4a0863fba025743](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/9bc5b5bd-1f87-4d1b-a60e-48ea1bd62277)
The picture above shows the nails wrapped around the wire and we will put both nails into the soil to test the moisture content. The logic behind using nails is that water can conduct electricity, but dry soil cannot.
![c67a225d95f21d0487c20b9ef9c755a](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/d33fdc7d-7dcd-4b05-aa20-a7b36706f32d)
![3d9a6ada1cdaf87d57281c5b4d5c9e0](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/714d0538-0cbc-474e-8643-c5a14e5768a3)
The resistor and DHT22 sensor are soldered to the ESP8266 so the kit is held in place as shown in the picture above.

The image below shows how the ultrasonic range finder and buzzer are connected to the ARDUINO board shown below. This part of the coding is designed（See document：Sketch_oct30c.ino） so that if the ultrasonic device detects an object within 50cm, the buzzer will sound.Then there is the connection between the LED light and the ARDUINO board. This part is if the distance is less than 30, it means that the object is very close to the sensor. In this case, the 'map' function maps 'cm' values from 1 to 30 to a blink rate range of 10 to 300. This means that the closer the distance, the faster the LED flashes.
If the distance is not less than 30 but less than 90, the code will execute another condition. Within this range, the 'map' function maps 'cm' values from 30 to 90 to a blink rate range of 300 to 1000. This means that when the distance is between 30 and 90, the LED's blink rate will vary between these two values.
If the distance does not meet the previous conditions, meaning the distance is greater than or equal to 90 (possibly the maximum measurement range), then 'blinkrate' will be set to 0 and the LED will not blink.To summarize, the purpose of this code is to adjust the blink rate of the LED based on the measured distance to provide visual feedback. When an object is close to the sensor, the LED flashes quickly, when the object is further away from the sensor, the LED flashes slowly, and when the object moves away from the sensor, the LED stops flashing. This can be used to create a distance-sensitive visual effect.
The reason why I did this part is so that when an object comes close to the plant, an alert will sound. 
![f6d77bd476d4fab1103affcdc5cfd26](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/55d1d5c9-ca04-44ad-af97-511fadc7e47b)


https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/8415047c-701b-43b8-b84c-c804e6b3699b



## Position of the sensor
The picture shows the position of a basic plant monitor when used with plants.
![db29ef35473dda4ab624c5ad8bb761f](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/b6210bb2-b708-4427-9bc4-575e07864ddc)

Here is my final prototype of the factory monitor and how it will be positioned with the factory.（These are two separate devices）
![334455da0fea6dda641cc268b40f0f5](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/5da4c159-18ef-456e-85f0-a075e7b98be1)

## Data visualisation
After we complete the corresponding settings through the programming software Arduino IDE used in the entire project.

Then, using the knowledge we learned earlier, we can open MQTT Explorer which can send readings to the MQTT web server and make them visible locally by browsing to the device's IP address：
![c19af44d1b4de30d33fec52c8d087a0](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/ae13003d-ac1a-43d1-bc14-4882f90f3d7a)
![222835c3aef55bf31fde28e43d52140](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/86af4062-5063-4a9b-a38b-3cedb3fbf33e)
Before setting up the Raspberry Pi to our data store, we need to install the latest 64-bit version of Raspbian. Once the installation is complete, insert your microSD card and make sure it has at least 8GB or more of space. Before you start writing on the SD card, select a 64-bit operating system, then enter your local network information and set up your account. Record your information as we will use it later.

![ea7536d9db7fa6d600e4128e35c3b18](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/fe8de4d0-30db-4f28-853f-7efd488a5311)
![e8198377b8f4c38dfca17f3b17dc19c](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/579f2e91-30fb-4398-8091-c64478ee7f14)



Once the writing is complete and the card has flashed, insert the card into the Raspberry Pi and power it up. Open a new terminal window on Windows and enter the hostname you just created:
![ca76b9ec9382b884a46ee864e412fac](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/002d2096-9399-4029-ab5a-228ebaf70a4a)





Through the knowledge learned, make a series of settings about influxdb (Enter your hostname in the link http://hostname.local:8086 and create a new account) and Grafana (use the account:admin and password:admin to log in, http://staff-pi-casa0014.local:3000)

Then,We can monitor the plants through the monitor and return the data to the web page for viewing.on the afternoon of October 31st I used the Plant Monitor basic prototype, the entire data visualized in charts via telegraf in influxdb, the peak at the beginning was produced when I watered the plant with a full bottle of water.（As shown below）


![d68ec4c233479338c35a7ce076d4262](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/ef7e7a25-ff96-4594-bdfa-662610f4845c)
In order to test the temperature, I blew into the DHT22 and We could see that the value reached 60，After a while, the value became 40，Then we can see that the temperature starts to slowly change.（As shown below）

![a5b9c75e2b6286cfe14fb14430be22d](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/b040d530-3ca1-41f2-b548-78b9de34277d)

These are the data I monitored from 10pm on October 31st to 10am on November 1st. I found that there were many fluctuations in soil moisture,I think this is a regular phenomenon. Because there are very regular fluctuations, I think it may be a problem with the placement of the nails.（As shown below）
![ac573e70302952918da74cd66f8837b](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/0c35c9bf-ba2d-4b91-af66-81226be2edba)

I went back and measured the soil moisture again, this was measured from 9 November to 10 October, about 22 hours, and found that the data levelled off and there was no rectangular data, which I think is the more correct data.
![image](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/30dca125-1919-4792-855a-3a7b31450856)




When we complete these operations, we can see the data for monitoring the plant soil.
