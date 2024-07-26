/*

*/
#include <math.h>
// Variables to declare
const int decNumber = 18;
const int numOfBits = floor(log(decNumber)/log(2)) + 1; // Grab the maximum number of bits required to represent the decimal number
int bitArray[numOfBits];

void clk() {
  // Read input to D11 (to check if output pin is ON or OFF)
  if(digitalRead(11) == HIGH) {
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
  }
}
// Converts decimal to binary as an array
void decToBinary(int n)
{
    // Put the bits into an array for a given number
    for (int i = numOfBits - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            bitArray[numOfBits - i - 1] = 1;
        else
            bitArray[numOfBits - i - 1] = 0;
    }
}

void multiPin(int start, int end, int output) {
  for (int i = start; i <= end; i++) {
    digitalWrite(i, output);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT); // Serial Data Output
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(12, OUTPUT); // Clock output
  pinMode(11, INPUT); // Clock check
  decToBinary(decNumber);
  digitalWrite(12, LOW); // Initialize clock as LOW at start
}

void loop() { /*
  for (int i = 0; i < sizeof(bitArray)/sizeof(int); i++) {
    // bitArray[0] will hold the most significant bit (left-most bit) of a binary number, and thus will be first 
    // to output to the LEDs via FIFO queue

    // Writes each binary bit into shift register on falling edge
    // (before loading onto next register) as a serial input. 
    // This is to ensure next register is loaded properly on CLK rising edge rather than pushing next bit on falling edge
    if (digitalRead(D11) == LOW) {
      digitalWrite(A0, bitArray[i]);  
    }
    delay(500);
    // Shift the bit with the clock cycle before inserting new bit value
    clk();
  }*/
  for(int j = 0; j < 3; j++){
    for(int k = 0; k < 4; k++) {
      digitalWrite(14 + k, HIGH);
      delay(200);
      digitalWrite(14+k, LOW);
    }
  }
  for(int p = 0; p < 4; p++) {
    multiPin(14,17,1);
    delay(200);
    multiPin(14,17,0);
    delay(200);
  }
}
