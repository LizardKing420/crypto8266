#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <internetcode.h>
#define pin_plava 13
// #define WIFI_SSID   "Fam Martic"
// #define WIFI_PASS   "obitelj martic"
// //PIN Nr.:  Boja:
// //12        Zelena
// //13        Plava
// //15        Crvena
 int connection_indicator;

int i_cnt=0;
void setup()
{
pinMode(pin_plava,OUTPUT);
Connect_WiFi();
Serial.begin(9600);
connection_indicator=Connect_WiFi();
pinMode(connection_indicator,OUTPUT);
}

void loop()
{   
    i_cnt++;
    digitalWrite(connection_indicator, LOW);
    delay(1500);
    digitalWrite(connection_indicator, HIGH);
    getBTC();
    delay(1500);
    Serial.print("Loop nr. ");
    Serial.print(i_cnt);
    Serial.println(" done!");
}