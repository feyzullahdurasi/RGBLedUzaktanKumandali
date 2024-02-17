#include <IRremote.h>

int sensorPin = 2;
int redPin = 5;
int greenPin = 6;
int bluePin =9;

byte red,blue,green;// 0-255 arası deger alacak.

IRrecv sensor(sensorPin);
decode_results deger;

void setup() {
  sensor.enableIRIn();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600); // sensorun calismasi icin gerekli baslangic kodu
}

void loop() {
  if(sensor.decode(&deger))
  {
    Serial.print("Tuş kodu: ");
    Serial.println(deger.value, HEX);
    sensor.resume();
    if(deger.value == 0xFFA25D) // gelen hex decimal kodları yazılacak
      red = red + 32;
    if(deger.value == 0xFFA25D)
      red = red - 32;
    if(deger.value == 0xFFA25D)
      green = green + 32;
    if(deger.value == 0xFFA25D)
      green = green - 32;
    if(deger.value == 0xFFA25D)
      blue = blue + 32;
    if(deger.value == 0xFFA25D)
      blue = blue - 32;
    if(deger.value == 0xFFA25D) // bütün degerleri sıfırlar
      red = 0, blue = 0, green = 0; 
    
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  }
  delay(10);
  //delay(300);
}
