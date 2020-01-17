// ****** CHOOSE(uncomment) ONLY ONE!!! ******

#define DUSTSENSOR_PMS5003_7003_BME280_0x76 // PMS5003 / PMS7003 - BME280_0x76
// #define DUSTSENSOR_PMS5003_7003_BME280_0x77 // PMS5003 / PMS7003 - BME280_0x77
// #define DUSTSENSOR_SDS011_21 // Nova Fitness SDS011 / SDS021
// #define DUSTSENSOR_HPMA115S0 // Honeywell HPMA115S0
// #define DUSTSENSOR_SPS30 // Sensirion SPS30

// *******************************************

/*

   ESP8266

  Podłączenie czujnikow dla ESP8266 NodeMCU:
  BME280/BMP280: VIN - 3V; GND - G; SCL - D4; SDA - D3
  SHT1x: VIN - 3V; GND - G; SCL - D5; DATA/SDA - D6 wymaga rezystora 10k podłaczonego do VCC
  SHT21/HTU21D: VIN - 3V; GND - G; SCL - D5; SDA - D6
  DHT22: VIN - 3V; GND - G; D7
  PMS5003/7003: VIN - VIN/5V; GND - G; Zielony/TX - D1; Niebieski/RX - D2
  HPMA115S0: VIN - VIN/5V; GND - G; TX - D1; RX - D2
  SDS011/21: VIN - 5V; GND - G; TX - D1; RX - D2
  Sensirion SPS30: VIN - 5V; GND - G; TX - D1; RX - D2

  Connection of sensors on ESP8266 NodeMCU:
  BME280/BMP280: VIN - 3V; GND - G; SCL - D4; SDA - D3
  SHT1x: VIN - 3V; GND - G; SCL - D5; DATA/SDA - D6 required pull-up resistor 10k to VCC
  SHT21/HTU21D: VIN - 3V; GND - G; SCL - D5; SDA - D6
  DHT22: VIN - 3V; GND - G; D7
  PMS5003/7003: VIN - VIN/5V; GND - G; Green/TX - D1; Blue/RX - D2
  HPMA115S0: VIN - VIN/5V; GND - G; TX - D1; RX - D2
  SDS011/21: VIN - 5V; GND - G; TX - D1; RX - D2
  Sensirion SPS30: VIN - 5V; GND - G; TX - D1; RX - D2


   ESP32

  Podłączenie czujnikow dla ESP32:
  BME280/BMP280: VIN - 3V; GND - G; SCL - D17; SDA - D16
  SHT1x: VIN - 3V; GND - G; SCL - D5; DATA/SDA - D6 wymaga rezystora 10k podłaczonego do VCC
  SHT21/HTU21D: VIN - 3V; GND - G; SCL - D5; SDA - D6
  DHT22: VIN - 3V; GND - G; D7
  PMS5003/7003: VIN - VIN/5V; GND - G; TX - D5; RX - D4
  HPMA115S0: VIN - VIN/5V; GND - G; TX - D1; RX - D2
  SDS011/21: VIN - 5V; GND - G; TX - D5; RX - D4
  Sensirion SPS30: VIN - 5V; GND - G; TX - D5; RX - D4

  Connection of sensors on ESP32:
  BME280/BMP280: VIN - 3V; GND - G; SCL - D17; SDA - D16
  SHT1x: VIN - 3V; GND - G; SCL - D5; DATA/SDA - D6 required pull-up resistor 10k to VCC
  SHT21/HTU21D: VIN - 3V; GND - G; SCL - D5; SDA - D6
  DHT22: VIN - 3V; GND - G; D7
  PMS5003/7003: VIN - VIN/5V; GND - G; TX - D5; RX - D4
  HPMA115S0: VIN - VIN/5V; GND - G; TX - D1; RX - D2
  SDS011/21: VIN - 5V; GND - G; TX - D5; RX - D4
  Sensirion SPS30: VIN - 5V; GND - G; TX - D5; RX - D4
*/

/*
  ESP8266 PMS7003/BME280_0x76 - NodeMCU 1.0 - 1M SPIFFS --- FS:1MB OTA: ~1019KB

  Szkic używa 531556 bajtów (50%) pamięci programu. Maksimum to 1044464 bajtów.
  Zmienne globalne używają 54380 bajtów (66%) pamięci dynamicznej, pozostawiając 27540 bajtów dla zmiennych lokalnych. Maksimum to 81920 bajtów.

  Szkic używa 541500 bajtów (51%) pamięci programu. Maksimum to 1044464 bajtów.
  Zmienne globalne używają 56072 bajtów (68%) pamięci dynamicznej, pozostawiając 25848 bajtów dla zmiennych lokalnych. Maksimum to 81920 bajtów.

  ESP32 Dev Module PMS7003/BME280_0x76 - 1.9MB APP with OTA - 190KB SPIFFS

  Szkic używa 1251682 bajtów (63%) pamięci programu. Maksimum to 1966080 bajtów.
  Zmienne globalne używają 62776 bajtów (19%) pamięci dynamicznej, pozostawiając 264904 bajtów dla zmiennych lokalnych. Maksimum to 327680 bajtów.

  Szkic używa 1255726 bajtów (63%) pamięci programu. Maksimum to 1966080 bajtów.
  Zmienne globalne używają 61336 bajtów (18%) pamięci dynamicznej, pozostawiając 266344 bajtów dla zmiennych lokalnych. Maksimum to 327680 bajtów.

*/

#include "FS.h"
#include <ArduinoJson.h> // 6.9.0 or later
#include "src/WiFiManager.h" // https://github.com/tzapu/WiFiManager/tree/development // 17.01.2020  DEV
#ifdef ARDUINO_ARCH_ESP8266
#ifndef DUSTSENSOR_PMS5003_7003_BME280_0x77
#include "src/esp8266/bme280_0x76.h" // https://github.com/zen/BME280_light // CUSTOMIZED! 17.01.2020
#else
#include "src/esp8266/bme280_0x77.h" // https://github.com/zen/BME280_light // CUSTOMIZED! 17.01.2020
#endif
#elif defined ARDUINO_ARCH_ESP32
#include "src/esp32/Adafruit_BME280.h" // https://github.com/Takatsuki0204/BME280-I2C-ESP32 // 17.01.2020
#endif
#include "src/HTU21D.h" // https://github.com/enjoyneering/HTU21D // 17.01.2020
#include "src/Adafruit_BMP280.h" // https://github.com/adafruit/Adafruit_BMP280_Library // 17.01.2020
#include "src/SHT1x.h" // https://github.com/practicalarduino/SHT1x // 17.01.2020
#include <DHT.h>

#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
#include "src/pms.h" // https://github.com/fu-hsi/PMS // 17.01.2020
#elif defined DUSTSENSOR_SDS011_21
#ifdef ARDUINO_ARCH_ESP8266
#include "src/esp8266/SdsDustSensor.h" // SDS011/SDS021 - https://github.com/lewapek/sds-dust-sensors-arduino-library // 17.01.2020
#elif defined ARDUINO_ARCH_ESP32
#include "src/esp32/SDS011.h" // https://github.com/ricki-z/SDS011 // 17.01.2020
#endif
#elif defined DUSTSENSOR_HPMA115S0
#include "src/hpma115S0.h" // https://github.com/hpsaturn/HPMA115S0 // 17.01.2020
#elif defined DUSTSENSOR_SPS30
#include "src/sps30.h" // https://github.com/paulvha/sps30 // 17.01.2020
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
#include "src/pms.h" // https://github.com/fu-hsi/PMS // 17.01.2020
#endif

#include "src/spiffs.h"
#include "src/config.h"
#include "defaultConfig.h"
#include "src/autoupdate.h"
#include "src/smoglist.h"

#include "src/luftdaten.h"
#include "src/airmonitor.h"
#include "src/thing_speak.h"
#include "src/aqieco.h"
#include "src/ESPinfluxdb.h" // https://github.com/hwwong/ESP_influxdb // 17.01.2020

