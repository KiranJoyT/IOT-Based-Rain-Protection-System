#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Servo.h>
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(D3, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
BlynkTimer timer1;
char auth[] = "anZq33IxSdKaZGTm9VYuwFRgfPqyVaw3"; //Enter the Auth code which was
send by Blink
char ssid[] = "xxxx"; //Enter your WIFI Name
char pass[] = "xxxx"; //Enter your WIFI Password
void weather() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int r = analogRead(A0);
  bool l = digitalRead(D4);
  r = map(r, 0, 1023, 100, 0);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t); //V0 is for Temperature
  Blynk.virtualWrite(V1, h); //V1 is for Humidity
  Blynk.virtualWrite(V2, r); //V2 is for Rainfall
  if (l == 0) {
    WidgetLED led1(V3);
    led1.on();
    lcd.setCursor(9, 1);
    lcd.print("L :");
    lcd.print("High");
    lcd.print(" ");
  } else if (l == 1) {
    WidgetLED led1(V3);
    led1.off();
    lcd.setCursor(9, 1);
    lcd.print("L :");
    lcd.print("Low");
    lcd.print(" ");
  }
    lcd.setCursor(0, 0);
    lcd.print("T :");
    lcd.print(t);
    lcd.setCursor(0, 1);
    lcd.print("H :");
    lcd.print(h);
    lcd.setCursor(9, 0);
    lcd.print("R :");
    lcd.print(r);
    lcd.print(" ");
 }
 int flag=0;
 void notifyRain()
 {
   int isButtonPressed = digitalRead(D7);
   if (isButtonPressed==0 && flag==0) {
      Serial.println("Its Raining");
      Blynk.notify("Its Raining!!!! Turn on the protection");
      flag=1;
   }
   else if (isButtonPressed==1)
   {
     flag=0;
   }
 }
 void setup() {
   Serial.begin(9600); // See the connection status in Serial Monitor
   lcd.init();
   lcd.backlight();
   Blynk.begin(auth, ssid, pass);
   servo.attach(15); // NodeMCU D8 pin
   dht.begin();
   // Setup a function to be called every second
   timer.setInterval(10L, weather);
   pinMode(D7 ,INPUT);
   timer1.setInterval(1000L,notifyRain);
 }
 void loop() {
   Blynk.run(); // Initiates Blynk
   timer.run(); // Initiates SimpleTimer
   timer1.run();
 }
 BLYNK_WRITE(V4)
 {
  servo.write(param.asInt());
 }


