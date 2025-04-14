/*------------------------------------------------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/
//-------------------------------------------------------------------
//=  A. - Library  include and define  yang diperlukan              =
//-------------------------------------------------------------------

#include <WiFi.h>
#include <MQTT.h>
#include <Wire.h>
#include <SPI.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>


//--------------------------------------------------------------------
//=  B. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN ----
//--------------------------------------------------------------------

//---Actuator and Relay  pin connection---
#define relay01     27 
#define relay02     26
#define buzzer      25
#define SensorSuhu  15 // pin sambungan ke DS18B20 (ONEWIRE)
#define sensorLembab1 34
#define sensorLembab2 35
#define sensorLembab3 33

//---Penentuan nama Pembolehubah nama yg diumpukkan kepada satu nilai awal yg ditetapkan --
LiquidCrystal_I2C lcd(0x27,20,2);

// ~~~~~~~~~~~~~~~~~~~~ PENTING ~~~~~~~~~~~~~~~~~~~~~~~~
// ------ Sila edit nama atau ID ikut keperluan --------
#define Client_Id   "josephinekksbj202500001"
#define NamaBroker  "broker.emqx.io"
#define namaSSID    "JOSAN";
#define SSIDpwd     "s@nthini";
//#define namaSSID    "IoT";
//#define SSIDpwd     "iot@kksj2023";
// ~~~~~~~~~~~~~~~~~~~  TAMMAT   ~~~~~~~~~~~~~~~~~~~~~~~

//=   C.  - ISTIHAR  constant dan pembolehubah------------------------------
//---Penetapan nama Pembolehubah yg diumpukkan kepada satu nilai awal  --
const char ssid[] = namaSSID;
const char pass[] = SSIDpwd;

//------ ISTIHAR Pemboleh ubah dengan jenis Data yang digunakan---
unsigned long lastMillis = 0;
float dataSuhuC; // suhu dalam Celsius


//-=   D. - Cipta Objek dari Librari berkaitan------------------ ----
//--------------------------------------------------------------------------

WiFiClient net;
MQTTClient client;



// Istihar objek bagi Module Sersor Suhu Dallas 18B20
OneWire oneWire(SensorSuhu);
DallasTemperature sensors(&oneWire);

//##################  Seksyen 1 - TAMAT #############################

//==================  Seksyen 2 - Fungsi Setup ======================
//-------------------------------------------------------------------

void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  pinMode(buzzer,OUTPUT);

  Serial.begin(115200); // initialize serial

  WiFi.begin(ssid, pass);
  client.begin(NamaBroker, net);
  client.onMessage(messageReceived);

  sensors.begin();    // initialize the DS18B20 sensor
  connect();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ESP32 - UJI LCD");
  delay(2000);
  lcd.clear();
  delay(5000);
}
//##################  Seksyen 2 - TAMAT #############################


//==============  Seksyen 3 - Fungsi Utama (LOOP) ===================
//-------------------------------------------------------------------
void loop() {

 client.loop();
 delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

// publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
  lastMillis = millis();

    //------SENSOR 1-------------------------------------------------------------
    sensors.requestTemperatures(); 
    dataSuhuC = sensors.getTempCByIndex(0);
    Serial.print(dataSuhuC);
    Serial.println(" ºC");
    client.publish("esidevkit/suhu", String(dataSuhuC));
    //----------------------------------------------------------------------------
  
    //------SENSOR seterusnya-------------------------------------------------------------
    
          // ---masuk kod sensor seterusnya -----
    
    sensorTanah1();
    sensorTanah2();
    sensorTanah3();

    //----------------------------------------------------------------------------
  
  }
}
//##################  Seksyen 3 - TAMAT #############################