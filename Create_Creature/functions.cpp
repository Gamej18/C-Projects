#include "PROG5.h"

/*
  loads creatures from a file of users choice or lets the user enter a creature
  manually into the program.
*/
int enterCreatures (int currCreatures, Creature array[]) {
 int userInput;
 int user;
 ifstream inFile;
 string userFile;
 string boolVar;
 string addmoreC;
 string temp;
 do {
   cout << "What do you want to do?" << endl;
   cout << "1.\tLoad my creatures from a file." << endl;
   cout << "2.\tEnter one Creature manually." << endl;
   cout << "CHOICE:\t";
   cin >> userInput;
   cout << "\n\n";

   while (userInput < 1 || userInput > 2)
   {
     cout << "Enter a valid number" << endl;
     cin >> userInput;
   }

   if (userInput == 1) {
     cout << "What is the name of your file with your list of creatures?  (ex: filename.txt)" << endl;
     cout << "FILENAME: ";
     cin >> userFile;
   break;
   inFile.open(userFile);
   if(!inFile.is_open()) {
     cout << "Could not open CreaturesFile.txt." << endl;
    }
      if(inFile) {
        getline(inFile,array[currCreatures].creatureName, '#');
        while(!inFile.eof()) {
          getline(inFile, array[currCreatures].CreDescription, '#');
          getline(inFile, temp, '#');
          array[currCreatures].avgLength = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].avgHeight = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].creatureOrigin = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].DangCreature = !(temp == "0");
          getline(inFile, temp, '#');
          array[currCreatures].holdCost.takecareHours = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].holdCost.takecareperHour = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].holdCost.oneweekFood = ConvertToFloat(temp);
          getline(inFile, temp, '#');
          array[currCreatures].holdCost.materials = ConvertToFloat(temp);
          currCreatures++;
        }
      }
    }
   if (userInput == 2) {
       cin.ignore();
       cout << "NAME: ";
       getline(cin, array[currCreatures].creatureName);
       cout << endl;
       cout << "DESCRIPTION: ";
       getline(cin, array[currCreatures].CreDescription);
       cout << endl;
       cout << "AVERAGE LENGTH (in feet): ";
       cin >> array[currCreatures].avgLength;
       cout << endl;
       cout << "AVERAGE HEIGHT (in feet): ";
       cin >> array[currCreatures].avgHeight;
       cout << endl;
       cout << "LOCATION: ";
       cin >> array[currCreatures].creatureOrigin;
       cout << endl;
       cout << "IS IT A DANGEROUS CREATURE? (y or n)";
       cin >> boolVar;
       if (boolVar == "y") {
         array[currCreatures].DangCreature = true;
       }
       else {
         array[currCreatures].DangCreature = false;
       }
       cout << "How many hours do you spend caring for the ";
       cout << array[currCreatures].creatureName << endl;
       cout << "NUM HOURS: " << endl;
       cin >> array[currCreatures].holdCost.takecareHours;
       cout << "What is the cost per hour for caring for the ";
       cout << array[currCreatures].creatureName << endl;
       cout << "COST PER HOUR: " << endl;
       cin >> array[currCreatures].holdCost.takecareperHour;
       cout << "How much money do you spend on food for the ";
       cout << array[currCreatures].creatureName << endl;
       cout << "FOOD COST: " << endl;
       cin >> array[currCreatures].holdCost.oneweekFood;
       cout << "How much money do you spend on grooming and medical supplies for the ";
       cout << array[currCreatures].creatureName << endl;
       cout << "SUPPLY COST: " << endl;
       cin >> array[currCreatures].holdCost.materials;
       cout << "the " << array[currCreatures].creatureName << " has been added" << endl;
       cout << "\n\n";
       cout << "Want to add more creatures? (y or n)";
       cin >> addmoreC;
       if (addmoreC == "y") {
         currCreatures++;
       }
       else {
         break;
       }
    }
 } while (addmoreC != "n");
 inFile.close();
 return currCreatures;

}
/*
Lets the user Delete a creature from the creature thats in the array.
*/

