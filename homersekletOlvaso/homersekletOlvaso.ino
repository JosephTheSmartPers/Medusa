#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <ESP8266HTTPClient.h>

String hoszt = "http://139.162.189.55/radio/api.php"; // Ezt a címet használjuk az adatok elküldésére egy adatbázisba, hogyha a mi veboldalunkat szeretné használni, ezt hagyja így. 
                                                      //This will be used for a post request to an API, but you can use a different solution, if you want our website to see the temperature, leave that part untouched.
                                                     
const int port = 80; // Ezt a portot használd, ha a mi alap veboldalunkat akarod használni.
                     //Use this port if you wan't to use our base website, but you can change it.

const String apiKey = "WBtaEIIPDMMMtiga40Ca6UkhSvmvCdwN"; // Hogyha az alap veboldalunkat használod, akkor (majd a jövőben) le kell kérned egy saját API kulcsot, és arra cseréld ki.
                                                          // If you use the official website you will (in the future) have to generate an API key for yourself. 

const char* ssid     = ""; // Your ssid/network name
const char* jelszo = "";   // Your password

const int halasztas = 30 * 1000 // Idő két mérés elküldése között (a veboldal 30 mp alatt nem engedi)
                                // Time between two readings (the website doesn't accept if the delay is under 30 seconds)

OneWire  ds(2);  // a kettes bemeneten egy 4.7 ohmos ellenállás szükséges
                 //on pin 2 (a 4.7K resistor is necessary)
WiFiServer server(80);

void setup() {
Serial.begin(115200); // Az adatátvételi sebesség a soros csatornán
                      // The baud rate for the Serial port.
delay(10);

// Csatlakozik az internethez 
// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Csatlakozás a ");
Serial.println(ssid);

WiFi.begin(ssid, jelszo);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi-re csatlakozva \n");

// Szerver elindítása
// Start the server
server.begin();
Serial.println("Szerver elindítva ");

// Kiírja az IP címet, ami majd kelleni fog a szenzor konfigurlásához.
// Print the IP address, you will need this later, for configuring the sensor.
Serial.println(WiFi.localIP()); // 
}

void loop() {

byte i;
byte present = 0;
byte type_s;
byte data[12];
byte addr[8];
float celsius, fahrenheit;

if ( !ds.search(addr)) {
Serial.println("No more addresses.");
Serial.println();
ds.reset_search();
delay(250);
return;
}

Serial.print("ROM =");
for ( i = 0; i < 8; i++) {
Serial.write(' ');
Serial.print(addr[i], HEX);
}

if (OneWire::crc8(addr, 7) != addr[7]) {
Serial.println("CRC is not valid!");
return;
}
Serial.println();

// Megnézi a hőszenzor kompatibilitását.
// Checking temperature sensor compatability.
switch (addr[0]) {
case 0x10:
Serial.println("  Chip = DS18S20"); 
type_s = 1;
break;
case 0x28:
Serial.println("  Chip = DS18B20");
type_s = 0;
break;
case 0x22:
Serial.println("  Chip = DS1822");
type_s = 0;
break;
default:
Serial.println("Device is not a DS18x20 family device.");
return;
}

// Kiszámolja a hőmérsékletet a hőszenzor értéke alapján, számolva az ellenállással.
// Calculates the temperature based on the readings of the sensor, calculating with the resistance.
ds.reset();
ds.select(addr);
ds.write(0x44, 1);        

delay(1000); 

present = ds.reset();
ds.select(addr);
ds.write(0xBE);         

Serial.print("  Data = ");
Serial.print(present, HEX);
Serial.print(" ");
for ( i = 0; i < 9; i++) {           
data[i] = ds.read();
Serial.print(data[i], HEX);
Serial.print(" ");
}
Serial.print(" CRC=");
Serial.print(OneWire::crc8(data, 8), HEX);
Serial.println();

int16_t raw = (data[1] << 8) | data[0];
if (type_s) {
raw = raw << 3; 
if (data[7] == 0x10) {

raw = (raw & 0xFFF0) + 12 - data[6];
}
} else {
byte cfg = (data[4] & 0x60);

if (cfg == 0x00) raw = raw & ~7;  
else if (cfg == 0x20) raw = raw & ~3; 
else if (cfg == 0x40) raw = raw & ~1; 
}
celsius = (float)raw / 16.0;
fahrenheit = celsius * 1.8 + 32.0;


if (WiFi.status() == WL_CONNECTED) {
  
    String url = "?sensorID=" + WiFi.localIP().toString() + "&temp=" + celsius + "&key=" + apiKey;

    const String csatlakozasUrl = (hoszt + url);
    Serial.println("Csatlakozás ehhez veboldalhoz: " + csatlakozasUrl);
    HTTPClient http;
    
 
    http.begin(csatlakozasUrl);  // Megpróbál csatlakozni a veboldalhoz, és elküldeni az adatokat
                                // Connects to the website and atttempts to send the data
    int httpCode = http.GET();                                  
 
    if (httpCode > 0) { // Ha a veboldal adott vissza valamit
                        // If the website returned something
 
      String payload = http.getString();   
      Serial.println(payload);             
 
    }
 
    http.end();   
 
  } else {
    Serial.println("No WiFi ):");
    }

  
 
delay(10000);
}
