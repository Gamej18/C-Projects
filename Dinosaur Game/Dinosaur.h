#ifndef DINOSAUR_H
#define DINOSAUR_H



#include <iostream>
#include <string>
using namespace std;

class Dinosaur
{
	private:
		string dinoName;
		string dinoDescription;
		int lifePoints;
		int hitPoints;
	public:
        Dinosaur() {};
		Dinosaur(string,string,int,int);
        ~Dinosaur() {};
		void setName(string);
		void setDescription(string);
		void setLife(int);
		void setHitPoints(int);
		string getName() const;
		string getDescription() const;
		int getLife() const;
		int getHitPoints() const;
        void printDinosaur();
};

Dinosaur::Dinosaur(string name, string description, int lifeP, int hitP)
{
	dinoName = name;
	dinoDescription = description;
	lifePoints = lifeP;
	hitPoints = hitP;
}

void Dinosaur::setName(string dN)
{
	dinoName = dN;
}

void Dinosaur::setDescription(string dD)
{
	dinoDescription = dD;
}

void Dinosaur::setLife(int lp)
{
	lifePoints = lp;
}

void Dinosaur::setHitPoints(int hp)
{
	hitPoints = hp;
}

string Dinosaur::getName() const
{
	return this->dinoName;
}

string Dinosaur::getDescription() const
{
	return this->dinoDescription;
}

int Dinosaur::getLife() const
{
	return lifePoints;
}

int Dinosaur::getHitPoints() const
{
	return hitPoints;
}


void Dinosaur::printDinosaur()
{
    cout << "Name\t: " << getName() << endl;
    cout << "Description:" << endl;
    cout << getDescription() << "\n" << endl;
    cout << "LIFE POINTS:\t" << getLife() << endl;
    cout << "HIT POINTS:\t" << getHitPoints() << endl;
}

#endif
