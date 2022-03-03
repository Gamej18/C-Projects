//
//  TestDino.cpp
//  
//
//  Created by Jalen Bowens on 3/9/20.
//
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include <cstdlib>
#include <ctime>
using namespace std;
void MergeSort(LinkedList*, int, int);
void Merge(LinkedList*, int, int, int);
bool binarySearch(LinkedList*, int, int, string);


int main ()
{
    string temp, name, description, nameOne, nameTwo, choice;
    int random, damage, damageTwo, lp, hp;
    int x = 0;
    char userInput;
    LinkedList list;
	
    ifstream inFile;
    
    inFile.open("dinosaurFile.txt");
	if(!inFile.is_open()) {
		cout << "Sorry, I was unable to open the file.\n\n";
	}
    getline(inFile, temp);
    while(!inFile.eof())
    {
        
        name = temp; // stores a temporary variable for name
        getline(inFile, temp);
        description = temp;
        inFile >> lp; // life points of the dinosaur
        inFile >> hp; // hit points of the dinosaur
        inFile.ignore();
        if (binarySearch(&list, 0, list.getLength()-1, name) == false)
        {
            Dinosaur * NewDino = new Dinosaur(name, description, lp, hp);
            list.appendNode(NewDino);
            MergeSort(&list, 0, list.getLength()-1);
            
            cout << name << " has been added to the list of dinosaurs that can fight." << endl;
            x++;
        }
        
        getline(inFile, temp);
    }
    inFile.close();
    
    cout << x << " Dinosaurs from dinosaurFile.txt have been added to the zoo." << endl;
    cout << "||||||||||||||||||||||||||||||||||||";
    cout << "||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||";
    cout << "||||||||||||||||||||||||||||||||||||" << endl;
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
    
    do
    {
        cout << "READY TO FIGHT!!" << endl;
        cout << "PLAYER 1 NAME: ";
        getline(cin, nameOne);
        cout << "PLAYER 2 NAME: ";
        getline(cin, nameTwo);
        
        
        cout << "Before you have to select your dinosaur, " << endl;
        cout << "do you want to print details about each one?" << endl;
		cin >> userInput;
        
        while (userInput != 'y' && userInput != 'n')
        {
            cin >> userInput;
            
            if (userInput != 'y' && userInput != 'n')
            {
                cout << "Invalid Input try again." << endl;
            }
        }
        
        if(userInput == 'y')
        {
            for (x = 0; x < list.getLength(); x++)
            {
                cout << "**************************************";
                cout << "**************************************" << endl;
                cout << "DINOSAUR " << x + 1 << ":" << endl;
                list.getNodeValue(x)->printDinosaur();
                
            }

            
        }
        cout << "**************************************";
        cout << "**************************************" << endl;
        cout << "**************************************";
        cout << "**************************************" << endl;
        cout << "\n";
        cout << nameOne << ", ENTER THE DINOSAUR NUMBER YOU WISH TO FIGHT!!" << endl;
        cout << "**************************************";
        cout << "**************************************" << endl;
        
        for (int i = 0; i < list.getLength(); i++)
        {
            cout << i + 1 << "-" << list.getNodeValue(i)->getName() << "\t";
            
        }
        
        cout << endl;
        cout << "**************************************";
        cout << "**************************************\n\n";
        int userNum;
        cout << nameOne << " DINOSAUR CHOICE (1-5): ";
        cin >> userNum;
        
        Dinosaur one;
        
        one = *list.getNodeValue(userNum-1); // the dinosaur that the player chooses
        
        cout << nameTwo << ", ENTER THE DINOSAUR NUMBER YOU WISH TO FIGHT!!" << endl;
        cout << "**************************************";
        cout << "**************************************" << endl;
        
        for (int k = 0; k < list.getLength(); k++)
        {
            cout << k + 1 << "-" << list.getNodeValue(k)->getName() << "\t";
            
        }
        
        cout << endl;
        cout << "**************************************";
        cout << "**************************************\n\n";
        int userNumTwo;
        cout << nameTwo << " DINOSAUR CHOICE (1-5): ";
        cin >> userNumTwo;
        cin.ignore();
        Dinosaur two;
        
        two = *list.getNodeValue(userNumTwo-1); // the dinosaur that the player chooses
        
        int round = 1;
        int g;
        int turn = 0;
        int remainingLife = 0;
        int remainingLifeTwo= 0;;
        while (turn < 3 && one.getLife() >= 0 && two.getLife() >= 0)
        {
            cout << "||||||||||||||||||||||||||||||||||||";
            cout << "||||||||||||||||||||||||||||||||||||" << endl;
            cout << "||||||||||||||||||||||||||||||||||||";
            cout << "||||||||||||||||||||||||||||||||||||" << endl;
            cout << "||||||||||||||||||||||||||||||||||||";
            cout << "||||||||||||||||||||||||||||||||||||" << endl;
            cout << "||||||||||||||||||||||||||||||||||||";
            cout << "||||||||||||||||||||||||||||||||||||" << endl;
            cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv";
            cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
            cout << "\n";
            cout << "*********************************";
            cout << "ROUND " << round;
            cout << "*********************************\n\n";
            cout << nameOne << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << nameTwo << "'s " <<
            two.getName() << endl;
            cin.ignore();
            srand(time(NULL));
            random = rand() % 6 + 1;
            damage = random * one.getHitPoints();
            cout << "YOU HIT " << two.getName();
            cout << " for " << damage << " POINTS\n\n";
            remainingLife =  two.getLife() - damage;
            cout << two.getName() << " NOW HAS " << remainingLife << endl;
            two.setLife(remainingLife);
            if (two.getLife() <= 0)
            {
                cout << nameOne << ", " << one.getName() << " KNOCKED OUT " << two.getName() << endl;
                cout << "YOU WON!!" << endl;
                break;
            }
            
            
            
            cout << nameTwo << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << nameOne << "'s " <<
            one.getName() << "\n\n";
            cin.ignore();
            srand(time(NULL));
            random = rand() % 6 + 1;
            damageTwo = random * two.getHitPoints();
            cout << "YOU HIT " << one.getName();
            cout << " for " << damageTwo << " POINTS\n\n";
            remainingLifeTwo = one.getLife() - damageTwo;
            cout << one.getName() << " NOW HAS " << remainingLifeTwo << endl;
            one.setLife(remainingLifeTwo);
            
            if (one.getLife() <= 0)
            {
                cout << nameTwo << ", " << two.getName() << " KNOCKED OUT " << one.getName() << endl;
                cout << "YOU WON!!\n\n";
                break;
            }
            if (one.getLife() && two.getLife() > 0)
            {
                
            }
            
            turn++;
            round++;
        }
        if(round > 3)
        {
            if(one.getLife() > two.getLife())
            {
                cout << nameOne << ", " << one.getName() << " KNOCKED OUT " << two.getName() << endl;
                cout << "YOU WON!!" << endl;
            }
            else
            {
                cout << nameTwo << ", " << two.getName() << " KNOCKED OUT " << one.getName() << endl;
                cout << "YOU WON!!\n\n";
            }
        }
        cout << "Would you like to play again (y/n) \t";
        cin >> choice;
        cout << "\n\n";
        if (choice != "y" && choice != "n")
        {
            cout << "you did not enter 'y' or 'n'. Would you like to play again (y/n) \n\n";
            cin >> choice;

        }
        if (choice == "n")
        {
            cout << "GOODBYE!!\n\n";
        }
        else
            cin.ignore();
    }while(choice == "y");
    
}


