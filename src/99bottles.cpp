#include <iostream>
#include "BottleSong/BottleSong.h"

int main ()
{
    //Register classes
    BottleNumberFactory * pFactory = BottleNumberFactory::Instance();
    static bool b0Registered = BottleNumberFactory::Register(0,BottleNumber0::CreateMethod);
    static bool b1Registered = BottleNumberFactory::Register(1,BottleNumber1::CreateMethod);
    static bool b6Registered = BottleNumberFactory::Register(6,BottleNumber6::CreateMethod);
 
    std::cout << "Hello World" << std::endl;
    BottleSong newSong;
    std::cout << newSong.verses(99,0);
    return 0;
}