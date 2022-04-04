#include <Arduino.h>
#include <ESP8266WiFi.h>
#define pin_plava 13
#define WIFI_SSID   "Fam Martic"
#define WIFI_PASS   "obitelj martic"
//PIN Nr.:  Boja:
//12        Zelena
//13        Plava
//15        Crvena

//Vrijednos ret integera je broj pina koij trebas ukljuciti da bi boja LED inidcirala status veze (Zelena - Connected, Crvena- Time Out,Plava povezivanje jos u tijeku)
int Connect_WiFi()
{
    digitalWrite(pin_plava, HIGH);
    int i_cnt = 0;
    WiFi.begin(WIFI_SSID,WIFI_PASS);
    Serial.println(); Serial.print("Connecting to :"); Serial.println(WIFI_SSID);
    Serial.print('[');
    while (WiFi.status()!=WL_CONNECTED)
    {
        Serial.print('#');
        i_cnt++;
        delay(200);        
        if (WiFi.status() == WL_NO_SSID_AVAIL) //Ako je pogrsan SSID
        {
            Serial.println("]");
            Serial.print("SSID: "); Serial.print(WIFI_SSID); Serial.println(" not avaliable!");
            digitalWrite(pin_plava, LOW);
            return 15;
        }
        if (WiFi.status() == WL_WRONG_PASSWORD) //Ako je pogresna sifra
        {
            Serial.println("]");
            Serial.print("Wrong password for SSID: "); Serial.print(WIFI_SSID); Serial.println("!");
            digitalWrite(pin_plava, LOW);
            return 15;
        }
        if (i_cnt > 50)                        //Ovo se brine o tome da se ne povezuje beskrajno dugo u slucaju greske
        {
            Serial.println("]");
            Serial.println("Connection failed(connection time too long)!");
            digitalWrite(pin_plava, LOW);
            return 15;
        }
    }
    Serial.println("]");
    Serial.print("Conected to:"); Serial.println(WIFI_SSID);
    digitalWrite(pin_plava, LOW);
    return 12;
}