int DeleteCreatures (int currCreatures, Creature array[]) {
  string creatureVar;
  cout << "The following is a list of all the creatures you take care of: " << endl;
  for (int i = 0; i <= currCreatures; i++) {
    cout << array[i].creatureName << endl;
  }
  cin.ignore();
  cout << "\n\n";
  cout << "What creature do you wish remove?" << endl;
  cout << "CREATURE NAME: ";
  getline(cin, creatureVar);
  if (MoveArrayElements(creatureVar, currCreatures, array)) {
    currCreatures--;
    cout << "You have removed " << creatureVar << endl;
  }
  return currCreatures;
}

/*
moves the creatures to the right once a creature is deleted.
*/
bool MoveArrayElements (string creatureVar, int currCreatures, Creature array[]) {
  bool ifFound = false;
  int index;


  for (int j = 0; j < currCreatures; j++) {
    if (creatureVar == array[j].creatureName) {
      index = j;
      ifFound = true;
    }
  }
  if (ifFound) {
    for (int i = index; i <= currCreatures; i++) {

        array[i].creatureName = array[i + 1].creatureName;
        array[i].CreDescription = array[i +1].CreDescription;
        array[i].avgHeight = array[i + 1].avgHeight;
        array[i].avgLength = array[i + 1].avgLength;
        array[i].creatureOrigin = array[i + 1].creatureOrigin;
        array[i].DangCreature = array[i + 1].DangCreature;
        array[i].holdCost.takecareHours = array[i + 1].holdCost.takecareHours;
        array[i].holdCost.takecareperHour = array[i + 1].holdCost.takecareperHour;
        array[i].holdCost.oneweekFood = array[i + 1].holdCost.oneweekFood;
        array[i].holdCost.materials = array[i + 1].holdCost.materials;
    }
    return true;
  }
  return false;
}

