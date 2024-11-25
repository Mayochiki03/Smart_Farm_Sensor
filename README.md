# ระบบตรวจสอบสภาพแวดล้อมในฟาร์มอัจฉริยะ

โปรเจกต์นี้เป็นระบบตรวจสอบสภาพแวดล้อมในฟาร์มอัจฉริยะที่ใช้เซ็นเซอร์ต่างๆ (DHT22, PMS7003, Rain Sensor) และเชื่อมต่อกับ Blynk เพื่อการตรวจสอบข้อมูลแบบเรียลไทม์ ระบบนี้ถูกสร้างขึ้นโดยใช้ NodeMCU ESP8266 และให้ข้อมูลเกี่ยวกับอุณหภูมิ ความชื้น ความเข้มข้นของอนุภาค (PM) และการตรวจจับฝน

## คุณสมบัติ
- **DHT22 AM2302 Module**: วัดอุณหภูมิและความชื้น
- **Laser Dust Sensor PMS7003 G7**: ตรวจสอบคุณภาพอากาศโดยวัดอนุภาค (PM1.0, PM2.5, PM10)
- **Rain Sensor Module**: ตรวจจับการเกิดฝน
- **การเชื่อมต่อ Blynk**: ส่งข้อมูลแบบเรียลไทม์ไปยังแอป Blynk
- **NodeMCU ESP8266**: เชื่อมต่อกับ Wi-Fi เพื่อนำข้อมูลขึ้น Blynk

## สิ่งที่ต้องใช้
- **ฮาร์ดแวร์**:
  - NodeMCU ESP8266
  - DHT22 AM2302 Module (เซ็นเซอร์วัดอุณหภูมิและความชื้น)
  - Laser Dust Sensor PMS7003 G7 (เซ็นเซอร์ตรวจจับฝุ่นละออง PM)
  - Rain Sensor Module (เซ็นเซอร์วัดปริมาณน้ำฝน)
  - สายจั๊มเปอร์และบอร์ดทดลอง (Breadboard)

- **ซอฟต์แวร์**:
  - Arduino IDE
  - แอป Blynk (ติดตั้งบนสมาร์ทโฟน)
  - ไลบรารี Blynk
  - ไลบรารี DHT sensor
  - ไลบรารี SoftwareSerial

## การตั้งค่า

1. **ติดตั้งไลบรารี**:
   - ใน Arduino IDE ไปที่ **Sketch > Include Library > Manage Libraries**.
   - ติดตั้งไลบรารีดังนี้:
     - `Blynk`
     - `DHT sensor library`
     - `SoftwareSerial`

2. **การตั้งค่า Blynk**:
   - สร้างบัญชี Blynk และตั้งค่าโปรเจกต์ในแอป Blynk.
   - คัดลอก **Authentication Token** จากแอป Blynk.

3. **การเชื่อมต่อฮาร์ดแวร์**:
   - เชื่อมต่อเซ็นเซอร์ DHT22 กับ GPIO2 ของ NodeMCU.
   - เชื่อมต่อเซ็นเซอร์ PMS7003 G7 กับขา RX และ TX ของ NodeMCU (GPIO4 และ GPIO5).
   - เชื่อมต่อเซ็นเซอร์ฝนกับ A0 (ขาอนาล็อก) ของ NodeMCU.

4. **อัปโหลดโค้ด**:
   - เปิด Arduino IDE เลือกบอร์ดและพอร์ตที่ถูกต้องสำหรับ NodeMCU ESP8266.
   - อัปโหลดโค้ดที่ให้มาไปยัง NodeMCU.

5. **การตั้งค่า Blynk**:
   - แทนที่ตัวแปร `auth` ด้วย Authentication Token ของคุณ.
   - ตั้งค่า Virtual Pins (V2, V3, V4, V5, V6) ในแอป Blynk เพื่อแสดงข้อมูล (PM, อุณหภูมิ, ความชื้น ฯลฯ).

