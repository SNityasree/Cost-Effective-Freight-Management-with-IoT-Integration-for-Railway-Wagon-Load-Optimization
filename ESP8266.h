#define BLYNK TEMPLATE ID "TMPL3NBtMzbtv"
#define BLYNK_TEMPLATE_NAME "loading"
#define BLYNK AUTH_TOKEN "UXP9KirvleVrlWdPj7J9z1yZMNrRD2Jr"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
LiquidCrystal_I2C led(0x27,16,2);
#include "HX711.h"
#define buz 19
const int trigPin = D5;
const int echoPin = D8;
#define ml DO
#define m2 D3
// defines variables
long duration:
int distance;
const int LOADCELL_DOUT_PIN = D6;
const int LOADCELL SCK_PIN = D7;
float weight;
HX711 scale;
char auth[] = "uXP9KirvleVrIWdPj7J9z1yZMNrRD2Jr";
char ssid[]= "Iot2023";
char pass[] = "testing2023";
//Blynk.sync Virtual(V3);
//Blynk.syne Virtual(V4);
int forward=0;
int Stop=0;
BLYNK WRITE (V3)
{
forward-param.asInt();
Serial.print(forward):
}
BLYNK WRITE (V4)
{
  Stop=param.asInt();

Serial.print(Stop);
}
void setup() {

Serial.begin(57600);

lcd.begin():// initialize the led
// Print a message to the LCD,
lcd.backlight();
lcd.setCursor(0,0);
led.print("IOT WEIGHING SCALE");
Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Blynk.begin(auth, ssid, pass);
pinMode(mI,OUTPUT);
pinMode(m2,OUTPUT);
digitalWrite(m1,0);
digitalWrite(m2,0);
scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
scale.set scale(-550.275); // 556.325 this value is obtained by calibrating the scale with known weights as in previous step
scale.tare(); // reset the scale to 0
}
//DIY_CHEAP_PERFECT
void loop() (
Serial.print("Weight: ");
Serial.println(scale.get_units(10), 1);
weight (scale.get_units(10));
Blynk, virtualWrite(V0,weight);
if (forward==1)
{
Forward();
}
else
if (Stop==1)
{
Stop1();
}
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds.
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
// Reads the echoPin, returns the sound wave travel time in microseconds
digitalWrite(trigPin, LOW);
duration= pulseIn(echoPin, HIGH);
//Calculating the distance
distance = duration * 0.034/2:
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Blynk.virtualWrite(V2,distance);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Weight: ");
lcd.print(scale.get_units(10), 1);
scale.power_down();
// put the ADC in sleep mode
delay(1000);
scale.power_up();
if(weight<20 && weight>1)
lcd.setCursor(0,0);
lcd.print(" under loading");
int x = 40-weight:
lcd.setCursor(0,1);
lcd.print("add:");
lcd.print(x);
Blynk.virtualWrite(V1," under weight");
}
if(weight>35 && weight<40)
{

lcd.setCursor(0,1);
lcd.print("STANDARD WEIGHT");
Blynk. virtualWrite(V1."STANDARD WEIGHT");
delay(1000);
}
if(weight>41)
lcd.setCursor(0,0);
lcd.print(" over weight");
digitalWrite(buz, 1);
Blynk.virtualWrite(V1," over weight");
int x=weight-40;
lcd.setCursor(0,1);
lcd.print("remove:");
lcd.print(x);
delay(1000);
digitalWrite(buz,0);
}
if(weight<1)
{
Blynk.virtualWrite(V1," normal ");
  }
Blynk.run();
}
void Forward()
{
digitalWrite(m1,1);
digitalWrite(m2,0);
}
void Stop1() 
{
digitalWrite(m1,0);
digitalWrite(m2.0);
}
