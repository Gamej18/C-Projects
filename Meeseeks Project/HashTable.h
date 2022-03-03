//
//  HashTable.cpp
//  
//
//  Created by Jalen Bowens on 4/5/20.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
#include "Meeseeks.h"
/*
     Function Name:
     Parameters:
     Returns:
     Purpose:
 */
using namespace std;

template <class T>
class HashTable
{
    private:
        int tableSize;
        HashEntry<T>** hashArray;
        
    public:
        HashTable() {}
        HashTable (int size)
        {
            tableSize = size;
            hashArray = new HashEntry<T>*[tableSize];
            for(int i = 0; i < tableSize; i++)
                hashArray[i] = NULL;
        }
        ~HashTable()
        {
            for(int i = 0; i < tableSize; i++)
            {
                if(hashArray[i] != NULL)
                {
                    HashEntry<T> * prevEntry = NULL;
                    HashEntry<T> * entry = hashArray[i];
                    while(entry != NULL)
                    {
                        prevEntry = entry;
                        entry = entry->getNext();
                        delete prevEntry;
                    }
                }
            }
            delete [] hashArray;
        }
        
        T getValue(int);
        void putValue(int,T);
        void removeValue(int);
        void printHashTable();
};
/*
    Function Name: getValue()
    Parameters: integer variable to get the key for the value.
    Returns: getValue value in the entry.
    Purpose: To get the value of Meeseeks
 */
template <class T>
T HashTable<T>::getValue(int key)
{
    int bucketIndex = key % tableSize;
    if(hashArray[bucketIndex] == NULL)
    {
        return NULL;
    }
    else
    {
        HashEntry<T> * entry;
        entry = hashArray[bucketIndex];
        while (entry != NULL && entry->getKey() != key)
            entry = entry->getNext();
        if(entry == NULL)
            return NULL;
    else
        return entry->getValue();
    }
}
/*
   Function Name: putValue()
   Parameters: integer variable to get the key for the value and the value.
   Returns: nothing
   Purpose: To put the Value of the objects that we create in the Hashentry.
*/
template <class T>
void HashTable<T>::putValue(int key, T value)
{
    int bucketIndex = key % tableSize;
    if(hashArray[bucketIndex] == NULL)
    {
        hashArray[bucketIndex] = new HashEntry<T>(key, value);
    }
    else
    {
        HashEntry<T>* entry = hashArray[bucketIndex];
        while (entry->getNext() != NULL)
            entry = entry->getNext();
        if(entry->getKey() == key)
            entry->setValue(value);
        else
            entry->setNext(new HashEntry<T>(key, value));
    }

}
/*
    Function Name: removeValue()
    Parameters: integer variable
    Returns: nothing.
    Purpose: To remove the value from the Hashtables Hash Entry.
*/
template <class T>
void HashTable<T>::removeValue(int key)
{
    HashEntry<T> *entry;
    HashEntry<T> *prevEntry;
    int bucketIndex = key% tableSize;
    if(hashArray[bucketIndex] != NULL)
    {
        //traverse through list and find matched key
        prevEntry = NULL;
        entry = hashArray[bucketIndex];
        while(entry->getNext() != NULL & entry->getKey() != key)
        {
            prevEntry = entry;
            entry = entry->getNext();
        }
        if(entry->getKey() == key) //found the key in previous while loop
        {
            if(prevEntry == NULL)
            {
                HashEntry<T> *nextEntry = entry->getNext();
                delete entry;
                hashArray[bucketIndex] = nextEntry; //re-link list
            }
            else
            {
                HashEntry<T> *next = entry->getNext();
                delete entry;
                prevEntry->setNext(next);
            }
        }
    }
}

/*
    Function Name: printHashTable
    Parameters: none
    Returns: nothing
    Purpose: To Print out the Hash Table in a nicely order
    READ BELOW!!|
                V
    I couldn't understand how to get the ostream to print out in here with all the values. So it's not working and it sucks.
*/
template <class T>
void HashTable<T>::printHashTable()
{
    Meeseeks One;
    cout << "----------\n";
    
    for(int i=0; i<tableSize; i++)
    {
        if(hashArray[i] != NULL)
        {
            HashEntry<T>* entry = hashArray[i];
            while(entry->getNext() != NULL)
            {
                cout << "---->" << setw(8) << *(entry->getValue());
                entry = entry->getNext();
            }
            cout << "---->" << setw(8) << *(entry->getValue());
            cout << "\n";
        }
        else
            cout << setw(8) << NULL << "\n";
    }
    cout << "----------\n\n";
}








#endif