## การอธิบายโค้ด

### ไลบรารี
- **ESP8266WiFi.h**: ใช้สำหรับการจัดการการเชื่อมต่อ Wi-Fi.
- **BlynkSimpleEsp8266.h**: การเชื่อมต่อ Blynk กับ ESP8266.
- **SoftwareSerial.h**: ใช้สำหรับการสื่อสารกับเซ็นเซอร์ PMS7003 G7.
- **DHT.h**: ใช้สำหรับการสื่อสารกับเซ็นเซอร์ DHT22.
- **SPI.h**: (ไม่ได้ใช้ในโค้ดนี้ แต่สามารถนำไปใช้ในอนาคตเมื่อเพิ่มเซ็นเซอร์อื่นๆ).

### ฟังก์ชัน
- `setup()`: เริ่มต้นการสื่อสารทางอนุกรม เชื่อมต่อ Wi-Fi เริ่มต้นการทำงาน Blynk และเริ่มต้นเซ็นเซอร์.
- `sendUptime()`: ส่งข้อมูลอุณหภูมิและความชื้นไปยัง Blynk ทุกๆ 20 วินาที.
- `readPMData()`: อ่านข้อมูลจากเซ็นเซอร์ PMS7003 G7 และส่งไปยัง Blynk.

### ตัวแปร
- `pm1`, `pm2_5`, `pm10`: เก็บค่าการวัดอนุภาค.
- `RainsensorValue`: เก็บค่าจากเซ็นเซอร์ฝน.
- `dht`: ตัวแปรที่แทนเซ็นเซอร์ DHT22.
- `mySerial`: ตัวจัดการการสื่อสารกับเซ็นเซอร์ PMS7003 G7.

## วิธีการใช้งาน

1. เมื่อ NodeMCU เชื่อมต่อกับ Wi-Fi ข้อมูลจากเซ็นเซอร์ต่างๆ จะถูกส่งไปยังแอป Blynk.
2. เปิดแอป Blynk และดูข้อมูลอุณหภูมิ ความชื้น PM1.0, PM2.5, PM10 และการตรวจจับฝนได้แบบเรียลไทม์บนสมาร์ทโฟน.
3. คุณสามารถขยายฟังก์ชันของโปรเจกต์นี้ได้โดยการเพิ่มเซ็นเซอร์อื่นๆ หรือเพิ่มฟีเจอร์ใหม่ๆ เช่น การควบคุมการให้น้ำอัตโนมัติ.

## ภาพชิ้นงาน

![ภาพการเชื่อมต่อฮาร์ดแวร์](https://codfzaeaouvwxhozpuhq.supabase.co/storage/v1/object/sign/SmartFarm/IMG_1019.JPEG?token=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1cmwiOiJTbWFydEZhcm0vSU1HXzEwMTkuSlBFRyIsImlhdCI6MTczMjUyMTMyOCwiZXhwIjoxODI3MTI5MzI4fQ.M8H1tUg2E1tWZwgfFwKvd7WpnaHsuMQSA8YyMuHNckY&t=2024-11-25T07%3A55%3A28.583Z)

![ภาพการทำงานของเซ็นเซอร์](https://codfzaeaouvwxhozpuhq.supabase.co/storage/v1/object/sign/SmartFarm/IMG_1002.JPEG?token=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1cmwiOiJTbWFydEZhcm0vSU1HXzEwMDIuSlBFRyIsImlhdCI6MTczMjUyMTMxOSwiZXhwIjoxODI3MTI5MzE5fQ.2PN8nAKRAGPRFuw3TnxAbyOQqTMmmTu2U5JvKJnwHjk&t=2024-11-25T07%3A55%3A19.727Z)

## ไลเซนส์
โปรเจกต์นี้เป็นซอฟต์แวร์โอเพนซอร์สภายใต้ MIT License คุณสามารถแก้ไข แจกจ่าย และใช้โค้ดตามความต้องการของคุณ.
