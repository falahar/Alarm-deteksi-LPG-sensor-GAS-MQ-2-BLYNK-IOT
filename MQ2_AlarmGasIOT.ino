#define BLYNK_TEMPLATE_ID "TMPLrf0dNhDA"
#define BLYNK_DEVICE_NAME "Alarm Gas LPG"
#define BLYNK_AUTH_TOKEN "vvGPGc_Qpal7ijacEt60kMnPj7rhBVZa"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
#define BLYNK_PRINT Serial    


#define buzzer 4 //D2

char ssid[] = "Redmi 9T"; //Enter WIFI Name
char pass[] = "12345678"; //Enter WIFI Password
 
BlynkTimer timer;
WidgetLED led(V2);
 
int mq2 = A0;
int data = 0; 

void setup() 
{
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run();
  Blynk.run();
}
 
void getSendData()
{
  data = analogRead(mq2); 
  Blynk.virtualWrite(V6, data); 
  Serial.print("Analog Sensor:");
  Serial.print(data);
  Serial.print("\t");
  if (data >750 )// sesuaikan kondisi batas terdeteksi Gas(750 sd 800)
  {
    Serial.println("Gas Bocor!");
    tone(buzzer, 1000, 200);
    led.on();
  }
  else
  {
    Serial.println("AMAN");
    noTone(buzzer);
    led.off();
  }
 
}
