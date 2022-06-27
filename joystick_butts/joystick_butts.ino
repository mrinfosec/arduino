/*
 * Program to drive lights and joystick control for "Wall of Butts" art project
 * 
 * Pseudocode:
 * 
 * Define joystick sampling period and idle advance period
 * define bounding box for js zero
 * 
 * 1.  Loop at joystick sampling rate
 * 2.  If js not out of bounding box, loop
 *   a.  if millis mod rotation period < sampling rate, then advance light
 * 3.  If js is out of bounding box, then:
 *  - read x and y on js
 *  - compute arctan y/x
 *  - take degrees, multiply by 100, divide by 360 to get which light
 *  - update to use that light
 * 4.  If js goes back to zero, unlight light and wait 2 seconds to begin light loop again

  created 2022
  by Dashiell and Gary Baalman
  
*/

// constants won't change. Used here to set a pin number:
// const int ledPin =  LED_BUILTIN;// the number of the LED pin

const int X_pin = A0;  // analog pin connected to X-axis of joystick
const int Y_pin = A1; // analog pin connected to Y-axis of joystick
// const int xZeroMin = -40; // this and next four constants define the "zero" box for the joystick 
// const int xZeroMax = 40;
// const int yZeroMin = -40;
// const int yZeroMax = 40;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
double currentx = 0;  // current x-axis position of joystick - might not work?
double currenty = 0;  // current y-axis position of joystick

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long js_interval = 100;           // interval at which to sample joystick (milliseconds)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= js_interval) {
    // insert per-joystick-sampling-period code here
    previousMillis = currentMillis;
    currentx=(analogRead(X_pin) - 512);
    currenty=(-1 * (analogRead(Y_pin) - 512));
    // TODO with Dash:  add atan2 function to convert from cartesian to polar coordinates
/*    Serial.print("X-axis: ");
    Serial.print(currentx);
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(currenty);
    Serial.print("\n\n");
*/
    
  }
}
