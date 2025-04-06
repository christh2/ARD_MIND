// Define LED pins
const int red_led = 1;
const int green_led = 2;
const int blue_led = 3;

// Define button pins
const int red_button = 8;
const int green_button = 9;
const int blue_button = 10;

// Array to store LED pins for iteration
const int leds[3] = {1, 2, 3};

// Potentiometer analog input pin
const int potentio = 0;
int tension = 0; // Variable to store analog reading

// Variables to store button states
int red_state;
int green_state;
int blue_state;

void setup() {
  // Initialisation of LED pins as OUTPUT
  pinMode(red_led, OUTPUT); // Defining the pin 1 (red LED ) as an OUTPUT
  pinMode(green_led, OUTPUT); // Defining the pin 2 ( green LED ) as an OUTPUT
  pinMode(blue_led, OUTPUT);  // Defining the pin 3 (blue LED ) as OUTPUT

  // Initialisation of buttons pins as INPUT
  pinMode(red_button, INPUT);   // Defining the pin 8 (red Button ) as an INPUT
  pinMode(green_button, INPUT); // Defining the pin 9 (green Button ) as an INPUT
  pinMode(blue_button, INPUT);  // Defining the pin 10 (red Button ) as an INPUT

  // Turn all LEDs OFF at the beginning
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH); // HIGH = OFF because wired with pull-down logic
  }
}

void loop() {
  // Reseting button states
  red_state = 0;
  green_state = 0;
  blue_state = 0;

  // Reading button states
  red_state = digitalRead(red_button);     // Reading the state of the red button
  green_state = digitalRead(green_button); // Reading the state of the green button
  blue_state = digitalRead(blue_button);   // Reading the state of the blue button

  // Controling Red LED
  if (red_state == 1) {
    digitalWrite(red_led, LOW); // Turn ON red LED if red button pressed
  } else {
    digitalWrite(red_led, HIGH); // Turn OFF red LED when red button is not pressed
  }

  // Special light sequence which will been executing when green button is pressed
  if (green_state == 1) {
    digitalWrite(blue_led, LOW);  // Turn ON blue LED 
    delay(1000);                  // Wait for a second
    digitalWrite(blue_led, HIGH); // Turn OFF blue LED

    digitalWrite(red_led, LOW);   // Turn ON red LED
    delay(1000);                  // Wait for a second
    digitalWrite(red_led, HIGH);  // Turn OFF red LED

    digitalWrite(green_led, LOW); // Turn ON green LED
    delay(1000);                  // Wait for a second
   
    digitalWrite(blue_led, HIGH); // Turn ON blue again
    delay(1000);                  // Wait for a second

    // Turn ON all LEDs
    digitalWrite(green_led, LOW); // Turn ON green LED 
    digitalWrite(red_led, LOW);   // Turn ON red LED
    digitalWrite(blue_led, LOW);  // Turn ON blue LED
    delay(1000);                  // Wait for a second
  } else {
    // Turn OFF all LEDs 
    digitalWrite(red_led, HIGH);  // Turn OFF red LED
    digitalWrite(blue_led, HIGH); // Turn OFF blue LED
    digitalWrite(green_led, HIGH);// Turn OFF green LED
  }

  // Controling Blue LED
  if (blue_state == 1) {
    digitalWrite(blue_led, LOW); // Turn ON blue LED if blue button pressed
  } else {
    digitalWrite(blue_led, HIGH); // Turn OFF blue LED when blue button is not pressed
  }

  // Read potentiometer value
  tension = analogRead(potentio); // Reading the value on the tension on the analog pin A0

  // Call function to adjust LED state based on potentiometer
  teinte(tension);
}

// Function to update LED states based on analog value
void teinte(int value) {
  for (int i = 0; i < 3; i++) {
   if (value >= (i * 10))
   {
  digitalWrite(leds[i], LOW); // Turn ON the LEDs according to the value of the potentiometer 
   } 
   else {
         digitalWrite(leds[i], HIGH);
        }
  }
