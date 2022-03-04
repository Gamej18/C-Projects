#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Cost {
  float takecareHours;
  float takecareperHour;
  float oneweekFood;
  float materials;
};

struct Creature {
  string creatureName;
  string CreDescription; // Description of creature variable.
  float avgHeight; // avg height of creature.
  float avgLength; // avg length of creature.
  string creatureOrigin;
  bool DangCreature;
  Cost holdCost;
};

int enterCreatures(Creature[]);
int DeleteCreatures(int, Creature[]);
bool MoveArrayElements(string, int, Creature[]);
void printCreatures(int, Creature[]);
void PrintStatistics(int, Creature[]);
void SaveCreaturesToFile(int, Creature[]);
float ConvertToFloat(string);
#endif
