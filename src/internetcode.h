#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#define pin_plava 13
#define WIFI_SSID   "Fam Martic"
#define WIFI_PASS   "obitelj martic"
#define TEST_HOST "api.coingecko.com"
#define TEST_HOST_FINGERPRINT "33:C5:7B:69:E6:3B:76:5C:39:3D:F1:19:3B:17:68:B8:1B:0A:1F:D9" //ova vrijednost se mijenja svako par mijeseci
//PIN Nr.:  Boja:
//12        Zelena
//13        Plava
//15        Crvena
WiFiClientSecure client;
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
        if (i_cnt > 100)                        //Ovo se brine o tome da se ne povezuje beskrajno dugo u slucaju greske
        {
            Serial.println("]");
            Serial.println("Connection failed(connection time too long)!");
            digitalWrite(pin_plava, LOW);
            return 15;
        }
    }
    Serial.println("]");
    IPAddress ip = WiFi.localIP();
    Serial.print("Conected to:"); Serial.print(WIFI_SSID); Serial.print(" | IP:"); Serial.println(ip);
    digitalWrite(pin_plava, LOW);
    client.setFingerprint(TEST_HOST_FINGERPRINT);
    return 12;
}
//pokusatu cu sa set insecure, 
void getBTC() 
{
  if (!client.connect(TEST_HOST, 443))
{
    Serial.println(F("Connection failed"));
    return;
}

  // give the esp a breather
  yield();

  // Send HTTP request
  client.print(F("GET "));
  // This is the second half of a request (everything that comes after the base URL)
  client.print("/api/v3/simple/price?ids=ethereum%2Cbitcoin&vs_currencies=usd%2Ceur"); // %2C == ,

    client.println(F(" HTTP/1.0"));

  //Headers
  client.print(F("Host: "));
  client.println(TEST_HOST);

  client.println(F("Cache-Control: no-cache"));

  if (client.println() == 0)
  {
    Serial.println(F("Failed to send request"));
    return;
  }
  //delay(100);
  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));

  // Check if it responded "OK" with either HTTP 1.0 or 1.1
//   if (strcmp(status, "HTTP/1.0 200 OK") != 0 || strcmp(status, "HTTP/1.1 200 OK") != 0)
//   {
//     {
//       Serial.print(F("Unexpected response: "));
//       Serial.println(status);
//       return;
//     }
//   }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders))
  {
    Serial.println(F("Invalid response"));
    return;
  }

  // For APIs that respond with HTTP/1.1 we need to remove
  // the chunked data length values at the start of the body
  //
  // peek() will look at the character, but not take it off the queue
  while (client.available() && client.peek() != '{' && client.peek() != '[')
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
    Serial.println("BAD");
  }

  // While the client is still availble read each
  // byte and print to the serial monitor
  while (client.available())
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
  }

}