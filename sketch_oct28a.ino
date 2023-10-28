#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ezTime.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <DHT_U.h>

// Wifi and MQTT

#include "arduino_secrets.h" 

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Sensors - DHT22 and Nails
uint8_t DHTPin = 12;        // on Pin 12 of the Huzzah
uint8_t soilPin = 0;      // ADC or A0 pin on Huzzah
float Temperature;
float Humidity;
int Moisture = 1; // initial value just in case web page is loaded before readMoisture called
int sensorVCC = 13;
int blueLED = 2;
DHT dht(DHTPin, DHTTYPE);   // Initialize DHT sensor.