#ifdef ARDUINO_ARCH_ESP8266 // ESP8266 core for Arduino - 2.6.3 or later
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#ifndef DUSTSENSOR_SPS30
#include <ESP8266HTTPUpdateServer.h>
#endif
#include <SoftwareSerial.h>
#elif defined ARDUINO_ARCH_ESP32 // Arduino core for the ESP32 - 1.0.4-rc1 or later // at 1.0.3 autoupdate doesn't work !!!
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <WebServer.h>
#include <Update.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <time.h>
#include <HardwareSerial.h>
#endif

#include <PubSubClient.h>
#include <Wire.h>

// TEMP/HUMI/PRESS Sensor config - START
// BME280 config
#ifdef ARDUINO_ARCH_ESP8266 // VIN - 3V; GND - G; SCL - D4; SDA - D3
#define ASCII_ESC 27
char bufout[10];
BME280<> BMESensor;
#elif defined ARDUINO_ARCH_ESP32 // VIN - 3V; GND - G; SCL - D17; SDA - D16
#define I2C_SDA 16
#define I2C_SCL 17
Adafruit_BME280 bme(I2C_SDA, I2C_SCL); // I2C
#endif

// BMP280 config
Adafruit_BMP280 bmp; //I2C

// Serial for SHT21/HTU21D config
HTU21D  myHTU21D(HTU21D_RES_RH12_TEMP14);

// DHT22 config
#define DHTPIN 13 // D7 on NodeMCU/WeMos board
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

// SHT1x – Config
#define dataPin 14 //D5
#define clockPin 12 //D6
SHT1x sht1x(dataPin, clockPin);
// TEMP/HUMI/PRESS Sensor config - END

// DUST Sensor config - START

#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
//***PMSx003 - START***
#ifdef ARDUINO_ARCH_ESP8266
// SoftwareSerial PMS_Serial; -- only for esp8266 core 2.6.0
SoftwareSerial PMS_Serial(5, 4); // Change TX - D1 and RX - D2 pins -- esp8266 core 2.6.1 or later
PMS pms(PMS_Serial);
PMS::DATA data;
#elif defined ARDUINO_ARCH_ESP32
HardwareSerial PMS_Serial(1); // Change TX - D5 and RX - D4 pins
PMS pms(PMS_Serial);
PMS::DATA data;
#endif
//***PMSx003 - END***
#elif defined DUSTSENSOR_SDS011_21
//***SDS0x1 - START***
#ifdef ARDUINO_ARCH_ESP8266
// SDS011/21 config
SdsDustSensor sds(5, 4); // Change TX - D1 and RX - D2 pins
#elif defined ARDUINO_ARCH_ESP32
// SDS011/21 config
HardwareSerial sds_port(2); // Change TX - D5 and RX - D4 pins
SDS011 my_sds;
int err;
float SDSpm25, SDSpm10;
#endif
//***SDS0x1 - END***
#elif defined DUSTSENSOR_HPMA115S0
//***HPMA115S0 - START***
#ifdef ARDUINO_ARCH_ESP8266
SoftwareSerial hpmaSerial(5, 4); // TX/RX – D1/D2
HPMA115S0 hpma115S0(hpmaSerial);
#elif defined ARDUINO_ARCH_ESP32
HardwareSerial hpmaSerial(1); // Change TX - D5 and RX - D4 pins
HPMA115S0 hpma115S0(hpmaSerial);
#endif
unsigned int hpma115S0_pm25, hpma115S0_pm10;
//***HPMA115S0 - END***
#elif defined DUSTSENSOR_SPS30
//***SPS30 - START***
#ifdef ARDUINO_ARCH_ESP32
#define SPS30_RX_PIN 4           // D4
#define SPS30_TX_PIN 5           // D5
#else
#define SPS30_RX_PIN 4            // D2
#define SPS30_TX_PIN 5            // D1
#endif
#define SP30_COMMS SERIALPORT1
#define SPS30_AUTOCLEANINTERVAL -1
#define SPS30_PERFORMCLEANNOW 1
#define SPS30_DEBUG 0
// create constructor
SPS30 sps30;
float SPS30_PM1, SPS30_PM25, SPS30_PM4, SPS30_PM10;
//***SPS30 - END***
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
//***PMSx003 - START***
#ifdef ARDUINO_ARCH_ESP8266
// SoftwareSerial PMS_Serial; -- only for esp8266 core 2.6.0
SoftwareSerial PMS_Serial(5, 4); // Change TX - D1 and RX - D2 pins -- esp8266 core 2.6.1 or later
PMS pms(PMS_Serial);
PMS::DATA data;
#elif defined ARDUINO_ARCH_ESP32
HardwareSerial PMS_Serial(1); // Change TX - D5 and RX - D4 pins
PMS pms(PMS_Serial);
PMS::DATA data;
#endif
//***PMSx003 - END***
#endif


// DUST Sensor config - END

char device_name[20];

unsigned long DUST_interval = 60 * 1000; // 1 minute
unsigned long previous_DUST_Millis = 0;

unsigned long SENDING_FREQUENCY_interval = 60 * 1000; // 1 minute
unsigned long previous_SENDING_FREQUENCY_Millis = 0;

unsigned long SENDING_DB_FREQUENCY_interval = 60 * 1000; // 1 minute
unsigned long previous_SENDING_DB_FREQUENCY_Millis = 0;

unsigned long previous_2sec_Millis = 0;
unsigned long TwoSec_interval = 2 * 1000; // 2 second

unsigned long REBOOT_interval = 24 * 60 * 60 * 1000; // 24 hours
unsigned long previous_REBOOT_Millis = 0;

#ifdef DUSTSENSOR_SPS30
int pmMeasurements[10][4];
#else
int pmMeasurements[10][3];
#endif
int iPM, averagePM1, averagePM25, averagePM4, averagePM10 = 0;
float currentTemperature, currentHumidity, currentPressure = 0;
float calib = 1;

bool need_update = false;
char SERVERSOFTWAREVERSION[255] = "";
char CURRENTSOFTWAREVERSION[255] = "";

#ifdef ARDUINO_ARCH_ESP8266
ESP8266WebServer WebServer(80);
#ifndef DUSTSENSOR_SPS30
ESP8266HTTPUpdateServer httpUpdater;
#endif
#elif defined ARDUINO_ARCH_ESP32
WebServer WebServer(80);
#endif

WiFiClient espClient;
PubSubClient mqttclient(espClient);

WiFiManager wifiManager;

// check TEMP/HUMI/PRESS Sensor - START
bool checkHTU21DStatus() {
  int temperature_HTU21D_Int = int(myHTU21D.readTemperature());
  int humidity_HTU21D_Int = int(myHTU21D.readHumidity());
  if ((temperature_HTU21D_Int == 0 && humidity_HTU21D_Int == 0) || (temperature_HTU21D_Int == 255 && humidity_HTU21D_Int == 255)) {
    if (DEBUG) {
      Serial.println("No data from HTU21D sensor!\n");
    }
    return false;
  } else {
    return true;
  }
}

bool checkBmeStatus() {
#ifdef ARDUINO_ARCH_ESP8266
  int temperature_BME280_Int = BMESensor.temperature;
  int pressure_BME280_Int = (BMESensor.seaLevelForAltitude(MYALTITUDE));
  int humidity_BME280_Int = BMESensor.humidity;
#elif defined ARDUINO_ARCH_ESP32
  int temperature_BME280_Int = bme.readTemperature();
  int pressure_BME280_Int = (bme.seaLevelForAltitude(MYALTITUDE, (bme.readPressure() / 100.0F)));
  int humidity_BME280_Int = bme.readHumidity();
#endif
  if (temperature_BME280_Int == 0 && pressure_BME280_Int == 0 && humidity_BME280_Int == 0) {
    if (DEBUG) {
      Serial.println("No data from BME280 sensor!\n");
    }
    return false;
  } else {
    return true;
  }
}

