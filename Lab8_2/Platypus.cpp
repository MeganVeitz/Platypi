// Section CSC160 - Computer Science I: C++
// File Name:  Platypus.cpp
// Student: Meg Veitz
// Homework Number: Lab 10
// Description: Mr. Burns is trying to cover up his tracks and needs our help to save his reputation and his  money.
//              To accomplish this goal we will be looking at attributes of the platyuses to determinr if Mr. Burns is
//              breaking any note worth environmental concerns. 
// Last Changed: Got the random lib working

#include <iostream>
#include <cctype>
#include <random>
#include <string>
#include <locale>
#include "Platypus.h" 
#include <fstream>

using namespace std;

//**
//Creating a default constructor that creates a dead platypus
Platypus::Platypus(){
   alive = 0;
}

//initialized funtion 
Platypus::Platypus(char initGender, float initWeight, short initAge, string initNameString){
   if((initGender == 'M'|| initGender == 'm' || initGender == 'F' || initGender == 'f')
      && initWeight >= 0
      && initAge >= 0){
        gender = initGender;
        weight = initWeight;
        age = initAge;
        nameString = initNameString;
        
        alive = 1;
        mutant = 0;
        egg = 0;

        cout << nameString << " Platypus Made" << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << endl;
        cout << "Age: " << age << " months" << endl;
        cout << "Alive: " << alive << endl;
        cout << "Mutant: " << mutant << endl;
        cout << "Egg: " << egg << endl;
      }
      else{
         cout << "Invalid Data" << endl;
      }
}


void Platypus::print(){
   cout << "Name:  " << get_nameString() << endl;
   cout << "Gender:  " << gender << endl;
   cout << "Age:  " << get_age() << " months" <<endl;
   cout << "Weight:  " << get_weight() << " lbs" << endl;
   cout << "Alive:  " << get_alive() << "  (1=Yes 0=No)" << endl;
   cout << "Mutant:  " << get_mutant() << "  (1=Yes 0=No)" << endl;
}


void Platypus::age_me(){
   if (get_alive() == 0){
      cout << "The platypus has died, poor fella." << endl;
      return;
   }
   
   cout << "Platpus is aging!" << endl;
    int chance;
    int weight_percent;
    int death_rand;
    
    set_age(get_age() + 1);
    
    //possiblity of becoming mutant (by %2)
    chance = (rand() % 50) +1;
    //cout << "Age is: " << get_age() << " Chance is: " << chance << endl;
    if(chance % 2 == 1){
        mutant = 1;
        cout << "Platypus has mutated!" << endl;
    }
    
    if (weight >= 10){
        cout << "The aged platypus has died, poor fella." << endl;
        alive = false;
    }
    
    //10% of weight = Death
    weight_percent = weight * 10;
    
    //rand num 1-100
    death_rand = (rand() % 100) + 1;

    //cout << "weight_percent: " << weight_percent << " death_rand: " << death_rand << endl;
    
    //if random number is less than or equal to plat weight times 10 then Death
    if(death_rand <= weight_percent){
        alive = 0;
        cout << "The aged platypus has died, poor fella." << endl;
    }  
}//end age_me


void Platypus::fight(Platypus & p2){
   if(alive == 0){
      cout << "Your Platypus can fight" << endl;
      return;
   }
   
   if(p2.get_alive()==0){
      cout << "That Platypus is dead." << endl; 
   }
   
   cout << "Platypus fight!" << endl;
   float p2_weight = p2.get_weight();
   float fight_ratio = (weight / p2_weight) * 50;

   random_device rd; // obtain a random number from hardware
   mt19937 gen(rd()); // seed the generator
   uniform_int_distribution<> distr(1, 100); // define the range
   int chance = distr(gen);
   if (chance  < fight_ratio){
      p2.make_dead();
      cout << "The second platypus has died in the fight." << endl;
   }
   else{
      alive = 0;
      cout << "Your platypus died in the fight." << endl;
   }
}//end fight


void Platypus::eat(){
   if(alive == 0){
      cout <<"Platypus is already dead." << endl;
      return;
   }
   cout << "Stuffing face ..." << endl;
   
   random_device rd; // obtain a random number from hardware
   mt19937 gen(rd()); // seed the generator
   uniform_int_distribution<> distr(1, 50); // define the range

   float weightPercent = distr(gen)/100.0; 
   weight += (weight*(weightPercent));
   cout << "New weight is: " << weight << endl;
}// end eat


void Platypus::hatch(){
   string new_name;
   string fileName;
   // rand gender
   random_device rd; // obtain a random number from hardware
   mt19937 gen(rd()); // seed the generator
   uniform_int_distribution<> distr(0, 1); // define the range
   int chance = distr(gen);
   if (chance == 0) {
      set_gender('M');
      fileName = "m_names.txt";
   }
   else{
      set_gender('F');
      fileName = "f_names.txt";
   }

   uniform_int_distribution<> distr1(0, 50); // define the range
   int nameNumber = distr1(gen);

   ifstream fin;
   fin.open(fileName);
   for (int i=0; i < nameNumber; i++) {
      getline(fin, new_name);
   }
   
   set_nameString(new_name);

   //weight chance
   uniform_int_distribution<> distr2(10, 100); // define the range
   float new_weight = distr2(gen)/100.0;
   set_weight(new_weight);
   set_age(0);
   set_alive(1);//true
   set_egg(false);
   set_mutant(false);
   cout << "New platypus made" << endl;
}//end hatch


