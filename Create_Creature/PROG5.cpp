#include "PROG5.h"

int main() {
  int NUM_ELE = 100;
  Creature array[NUM_ELE];
  int currCreatures = 0;
  int userchoice;
  string creatureVar;
  string user;
  do {
    cout << "What would you like to do?" << endl;
    cout << "\t\t1. Enter some Magical Creatures" << endl;
    cout << "\t\t2. Delete Magical Creatures" << endl;
    cout << "\t\t3. List/Print Creatures" << endl;
    cout << "\t\t4. Print Statistics on Creature Cost" << endl;
    cout << "\t\t5. End Program." << endl;
    cout << "Enter: (1, 2, 3 , 4 or 5)";
    cin >> userchoice;
    if (userchoice == 1) {
      currCreatures = enterCreatures(array);
    }
    if (userchoice == 2) {
      currCreatures = DeleteCreatures(currCreatures, array);
    }
    if (userchoice == 3) {
      printCreatures(currCreatures, array);

    }
    if (userchoice == 4) {
      PrintStatistics(currCreatures, array);
    }
    if (userchoice == 5) {
      cout << "Would you like to save creatures to a file. (y or n)" << endl;
      cin >> user;
      if (user == "y") {
        SaveCreaturesToFile(currCreatures, array);
      }
    }
  } while (userchoice != 5);
}
