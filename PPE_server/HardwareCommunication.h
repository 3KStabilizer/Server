#ifndef HARDWARECOMMUNICATION_H_INCLUDED
#define HARDWARECOMMUNICATION_H_INCLUDED

//#include <wiringPi.h>

class HardwareCommunication
{
public:
    HardwareCommunication();
    ~HardwareCommunication();

    void setXaxis(int);
    void setYaxis(int);
    void setZaxis(int);
};

#endif // HARDWARECOMMUNICATION_H_INCLUDED
