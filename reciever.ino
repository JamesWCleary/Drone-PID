#include <Servo.h>

#define MIN_PULSE_LENGTH 1000
#define MAX_PULSE_LENGTH 2000

Servo motA, motB, motC, motD;
char data;

int pwm;
int roll_pwm;
int throttle = 1000;
int roll;


void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
      
  motA.attach(3, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motB.attach(5, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motC.attach(6, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
  motD.attach(7, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);

}

void loop() {
  roll = pulseIn(9, HIGH);
  throttle = pulseIn(8, HIGH);
  pwm = map(input, 990, 2000, 2000, 990);
  roll_pwm = map(roll, 1000, 2000, 1005, 1990);
  Serial.print(roll);
  Serial.print(" >> ");
  Serial.println(roll_pwm);
  motA.writeMicroseconds(pwm);
  motB.writeMicroseconds(pwm);
  
  
}