void Platypus::make_dead(){
   set_alive(0);
}

//Steve made
void Platypus::randomize(){
   age = (rand()%36);
   alive = 1;
   set_nameString("P");
}


//Meg created
bool Platypus::mate(Platypus & p2) {
   //if same gender, can't mate
   if (p2.get_mutant() == true || get_mutant() == true){
      cout << "Your Platypi can not mate, at least one is a mutant" << endl;
   }
   //if plat same gender, can't mate
   if(p2.get_gender() == get_gender()){
         cout << "Your Platypi are the same gender and can not mate" << endl;
   } else {
      //opp gender, mate
      //if calling plat weight*age > p2 weight*age is true then accept 
      if ((get_weight() * get_age()) > (p2.get_weight() * p2.get_age())){
         cout << "The Platypus are mating!" << endl;
         return true;
      } else{ ////else refuse = flase
         return false;
      }
   }
}

//Meg's refined code ~ still needs to figure out mate function parameter 
void Platypus::do_something(Platypus* north, Platypus* south, Platypus* east, Platypus* west, bool value){
	//Calling Play randomly dchoose direction
   int direction = (rand() % 4);
   string whatDone = " "; 

	switch (direction){
      //North (0,1)
		case 0:
         //if N plat is dead, calling plat eat
         if (!north->get_alive()){
            Platypus::eat();
            whatDone = "The Platypus ate!";
         }
         else{
         //N plat isn't dead, rand choose interact
            int interact = (rand() % 2);
            if (interact == 1) {
               //if same gender, fight
               if(north->get_gender() == Platypus::get_gender()){
                  Platypus::fight(*north);
                  whatDone = "The Platypus fighting!";

               } else {
               //opp gender, mate
                  Platypus::mate(*north);
                  whatDone = "The Platypi are mating!";

               }
            }
         }
			break;

      //South (0,-1)
		case 1:
			//if S plat is dead, calling plat eat
         if (!south->get_alive()){
            Platypus::eat();
            whatDone = "The Platypus ate!";

         }
         else{
         //S plat isn't dead, rand choose interact
            int interact = (rand() % 2);
            if (interact == 1) {
               //if same gender, fight
               if(south->get_gender() == Platypus::get_gender()){
                  Platypus::fight(*south);
                  whatDone = "The Platypus are fighting!";
               } else {
               //opp gender, mate
                  Platypus::mate(*south);//Can i put p2 as parameter or does it have to be related to it's direction name?
                  whatDone = "The Platypus are mating!";
               }
            }
         }
			break;

      //East (1,0)
		case 2:
			//if E plat is dead, calling plat eat
         if (!east->get_alive()){
            Platypus::eat();
            whatDone = "The Platypus ate!";
         } else{
         //E plat isn't dead, rand choose interact
            int interact = (rand() % 2);
            if (interact == 1) {
               //if same gender, fight
               if(east->get_gender() == Platypus::get_gender()){
                  Platypus::fight(*east);
                  whatDone = "The Platypus are fighting!";

               } else {
               //opp gender, mate
                  Platypus::mate(*east);
                  whatDone = "The Platypus are fighting!";
               }
            }
         }
			break;

      //West (-1,0)
		case 3:
		   //if W plat is dead, calling plat eat
         if (!west->get_alive()){
            Platypus::eat();
            whatDone = "The Platypus ate!";
         } else{
         //W plat isn't dead, rand choose interact
            int interact = (rand() % 2);
            if (interact == 1) {
               // if same gender, fight
               if(west->get_gender() == Platypus::get_gender()){
                  Platypus::fight(*west);
                  whatDone = "The Platypus are fighting!";
               } else {
                  //opp gender, mate
                  Platypus::mate(*west);
                  whatDone = "The Platypus are mating!";
               }
            }
         }
			break;

		default:
			cout << "Error; unable to complete action." << endl;
   }//end switch
   if (value){
      cout << Platypus::get_nameString() << " " << whatDone << endl; 
   }
}

//Access
float Platypus::get_weight(){
   return weight;
}

short Platypus::get_age(){
   return age;
}

bool Platypus::get_alive(){
   return alive;
}

string Platypus::get_nameString(){
   return nameString;
}

char Platypus::get_gender(){
   return gender;
}

bool Platypus::get_mutant(){
   return mutant;
}

bool Platypus::get_egg(){
   return egg;
}

//Sets
void Platypus::set_weight(float newWeight){
   weight = newWeight;
}

//created by Meg
void Platypus::set_egg(bool NewEgg){
   egg = NewEgg;
}

void Platypus::set_age(short newAge){
   age = newAge;
}

void Platypus::set_nameString(string newString){
   nameString = newString;
}

void Platypus::set_gender(char newGender){
   gender = newGender;
}

void Platypus::set_mutant(bool newMutant){
   mutant = newMutant;
}

void Platypus::set_alive(bool newAlive){
   alive = newAlive;
}
