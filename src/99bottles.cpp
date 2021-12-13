#include <iostream>
#include "BottleSong/BottleSong.h"

int main ()
{
    std::cout << "Hello World" << std::endl;
    BottleSong newSong;
    std::cout << newSong.verses(99,0);
    return 0;
}