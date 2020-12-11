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

World::World() {
    initialize(25);
}
//initialize function
void World::initialize(int numPlat = 25){
      //Sets all plat to dead, not egg
    //Constructor for array
    for (int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            platArray[i][j] = World::null_platypus;
        }
    } 
    //takes 1 paremeter that indicates how many plat should be alive
    //For each one that should be alive - randomly pick a dead plat and call the platypus randomize function to make a live plat
    //then make both predators live and place them randomly in the world
    int sentinel = 0;
    while(sentinel < numPlat){
        int randomRow = (rand()%10);
        int randomCol = (rand()%10);
        // Make sure there is nothing else living in this spot
        if (platArray[randomRow][randomCol].get_alive() != 1){
            platArray[randomRow][randomCol].hatch();
            cout << "Making a platypus "<< platArray[randomRow][randomCol].get_nameString() << endl;
            sentinel ++;
        }
    }
    //homer = Predator("homer", HomerEffency);
    cout << "Homer's name "<<homer.get_nameString() << endl;
    //cletus = Predator("cletus", HomerEffency);
    while(true){
        int randomRow = (rand()%10);
        int randomCol = (rand()%10);
        if (platArray[randomRow][randomCol].get_alive() != 1){
            platArray[randomRow][randomCol]=Predator("homer", HomerEffency);
            cout << platArray[randomRow][randomCol].get_nameString() << endl;
            cout << "Making homer at "<<randomRow<<" "<<randomCol<<endl;
            break;
        }
    }
    while(true){
        int randomRow = (rand()%10);
        int randomCol = (rand()%10);
        if (platArray[randomRow][randomCol].get_alive() != 1){
            platArray[randomRow][randomCol]=cletus;
            break;
        }
    }
}

//count_platypus funciton

//print funciton
void World::printWorld(){
    //char printChar = " ";

    // Print array as grid
    for (int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            //if statement
            //printChar = " ";
            //if platArray[i][j] != null 
            //printChar = whatToPrint(platArray[i][j]);
            //cout << "|" << printChar << "|";
			cout << "|" << platArray[i][j].get_alive();
		}
		cout << "|" << endl;
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