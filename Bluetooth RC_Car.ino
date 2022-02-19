#include <SoftwareSerial.h>

SoftwareSerial bt_contact(12,8); //RX,TX pinleri olarak ayarladık

const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
const int e5 = 9;
const int e6 = 10;

const int bz = 11;



void setup() {

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(e5,OUTPUT);
pinMode(e6,OUTPUT);
pinMode(bz,OUTPUT);

Serial.begin(9600);
bt_contact.begin(9600);

}

void loop() {




if (bt_contact.available()) {

  char  data = bt_contact.read();
  Serial.println(data);

  if (data == 'S') // Duruyor , Stop
  {
     delay(500);
     analogWrite(e5,0);
     analogWrite(e6,0);
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
     digitalWrite(in3,LOW);
     digitalWrite(in4,LOW);
   }
    

  else if (data == 'F') // İleri , forward
  {
     delay(200);
     analogWrite(e5,255);
     analogWrite(e6,255);
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);  
  }

  else if (data == 'B')  // Geri , Back
  {
     delay(200);
     analogWrite(e5,155);
     analogWrite(e6,155);
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);  
  }

  else if (data == 'R') // Sağ , Right
  {
     delay(200);
     analogWrite(e5,50);
     analogWrite(e6,100);
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);  
  }

  else if (data == 'L')  // Sol , Left
  {
     delay(200);
     analogWrite(e5,100);
     analogWrite(e6,50);
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW); 
     
  }

  else if (data == 'V') // Korna , Horn
    {
      delay(100);
      digitalWrite(bz,HIGH);
      delay(500);
      digitalWrite(bz,LOW);
    }

  else 
  {
    delay(500);
    analogWrite(e5,0);
    analogWrite(e6,0);
  }


 }

}