bool checkBmpStatus() {
  int temperature_BMP_Int = bmp.readTemperature();
  int pressure_BMP_Int = bmp.readPressure();
  if (temperature_BMP_Int == 0 && pressure_BMP_Int == 0) {
    if (DEBUG) {
      Serial.println("No data from BMP280 sensor!\n");
    }
    return false;
  } else {
    return true;
  }
}

bool checkDHT22Status() {
  int humidity_DHT_Int = dht.readHumidity();
  int temperature_DHT_Int = dht.readTemperature();
  if (humidity_DHT_Int == 0 && temperature_DHT_Int == 0) {
    if (DEBUG) {
      Serial.println("No data from DHT22 sensor!\n");
    }
    return false;
  } else {
    return true;
  }
}

bool checkSHT1xStatus() {
  int humidity_SHT1x_Int = sht1x.readHumidity();
  int temperature_SHT1x_Int = sht1x.readTemperatureC();
  if (humidity_SHT1x_Int == 0 && temperature_SHT1x_Int == 0) {
    if (DEBUG) {
      Serial.println("No data from SHT1x sensor!\n");
    }
    return false;
  } else {
    return true;
  }
}
// check TEMP/HUMI/PRESS Sensor - END

void minutesToSeconds() {
  DUST_interval = 1000; // 1 second
  SENDING_FREQUENCY_interval = 1000;
  SENDING_DB_FREQUENCY_interval = 1000;
}

void MQTTreconnect() {
  // Loop until we're reconnected
  if (!mqttclient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (mqttclient.connect("ESP8266Client", MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttclient.state());
      Serial.println("\n");
    }
  }
}

// default translation - english
#include "src/default_intl.h"

#include "src/translator.h"

// all HTML content
#include "src/html-content.h"

// library doesnt support arguments :/
#include "src/webserver.h"

void setup() {
  Serial.begin(115200);
  yield();

  fs_setup();
  yield();

#ifdef ARDUINO_ARCH_ESP32
  disableCore0WDT();
  //disableCore1WDT(); // ESP32-solo-1 so only CORE0!
#endif

  loadtranslation(SELECTED_LANGUAGE);
  yield();

  // DUST SENSOR setup - START
#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
  if (!strcmp(DUST_MODEL, "PMS7003")) {
#ifdef ARDUINO_ARCH_ESP8266
    PMS_Serial.begin(9600); //PMSx003 serial -- esp8266 core 2.6.1 or later
    //PMS_Serial.begin(9600, 5, 4); // Change TX - D1 and RX - D2 pins -- only for esp8266 core 2.6.0
#elif defined ARDUINO_ARCH_ESP32
    PMS_Serial.begin(9600, SERIAL_8N1, 5, 4); //PMSx003 serial
#endif
    if (FREQUENTMEASUREMENT == true) {
      pms.wakeUp();
      delay(500);
      pms.activeMode();
    } else {
      pms.passiveMode();
      delay(500);
      pms.sleep();
    }
  }
#elif defined DUSTSENSOR_SDS011_21
  if (!strcmp(DUST_MODEL, "SDS011/21")) {
#ifdef ARDUINO_ARCH_ESP8266
    sds.begin();  //SDS011/21 sensor begin
#elif defined ARDUINO_ARCH_ESP32
    sds_port.begin(9600, SERIAL_8N1, 5, 4);  //SDS011/21 sensor begin
    my_sds.begin(&sds_port);
#endif
    if (FREQUENTMEASUREMENT == true) {
#ifdef ARDUINO_ARCH_ESP8266
      sds.wakeup();
      sds.setQueryReportingMode().toString(); // ensures sensor is in 'query' reporting mode
      sds.setContinuousWorkingPeriod().toString(); // ensures sensor has continuous working period - default but not recommended
#elif defined ARDUINO_ARCH_ESP32
      err = my_sds.read(&SDSpm25, &SDSpm10);
      if (!err) {
        Serial.println("Data from SDS011!\n");
      }
#endif
    } else {
#ifdef ARDUINO_ARCH_ESP8266
      sds.setCustomWorkingPeriod(1);
      WorkingStateResult state = sds.sleep();
#elif defined ARDUINO_ARCH_ESP32
      err = my_sds.read(&SDSpm25, &SDSpm10);
      if (!err) {
        Serial.println("Data from SDS011!\n");
      }
#endif
    }
  }
  delay(10);
#elif defined DUSTSENSOR_HPMA115S0
  if (!strcmp(DUST_MODEL, "HPMA115S0")) {
#ifdef ARDUINO_ARCH_ESP8266
    hpmaSerial.begin(9600); //HPMA115S0 serial
#elif defined ARDUINO_ARCH_ESP32
    hpmaSerial.begin(9600, SERIAL_8N1, 5, 4); //HPMA115S0 serial
#endif
    delay(100);
    if (FREQUENTMEASUREMENT == true) {
      hpma115S0.Init();
      delay(100);
      hpma115S0.EnableAutoSend();
      delay(100);
      hpma115S0.StartParticleMeasurement();
    } else {
      hpma115S0.Init();
      delay(100);
      hpma115S0.StopParticleMeasurement();
    }
  }
  delay(10);
#elif defined DUSTSENSOR_SPS30
  if (!strcmp(DUST_MODEL, "SPS30")) {
    Serial.println(F("Trying to connect to SPS30..."));

    // set driver debug level
    sps30.EnableDebugging(SPS30_DEBUG);

    // set pins to use for softserial and Serial1 on ESP32
    if (SPS30_TX_PIN != 0 && SPS30_RX_PIN != 0) sps30.SetSerialPin(SPS30_RX_PIN, SPS30_TX_PIN);

    // Begin communication channel;
    if (sps30.begin(SP30_COMMS) == false) {
      Errorloop("could not initialize communication channel.", 0);
    }

    // check for SPS30 connection
    if (sps30.probe() == false) {
      Errorloop("could not probe / connect with SPS30.", 0);
    }
    else
      Serial.println(F("Detected SPS30."));

    // reset SPS30 connection
    if (sps30.reset() == false) {
      Errorloop("could not reset.", 0);
    }

    // read device info
    GetDeviceInfo();

    // do Auto Clean interval
    SetAutoClean();

    // start measurement
    if (sps30.start() == true)
      Serial.println(F("\nMeasurement started"));
    else
      Errorloop("Could NOT start measurement", 0);

    // clean now requested
    if (SPS30_PERFORMCLEANNOW) {
      // clean now
      if (sps30.clean() == true)
        Serial.println(F("fan-cleaning manually started"));
      else
        Serial.println(F("Could NOT manually start fan-cleaning"));
    }

    if (SP30_COMMS == I2C_COMMS) {
      if (sps30.I2C_expect() == 4)
        Serial.println(F(" !!! Due to I2C buffersize only the SPS30 MASS concentration is available !!! \n"));
    }
  }
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
  if (!strcmp(DUST_MODEL, "PMS7003")) {
#ifdef ARDUINO_ARCH_ESP8266
    PMS_Serial.begin(9600); //PMSx003 serial -- esp8266 core 2.6.1 or later
    //PMS_Serial.begin(9600, 5, 4); // Change TX - D1 and RX - D2 pins -- only for esp8266 core 2.6.0
#elif defined ARDUINO_ARCH_ESP32
    PMS_Serial.begin(9600, SERIAL_8N1, 5, 4); //PMSx003 serial
#endif
    if (FREQUENTMEASUREMENT == true) {
      pms.wakeUp();
      delay(500);
      pms.activeMode();
    } else {
      pms.passiveMode();
      delay(500);
      pms.sleep();
    }
  }
#endif
  yield();
  // DUST SENSOR setup - END

  if (SENDING_FREQUENCY < DUST_TIME) {
    SENDING_FREQUENCY = DUST_TIME;
  }
  if (SENDING_DB_FREQUENCY == 0) {
    SENDING_DB_FREQUENCY = SENDING_FREQUENCY;
  }
  yield();

  if (FREQUENTMEASUREMENT == true) {
    minutesToSeconds();
  }

  if (strcmp(DUST_MODEL, "Non")) {
    DUST_interval = DUST_interval * DUST_TIME;
  }
  if (DEEPSLEEP_ON == true) {
    if (LUFTDATEN_ON or AQI_ECO_ON or AIRMONITOR_ON or SMOGLIST_ON or THINGSPEAK_ON or INFLUXDB_ON or MQTT_ON) {
      SENDING_FREQUENCY_interval = SENDING_FREQUENCY_interval * SENDING_FREQUENCY;
    }
#ifdef ARDUINO_ARCH_ESP32
#define uS_TO_S_FACTOR 1000000ULL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  int(SENDING_FREQUENCY_interval/1000)        /* Time ESP32 will go to sleep (in seconds) */
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
    Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds\n");
#endif
  } else {
    if (LUFTDATEN_ON or AQI_ECO_ON or AIRMONITOR_ON or SMOGLIST_ON) {
      SENDING_FREQUENCY_interval = SENDING_FREQUENCY_interval * SENDING_FREQUENCY;
    }
    if (THINGSPEAK_ON or INFLUXDB_ON or MQTT_ON) {
      SENDING_DB_FREQUENCY_interval = SENDING_DB_FREQUENCY_interval * SENDING_DB_FREQUENCY;
    }
  }
  yield();

  // TEMP/HUMI/PRESS Sensor seturp - START
  if (!strcmp(THP_MODEL, "BME280")) {
#ifdef ARDUINO_ARCH_ESP8266
    Wire.begin(0, 2);
    BMESensor.begin();
#elif defined ARDUINO_ARCH_ESP32
    bme.begin();
#endif
  } else if (!strcmp(THP_MODEL, "BMP280")) {
    Wire.begin(0, 2);
    bmp.begin();
  } else if (!strcmp(THP_MODEL, "HTU21")) {
    myHTU21D.begin();
  } else if (!strcmp(THP_MODEL, "DHT22")) {
    dht.begin();
  } else if (!strcmp(THP_MODEL, "SHT1x")) {
  }
  yield();
  // TEMP/HUMI/PRESS Sensor setup - END

  // get ESP id
  if (DEVICENAME_AUTO) {
#ifdef ARDUINO_ARCH_ESP8266
    sprintf(device_name, "Smogomierz-%06X", ESP.getChipId());
#elif defined ARDUINO_ARCH_ESP32
    sprintf(device_name, "Smogomierz-%06X", ESP.getEfuseMac());
#endif
  } else {
    strncpy(device_name, DEVICENAME, 20);
  }

  Serial.print("Device name: ");
  Serial.println(device_name);

  wifiManager.setCountry("US");

  if (wifiManager.autoConnect(device_name)) {
    Serial.println("connected...yeey :)");
    //wifiManager.setConfigPortalBlocking(false);
    WiFi.mode(WIFI_STA); // https://github.com/hackerspace-silesia/Smogomierz/issues/47#issue-496810438
#ifdef ARDUINO_ARCH_ESP32
    WiFi.setSleep(false); // https://github.com/espressif/arduino-esp32/issues/962#issuecomment-522899519
#endif
  } else {
    Serial.println("Configportal running");
    wifiManager.setConfigPortalBlocking(false);
  }
  delay(250);

  // check update
  if (checkUpdate(0) == true) {
    need_update = true;
  } else {
    need_update = false;
  }

  if (MQTT_ON) {
    mqttclient.setServer(MQTT_HOST, MQTT_PORT);
  }

  if (INFLUXDB_ON) {
    Influxdb influxdb(INFLUXDB_HOST, INFLUXDB_PORT);
    if (influxdb.opendb(INFLUXDB_DATABASE, DB_USER, DB_PASSWORD) != DB_SUCCESS) {
      Serial.println("Opening InfluxDB failed");
    } else {
      Serial.println("Opening InfluxDB succeed");
    }
  }

  //  WebServer config - Start
  WebServer.on("/", HTTP_GET,  handle_root);
  WebServer.on("/config", HTTP_POST, handle_config_post);
  WebServer.on("/config", HTTP_GET, handle_config);
  WebServer.on("/update", HTTP_GET, handle_update);
  WebServer.on("/api", HTTP_GET, handle_api);
  WebServer.on("/erase_wifi", HTTP_GET, erase_wifi);
  WebServer.on("/restore_config", HTTP_GET, restore_config);
  WebServer.on("/fwupdate", HTTP_GET, fwupdate);
  WebServer.on("/autoupdateon", HTTP_GET, autoupdateon);
  WebServer.onNotFound(handle_root);

#ifdef ARDUINO_ARCH_ESP8266
#ifndef DUSTSENSOR_SPS30
  httpUpdater.setup(&WebServer, "/update");
#endif
#elif defined ARDUINO_ARCH_ESP32
  /*handling uploading firmware file */
  WebServer.on("/update", HTTP_POST, []() {
    WebServer.sendHeader("Connection", "close");
    WebServer.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart();
  }, []() {
    HTTPUpload& upload = WebServer.upload();
    if (upload.status == UPLOAD_FILE_START) {
      //Serial.printf("Update: %s\n", upload.filename.c_str());
      Serial.print("Update: " + String(upload.filename.c_str()) + "\n");
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_WRITE) {
      /* flashing firmware to ESP*/
      if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_END) {
      if (Update.end(true)) { //true to set the size to the current progress
        //Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        Serial.print("Update Success: " + String(upload.totalSize) + "\nRebooting...\n");
      } else {
        Update.printError(Serial);
      }
    }
  });
#endif
  //  WebServer Config - End

  // Check if config.h exist in ESP data folder
  WebServer.begin();

  MDNS.begin(device_name);

  MDNS.addService("http", "tcp", 80);
  //Serial.printf("HTTPServer ready! http://%s.local/\n", device_name);
  Serial.print("HTTPServer ready! http://" + String(device_name) + ".local/\n");
  delay(300);
}

