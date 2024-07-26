/*

*/
#include <math.h>
// Variables to declare
int decNumber = 18;
int numOfBits = floor(log2(decNumber)) + 1; // Grab the maximum number of bits required to represent the decimal number
int bitArray[numOfBits];

void clk() {
  // Read input to D11 (to check if output pin is ON or OFF)
  if(digitalRead(D11) == HIGH) {
    digitalWrite(D12, LOW);
  } else {
    digitalWrite(D12, HIGH);
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

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT); // Serial Data Output
  pinMode(D12, OUTPUT); // Clock output
  pinMode(D11, INPUT); // Clock check
  decToBinary(decNumber);
  digitalWrite(D12, LOW); // Initialize clock as LOW at start
}

void loop() {
  for (int i = 0; i < sizeof(bitArray)/sizeof(bitArray[0]); i++) {
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
  }
}
