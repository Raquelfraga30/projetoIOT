const int trigPin1 = 5;
const int echoPin1 = 4;
const int motorPin1 = 6;

const int trigPin2 = 2;
const int echoPin2 = 3;
const int motorPin2 = 7;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(motorPin1, OUTPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(motorPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  long duration1 = pulseIn(echoPin1, HIGH);
  float distance1 = (duration1 * 0.034) / 2;

  Serial.print("Distancia 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duration2 = pulseIn(echoPin2, HIGH);
  float distance2 = (duration2 * 0.034) / 2;

  Serial.print("Distancia 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Controle do motor 1
  if (distance1 < 10) {
    digitalWrite(motorPin1, HIGH);
  } else {
    digitalWrite(motorPin1, LOW);
  }

  // Controle do motor 2
  if (distance2 < 10) {
    digitalWrite(motorPin2, HIGH);
  } else {
    digitalWrite(motorPin2, LOW);
  }

  delay(100);
}