void loop() {
  if (need_update == true && AUTOUPDATE_ON) {
    for (int i = 0; i < 5 ; i++) {
      doUpdate(0);
      delay(1000);
    }
  }
  yield();

  pm_calibration();

  // DUST SENSOR refresh data - START
#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.read(data);
  }
#elif defined DUSTSENSOR_SDS011_21
#ifdef ARDUINO_ARCH_ESP8266
  PmResult SDSdata = sds.queryPm();
#endif
#elif defined DUSTSENSOR_HPMA115S0
#elif defined DUSTSENSOR_SPS30
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.read(data);
  }
#endif
  // DUST SENSOR refresh data - END
  yield();

  //webserverShowSite(WebServer, BMESensor, data);
  WebServer.handleClient();

  /*
    #ifdef ARDUINO_ARCH_ESP8266
    MDNS.update();
    #endif
  */

  if (strcmp(DUST_MODEL, "Non")) {
    unsigned long current_DUST_Millis = millis();
    if (FREQUENTMEASUREMENT == true ) {
      if (current_DUST_Millis - previous_DUST_Millis >= DUST_interval) {
        takeNormalnPMMeasurements();
        previous_DUST_Millis = millis();
      }
    }
    if (DEEPSLEEP_ON == true) {
      Serial.println("\nDeepSleep Mode!\n");

      takeSleepPMMeasurements();
      yield();

      if (LUFTDATEN_ON or AQI_ECO_ON or AIRMONITOR_ON or SMOGLIST_ON) {
        takeTHPMeasurements();
        sendDataToExternalServices();
      }
      if (THINGSPEAK_ON or INFLUXDB_ON or MQTT_ON) {
        takeTHPMeasurements();
        sendDataToExternalDBs();
      }

#ifdef ARDUINO_ARCH_ESP8266
      Serial.println("Going into deep sleep for " + String(SENDING_FREQUENCY) + " minutes!");
      Serial.flush();
      ESP.deepSleep(SENDING_FREQUENCY * 60 * 1000000); // *1000000 - secunds
      yield();
#elif defined ARDUINO_ARCH_ESP32
      Serial.println("Going to sleep now");
      Serial.flush();
      esp_deep_sleep_start();
#endif

    } else {
      if (current_DUST_Millis - previous_DUST_Millis >= DUST_interval) {
        takeSleepPMMeasurements();
        previous_DUST_Millis = millis();
      }
    }
  } else {
    if (DEEPSLEEP_ON == true) {
      Serial.println("\nDeepSleep Mode!\n");
      unsigned long current_2sec_Millis = millis();
      previous_2sec_Millis = millis();
      while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 10) {
        WebServer.handleClient();
        previous_2sec_Millis = millis();
      }
      if (LUFTDATEN_ON or AQI_ECO_ON or AIRMONITOR_ON or SMOGLIST_ON) {
        takeTHPMeasurements();
        sendDataToExternalServices();
      }
      if (THINGSPEAK_ON or INFLUXDB_ON or MQTT_ON) {
        takeTHPMeasurements();
        sendDataToExternalDBs();
      }
      yield();

#ifdef ARDUINO_ARCH_ESP8266
      Serial.println("Going into deep sleep for " + String(SENDING_FREQUENCY) + " minutes!");
      Serial.flush();
      ESP.deepSleep(SENDING_FREQUENCY * 60 * 1000000); // *1000000 - secunds
      yield();
#elif defined ARDUINO_ARCH_ESP32
      Serial.println("Going to sleep now");
      Serial.flush();
      esp_deep_sleep_start();
#endif

    }
  }

  if (LUFTDATEN_ON or AQI_ECO_ON or AIRMONITOR_ON or SMOGLIST_ON) {
    unsigned long current_SENDING_FREQUENCY_Millis = millis();
    if (current_SENDING_FREQUENCY_Millis - previous_SENDING_FREQUENCY_Millis >= SENDING_FREQUENCY_interval) {
      takeTHPMeasurements();
      sendDataToExternalServices();
      previous_SENDING_FREQUENCY_Millis = millis();
    }
  }

  if (THINGSPEAK_ON or INFLUXDB_ON or MQTT_ON) {
    unsigned long current_SENDING_DB_FREQUENCY_Millis = millis();
    if (current_SENDING_DB_FREQUENCY_Millis - previous_SENDING_DB_FREQUENCY_Millis >= SENDING_DB_FREQUENCY_interval) {
      takeTHPMeasurements();
      sendDataToExternalDBs();
      previous_SENDING_DB_FREQUENCY_Millis = millis();
    }
  }

  unsigned long current_REBOOT_Millis = millis();
  if (current_REBOOT_Millis - previous_REBOOT_Millis >= REBOOT_interval) {
    Serial.println("autoreboot...");
    delay(1000);
    previous_REBOOT_Millis = millis();
#ifdef ARDUINO_ARCH_ESP8266
    ESP.reset();
#elif defined ARDUINO_ARCH_ESP32
    ESP.restart();
#endif
    delay(5000);
  }

} // loop() - END

