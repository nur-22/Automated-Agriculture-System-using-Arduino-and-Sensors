#define trig 2
#define echo 4
#define led 8

//Servo
#include <Servo.h>

Servo gate;


void setup() {
  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led,OUTPUT);
  
  gate.attach(9);
  

}

void loop() {

//ultra sonic sensor

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t =pulseIn(echo,HIGH);

  long cm = t /4 / 2;

  Serial.print(cm);
  Serial.println("cm");

//led
  if (cm <=19){
    digitalWrite(led, HIGH);
   
  }
  else{
    digitalWrite(led,LOW);
  }

 //Gate

  gate.write(170);

  if (cm<= 19){

    for( int j=170;j>=90;j--){
      gate.write(j);
      delay(50); //gate speed//90 degree
    }

    delay(5000); //gate opening delay time 
    
    for( int i=90;i<=170;i++){
    gate.write(i);
    delay(50);
  }
   
  }
  else{
    gate.write(170);
  }

}
