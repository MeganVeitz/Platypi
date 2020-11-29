// Section CSC160 - Computer Science I: C++
// File Name:  main.cpp
// Student: Meg Veitz
// Homework Number: Lab 8
// Description: Mr. Burns is trying to cover up his tracks and needs our help to save his reputation and his  money.
//              To accomplish this goal we will be looking at attributes of the platyuses to determinr if Mr. Burns is
//              breaking any note worth environmental concerns. 
// Last Changed: fixed main.

#include <iostream>
#include "Platypus.cpp"
#include "Platypus.h"


int main(int, char**) {
    Platypus plat2 = Platypus('M', .03, 1, "Megatron");

    Platypus plat1 = Platypus();
    plat1.hatch();
    plat1.print();

    plat1.eat();
    plat1.print();

    plat1.age_me();
    plat1.print();

    plat1.fight(plat2);
    plat1.print();
      
   return 0;
}
