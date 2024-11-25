# ซอฟเเวร์ระบบสมาร์ทฟาร์ม NodeMCU ESP8266
		เป็นซอฟแวร์ภาษาC++ ที่พัฒนาบน Arduino UNO โดยจะมีการรับค่าเซนเซอร์ต่างเข้าไปยังบอร์ด 
	NodeMCU ESP8266 เพื่อนำค่าที่ได้มาขึ้นไปยังเซิฟเวอร์ของ Blynk เพื่อใช้ในการติดตามสมาร์ทฟาร์ม
## อุปกรณ์
 - NodeMCU ESP8266 (บอร์ดไมโคร คอนโทรเลอร์)
 - DHT22 AM2302 Module (โมดูลเซนเซอร์วัดอุณหภูมิ&ความชื้น)
 - Rain Sensor Module (โมดูลเซนเซอร์วัดปริมาณน้ำฝน)
 - Laser Dust Sensor PMS7003 G7 (เซ็นเซอร์ตรวจจับฝุ่นละออง วัดคุณภาพอากาศ PM)
## ไลบรารี
### NodeMCU ESP8266
 - #include <ESP8266WiFi.h>  // สำหรับการเชื่อมต่อ Wi-Fi
### Blynk
 - #include <BlynkSimpleEsp8266.h> // สำหรับการเชื่อมต่อ Blynk กับ NodeMCU
### DHT22 AM2302 (Temperature & Humidity Sensor)
 - #include <DHT.h>  // สำหรับการใช้งานเซ็นเซอร์ DHT
### Laser Dust Sensor PMS7003 G7
 - #include <SoftwareSerial.h>  // สำหรับการใช้งาน PMS7003 ผ่าน Software Serial
## พัฒนาต่อ	
	ชิ้นงานชิ้นนั้นได้ทำการพัฒนาต่อมาจากตัวชิ้นงาน Smart Farm ดังเดิมที่กระผมได้พัฒนาไว้ใน
	สมัยมัธยมปลายชิ้นนี้จะเป็นตัวที่มีการควบคุมเซนเซอร์
	หลากหลายเหมาะกับพืชที่ต้องการควบคุมในหลายๆอย่าง เเละโมเดลที่ออกเเบบมา
	เพื่อให้สามารถเคลื่นที่ได้ง่ายดาย
### ชิ้นงานก่อนพัฒนา
 เมื่อปี 2021 ได้จัดทำศูนย์การเรียนรู้ [Woranari Solar x Smart Farm](https://solarsmartfarm.wordpress.com/) เพื่อเป็นการเรียนรู้และใช้ในการประกวด 

## ภาพชิ้นงานปัจจุบัน
![คำอธิบายภาพ 1](https://codfzaeaouvwxhozpuhq.supabase.co/storage/v1/object/sign/SmartFarm/IMG_1019.JPEG?token=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1cmwiOiJTbWFydEZhcm0vSU1HXzEwMTkuSlBFRyIsImlhdCI6MTczMjUyMTMyOCwiZXhwIjoxODI3MTI5MzI4fQ.M8H1tUg2E1tWZwgfFwKvd7WpnaHsuMQSA8YyMuHNckY&t=2024-11-25T07%3A55%3A28.583Z)
![คำอธิบายภาพ 1](https://codfzaeaouvwxhozpuhq.supabase.co/storage/v1/object/sign/SmartFarm/IMG_1002.JPEG?token=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1cmwiOiJTbWFydEZhcm0vSU1HXzEwMDIuSlBFRyIsImlhdCI6MTczMjUyMTMxOSwiZXhwIjoxODI3MTI5MzE5fQ.2PN8nAKRAGPRFuw3TnxAbyOQqTMmmTu2U5JvKJnwHjk&t=2024-11-25T07%3A55%3A19.727Z)


