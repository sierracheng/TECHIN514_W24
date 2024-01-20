#include <Arduino.h>
#include <SwitecX25.h>

// standard X25.168 ranges from 0 to 315 degrees, at 1/3 degree increments
#define STEPS 945
static int nextPos = 0;
bool setFlag = false;

// For motors connected to D0, D1, D2, D3
SwitecX25 motor1(STEPS, D0, D1, D2, D3);

void setup(void)
{
  // run the motor against the stops
  motor1.zero();
  // start moving towards the center of the range
  motor1.setPosition(STEPS/2);
  
  Serial.begin(9600);
  Serial.print("Enter a step position from 0 through ");
  Serial.print(STEPS-1);
  Serial.println(".");
}

void loop(void)
{
  // the motor only moves when you call update
  motor1.update();

  if ((motor1.currentStep == motor1.targetStep) && setFlag) {
    nextPos = 0;
    setFlag = false;
  }
  
  if (Serial.available()) {
    char c = Serial.read();
    if (c==10 || c==13) {
      motor1.setPosition(nextPos);
      setFlag = true;
    } else if (c>='0' && c<='9') {
      nextPos = 10*nextPos + (c-'0');
    }
  }
  Serial.print(nextPos);
  Serial.print(",");
  Serial.print(motor1.currentStep);
  Serial.print(",");
  Serial.println(motor1.targetStep);
}