void sendDataToExternalServices() {

  if (LUFTDATEN_ON) {
    sendDataToLuftdaten(currentTemperature, currentPressure, currentHumidity, averagePM1, averagePM25, averagePM4, averagePM10);
    if (DEBUG) {
      Serial.println("Sending measurement data to the LuftDaten service!\n");
    }
  }

  if (AIRMONITOR_ON) {
    sendDataToAirMonitor(currentTemperature, currentPressure, currentHumidity, averagePM1, averagePM25, averagePM4, averagePM10);
    if (DEBUG) {
      Serial.println("Sending measurement data to the AirMonitor service!\n");
    }
  }

  if (SMOGLIST_ON) {
    sendDataToSmoglist(currentTemperature, currentPressure, currentHumidity, averagePM1, averagePM25, averagePM4, averagePM10);
    if (DEBUG) {
      Serial.println("Sending measurement data to the Smoglist service!\n");
    }
  }

  if (AQI_ECO_ON) {
    sendDataToAqiEco(currentTemperature, currentPressure, currentHumidity, averagePM1, averagePM25, averagePM4, averagePM10);
    if (DEBUG) {
      Serial.println("Sending measurement data to the aqi.eco service!\n");
    }
  }

}

void sendDataToExternalDBs() {

  if (MQTT_ON) {
    if (!mqttclient.connected()) {
      MQTTreconnect();
    }
    mqttclient.loop();
    yield();
  }

  if (THINGSPEAK_ON) {
    sendDataToThingSpeak(currentTemperature, currentPressure, currentHumidity, averagePM1, averagePM25, averagePM4, averagePM10);
    if (DEBUG) {
      Serial.println("Sending measurement data to the Thingspeak service!\n");
    }
  }

  if (INFLUXDB_ON) {
    Influxdb influxdb(INFLUXDB_HOST, INFLUXDB_PORT);
    if (influxdb.opendb(INFLUXDB_DATABASE, DB_USER, DB_PASSWORD) != DB_SUCCESS) {
      Serial.println("Opening database failed");
    } else {
      dbMeasurement row(device_name);

      if (!strcmp(DUST_MODEL, "PMS7003")) {
        if (DEBUG) {
          Serial.println("\nMeasurements from PMSx003!\n");
        }
        row.addField("pm1", averagePM1);
        row.addField("pm25", averagePM25);
        row.addField("pm10", averagePM10);
      } else if (!strcmp(DUST_MODEL, "SDS011/21")) {
        if (DEBUG) {
          Serial.println("\nMeasurements from SDS0x1!\n");
        }
        row.addField("pm1", averagePM1);
        row.addField("pm25", averagePM25);
        row.addField("pm10", averagePM10);
      } else if (!strcmp(DUST_MODEL, "HPMA115S0")) {
        if (DEBUG) {
          Serial.println("\nMeasurements from SDS!\n");
        }
        row.addField("pm1", averagePM1);
        row.addField("pm25", averagePM25);
        row.addField("pm10", averagePM10);
      } else if (!strcmp(DUST_MODEL, "SPS30")) {
        if (DEBUG) {
          Serial.println("\nMeasurements from SPS30!\n");
        }
        row.addField("pm1", averagePM1);
        row.addField("pm25", averagePM25);
        row.addField("pm10", averagePM10);
      } else {
        if (DEBUG) {
          Serial.println("\nNo measurements from Dust Sensor!\n");
        }
      }
      if (!strcmp(THP_MODEL, "BME280")) {
        if (checkBmeStatus() == true) {
          row.addField("temperature", (currentTemperature));
          row.addField("pressure", (currentPressure));
          row.addField("humidity", (currentHumidity));
        } else {
          if (DEBUG) {
            Serial.println("No measurements from BME280!\n");
          }
        }
      } else if (!strcmp(THP_MODEL, "HTU21")) {
        if (checkHTU21DStatus() == true) {
          row.addField("temperature", (currentTemperature));
          row.addField("humidity", (currentHumidity));
        } else {
          if (DEBUG) {
            Serial.println("No measurements from HTU21D!\n");
          }
        }
      } else if (!strcmp(THP_MODEL, "BMP280")) {
        if (checkBmpStatus() == true) {
          row.addField("temperature", (currentTemperature));
          row.addField("pressure", (currentPressure));
        } else {
          if (DEBUG) {
            Serial.println("No measurements from BMP280!\n");
          }
        }
      } else if (!strcmp(THP_MODEL, "DHT22")) {
        if (checkDHT22Status() == true) {
          row.addField("temperature", (currentTemperature));
          row.addField("humidity", (currentHumidity));
        } else {
          if (DEBUG) {
            Serial.println("No measurements from DHT22!\n");
          }
        }
      } else if (!strcmp(THP_MODEL, "SHT1x")) {
        if (checkSHT1xStatus() == true) {
          row.addField("temperature", (currentTemperature));
          row.addField("humidity", (currentHumidity));
        } else {
          if (DEBUG) {
            Serial.println("No measurements from SHT1x!\n");
          }
        }
      }

      if (influxdb.write(row) == DB_SUCCESS) {
        if (DEBUG) {
          Serial.println("Data sent to InfluxDB\n");
        }
      } else {
        if (DEBUG) {
          Serial.println("Error sending data to InfluxDB\n");
        }
      }
      row.empty();
    }
  }

  if (MQTT_ON) {
#ifdef ARDUINO_ARCH_ESP8266
    String mqttChipId = String(ESP.getChipId());
#elif defined ARDUINO_ARCH_ESP32
    String mqttChipId = String((uint32_t)(ESP.getEfuseMac()));
#endif
    if (strcmp(DUST_MODEL, "Non")) {
      if (DEBUG) {
        Serial.println("Measurements from PM Sensor!\n");
      }
      mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/PM1").c_str(), String(averagePM1).c_str(), true);
      mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/PM2.5").c_str(), String(averagePM25).c_str(), true);
      mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/PM10").c_str(), String(averagePM10).c_str(), true);
      if (averagePM25 <= 10) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "EXCELLENT", true);
      } else if (averagePM25 > 10 && averagePM25 <= 20) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "GOOD", true);
      } else if (averagePM25 > 20 && averagePM25 <= 25) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "FAIR", true);
      } else if (averagePM25 > 25 && averagePM25 <= 50) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "INFERIOR", true);
      } else if (averagePM25 > 50) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "POOR", true);
      } else {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/airquality").c_str(), "UNKNOWN", true);
      }
    }


    if (!strcmp(THP_MODEL, "BME280")) {
      if (checkBmeStatus() == true) {

        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/temperature").c_str(), String(currentTemperature).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/pressure").c_str(), String(currentPressure).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/humidity").c_str(), String(currentHumidity).c_str(), true);

      } else {
        if (DEBUG) {
          Serial.println("No measurements from BME280!\n");
        }
      }
    }

    if (!strcmp(THP_MODEL, "BMP280")) {
      if (checkBmpStatus() == true) {

        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/temperature").c_str(), String(currentTemperature).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/pressure").c_str(), String(currentPressure).c_str(), true);

      } else {
        if (DEBUG) {
          Serial.println("No measurements from BMP280!\n");
        }
      }
    }

    if (!strcmp(THP_MODEL, "HTU21")) {
      if (checkHTU21DStatus() == true) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/temperature").c_str(), String(currentTemperature).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/humidity").c_str(), String(currentHumidity).c_str(), true);
      } else {
        if (DEBUG) {
          Serial.println("No measurements from HTU21!\n");
        }
      }
    }

    if (!strcmp(THP_MODEL, "DHT22")) {
      if (checkDHT22Status() == true) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/temperature").c_str(), String(currentTemperature).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/humidity").c_str(), String(currentHumidity).c_str(), true);
      } else {
        if (DEBUG) {
          Serial.println("No measurements from DHT22!\n");
        }
      }
    }

    if (!strcmp(THP_MODEL, "SHT1x")) {
      if (checkDHT22Status() == true) {
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/temperature").c_str(), String(currentTemperature).c_str(), true);
        mqttclient.publish(String("Smogomierz-" + mqttChipId + "/sensor/humidity").c_str(), String(currentHumidity).c_str(), true);
      } else {
        if (DEBUG) {
          Serial.println("No measurements from SHT1x!\n");
        }
      }
    }

    if (DEEPSLEEP_ON == true) {
      mqttclient.disconnect();
    }
  }

}

