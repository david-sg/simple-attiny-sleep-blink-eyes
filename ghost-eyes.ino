// ghost eyes v12
// v1 test blinking, no sleeping
// v12 add snore library and test sleep

#include "tinysnore.h" // Include TinySnore Library

// pin 1 is left eye
int left = 1;
//pin 0 is right eye
int right = 0;

int t = 500; //time to stay on on a blink

int light_power = 75; //light intensity for pwm


void setup()
{
  randomSeed(analogRead(2)); // randomize using noise from analog pin 2
  for (int i = 0; i < 5; i++) {
    pinMode(i, OUTPUT);
  }
}

void delay_time () {
  delay(random(3000, 4000));
}

// blink left eye - turn it off and put right on
void left_eye () {
  //left off right on
  digitalWrite(left, LOW);
  analogWrite(right, light_power);
  delay(t);
  //right off left on
  digitalWrite(right, LOW);
  analogWrite(left, light_power);
  delay(t);
  // both on
  analogWrite(left, light_power);
  analogWrite(right, light_power);
}

void right_eye () {
  //right off left on
  digitalWrite(right, LOW);
  analogWrite(left, light_power);
  delay(t);
  //left off right on
  digitalWrite(left, LOW);
  analogWrite(right, light_power);
  delay(t);
  // both on
  analogWrite(left, light_power);
  analogWrite(right, light_power);
}

void blink () {
  //blink once
  //both off
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);

  delay(t);
  //both on
  analogWrite(left, light_power);
  //  digitalWrite(left, HIGH);
  analogWrite(right, light_power);
  //  digitalWrite(right, HIGH);
}

void combo () {
  switch (random(5)) {
    case 0:
      left_eye();
      right_eye();
      break;

    case 1:
      right_eye();
      left_eye();
      break;
    case 2:
      right_eye();
      blink();
      break;
    case 3:
      left_eye();
      blink();
      break;

    case 4:
      blink();
      delay(t);
      blink();
      delay(t);
      blink();
      delay(t);
      blink();
      break;

    default:
      blink();
      delay(t);
      blink();

      break;

  }
}

void loop()
{
  switch (random(3)) {
    case 0:
      left_eye();
      break;

    case 1:
      right_eye();
      break;

    case 2:
      blink();
      break;

    default:
      combo();

  }
  delay(random(3000, 10000));
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
  snore(5000); // Deep sleeps for 5 seconds, (low power) then resumes from here
}
