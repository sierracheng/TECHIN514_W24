#include <Arduino.h>
#include <SwitecX25.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// standard X25.168 ranges from 0 to 315 degrees, at 1/3 degree increments
#define STEPS 945
static int nextPos = 0;
bool setFlag = false;

// refreshClk variable to set display refresh rate
int refreshClk = 0;

// There is a active-low button switch connected to the pin D8
#define BUTTON_PIN D8

// There is a potentiometer connected to the pin A9
#define POT_PIN A9

// There is a 128x64 OLED display connected via I2C (SDA, SCL pins)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// For motors connected to D0, D1, D2, D3
SwitecX25 motor1(STEPS, D0, D1, D2, D3);

void setup(void)
{
  // run the motor against the stops
  motor1.zero();
  // start moving towards the center of the range
  motor1.setPosition(STEPS/2);

  // initialize the wire
  Wire.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  // set the text color
  display.setTextColor(WHITE);
  // set the text size
  display.setTextSize(1);
  // set the cursor position
  display.setCursor(0,0);
  // print a message
  display.println("Hello, world!");
  // update the display
  display.display();

  // initialize the serial port
  Serial.begin(9600);
  Serial.print("Enter a step position from 0 through ");
  Serial.print(STEPS-1);
  Serial.println(".");
}

void loop(void)
{
  // the motor only moves when you call update
  motor1.update();


  
  // bool buttonReleased = digitalRead(BUTTON_PIN);
  // Using analog read to simulate the digital (using 1000 as the threshold)
  bool buttonReleased = analogRead(BUTTON_PIN) > 1000;


  // Mapping the potentiometer value to the motor position
  // potentiometer: 1024 to 4095
  // motor position: 0 to 945
  int potValue = analogRead(POT_PIN);
  // only use the top-2 digits
  potValue = potValue / 100;
  // map the potentiometer value to the motor position
  int motorPosition = map(potValue, 10, 40, 0, STEPS-1);

  if (!buttonReleased) {
    nextPos = motorPosition;
  }
  motor1.setPosition(nextPos);

  // refreshing the display every 1000 cycles
  if (refreshClk == 1000) {
    // print the potentiometer analogh read value and the button digital read value to the OLED display
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Pot: ");
    display.println(analogRead(POT_PIN));
    display.print("Button: ");

    if (buttonReleased) {
      display.println("Released");
    } else {
      display.println("Pressed");
    }

    // print the target position and the current position to the display
    display.print("Target: ");
    display.println(motorPosition);
    display.print("Target set: ");
    display.println(motor1.targetStep);
    display.print("Current: ");
    display.println(motor1.currentStep);
    
    display.display();
    refreshClk = 0;
  }
  refreshClk++;

  // if ((motor1.currentStep == motor1.targetStep) && setFlag) {
  //   nextPos = 0;
  //   setFlag = false;
  // }
  
  // if (Serial.available()) {
  //   char c = Serial.read();
  //   if (c==10 || c==13) {
  //     motor1.setPosition(nextPos);
  //     setFlag = true;
  //   } else if (c>='0' && c<='9') {
  //     nextPos = 10*nextPos + (c-'0');
  //   }
  // }
  // Serial.print(nextPos);
  // Serial.print(",");
  // Serial.print(motor1.currentStep);
  // Serial.print(",");
  // Serial.println(motor1.targetStep);
}