// this function prints a creature to the screen or to a file of the users choice.
void printCreatures(int currCreatures, Creature array[]) {
  int userchoice;
  string userFile;
  ofstream inFile;
  cout << "1. Print Creaatures to the Screen " << endl;
  cout << "2. Print Creatures to a File" << endl;
  cout << "Choose 1 or 2" << endl;
  cout << "CHOICE: ";
  cin >> userchoice;
  cout << "----------------------------------------------------------------------" << endl;

  while (userchoice < 1 || userchoice > 2)
  {
    cout << "Enter a valid number" << endl;
    cin >> userchoice;
  }

  if (userchoice == 1) {
    for (int i = 0; i <= currCreatures; i++) {
      cout << "CREATURE " << i + 1 << ":" << endl;
      cout << "name: \t\t" << array[i].creatureName << endl;
      cout << "Description:" << endl;
      cout << "\t" <<array[i].CreDescription << endl;
      cout << "Length: \t" << array[i].avgLength << endl;
      cout << "Height: \t" << array[i].avgHeight << endl;
      cout << "Location: \t" << array[i].creatureOrigin << endl;
      cout << "Dangerous: \t";
      if (array[i].DangCreature == true) {
        cout << "YES" << endl;
      }

      else {
        cout << "NO" << endl;
      }

      cout << "number of hours to Care for the Creature: \t" << "$ ";
      cout << array[i].holdCost.takecareHours << endl;
      cout << "Cost Per Hour of Taking of Creature: \t\t" << "$ ";
      cout << array[i].holdCost.takecareperHour << endl;
      cout << "Cost to Feed Creatures: \t\t\t" << "$ ";
      cout << array[i].holdCost.oneweekFood << endl;
      cout << "Grooming & Supplies Cost: \t\t\t" << "$ ";
      cout << array[i].holdCost.materials << endl;
      cout << "\n\n" << endl;
      cout << "----------------------------------------------------------------------" << endl;
    }
  }
  if (userchoice == 2) {
    cout << "What is the name of your file you wish to print your creatures to?  (ex: filename.txt)" << endl;
    cout << "FILENAME: ";
    cin >> userFile;
    inFile.open(userFile);

    for (int i = 0; i <= currCreatures; i++) {
      inFile << "CREATURE " << i + 1 << ":" << endl;
      inFile << "name: \t\t" << array[i].creatureName << endl;
      inFile << "Description:" << endl;
      inFile << "\t" <<array[i].CreDescription << endl;
      inFile << "Length: \t" << array[i].avgLength << endl;
      inFile << "Height: \t" << array[i].avgHeight << endl;
      inFile << "Location: \t" << array[i].creatureOrigin << endl;
      inFile << "Dangerous: \t";
      if (array[i].DangCreature == true) {
        inFile << "YES" << endl;
      }

      else {
        inFile << "NO" << endl;
      }

      inFile << "number of hours to Care for the Creature: \t" << "$ ";
      inFile << array[i].holdCost.takecareHours << endl;
      inFile << "Cost Per Hour of Taking of Creature: \t\t" << "$ ";
      inFile << array[i].holdCost.takecareperHour << endl;
      inFile << "Cost to Feed Creatures: \t\t\t" << "$ ";
      inFile << array[i].holdCost.oneweekFood << endl;
      inFile << "Grooming & Supplies Cost: \t\t\t" << "$ ";
      inFile << array[i].holdCost.materials << endl;
      inFile << "\n\n" << endl;
      inFile << "----------------------------------------------------------------------" << endl;
      cout << "Your Creatures have been written to ";
      cout << userFile << endl;
    }
  }
}
// Prints the cost of each creature to the screen and the total of all the creatures together.
void PrintStatistics(int currCreatures, Creature array[]) {
  int Cost;
  int temp;

  cout << "COST OF EACH CREATURE FOR ONE WEEK:";
  cout << "\n\n";
  cout << "CREATURE\t\t\tCOST" << endl;

  for (int i = 0; i <= currCreatures; i++) {
    Cost = array[i].holdCost.takecareHours * array[i].holdCost.takecareperHour + array[i].holdCost.oneweekFood + array[i].holdCost.materials;
    cout << array[i].creatureName << "\t\t$\t\t" << Cost << endl;
    temp = temp + Cost;
    cout << endl;
  }
    cout <<"TOTAL COST:"<< "\t$\t\t" << temp << endl;
}
// Saves a creature to the file of the users choice.
void SaveCreaturesToFile (int currCreatures, Creature array[]) {
  string userFile;
  fstream inFile;
  string userInput;
  cout << "Would you like to save your creature list to a file? (y or n)" << endl;
  cout << "What is the name of the file you want to save your creatures to?" << endl;
  cout << "FILENAME: ";
  cin >> userFile;
  inFile.open(userFile, ios::out);
  if(!inFile.is_open()) {
    cout << "Could not open file" << endl;
  }

  if (inFile) {
      for (int i = 0; i <= currCreatures; i++) {
      inFile << array[i].creatureName << '#';
      inFile << array[i].CreDescription << '#';
      inFile << array[i].avgLength << '#';
      inFile << array[i].avgHeight << '#';
      inFile << array[i].creatureOrigin << '#';
      inFile << array[i].DangCreature << '#';
      inFile << array[i].holdCost.takecareHours << '#';
      inFile << array[i].holdCost.takecareperHour << '#';
      inFile << array[i].holdCost.oneweekFood << '#';
      inFile << array[i].holdCost.materials << '#';
      cout << "\n";
      cout << array[i].creatureName << "was saved to file" << endl;
    }
      inFile.close();
  }
  cout << currCreatures << "creatures were successfully saved to the " << userFile << " file" << endl;
  cout << "\n\n";
  cout << "GOODBYE!" << endl;
}
// converts the float to a string for the numbers in the enterCreatures function.
float ConvertToFloat (string s) {
  istringstream i(s);
  float x;
  if (!(i >> x))
      x = 0;
  return x;
}
