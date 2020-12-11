#include <iostream>
#include <cstdlib>
#include <string>
#include "Predator.h"

using namespace std;

Predator::Predator(){}

Predator::Predator(string pnm, int eff){
	nameString = pnm;
	efficiency = eff;
	Palive = 1;	
}

//setter functions
void Predator::PredAlive(){//this function allows the initializer function in world.cpp to set predators to living
	Palive = 1;
}

void Predator::predDead(){//this sets predators back to dead if they are hunted
	Palive = 0;
}

void Predator::setEff(int eff){
	efficiency = eff;
}

//getter functions
// string Predator::get_nameString() {
// 	return nameString;
// }

int Predator::getEff() const {
	return efficiency;
}

bool Predator::get_alive() {
	return Palive;
}
