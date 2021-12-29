#include <iostream>
#include "BottleSong/Song.h"
#include "BottleSong/BottleNumberFactory.h"
#include "BottleSong/BottleNumber.h"
#include "BottleSong/BottleNumber0.h"
#include "BottleSong/BottleNumber1.h"
#include "BottleSong/BottleNumber6.h"
#include "BottleSong/BeerBottleVerse.h"

int main ()
{
    //Register classes
    BottleNumberFactory * pFactory = BottleNumberFactory::Instance();
    static bool b0Registered = BottleNumberFactory::Register(0,BottleNumber0::CreateMethod);
    static bool b1Registered = BottleNumberFactory::Register(1,BottleNumber1::CreateMethod);
    static bool b6Registered = BottleNumberFactory::Register(6,BottleNumber6::CreateMethod);
 
    std::cout << "Hello World" << std::endl;
    BeerBottleVerse BeerVerse;
    Song newSong = Song(std::make_shared<BeerBottleVerse>(BeerVerse));
    std::cout << newSong.verses(99,0);
    return 0;
}