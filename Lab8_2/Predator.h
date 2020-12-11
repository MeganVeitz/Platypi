#include <iostream>
#include <cstdlib>
#include <string>
#include "Platypus.h"

#ifndef PREDA_PROG_H_INCLUDED
#define PREDA_PROG_H_INCLUDED
using namespace std;

class Predator:public Platypus{
	public:
		Predator();
		Predator(string, int);
		//utility
		template <typename t>
		void hunt(t& p);
		
		//setter
		void PredAlive();
		void predDead();
		void setEff(int);
		std::string nameString;

		//accessor
		//string get_nameString();
		int getEff() const;
		bool get_alive();
		//Friend
		/*friend class Platypus;*/	
	private:
		int efficiency;
		bool Palive;
};

template <typename t>
void Predator::hunt(t& p){ 
	int chance = (rand() % 99);             
	if(chance < efficiency){
        cout << "Animal has been hunted" << endl;
        p.make_dead();
	} else {
		cout << "Animal has survived!";
	}
}
#endif