#include "shifter.h"

// Initialize pin settings upon object creation
void Shifter::Shifter(int load, int mr, int clk, int data, int storage): load(load), mr(mr), clk(clk), data(data), storageClock(storage) { 
    pinMode(load, OUTPUT);      // Parallel Load (__PL__)
    pinMode(mr, OUTPUT);        // Master Reset (__MR__)
    pinMode(clk, OUTPUT);       // Shift Clock (SH_CP)
    pinMode(data, INPUT);       // Serial Data Output (Q7)
    pinMode(storage, OUTPUT);   // Latch Clock/Storage Clock (ST_CP)
}

// Clears shift registers before starting to use & initializes appropriate starting values for ST_CP, __PL__, and SH_CP
void Shifter::start(void) {
    digitalWrite(load, 1);
    digitalWrite(clk, 0);
    digitalWrite(storage, 0);
    reset();
}
// Puts __MR__ low to clear all data in shift registers
void Shifter::reset(void) {
    digitalWrite(load, 1);
    digitalWrite(mr, 0);
    delayMicroseconds(5);
    digitalWrite(load, 0);
    digitalWrite(mr, 1);
}
// Outputs a rising pulse for ST_CP to let data into input flip-flops. Parallel data must be sent prior to calling this
void Shifter::storagePulse(void) { // Storage Clock
    digitalWrite(storage, 1);
    delayMicroseconds(5);
    digitalWrite(storage, 0);
}
// Sets __PL__ to low to move input data (D0 - D7) into shift registers
void Shifter::parallelLoad(void) {
    delayMicroseconds(5);
    digitalWrite(load, 0);
    delayMicroseconds(5);
    digitalWrite(load, 1);
}
// // Loads data from input flip-flops to shift registers
// void Shifter::loadShiftRegister(void) {
//     parallelLoad();
//     digitalWrite(mr, 1);
// }