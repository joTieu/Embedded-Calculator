#include <max7219.h>
#include <math.h>

// Variables to declare
const int decNumber = 12;
const int numOfBits = floor(log(decNumber)/log(2)) + 1; // Grab the maximum number of bits required to represent the decimal number
int bitArray[numOfBits];
const int dataPin = A0;
// Read button inputs
const int button = D5;
const int num1 = A7;
// const
const int loadPin = A2;
const int clockPin = 12;

const byte digitSegments[10] = {
  B01111110, // 0
  B00110000, // 1
  B01101101, // 2
  B01111001, // 3
  B00110011,// 4
  B01011011,// 5
  B01011111,// 6
  B01110000,// 7
  B01111111,// 8
  B01111011 // 9
};

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

  pinMode()

  pinMode(clockPin, OUTPUT); // Clock output
  // pinMode(11, INPUT); // Clock check
  digitalWrite(clockPin, LOW); // Initialize clock as LOW at start
  // digitalWrite(latchPin, HIGH); // Enables data to be received
}

void loop() { 
  for (int i = numOfBits - 1; i >= 0; i--) {
    // bitArray[0] will hold the most significant bit (left-most bit) of a binary number, and thus will be first 
    // to output to the LEDs via FIFO queue

    if(decNumber/1000.0 > 0) {
      // Select digit 1 of 4-digit segment display
      multiPin(3, 5, 0); // Output via D3, D4, and D5 to encoder
      digitalWrite(loadPin, 0); // Keep low on load pin
      
      // Print serial bits of 1000s digit to SIPO shift register, then to resistor array
      switch((int)(decNumber/1000)) {
        case 1: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[1]); break;
        case 2: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[2]); break;
        case 3: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[3]); break;
        case 4: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[4]); break;
        case 5: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[5]); break;
        case 6: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[6]); break;
        case 7: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[7]); break;
        case 8: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[8]); break;
        case 9: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[9]); break;
        default: shiftOut(dataPin, clockPin, MSBFIRST, digitSegments[0]);
      }
        // printf("Digit 4 is: %d\n", (int)(decNumber/1000));
    }
    if(decNumber/100 > 0) {
        // printf("Digit 3 is: %d\n", (int)((decNumber % 1000) / 100));
      switch((int)((decNumber % 1000) / 100)) {
        case 1: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[1]); break;
        case 2: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[2]); break;
        case 3: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[3]); break;
        case 4: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[4]); break;
        case 5: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[5]); break;
        case 6: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[6]); break;
        case 7: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[7]); break;
        case 8: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[8]); break;
        case 9: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[9]); break;
        default: shiftOut(dataPin+2, clockPin, MSBFIRST, digitSegments[0]);
      }
    }
    if(floor(decNumber/10) > 0) {
        // printf("Digit 2 is: %d\n", (int)((decNumber % 100)/10));
      switch((int)((decNumber % 100)/10)) {
        case 1: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[1]); break;
        case 2: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[2]); break;
        case 3: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[3]); break;
        case 4: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[4]); break;
        case 5: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[5]); break;
        case 6: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[6]); break;
        case 7: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[7]); break;
        case 8: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[8]); break;
        case 9: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[9]); break;
        default: shiftOut(dataPin+3, clockPin, MSBFIRST, digitSegments[0]);
      }
    }
    if(floor(decNumber/1) > 0) {
        // printf("Digit 1 is: %d\n", (int)((decNumber % 100) % 10));
      switch((int)((decNumber % 100) % 10)) {
        case 1: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[1]); break;
        case 2: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[2]); break;
        case 3: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[3]); break;
        case 4: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[4]); break;
        case 5: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[5]); break;
        case 6: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[6]); break;
        case 7: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[7]); break;
        case 8: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[8]); break;
        case 9: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[9]); break;
        default: shiftOut(dataPin+4, clockPin, MSBFIRST, digitSegments[0]);
      }
    }

    // Writes each binary bit into shift register on falling edge
    // (before loading onto next register) as a serial input. 
    // This is to ensure next register is loaded properly on CLK rising edge rather than pushing next bit on falling edge
    //digitalWrite(latchPin, HIGH);
    //shiftOut(dataPin, clockPin, LSBFIRST, decNumber);
    delay(500);
    // digitalWrite(12, LOW);
    // digitalWrite(A0, bitArray[i]);  // Write bit to serial input when clock = 0
    // delay(1000); // Wait 1s
    // digitalWrite(12, HIGH);
    // delay(1000);
  }
  digitalWrite(loadPin, 1); // Writes to shift register
  delay(500);
  digitalWrite(loadPin, 0); // Stops writing to shift register
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
