#include <max7219.h>
#include <math.h>

// Delcared variables for driver 1
#define DEC_NUMBER 12 // Will be replaced with digitalRead later to receive button inputs for numbers
#define DATA_PIN1 14 // A0
// D10 = clk
// Delcared variables for driver 2
#define DATA_PIN2 15 // A1

// Read button inputs
int button = 5; // Toggle timer switch
int num1 = A7;

// CLK pin reserved to D10
// LOAD/CS pin reserved to D11
// DIN pin reserved to D12
#define loadPin 13
int ctr = 0;
MAX7219 max7219_1 = MAX7219(DATA_PIN1, MAX_CS, MAX_CLK);

void multiPin(int start, int end, int output) {
  for (int i = start; i <= end; i++) {
    digitalWrite(i, output);
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
  digitalWrite(loadPin, HIGH); // Prepare to load data to display drivers
  digitalWrite(A6, LOW);
  digitalWrite(A5, LOW);
}



void loop() { 
  // Read button presses to get input number
  // TODO here


  digitalWrite(loadPin, LOW); // Writes to shift register
  digitalWrite(A6, HIGH);
  max7219_1.DisplayText(digitArray(DEC_NUMBER, ctr), 1); // Displays all digits of input number
  delay(100);
  digitalWrite(loadPin, HIGH); // Stops writing to shift register to latch data to registers
  digitalWrite(A6, LOW);

  //
}
