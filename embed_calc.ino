#include <max7219.h>
#include <math.h>
#include <shifter.h>

// Delcared variables for driver 1
#define DEC_NUMBER 12 // Will be replaced with digitalRead later to receive button inputs for numbers
#define DATA_PIN1 14 // A0
// D10 = CLK by default

// Delcared variables for driver 2
#define DATA_PIN2 15 // A1

// Read button inputs
int button = 5; // Input pin for buttons

// MAX7219 Configurations
// CLK pin reserved to D10
// LOAD/CS pin reserved to D11
// DIN pin reserved to D12
#define LOAD_PIN 11 // Pin D11
int ctr = 0;
int rst = 0;
MAX7219 max7219_1(DATA_PIN1, MAX_CS, MAX_CLK);
MAX7219 max7219_res(DATA_PIN2, MAX_CS, MAX_CLK);

int PL = 9, CE = 8, CLK = 7, dataInput = 6, MR = 3;
Shifter shift(PL, MR, CLK, dataInput);

// Writes an output signal to a chain of pins
void multiPin(int start, int end, int output) {
  for (int i = start; i <= end; i++) {
    digitalWrite(i, output);
  }
}

void multiPinMode(int start, int end, int mode) {
  for (int i = start; i <= end; i++) {
    pinMode(i, mode);
  }
}

// Creates a char array of digits from input number
char* digitArray(int number, int ctr) {
  int digit;
  String numToString;
  // Find out the number of digits to allocate array size
  while (number >= 10) {
    digit = number % 10;
    number /= 10;
    ctr++;
  }
  char digits[ctr];
  numToString = String(number);
  numToString.toCharArray(digits, numToString.length());
  return digits;
}

void setup() {
  Serial.begin(9600);
  max7219_1.Begin();
  pinMode(DATA_PIN1, OUTPUT); // Serial Data Output for set of 4 digits
  digitalWrite(LOAD_PIN, HIGH); // Prepare to load data to display drivers

//  Shift Register configurations
  multiPinMode(CLK, PL, 1);
  pinMode(dataInput, INPUT);
  shifter.Begin();
  pinMode(A4, INPUT); // Reset button detection
  shift.start();
}

void loop() { 
  // Read button presses to get input number
  // TODO here: load to 4:1 shift register & shiftIn
  if(digitalRead(A4) == HIGH) {
    shift.reset(); // Clears digit number if reset button is pressed
  }
  // Send button signals in
  byte numberData = shiftIn(dataInput, CLK, LSBFIRST); // CLK signal to SH_CP pin
  shift.storagePulse();

  // Pin D9 = PL, D8 = CE, D7 = CLK, D6 = dataInput


  digitalWrite(LOAD_PIN, LOW); // Disables load signal to send serial data to registers
  max7219_1.DisplayText(digitArray(DEC_NUMBER, ctr), 1); // Displays all digits of input number
  delay(100);
  digitalWrite(LOAD_PIN, HIGH); // Stops writing to shift register to latch data to registers

  //
}
