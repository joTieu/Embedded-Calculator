/*

*/
#include <math.h>
// Variables to declare
const int decNumber = 12;
const int numOfBits = floor(log(decNumber)/log(2)) + 1; // Grab the maximum number of bits required to represent the decimal number
int bitArray[numOfBits];
int dataPin = A0;
int latchPin = A1;
int clockPin = D12;

int digitSegments[10] = {
  b1111110, // 0
  b0110000, // 1
  b1101101, // 2
  b1111001, // 3
  b0110011,// 4
  b1011011,// 5
  b1011111,// 6
  b1110000,// 7
  b1111111,// 8
  b1111011 // 9
};

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
  pinMode(dataPin, OUTPUT); // Serial Data Output
  pinMode(latchPin, OUTPUT); // Latch pin for shift register
  // pinMode(A2, OUTPUT);
  // pinMode(A3, OUTPUT);

  pinMode(clockPin, OUTPUT); // Clock output
  // pinMode(11, INPUT); // Clock check
  digitalWrite(clockPin, LOW); // Initialize clock as LOW at start
  digitalWrite(latchPin, HIGH); // Enables data to be received
  decToBinary(decNumber);
}

void loop() { 
  for (int i = numOfBits - 1; i >= 0; i--) {
    // bitArray[0] will hold the most significant bit (left-most bit) of a binary number, and thus will be first 
    // to output to the LEDs via FIFO queue

    // Writes each binary bit into shift register on falling edge
    // (before loading onto next register) as a serial input. 
    // This is to ensure next register is loaded properly on CLK rising edge rather than pushing next bit on falling edge
    digitalWrite(latchPin, HIGH);
    shiftOut(dataPin, clockPin, LSBFIRST, decNumber);
    digitalWrite(latchPin, LOW);
    delay(2000);
    // digitalWrite(12, LOW);
    // digitalWrite(A0, bitArray[i]);  // Write bit to serial input when clock = 0
    // delay(1000); // Wait 1s
    // digitalWrite(12, HIGH);
    // delay(1000);
  }
  digitalWrite(latchPin, LOW);
  // for(int j = 0; j < 3; j++){
  //   for(int k = 0; k < 4; k++) {
  //     digitalWrite(14 + k, HIGH);
  //     delay(200);
  //     digitalWrite(14+k, LOW);
  //   }
  // }
  // for(int p = 0; p < 4; p++) {
  //   multiPin(14,17,1);
  //   delay(200);
  //   multiPin(14,17,0);
  //   delay(200);
  // }
}
