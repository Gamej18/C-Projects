#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "HashTable.h"
#include "Meeseeks.h"

using namespace std;

void readFromFile(HashTable<Meeseeks*>*);
void enterManually(HashTable<Meeseeks*>*);
void SearchTable(HashTable<Meeseeks*>*);
void deleteCreature(HashTable<Meeseeks*>*);
void printMeeseeks(HashTable<Meeseeks*>*);

int main() {
	HashTable<Meeseeks*> *table = new HashTable<Meeseeks*>(10);
	int choice;
	
	do{
		cout << "MEESEEKS HELPFUL MENU\n";
		cout << "1. Add Meeseeks From File\n";
		cout << "2. Add Meeseeks Manually\n";
		cout << "3. Search for Meeseeks\n";
        cout << "4. Delete a Meeseeks\n";
        cout << "5. Print HashTable\n";
        cout << "6. End Program\n";
		cout << "CHOOSE 1-6: ";
		cin >> choice;
        cout << "\n\n";
		if(choice == 1)
		{
			readFromFile(table);
		}
		if(choice == 2)
		{
			enterManually(table);
		}
		if(choice == 3)
		{
			SearchTable(table);
		}
        if(choice == 4)
        {
            deleteCreature(table);
        }
        if(choice == 5)
        {
            printMeeseeks(table);
        }
        
        if(choice == 6)
        {
            cout << "GOODBYE!!\n";
            break;
        }
        
		
	}while (choice != 7);
}
/*
    Function Name: readFromFile
    Parameters: A dynamically created Hashtable of my custom class with size 10 in table
    Returns: none
    Purpose: to read all the data from the file into the object and put it into the HashTable.
*/
void readFromFile(HashTable<Meeseeks*>* table) {
	ifstream File;
	string N, temp, D, tP; // Name // timelimt //Description of Meeeseeks
	int key;
	int numM = 0; // number of meeseeks that's added
	File.open("dataFile.txt");
	getline(File, temp);
	while(!File.eof()) {
		N = temp;
        
		getline(File, temp);
		D = temp;
        
		getline(File, temp);
		tP = temp;
        
        File >> key;
		File.ignore();
 		Meeseeks * NewCreature = new Meeseeks(N,D,tP,key);
        cout << "Entering meeseeks with ID " << NewCreature->getnumID() << " and name " << NewCreature->getName() << endl;
        table->putValue(NewCreature->getnumID(), NewCreature);
		getline(File, temp);
        
        numM++;
	}
	File.close();
	File.clear();
    
    cout << "\n" << numM <<" meekeeks from creatureFile.txt have been added to the hash table.\n\n";
}

/*
    Function Name: enterManually
    Parameters: A dynamically created Hashtable of my custom class with size 10 in table
    Returns: none
    Purpose: to write all the data into the object and put it into the HashTable.
*/
void enterManually(HashTable<Meeseeks*>* table)
{
    string Name, temp, Des, tP;
    int key;
    
    cout << "KEY:\t";
    cin >> key;
    
    cout << "NAME:\t";
    getline(cin, Name);
    cin.ignore();
    cout << "DESCRIPTION:\t";
    getline(cin, Des);
    cin.ignore();
    cout << "TIME LIMIT:\t";
    getline(cin, tP);
    cin.ignore();
    Meeseeks * addCreature = new Meeseeks(Name, Des,tP,key);
    table->putValue(addCreature->getnumID(), addCreature);

}
/*
    Function Name: SearchTable()
    Parameters: A dynamically created Hashtable of my custom class with size 10 in table
    Returns: none
    Purpose: To go into the HashTable with the key and search what your looking for that matches the key.
*/
void SearchTable(HashTable<Meeseeks*>* table)
{
	Meeseeks * Morty; // pointer of Meeseeks. Named it Morty for fun.
	int key; // key you are searching for.
    
	cout << "What is the key of the meeseeks you are searching for? ";
	cin >> key;
    while(!cin)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid key. Must be an Integer.\n";
        cout << "\n\nKEY:  ";
        cin >> key;
    }
	Morty = table->getValue(key);
    if(Morty != NULL)
    {
        cout << "ID:\t" << Morty->getnumID() << endl;
        cout << "NAME:\t" << Morty->getName() << endl;
        cout << "DESCRIPTION:\n";
        cout << "\t\t " << Morty->getDes() << endl;
    }
    else
        cout << "\n\nThere are no Meeseeks with that key in the table.\n\n";
        
}

/*
    Function Name: deleteCreature
    Parameters: A dynamically created Hashtable of my custom class with size 10 in table
    Returns: none
    Purpose: To go into the HashTable and delete a creature depending on it's key.
*/
void deleteCreature(HashTable<Meeseeks*>* table)
{
    cout << "This is a list of Meeseeks currently in the HashTable.\n\n";
    table->printHashTable();
    cout << "\n\n";
    int id; // the ID thats connected to the creature.
    cout << "What is the ID of the meeseeks that you want to remove?\n";
    cout << "MEESEEKS ID: ";
    cin >> id;
    table->removeValue(id);
    cout << "You Have Removed a Meeseeks\n";
}
/*
    Function Name: printMeeseeks()
    Parameters: A dynamically created Hashtable of my custom class with size 10 in table
    Returns: none
    Purpose: To Print the HashTable in a nice and simple way.
*/
void printMeeseeks(HashTable<Meeseeks*>* table)
{
    table->printHashTable();
}
