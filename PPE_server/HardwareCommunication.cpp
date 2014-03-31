#include "HardwareCommunication.h"
#include <iostream>

using namespace std;

HardwareCommunication::HardwareCommunication()
{
    wiringPiSetup();
}
HardwareCommunication::~HardwareCommunication()
{

}

void HardwareCommunication::setXaxis(int val)
{
    //cout<<"set x axis not implemented yet, received : "<<val<<endl;
    int send = 0;//use to write 8 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    it will be send in two times
    data to send are as following :
    - axis to modify!
    0000.0000 0000.0000 0000.0000 1111.0XYZ
    this value represent the data, we set the four first
    MSB to one as the value is never encoded for the value (max value is 90
    the 7th bit will always be 0) X is set to one if movement is to st on X axis
    same for Y and Z
    -value :
    0000.0000 0000.0000 0000.0000 SXXX.XXXX
    S is use for the sign 0: positive 1: negative
    */
    send = 0x000000F4; //4=0100;
    digitalWrite(send);
    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative

}
void HardwareCommunication::setYaxis(int val)
{
    //cout<<"set y axis not implemented yet, received : "<<val<<endl;
        int send = 0;//use to write 8 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    it will be send in two times
    data to send are as following :
    - axis to modify!
    0000.0000 0000.0000 0000.0000 1111.0XYZ
    this value represent the data, we set the four first
    MSB to one as the value is never encoded for the value (max value is 90
    the 7th bit will always be 0) X is set to one if movement is to st on X axis
    same for Y and Z
    -value :
    0000.0000 0000.0000 0000.0000 SXXX.XXXX
    S is use for the sign 0: positive 1: negative
    */
    send = 0x000000F2; //2=0010;
    digitalWrite(send);
    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative

}
void HardwareCommunication::setZaxis(int val)
{
    //cout<<"set z axis not implemented yet, received : "<<val<<endl;
        int send = 0;//use to write 8 bits
    /* as we can only send a byte and we need to send a range of data between -90 and 90
    it will be send in two times
    data to send are as following :
    - axis to modify!
    0000.0000 0000.0000 0000.0000 1111.0XYZ
    this value represent the data, we set the four first
    MSB to one as the value is never encoded for the value (max value is 90
    the 7th bit will always be 0) X is set to one if movement is to st on X axis
    same for Y and Z
    -value :
    0000.0000 0000.0000 0000.0000 SXXX.XXXX
    S is use for the sign 0: positive 1: negative
    */
    send = 0x000000F1; //1=0001;
    digitalWrite(send);
    send = 0;
    send = send|(val>0?val:-val);
    send = send|(val>0?0x00000000:0x00000080);//set the 8th to one if negative

}
