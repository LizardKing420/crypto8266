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
extern float cryptoPrices[3];

int i_cnt=0;
float btcEur = 0;
float ethEur = 0;
float xmrEur = 0;
void setup()
{
pinMode(pin_plava,OUTPUT);
Connect_WiFi();
Serial.begin(9600);
connection_indicator=Connect_WiFi();
pinMode(connection_indicator,OUTPUT);
getCryptoPrices();
btcEur = getBTC();
ethEur = getETH();
xmrEur = getXMR();

}

void loop()
{   
    i_cnt++;
    digitalWrite(connection_indicator, LOW);
    delay(1500);
    digitalWrite(connection_indicator, HIGH);
    delay(1500);
    Serial.println("The current prices of your cryptocurrecies are as follows:");
    Serial.print("-- Bitcoin   : "); Serial.print(cryptoPrices[0]); Serial.println(" €");
    Serial.print("-- Etherium  : "); Serial.print(ethEur); Serial.println(" €");
    Serial.print("-- Monero    : "); Serial.print(xmrEur); Serial.println(" €");
    Serial.println();
    Serial.print("Loop nr. ");
    Serial.print(i_cnt);
    Serial.println(" done!");
    Serial.println("------------------");
}