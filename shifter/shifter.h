#ifndef SHIFTER_H
#define SHIFTER_H

class Shifter{
    private:
        int load;
        int mr;
        int clk;
        int data;
        int storageClock;
        void parallelLoad(void);
    public:
        void Shifter(int load, int mr, int clk, int data, int storage);
        void start(void);
        void reset(void);
        void storagePulse(void);
};

#endif