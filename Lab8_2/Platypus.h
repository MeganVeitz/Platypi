// Section CSC160 - Computer Science I: C++
// File Name:  Platypus.h
// Student: Meg Veitz
// Homework Number: Lab 10
// Description: Mr. Burns is trying to cover up his tracks and needs our help to save his reputation and his  money.
//              To accomplish this goal we will be looking at attributes of the platyuses to determinr if Mr. Burns is
//              breaking any note worth environmental concerns. 
// Last Changed: 

#include <iostream>
#include <cstring>

#ifndef PLATY_PROG_H_INCLUDED
#define PLATY_PROG_H_INCLUDED
using namespace std;

class Platypus{
   public:
      //Default constructor
      Platypus();
      //Parameterized 
      Platypus(char, float, short, std::string);
      string getName();

      //Display
      void print();
      
      //Main Functions
      void age_me();
      void fight(Platypus & p2);
      void eat();
      void hatch();
      //Meg made new function 
      void do_something(Platypus*, Platypus*, Platypus*, Platypus*, bool);
      bool mate(Platypus & p2);// Meg made
      void randomize(); //Steve made
      
      //Access function values
      short get_age();
      std::string get_nameString();
      char get_gender();
      float get_weight();
      bool get_alive();
      bool get_mutant();
      bool get_egg();
      
      //Set function values
    
      void make_dead();
      void set_age(short newAge);
      void set_nameString(std::string newString);
      void set_gender(char newGender);
      void set_weight(float newWeight);
      void set_alive(bool newAlive);
      void set_mutant(bool newMutant);
      void set_egg(bool NewEgg); //created by meg
      std::string nameString;

   private:
      float weight;
      short age;   //months
      char gender; //male||fem
      bool alive;  //true(1)=alive, false(0)=dead
      bool mutant; //true=mutant, false=dead
      bool egg;
};   
#endif

