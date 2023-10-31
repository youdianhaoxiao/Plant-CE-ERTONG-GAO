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
if(cm < 50){
  digitalWrite(12, HIGH);
  digitalWrite(LED, HIGH);
  }
  else{
  digitalWrite(LED, LOW);
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