void MergeSort(LinkedList * dino, int beg, int end)
{
    int mid = 0;
    
    if (beg < end)
    {
        mid = (beg + end) / 2;
        
        MergeSort(dino, beg, mid);
        MergeSort(dino, mid + 1, end);

        Merge(dino, beg, mid, end);
    }
}


void Merge(LinkedList * dino , int beg, int mid, int end)
{
    int mergedSize = end - beg + 1;
    int mergedPos = 0;
    int leftPos = 0;
    int rightPos = 0;
    LinkedList * dinoList = new LinkedList;
    
    leftPos = beg;
    rightPos = mid + 1;

    while (leftPos <= mid && rightPos <= end) {
        if(dino->getNodeValue(leftPos)->getName() < dino->getNodeValue(rightPos)->getName()) {
            dinoList->appendNode(dino->getNodeValue(leftPos));
            ++leftPos;
        }
        else {
            dinoList->appendNode(dino->getNodeValue(rightPos));
            ++rightPos;
        }
        ++mergedPos;
    }
    
    while(leftPos <= mid)
    {
        dinoList->appendNode(dino->getNodeValue(leftPos));
        ++leftPos;
        ++mergedPos;
    }
    while(rightPos <= end) {
        dinoList->appendNode(dino->getNodeValue(rightPos));
        ++rightPos;
        ++mergedPos;
    }

    for (mergedPos = 0; mergedPos < mergedSize; ++mergedPos)
    {
        dino->deleteNode(dinoList->getNodeValue(mergedPos));
        dino->appendNode(dinoList->getNodeValue(mergedPos));
    }
    delete dinoList;
}

bool binarySearch(LinkedList * dinoNode, int first, int last, string value)
{
    int middle;
    if (first > last)
        return false;
    
    middle = (first + last)/2;
    if (dinoNode->getNodeValue(middle)->getName()==value)
        return true;
    
    if(dinoNode->getNodeValue(middle)->getName()<value)
        return binarySearch(dinoNode, middle+1, last, value);
        
    else
        return binarySearch(dinoNode, first, middle-1, value);
}
