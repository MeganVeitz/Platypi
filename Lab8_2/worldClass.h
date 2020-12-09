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

//#ifndef PLATY_PROG_H_INCLUDED
//#define PLATY_PROG_H_INCLUDED
using namespace std;

class World{
   private:
    double Homer = 0.10;
    double Cletus = 0.25;
    int HomerX = 0; //Homers location
    int HomerY = 0;
    int CletusX = 0; //Cletus's location
    int CletusY = 0;
    bool null_platypus = true; //dead platypus holder

    //Display
    void print();

    //Main Functions
    void count_platypuses();

    //Access
    int get_count();
};