void takeTHPMeasurements() {
  if (!strcmp(THP_MODEL, "BME280")) {
#ifdef ARDUINO_ARCH_ESP8266
    BMESensor.refresh();
    yield();
#endif
    if (checkBmeStatus() == true) {
      if (DEBUG) {
        Serial.println("Measurements from BME280!\n");
      }
#ifdef ARDUINO_ARCH_ESP8266
      currentTemperature = BMESensor.temperature;
      currentPressure = BMESensor.seaLevelForAltitude(MYALTITUDE);
      currentHumidity = BMESensor.humidity;
#elif defined ARDUINO_ARCH_ESP32
      currentTemperature = (bme.readTemperature()); // maybe *0.89 ?
      currentPressure = (bme.seaLevelForAltitude(MYALTITUDE, (bme.readPressure() / 100.0F)));
      currentHumidity = (bme.readHumidity()); // maybe *0.89 ?
#endif

    } else {
      if (DEBUG) {
        Serial.println("No measurements from BME280!\n");
      }
    }
  } else if (!strcmp(THP_MODEL, "HTU21")) {
    if (checkHTU21DStatus() == true) {
      if (DEBUG) {
        Serial.println("Measurements from HTU21!\n");
      }
      currentTemperature = myHTU21D.readTemperature();
      currentHumidity = myHTU21D.readHumidity();
    } else {
      if (DEBUG) {
        Serial.println("No measurements from HTU21D!\n");
      }
    }
  } else if (!strcmp(THP_MODEL, "BMP280")) {
    if (checkBmpStatus() == true) {
      if (DEBUG) {
        Serial.println("Measurements from BMP280!\n");
      }
      currentTemperature = bmp.readTemperature();
      currentPressure = (bmp.readPressure()) / 100;
    } else {
      if (DEBUG) {
        Serial.println("No measurements from BMP280!\n");
      }
    }
  } else if (!strcmp(THP_MODEL, "DHT22")) {
    if (checkDHT22Status() == true) {
      if (DEBUG) {
        Serial.println("Measurements from DHT22!\n");
      }
      currentTemperature = dht.readTemperature();
      currentHumidity = dht.readHumidity();
    } else {
      if (DEBUG) {
        Serial.println("No measurements from DHT22!\n");
      }
    }
  } else if (!strcmp(THP_MODEL, "SHT1x")) {
    if (checkSHT1xStatus() == true) {
      if (DEBUG) {
        Serial.println("Measurements from SHT1x!\n");
      }
      currentTemperature = sht1x.readTemperatureC();
      currentHumidity = sht1x.readHumidity();
    } else {
      if (DEBUG) {
        Serial.println("No measurements from SHT1x!\n");
      }
    }
  }

}

