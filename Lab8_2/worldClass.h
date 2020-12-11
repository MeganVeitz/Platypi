// Section CSC160 - Computer Science I: C++
// File Name:  worldClass.h
// Student: Meg Veitz
// Homework Number: Lab 10
// Description: Mr. Burns is trying to cover up his tracks and needs our help to save his reputation and his  money.
//              To accomplish this goal we will be looking at attributes of the platyuses to determinr if Mr. Burns is
//              breaking any note worth environmental concerns. 
// Last Changed:

#include <iostream>
#include <cstring>
#include "Platypus.h"
#include "Predator.h"

#ifndef WORLD
#define WORLD
using namespace std;

class World{
    private:
        int HomerEffency = 10;
        Predator homer = Predator("homer", HomerEffency);
        int CletusEffency = 25;
        Predator cletus = Predator("cletus", HomerEffency);
        static const int row = 10;
        static const int col = 10;
        Platypus platArray [row][col];

        Platypus null_platypus = Platypus(); //dead platypus holder
    public:
        World();
        //Display
        void printWorld();

        //Main Functions
        void count_platypuses();
        void initialize(int);

        //Access
        int get_count();
};

#endif