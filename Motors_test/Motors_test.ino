#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void forward(uint8_t);
void backward(uint8_t);
void Stop(void);
void right(uint8_t);
void left(uint8_t);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Robot is running");
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(200);
  delay(6000);
  backward(200);
  delay(6000);
  Stop();
  delay(3000);
}

void forward(uint8_t vitesse){
  motor1.setSpeed(vitesse);
  motor2.setSpeed(vitesse);
  motor3.setSpeed(vitesse);
  motor4.setSpeed(vitesse);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void backward(uint8_t vitesse){
  motor1.setSpeed(vitesse);
  motor2.setSpeed(vitesse);
  motor3.setSpeed(vitesse);
  motor4.setSpeed(vitesse);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
 
void Stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right(uint8_t vitesse){
  motor1.setSpeed(vitesse);
  motor2.setSpeed(vitesse);
  motor3.setSpeed(vitesse);
  motor4.setSpeed(vitesse);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor1.run(FORWARD);
  motor4.run(FORWARD);
}

void left(uint8_t vitesse){
  motor1.setSpeed(vitesse);
  motor2.setSpeed(vitesse);
  motor3.setSpeed(vitesse);
  motor4.setSpeed(vitesse);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
}