void takeNormalnPMMeasurements() {
#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
  pmMeasurements[iPM][0] = int(calib * data.PM_AE_UG_1_0);
  pmMeasurements[iPM][1] = int(calib * data.PM_AE_UG_2_5);
  pmMeasurements[iPM][2] = int(calib * data.PM_AE_UG_10_0);
#elif defined DUSTSENSOR_SDS011_21
#ifdef ARDUINO_ARCH_ESP8266
  PmResult SDSdata = sds.queryPm();
  delay(1000);
  if (SDSdata.isOk()) {
    pmMeasurements[iPM][0] = int(calib * 0);
    pmMeasurements[iPM][1] = int(calib * SDSdata.pm25);
    pmMeasurements[iPM][2] = int(calib * SDSdata.pm10);
  } else {
    Serial.println("\nCould not read values from SDS sensor :( ");
  }
#elif defined ARDUINO_ARCH_ESP32
  err = my_sds.read(&SDSpm25, &SDSpm10);
  if (!err) {
    pmMeasurements[iPM][0] = int(calib * 0);
    pmMeasurements[iPM][1] = int(calib * SDSpm25);
    pmMeasurements[iPM][2] = int(calib * SDSpm10);
  } else {
    Serial.println("\nCould not read values from SDS sensor :( ");
  }
#endif
#elif defined DUSTSENSOR_HPMA115S0
  if (hpma115S0.ReadParticleMeasurement(&hpma115S0_pm25, &hpma115S0_pm10)) {
    if (hpma115S0_pm25 == 0 and hpma115S0_pm10 == 0) {
      delay(100);
      hpma115S0.ReadParticleMeasurement(&hpma115S0_pm25, &hpma115S0_pm10);
      pmMeasurements[iPM][0] = int(calib * 0);
      pmMeasurements[iPM][1] = int(calib * hpma115S0_pm25);
      pmMeasurements[iPM][2] = int(calib * hpma115S0_pm10);
    } else {
      pmMeasurements[iPM][0] = int(calib * 0);
      pmMeasurements[iPM][1] = int(calib * hpma115S0_pm25);
      pmMeasurements[iPM][2] = int(calib * hpma115S0_pm10);
    }
  }
#elif defined DUSTSENSOR_SPS30
  read_sps30_data();

  pmMeasurements[iPM][0] = int(calib * SPS30_PM1);
  pmMeasurements[iPM][1] = int(calib * SPS30_PM25);
  pmMeasurements[iPM][2] = int(calib * SPS30_PM10);
  pmMeasurements[iPM][3] = int(calib * SPS30_PM4);
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
  pmMeasurements[iPM][0] = int(calib * data.PM_AE_UG_1_0);
  pmMeasurements[iPM][1] = int(calib * data.PM_AE_UG_2_5);
  pmMeasurements[iPM][2] = int(calib * data.PM_AE_UG_10_0);
#endif

  if (DEBUG) {
    Serial.print("\n\nPM measurement number: ");
    Serial.print(iPM);
    Serial.print("\nValue of PM1: ");
    Serial.print(pmMeasurements[iPM][0]);
    Serial.print("\nValue of PM2.5: ");
    Serial.print(pmMeasurements[iPM][1]);
#ifdef DUSTSENSOR_SPS30
    Serial.print("\nValue of PM4: ");
    Serial.print(pmMeasurements[iPM][3]);
#endif
    Serial.print("\nValue of PM10: ");
    Serial.print(pmMeasurements[iPM][2]);
  }
  if (++iPM == NUMBEROFMEASUREMENTS) {
    averagePM();
    iPM = 0;
  }
}

void takeSleepPMMeasurements() {
  if (DEBUG) {
    Serial.print("\nTurning ON PM sensor...");
  }

#ifdef DUSTSENSOR_PMS5003_7003_BME280_0x76 or DUSTSENSOR_PMS5003_7003_BME280_0x77
  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.wakeUp();
    unsigned long current_2sec_Millis = millis();
    previous_2sec_Millis = millis();
    while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 5) {
      WebServer.handleClient();
      previous_2sec_Millis = millis();
    }
    previous_2sec_Millis = 0;
    pms.requestRead();
  }

  int counterNM1 = 0;
  while (counterNM1 < NUMBEROFMEASUREMENTS) {
    unsigned long current_2sec_Millis = millis();
    if (current_2sec_Millis - previous_2sec_Millis >= TwoSec_interval) {

      if (pms.readUntil(data)) {
        takeNormalnPMMeasurements();
        counterNM1++;
      }

      previous_2sec_Millis = millis();
    }
    WebServer.handleClient();
  }
  if (DEBUG) {
    Serial.print("\nTurning OFF PM sensor...\n");
  }

  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.sleep();
  }
#elif defined DUSTSENSOR_SDS011_21
  if (!strcmp(DUST_MODEL, "SDS011/21")) {
#ifdef ARDUINO_ARCH_ESP8266
    sds.wakeup();
    sds.setQueryReportingMode().toString(); // ensures sensor is in 'query' reporting mode
    sds.setContinuousWorkingPeriod().toString(); // ensures sensor has continuous working period - default but not recommended
#elif defined ARDUINO_ARCH_ESP32

#endif

    unsigned long current_2sec_Millis = millis();
    previous_2sec_Millis = millis();
    while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 10) {
      WebServer.handleClient();
      yield();
      previous_2sec_Millis = millis();
    }
    previous_2sec_Millis = 0;
  }

  int counterNM1 = 0;
  while (counterNM1 < NUMBEROFMEASUREMENTS) {
    unsigned long current_2sec_Millis = millis();
    if (current_2sec_Millis - previous_2sec_Millis >= TwoSec_interval) {
#ifdef ARDUINO_ARCH_ESP8266
      PmResult SDSdata = sds.queryPm();
#elif defined ARDUINO_ARCH_ESP32

#endif
      delay(1000);
      takeNormalnPMMeasurements();
      counterNM1++;
      previous_2sec_Millis = millis();
    }
    WebServer.handleClient();
    yield();
    delay(10);
  }
  if (DEBUG) {
    Serial.print("\nTurning OFF PM sensor...\n");
  }

  if (!strcmp(DUST_MODEL, "SDS011/21")) {
#ifdef ARDUINO_ARCH_ESP8266
    sds.setCustomWorkingPeriod(1);
    WorkingStateResult state = sds.sleep();
#elif defined ARDUINO_ARCH_ESP32

#endif
  }
#elif defined DUSTSENSOR_HPMA115S0
  if (!strcmp(DUST_MODEL, "HPMA115S0")) {
    hpma115S0.Init();
    delay(10);
    hpma115S0.EnableAutoSend();
    delay(10);
    hpma115S0.StartParticleMeasurement();

    unsigned long current_2sec_Millis = millis();
    previous_2sec_Millis = millis();
    while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 8) {
      WebServer.handleClient();
      delay(10);
      yield();
      previous_2sec_Millis = millis();
    }
    previous_2sec_Millis = 0;
  }
  int counterNM1 = 0;
  while (counterNM1 < NUMBEROFMEASUREMENTS) {
    unsigned long current_2sec_Millis = millis();
    if (current_2sec_Millis - previous_2sec_Millis >= TwoSec_interval) {
      if (hpma115S0.ReadParticleMeasurement(&hpma115S0_pm25, &hpma115S0_pm10)) {
        takeNormalnPMMeasurements();
        counterNM1++;
      }
      previous_2sec_Millis = millis();
    }
    WebServer.handleClient();
    yield();
    delay(10);
  }
  if (DEBUG) {
    Serial.print("\nTurning OFF PM sensor...\n");
  }

  if (!strcmp(DUST_MODEL, "HPMA115S0")) {
    hpma115S0.DisableAutoSend();
    delay(10);
    hpma115S0.StopParticleMeasurement();
  }
#elif defined DUSTSENSOR_SPS30
  if (!strcmp(DUST_MODEL, "SPS30")) {

    // WAKE UP SPS30!!

    unsigned long current_2sec_Millis = millis();
    previous_2sec_Millis = millis();
    while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 8) {
      WebServer.handleClient();
      delay(10);
      yield();
      previous_2sec_Millis = millis();
    }
    previous_2sec_Millis = 0;
  }
  int counterNM1 = 0;
  while (counterNM1 < NUMBEROFMEASUREMENTS) {
    unsigned long current_2sec_Millis = millis();
    if (current_2sec_Millis - previous_2sec_Millis >= TwoSec_interval) {

      read_sps30_data();
      takeNormalnPMMeasurements();
      counterNM1++;

      previous_2sec_Millis = millis();
    }
    WebServer.handleClient();
    yield();
    delay(10);
  }
  if (DEBUG) {
    Serial.print("\nTurning OFF PM sensor...\n");
  }

  if (!strcmp(DUST_MODEL, "SPS30")) {
    // GO TO SLEEP SPS30!!
  }
#else // If no dust sensor has been defined - use DUSTSENSOR_PMS5003_7003_BME280_0x76
  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.wakeUp();
    unsigned long current_2sec_Millis = millis();
    previous_2sec_Millis = millis();
    while (previous_2sec_Millis - current_2sec_Millis <= TwoSec_interval * 5) {
      WebServer.handleClient();
      previous_2sec_Millis = millis();
    }
    previous_2sec_Millis = 0;
    pms.requestRead();
  }

  int counterNM1 = 0;
  while (counterNM1 < NUMBEROFMEASUREMENTS) {
    unsigned long current_2sec_Millis = millis();
    if (current_2sec_Millis - previous_2sec_Millis >= TwoSec_interval) {

      if (pms.readUntil(data)) {
        takeNormalnPMMeasurements();
        counterNM1++;
      }

      previous_2sec_Millis = millis();
    }
    WebServer.handleClient();
  }
  if (DEBUG) {
    Serial.print("\nTurning OFF PM sensor...\n");
  }

  if (!strcmp(DUST_MODEL, "PMS7003")) {
    pms.sleep();
  }
