#ifndef HARDWARECOMMUNICATION_H_INCLUDED
#define HARDWARECOMMUNICATION_H_INCLUDED

#include <wiringPi.h>

/**
 * @brief provide communication process with the stabilizer hardware (i.e. an Arduino card)
 *
 */
class HardwareCommunication
{
public:
    /**
     * @brief main constructor
     *
     */
    HardwareCommunication();
    /**
     * @brief main destructor
     *
     */
    ~HardwareCommunication();

    /**
     * @brief send the new value on x axis to the card
     *
     * @param int the new value
     */
    void setXaxis(int);
    /**
     * @brief send the new value on y axis to the card
     *
     * @param int the new value
     */
    void setYaxis(int);
    /**
     * @brief send the new value on z axis to the card
     *
     * @param int the new value
     */
    void setZaxis(int);
};

#endif // HARDWARECOMMUNICATION_H_INCLUDED
