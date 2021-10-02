#define trig A3
#define echo A4

uint32_t duration = 0;
float distance = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Robot is running");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trig, LOW);
  
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin condition
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2.0; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: "); // in centimeters
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