#endif
}

void pm_calibration() {
  // Automatic calibration - START
  if (!strcmp(MODEL, "white")) {
    if (!strcmp(THP_MODEL, "BME280")) {
#ifdef ARDUINO_ARCH_ESP8266
      BMESensor.refresh();
      yield();
      if (int(BMESensor.temperature) < 5 or int(BMESensor.humidity) > 60) {
        calib1 = float((200 - (BMESensor.humidity)) / 150);
        calib2 = calib1 / 2;
        calib = calib2;
      } else {
        calib = calib1;
      }
#elif defined ARDUINO_ARCH_ESP32
      if (int(bme.readTemperature()) < 5 or int(bme.readHumidity()) > 60) {
        calib1 = float((200 - (bme.readHumidity())) / 150);
        calib2 = calib1 / 2;
        calib = calib2;
      } else {
        calib = calib1;
      }
#endif
    } else if (!strcmp(THP_MODEL, "HTU21")) {
      if (int(myHTU21D.readTemperature()) < 5 or int(myHTU21D.readCompensatedHumidity()) > 60) {
        calib1 = float((200 - (myHTU21D.readCompensatedHumidity())) / 150);
        calib2 = calib1 / 2;
        calib = calib2;
      } else {
        calib = calib1;
      }
    } else if (!strcmp(THP_MODEL, "DHT22")) {
      if (int(dht.readTemperature()) < 5 or int(dht.readHumidity()) > 60) {
        calib1 = float((200 - (dht.readHumidity())) / 150);
        calib2 = calib1 / 2;
        calib = calib2;
      } else {
        calib = calib1;
      }

    } else if (!strcmp(THP_MODEL, "SHT1x")) {
      if (int(sht1x.readTemperatureC()) < 5 or int(sht1x.readHumidity()) > 60) {
        calib1 = float((200 - (sht1x.readHumidity())) / 150);
        calib2 = calib1 / 2;
        calib = calib2;
      } else {
        calib = calib1;
      }
    }
  }
  // Automatic calibration - END

  if (!strcmp(THP_MODEL, "BME280")) {
    calib = calib1;
  } else if (!strcmp(THP_MODEL, "HTU21")) {
    calib = calib1;
  } else if (!strcmp(THP_MODEL, "DHT22")) {
    calib = calib1;
  } else if (!strcmp(THP_MODEL, "SHT1x")) {
    calib = calib1;
  } else if (!strcmp(THP_MODEL, "BMP280")) {
    calib = calib1;
  }

}

void averagePM() {
  averagePM1 = 0;
  averagePM25 = 0;
  averagePM10 = 0;
#ifdef DUSTSENSOR_SPS30
  averagePM4 = 0;
#endif
  for (int i = 0; i < NUMBEROFMEASUREMENTS; i++) {
    averagePM1 += pmMeasurements[i][0];
    averagePM25 += pmMeasurements[i][1];
    averagePM10  += pmMeasurements[i][2];
#ifdef DUSTSENSOR_SPS30
    averagePM4 += pmMeasurements[i][3];
#endif
  }
  averagePM1 = averagePM1 / NUMBEROFMEASUREMENTS;
  averagePM25 = averagePM25 / NUMBEROFMEASUREMENTS;
  averagePM10 = averagePM10 / NUMBEROFMEASUREMENTS;
#ifdef DUSTSENSOR_SPS30
  averagePM4 = averagePM4 / NUMBEROFMEASUREMENTS;
#endif
  if (DEBUG) {
    Serial.print("\n\nAverage PM1: ");
    Serial.print(averagePM1);
    Serial.print("\nAverage PM2.5: ");
    Serial.print(averagePM25);
#ifdef DUSTSENSOR_SPS30
    Serial.print("\nAverage PM4: ");
    Serial.print(averagePM4);
#endif
    Serial.print("\nAverage PM10: ");
    Serial.print(averagePM10);
  }
}

#ifdef DUSTSENSOR_SPS30
bool read_sps30_data()
{
  static bool header = true;
  uint8_t ret, error_cnt = 0;
  struct sps_values val;

  // loop to get data
  do {

    ret = sps30.GetValues(&val);

    // data might not have been ready
    if (ret == ERR_DATALENGTH) {

      if (error_cnt++ > 3) {
        ErrtoMess("Error during reading values: ", ret);
        return (false);
      }
      delay(1000);
    }

    // if other error
    else if (ret != SPS30_ERR_OK) {
      ErrtoMess("Error during reading values: ", ret);
      return (false);
    }

  } while (ret != SPS30_ERR_OK);

  SPS30_PM1 = val.MassPM1;
  SPS30_PM25 = val.MassPM2;
  SPS30_PM4 = val.MassPM4;
  SPS30_PM10 = val.MassPM10;
}

void GetDeviceInfo()
{
  char buf[32];
  uint8_t ret;
  //try to read serial number
  ret = sps30.GetSerialNumber(buf, 32);
  if (ret == SPS30_ERR_OK) {
    Serial.print(F("Serial number : "));

    if (strlen(buf) > 0)  Serial.println(buf);
    else Serial.println(F("not available"));
  }
  else
    ErrtoMess("could not get serial number", ret);
  // try to get product name
  ret = sps30.GetProductName(buf, 32);
  if (ret == SPS30_ERR_OK)  {
    Serial.print(F("Product name  : "));

    if (strlen(buf) > 0)  Serial.println(buf);
    else Serial.println(F("not available"));
  }
  else
    ErrtoMess("could not get product name.", ret);
  // try to get article code
  ret = sps30.GetArticleCode(buf, 32);
  if (ret == SPS30_ERR_OK)  {
    Serial.print(F("Article code  : "));

    if (strlen(buf) > 0)  Serial.println(buf);
    else Serial.println(F("not available"));
  }
  else
    ErrtoMess("could not get Article code .", ret);
}

void SetAutoClean()
{
  uint32_t interval;
  uint8_t ret;
  // try to get interval
  ret = sps30.GetAutoCleanInt(&interval);
  if (ret == SPS30_ERR_OK) {
    Serial.print(F("Current Auto Clean interval: "));
    Serial.print(interval);
    Serial.println(F(" seconds"));
  }
  else
    ErrtoMess("could not get clean interval.", ret);
  // only if requested
  if (SPS30_AUTOCLEANINTERVAL == -1) {
    Serial.println(F("No Auto Clean interval change requested."));
    return;
  }
  // try to set interval
  interval = SPS30_AUTOCLEANINTERVAL;
  ret = sps30.SetAutoCleanInt(interval);
  if (ret == SPS30_ERR_OK) {
    Serial.print(F("Auto Clean interval now set : "));
    Serial.print(interval);
    Serial.println(F(" seconds"));
  }
  else
    ErrtoMess("could not set clean interval.", ret);
  // try to get interval
  ret = sps30.GetAutoCleanInt(&interval);
  if (ret == SPS30_ERR_OK) {
    Serial.print(F("Current Auto Clean interval: "));
    Serial.print(interval);
    Serial.println(F(" seconds"));
  }
  else
    ErrtoMess("could not get clean interval.", ret);
}

void Errorloop(char *mess, uint8_t r)
{
  if (r) ErrtoMess(mess, r);
  else Serial.println(mess);
  /*
    Serial.println(F("Program on hold"));
    for (;;) delay(100000);
  */
}

void ErrtoMess(char *mess, uint8_t r)
{
  char buf[80];
  Serial.print(mess);
  sps30.GetErrDescription(r, buf, 80);
  Serial.println(buf);
}
#endif
