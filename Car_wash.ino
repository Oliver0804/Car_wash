#define BUZZ 9
#define DEVICE_1 10
#define DEVICE_2 11
#define DEVICE_3 12
#define A_MODE_TIME 10000
#define B_MODE_TIME 10000
#define C_MODE_TIME 10000
#define TRIGGER 100
#include <Timer.h>
#include <Event.h>
Timer BUZZ_TIMER;
int BuzzState = 1;
int NowMode = 0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(BUZZ, OUTPUT);
  pinMode(DEVICE_1, OUTPUT);
  pinMode(DEVICE_2, OUTPUT);
  digitalWrite(DEVICE_1, LOW);
  digitalWrite(DEVICE_2, LOW);
  digitalWrite(DEVICE_3, LOW);
  BUZZ_TIMER.every(500, Buzz_run); //1000
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue1 = analogRead(A0);
  delay(10);
  int sensorValue2 = analogRead(A1);
  delay(10);
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);

  if (sensorValue1 > TRIGGER && NowMode == 0) {
    NowMode++;
    tone(BUZZ, 330); delay(500);
    tone(BUZZ, 600); delay(500);
    tone(BUZZ, 330); delay(500);
    tone(BUZZ, 600); delay(500);
    noTone(BUZZ);
    Serial.println("DEVICE_1 ON");
    digitalWrite(DEVICE_1, HIGH);
    delay(A_MODE_TIME);
    Serial.println("DEVICE_1 OFF");
    digitalWrite(DEVICE_1, LOW);
  } else if (sensorValue2 > TRIGGER && NowMode == 1)
  {
    NowMode = 0;
    tone(BUZZ, 330); delay(500);
    tone(BUZZ, 600); delay(500);
    tone(BUZZ, 330); delay(500);
    tone(BUZZ, 600); delay(500);
    noTone(BUZZ);
    Serial.println("DEVICE_2 ON");
    digitalWrite(DEVICE_2, HIGH);
    delay(B_MODE_TIME);
    Serial.println("DEVICE_2 OFF");
    digitalWrite(DEVICE_2, LOW);
    tone(BUZZ, 250); delay(200);
    tone(BUZZ, 300); delay(200);
    tone(BUZZ, 350); delay(200);
    tone(BUZZ, 400); delay(500);
    noTone(BUZZ);
    Serial.println("DEVICE_2 OFF");
    digitalWrite(DEVICE_2, HIGH);
    delay(C_MODE_TIME);
    digitalWrite(DEVICE_2, LOW);
    tone(BUZZ, 700); delay(500);
    noTone(BUZZ);
    tone(BUZZ, 700); delay(500);
    noTone(BUZZ);
  }
  //BUZZ_TIMER.update();
  delay(100);

}
void Buzz_run() {
  if (BuzzState == 1) {
    BuzzState = 2;
    tone(BUZZ, 330);
  } else if (BuzzState == 2) {
    BuzzState = 1;
    tone(BUZZ, 600);
  } else {
    noTone(BUZZ);
  }
}
