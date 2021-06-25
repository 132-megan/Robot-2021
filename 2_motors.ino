
#include <Servo.h>

Servo myservo1;
Servo myservo2;


// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

int distanceThreshold = 0;
int cm = 0;
int inches = 0;

int IRSensor = 6;
int IRSensor2 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup() {
  
  myservo1.attach(1);
  myservo2.attach(2);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (IRSensor2, INPUT);


//  Serial.begin(9600);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  myservo1.write(85);
  myservo2.write(180);
  delay(3000);
  myservo1.write(180);
  myservo2.write(73);
 
}

void loop() {
delay(5000);
void FORWARD (){
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    // Turn on motor A & B
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);   
}

void BACKWARDS (){
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    // Turn on motor A & B
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);   
}

void ROTATELEFT (){
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);     
}

void ROTATERIGHT (){
    // Set motors to maximum speed
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);  
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

cm = 0.01723 * readUltrasonicDistance(13, 12);
cm = 0.01723 * readUltrasonicDistance(11, 10);


// convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");

int statusSensor = digitalRead (IRSensor);


while (cm > distanceThreshold && cm < distanceThreshold + 30){
  FOREWARD(100)
}


//for(){
//  if (cm > distanceThreshold && cm < distanceThreshold + 45) {
//    serial.println("greater than 0")
//    analogWrite(enA, 255);
//    analogWrite(enB, 255);
//    // Turn on motor A & B
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//    delay(1000);
//  }
//
//  if (cm > distanceThreshold && cm < distanceThreshold + 15) {
//    Serial.println("greater than 0");
//    myservo1.write(132.5);
//    myservo2.write(126.5);
//    delay(2000);
//    myservo1.write(180);
//    myservo2.write(73);
//    delay(2000);
//  }
//}

if (statusSensor == 1){
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      // Turn on motor A & B
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(1000);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(1000);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(1000);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}

if (cm > distanceThreshold && cm < distanceThreshold + 20) {
  Serial.println("greater than 0");
  myservo1.write(132.5);
  myservo2.write(126.5);
  delay(2000);
  myservo1.write(180);
  myservo2.write(73);
  delay(2000);
}



}
