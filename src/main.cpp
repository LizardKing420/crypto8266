#include "header.h"
#include <ESP8266WiFi.h>
#include <internetcode.h>
#include "german.h"
#include "croatian.h"
#define pin_plava 13
// #define WIFI_SSID   "Fam Martic"
// #define WIFI_PASS   "obitelj martic"
// //PIN Nr.:  Boja:
// //12        Zelena
// //13        Plava
// //15        Crvena

//                             // ovaj dio (dio 1.) ne trebam u LangBranch, pa cu ga izkomentirati
// int connection_indicator;
// extern float cryptoPrices[3];

// int i_cnt=0;
// float btcEur = 0;
// float ethEur = 0;
// float xmrEur = 0;


// void setup()
// {
// pinMode(pin_plava,OUTPUT);
// Connect_WiFi();
// Serial.begin(9600);
// connection_indicator=Connect_WiFi();
// pinMode(connection_indicator,OUTPUT);
// getCryptoPrices();
// btcEur = getBTC();
// ethEur = getETH();
// xmrEur = getXMR();

// }
                            //kraj djela 1

                            // setup metoda za debugg LangBrnacha (dio 2)
int randNumer; 

void setup() 
{
Serial.begin(9600);
pinMode(0, INPUT);
pinMode(12,OUTPUT);
randomSeed(analogRead(0));
}
                            // kraj djela 2

void loop()
{   
    digitalWrite(12, LOW);
    delay(1500);
    randNumer = int(random(0,100000));
    Serial.println();
    Serial.println("- - - - - - -");
    Serial.println(randNumer);
    Serial.println("- - - - - - -");
    // Serial.println(digit2TextAndSoundDe(randNumer));
    // Serial.println("...");
    Serial.println(digit2TextAndSoundHr(randNumer));
    Serial.println("......................................");
    digitalWrite(12, HIGH);
    delay(1500);

}