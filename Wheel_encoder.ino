int encoder_pin = 2;
#define motorForward 3
#define motorBackward 4
unsigned int rotation;
volatile byte pulses;
const int diskPoint  = 20;
#define pi 3.1416
#define diameter 2.3
bool flag = 1;
float distance;
void counter() {
  pulses++;
}
void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(encoder_pin), counter, RISING);
  pulses = 0;
  distance = 0;
}
void loop() {
  while (Serial.available() > 0) {

    int d = Serial.parseInt();


    while (flag == 1) {
      digitalWrite(motorForward, HIGH);
      if (pulses >= 1) {
        pulses = 0;
        detachInterrupt(encoder_pin);
        distance = distance + (pi * 2.3 * .05 );
        if (distance >= 0 && distance < d)
          digitalWrite(motorForward, HIGH);
        attachInterrupt(digitalPinToInterrupt(encoder_pin), counter, RISING);
      }
      else if (distance >= d ) {
        Serial.print(distance);
        detachInterrupt(encoder_pin);
        digitalWrite(motorForward, LOW);
        flag = 0;
        break;
      }
    }
  }
}


