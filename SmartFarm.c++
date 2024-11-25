#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <DHT.h>
#include <SPI.h>

// Software Serial สำหรับสื่อสารกับเซ็นเซอร์ PM
SoftwareSerial mySerial(4, 5); // TX, RX

// ตัวจับเวลา Blynk
BlynkTimer timer;

// ตัวแปรสำหรับเซ็นเซอร์ PM
unsigned int pm1 = 0;
unsigned int pm2_5 = 0;
unsigned int pm10 = 0;

// Blynk Authentication
#define BLYNK_TEMPLATE_ID "TMPLnow79eai"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "_-794na4tSDOIP8Ydo2bjEzyIeR6LiFH"

char auth[] = "_-794na4tSDOIP8Ydo2bjEzyIeR6LiFH";
char ssid[] = "MN";
char pass[] = "12341234";

// เซ็นเซอร์ DHT
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ตัวแปรสำหรับเซ็นเซอร์วัดฝน
int RainsensorValue;

void setup() {
  Serial.begin(115200); // เริ่มต้น Serial Communication
  while (!Serial);

  mySerial.begin(9600); // เริ่มต้น Software Serial
  Blynk.begin(auth, ssid, pass); // เริ่มต้น Blynk
  
  dht.begin(); // เริ่มต้น DHT
  RainsensorValue = analogRead(A0); // อ่านค่าจากเซ็นเซอร์วัดฝน
  
  timer.setInterval(20000L, sendUptime); // ส่งข้อมูลทุก ๆ 20 วินาที
}

void sendUptime() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  Blynk.virtualWrite(V5, t); // ส่งอุณหภูมิ
  Blynk.virtualWrite(V6, h); // ส่งความชื้น
}

void loop() {
  if (Blynk.connected()) {
    Blynk.run(); // รันการทำงาน Blynk
  }
  timer.run(); // รันตัวจับเวลา

  readPMData(); // อ่านข้อมูลเซ็นเซอร์ PM
}

void readPMData() {
  int index = 0;
  char value;
  char previousValue;

  while (mySerial.available()) {
    value = mySerial.read();

    // ตรวจสอบ Header
    if ((index == 0 && value != 0x42) || (index == 1 && value != 0x4D)) {
      Serial.println("Cannot find the data header.");
      break;
    }

    if (index == 4 || index == 6 || index == 8)
    } else if (index == 5) {
      pm1 = 256 * previousValue + value;
      Serial.print("{ ");
      Serial.print("\"pm1\": ");
      Serial.print(pm1);
      Serial.print(" ug/m3");
      Serial.print(" }");
      Blynk.virtualWrite(V3, pm1); // ส่งค่า PM1.0 ไปยัง Blynk
    } else if (index == 7) {
      pm2_5 = 256 * previousValue + value;
      Serial.print("{ ");
      Serial.print("\"pm2_5\": ");
      Serial.print(pm2_5);
      Serial.print(" ug/m3");
      Serial.print(" }");
      Blynk.virtualWrite(V2, pm2_5); // ส่งค่า PM2.5 ไปยัง Blynk
    } else if (index == 9) {
      pm10 = 256 * previousValue + value;
      Serial.print("{ ");
      Serial.print("\"pm10\": ");
      Serial.print(pm10);
      Serial.print(" ug/m3");
      Serial.print(" }");
      Blynk.virtualWrite(V4, pm10); // ส่งค่า PM10 ไปยัง Blynk
    }
    if (index > 15) {
      break;
    }
    index++;
  }

