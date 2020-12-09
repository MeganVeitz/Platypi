// Section CSC160 - Computer Science I: C++
// File Name:  worldClass.h
// Student: Meg Veitz
// Homework Number: Lab 10
// Description: Mr. Burns is trying to cover up his tracks and needs our help to save his reputation and his  money.
//              To accomplish this goal we will be looking at attributes of the platyuses to determinr if Mr. Burns is
//              breaking any note worth environmental concerns. 
// Last Changed:
#include <iostream>
#include <cctype>
#include <random>
#include <string>
#include <locale>
#include "worldClass.h" 
#include <fstream>
using namespace std;

World::World(){}
//Constructor for array
    const int row = 10;
    const int col = 10;
    int platArray [row][col];

//initialize function
    //Sets all plat to dead, not egg
    
    //takes 1 paremeter that indicates how many plat should be alive
    //For each one that should be alive - randomly pick a dead plat and call the platypus randomize function to make a live plat
    //then make both predators live and place them randomly in the world
//count_platypus funciton

//print funciton
void World::print(){
    //char printChar = " ";

    // Print array as grid
    for (int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            //if statement
            //printChar = " ";
            //if platArray[i][j] != null 
            //printChar = whatToPrint(platArray[i][j]);
            //cout << "|" << printChar << "|";
			cout << "|" << platArray[i][j] << "|";
		}
		cout << '\n';
    }
}

//private WhatToPrint(object or pointer??)
    //if Homer {return H}
    //if Cletus {return C}
    //if male return m
    //if female return f
    //if mutant return *
    //if egg return -
//step function

//simulate function