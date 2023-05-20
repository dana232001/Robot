
#define trigger 9
#define echo 10
#define MAX_DISTANCE 400
#define COLL_DIST 20 // distanta de coliziune la care robot stop si inapoi este de : 20cm

// L298n module 
// 1(+)inainte dreapta = DrFr
// 2(+)inapoi dreapta = DrSp
// 3(+)inainte stanga = StFr
// 4(+)inapoi stanga = StSp

int p3 = 2;
int p4 = 3;
int p2 = 5;
int p1 = 4;
const int buzzer = 11;
const int ledPin = 13;

void setup() {
Serial.begin(9600);
pinMode(p3,OUTPUT);
pinMode(p2,OUTPUT);
pinMode(p4,OUTPUT);
pinMode(p1,OUTPUT);
digitalWrite(p3,LOW);
digitalWrite(p2,LOW);
digitalWrite(p4,LOW);
digitalWrite(p1,LOW);
}

void loop() {
long duration,Dist;
pinMode(trigger, OUTPUT);
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
pinMode(echo, INPUT);
duration = pulseIn(echo, HIGH);
Dist = duration/29/2 ;
Serial.println(Dist);
if (( Dist > 0 ) && ( Dist < COLL_DIST )) 
{ // daca distanta curenta < decit distanta de coliziune
  moveStop();
  tone(buzzer, 600);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  noTone(buzzer);
  digitalWrite(ledPin, LOW);
  Serial.println("backward");
  moveBackward();
  delay(500);
  Serial.println("right");
  turnRight();
  delay(300);
} else {
  Serial.println("forward");
  moveForward();
}
}

void moveStop() {
digitalWrite(p3,LOW);
digitalWrite(p2,LOW);
digitalWrite(p4,LOW);
digitalWrite(p1,LOW);
}

void moveForward() {
digitalWrite(p3,HIGH);
digitalWrite(p2,HIGH);
digitalWrite(p4,LOW);
digitalWrite(p1,LOW);
}

void moveBackward() {
digitalWrite(p3,LOW);
digitalWrite(p2,LOW);
digitalWrite(p4,HIGH);
digitalWrite(p1,HIGH);
}

void turnRight() {
digitalWrite(p3,LOW);
digitalWrite(p2,HIGH);
digitalWrite(p4,HIGH);
digitalWrite(p1,LOW);
}

void turnLeft() {
digitalWrite(p3,HIGH);
digitalWrite(p2,LOW);
digitalWrite(p4,LOW);
digitalWrite(p1,HIGH);
}
