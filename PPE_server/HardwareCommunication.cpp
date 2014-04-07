#include "HardwareCommunication.h"
#include <iostream>

using namespace std;

HardwareCommunication::HardwareCommunication()
{
    //wiringPiSetup();
}
HardwareCommunication::~HardwareCommunication()
{

}

void HardwareCommunication::setXaxis(int val)
{
    //cout<<"set x axis not implemented yet, received : "<<val<<endl;
    int send = 0;//use to write 10 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    we can write 10 bits data (from 0 to 1023)
    data to send are as following :
    To encode 90 value we need 7 bits (2⁷ = 128)
    +1 bit for the sign
    + 3 value for each axis 2 bits (2² = 4)
    AA SXXX XXXX
    X bits are used to encode the value
    S to encode the sign
    and A to encode the axis
    */

    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative
    send = send|(val>0?0x00000000:0x00000100);//set 9th bit to 1 for x axis
    analogWrite(0,send);
}
void HardwareCommunication::setYaxis(int val)
{
//cout<<"set x axis not implemented yet, received : "<<val<<endl;
    int send = 0;//use to write 10 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    we can write 10 bits data (from 0 to 1023)
    data to send are as following :
    To encode 90 value we need 7 bits (2⁷ = 128)
    +1 bit for the sign
    + 3 value for each axis 2 bits (2² = 4)
    AA SXXX XXXX
    X bits are used to encode the value
    S to encode the sign
    and A to encode the axis
    */

    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative
    send = send|(val>0?0x00000000:0x00000200);//set 10th bit to 1 for y axis
    analogWrite(0,send);
}
void HardwareCommunication::setZaxis(int val)
{
//cout<<"set x axis not implemented yet, received : "<<val<<endl;
    int send = 0;//use to write 10 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    we can write 10 bits data (from 0 to 1023)
    data to send are as following :
    To encode 90 value we need 7 bits (2⁷ = 128)
    +1 bit for the sign
    + 3 value for each axis 2 bits (2² = 4)
    AA SXXX XXXX
    X bits are used to encode the value
    S to encode the sign
    and A to encode the axis
    */

    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative
    send = send|(val>0?0x00000000:0x00000300);//set 9th bit to 1 and 10th bit for z axis
    analogWrite(0,send);
}
