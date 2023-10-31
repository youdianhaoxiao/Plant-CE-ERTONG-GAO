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
| Buzzer | Send out a warning voice|

### Detailed assembly pictures
![0bf0253ed899834b4a0863fba025743](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/9bc5b5bd-1f87-4d1b-a60e-48ea1bd62277)
The picture above shows the nails wrapped around the wire and we will put both nails into the soil to test the moisture content. The logic behind using nails is that water can conduct electricity, but dry soil cannot.
![c67a225d95f21d0487c20b9ef9c755a](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/d33fdc7d-7dcd-4b05-aa20-a7b36706f32d)
![3d9a6ada1cdaf87d57281c5b4d5c9e0](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/714d0538-0cbc-474e-8643-c5a14e5768a3)
The resistor and DHT22 sensor are soldered to the ESP8266 so the kit is held in place as shown in the picture above.

The image below shows how the ultrasonic range finder and buzzer are connected to the ARDUINO board shown below. This part of the coding is designed so that if the ultrasonic device detects an object within 50cm, the buzzer will sound.Then there is the connection between the LED light and the ARDUINO board. This part is if the distance is less than 30, it means that the object is very close to the sensor. In this case, the 'map' function maps 'cm' values from 1 to 30 to a blink rate range of 10 to 300. This means that the closer the distance, the faster the LED flashes.
If the distance is not less than 30 but less than 90, the code will execute another condition. Within this range, the 'map' function maps 'cm' values from 30 to 90 to a blink rate range of 300 to 1000. This means that when the distance is between 30 and 90, the LED's blink rate will vary between these two values.
If the distance does not meet the previous conditions, meaning the distance is greater than or equal to 90 (possibly the maximum measurement range), then 'blinkrate' will be set to 0 and the LED will not blink.To summarize, the purpose of this code is to adjust the blink rate of the LED based on the measured distance to provide visual feedback. When an object is close to the sensor, the LED flashes quickly, when the object is further away from the sensor, the LED flashes slowly, and when the object moves away from the sensor, the LED stops flashing. This can be used to create a distance-sensitive visual effect.
The reason why I do this part is that when someone is close to the plant, there will be an alarm sound to remind.
#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 9;        //assign pin 9 to trigger
const int echoPin = 10;       //assign pin 10 to echo
const int LED = 13;           //keep the LED on pin 13
const boolean debug =true;  //variable to show hide debug info

// establish variables for duration of the ping, and the distance result in centimeters and one for LED blink rate:
long duration, cm;
int blinkrate = 0;

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void setup() {
  // initialize serial communication:
  if(debug){
    Serial.begin(9600);
    Serial.println("Starting blinker");
  }
  pinMode(LED, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input     
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);
if(cm < 100){

  if(cm < 30){
    blinkrate = map(cm, 1, 30, 10, 300);
  }
  else if(cm < 90){
    blinkrate = map(cm, 30, 90, 300, 1000);
  }
  else{
    blinkrate = 0;
  }

if(cm < 50){
  digitalWrite(12, HIGH);
  }
  else{
  digitalWrite(12, LOW);
  }

  if(debug){
    Serial.print(" cm: ");
    Serial.print(cm);
    Serial.print("   blinkrate: ");  
    Serial.println(blinkrate);
  }
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(blinkrate);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(blinkrate);


delay(20);
}

}
![f6d77bd476d4fab1103affcdc5cfd26](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/55d1d5c9-ca04-44ad-af97-511fadc7e47b)

## Position of the sensor
The picture shows the position of a basic plant monitor when used with plants, the disadvantage of this prototype is that the distance between the nails is random and completely depends on the user how to insert them, but the user should not gain knowledge of the correct distance. 
![db29ef35473dda4ab624c5ad8bb761f](https://github.com/youdianhaoxiao/Plant-CE-ERTONG-GAO/assets/146217421/b6210bb2-b708-4427-9bc4-575e07864ddc)
