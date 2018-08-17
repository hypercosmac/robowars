int fl = 12;
int fr = 11;
int bl = 6;
int br = 9;
int flr = 8;
int frr = 7;
int blr = 5;
int brr = 10;
int a = 0;

#include <IRremote.h>

const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(fl,OUTPUT);
  pinMode(fr,OUTPUT);
  pinMode(bl,OUTPUT);
  pinMode(br,OUTPUT);
  pinMode(flr,OUTPUT);
  pinMode(frr,OUTPUT);
  pinMode(blr,OUTPUT);
  pinMode(brr,OUTPUT);
  
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  pinMode(14,OUTPUT);
  digitalWrite(14,LOW);
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    a = Serial.read();
    a = a-48;
    Serial.println(a);
  }
  if (irrecv.decode(&results)){
    /*if (results.value == 0XFFFFFFFF){
        results.value = key_value;
    }*/
    switch(results.value){
        case 0xFF629D:
        Serial.println("Front");
        front();
        break;
        case 0xFFC23D:
        Serial.println("Right");
        right();
        break;
        case 0xFFA857:
        Serial.println("Back");
        back();
        break;
        case 0xFF22DD:
        Serial.println("Left");
        left();
        break;
        case 0xFF02FD:
        Serial.println("Spin");
        spin();
        break ;  
        case 0xFF42BD:
        Serial.println("*");
        break ;               
        case 0xFF52AD:
        Serial.println("#");
        break ;  
        case 0xFF4AB5:
        Serial.println("Stop");
        off();
        break ;
        case 0xFF6897:
        Serial.println("1");
        front();
        break ;
        case 0xFF9867:
        Serial.println("2");
        break ;
        case 0xFFB04F:
        Serial.println("3");
        break ;
        case 0xFF30CF:
        Serial.println("4");
        break ;
        case 0xFF18E7:
        Serial.println("5");
        break ;
        case 0xFF7A85:
        Serial.println("6");
        break ;
        case 0xFF10EF:
        Serial.println("7");
        break ;
        case 0xFF38C7:
        Serial.println("8");
        break ;
        case 0xFF5AA5:
        Serial.println("9");
        break ;      
      }
    irrecv.resume();
  }
  
 if (a == 1){
    front();
  }
  else if (a==0){
    off();
  }
  else if (a==2){
    back();
  }
  else if (a==3){
    right();
  }
  else if (a==4){
    left();
  }
  else if (a==5){
    spin();
  }
}
void off(){
  digitalWrite(fl,LOW);
  digitalWrite(fr,LOW);
  digitalWrite(bl,LOW);
  digitalWrite(br,LOW);
  digitalWrite(flr,LOW);
  digitalWrite(frr,LOW);
  digitalWrite(blr,LOW);
  digitalWrite(brr,LOW);
}
void front(){
  digitalWrite(flr,LOW);
  digitalWrite(frr,LOW);
  digitalWrite(blr,LOW);
  digitalWrite(brr,LOW);
  digitalWrite(fl,HIGH);
  digitalWrite(fr,HIGH);
  digitalWrite(bl,HIGH);
  digitalWrite(br,HIGH);
}
void back(){
  digitalWrite(fl,LOW);
  digitalWrite(fr,LOW);
  digitalWrite(bl,LOW);
  digitalWrite(br,LOW);
  digitalWrite(flr,HIGH);
  digitalWrite(frr,HIGH);
  digitalWrite(blr,HIGH);
  digitalWrite(brr,HIGH);
}
void left(){
  digitalWrite(flr,LOW);
  digitalWrite(frr,LOW);
  digitalWrite(blr,LOW);
  digitalWrite(brr,LOW);
  digitalWrite(fl,LOW);
  digitalWrite(fr,HIGH);
  digitalWrite(bl,LOW);
  digitalWrite(br,HIGH);
}
void right(){
  digitalWrite(flr,LOW);
  digitalWrite(frr,LOW);
  digitalWrite(blr,LOW);
  digitalWrite(brr,LOW);
  digitalWrite(fl,HIGH);
  digitalWrite(fr,LOW);
  digitalWrite(bl,HIGH);
  digitalWrite(br,LOW);
}
void spin(){
  digitalWrite(flr,LOW);
  digitalWrite(frr,HIGH);
  digitalWrite(blr,LOW);
  digitalWrite(brr,HIGH);
  digitalWrite(fl,HIGH);
  digitalWrite(fr,LOW);
  digitalWrite(bl,HIGH);
  digitalWrite(br,LOW);
}

