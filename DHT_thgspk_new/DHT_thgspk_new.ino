#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include "DHT.h"
const char* ssid = "Virus infected Wi-Fi!"; //Your Network SSID
const char* password = "WF647241BB1"; //Your Network Password

float temp,hum;
WiFiClient client;
unsigned long myChannelNumber = 1019929; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "988MV8VCTJSQUQZ8"; //Your Write API Key
#define DHTPIN D3
DHT dht(DHTPIN,DHT11);
void setup()
{
Serial.begin(9600);
delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);
ThingSpeak.begin(client);
dht.begin();
}

void loop()
{
temp=dht.readTemperature();
hum=dht.readHumidity();
delay(500);

ThingSpeak.writeField(myChannelNumber, 1,temp, myWriteAPIKey); //Update in ThingSpeak

ThingSpeak.writeField(myChannelNumber, 2,hum, myWriteAPIKey);

delay(100);

}
