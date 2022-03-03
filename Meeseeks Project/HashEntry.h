//
//  HashTable.cpp
//  
//
//  Created by Jalen Bowens on 4/5/20.
//
#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <iostream>
using namespace std;

template <class T>
class HashEntry
{
    private:
        int key;
        T value;
        HashEntry* next;
        
    public:
        HashEntry() {}
        HashEntry(int k, T v)
        {
            this->key = k;
            this->value = v;
            this->next = NULL;
        }
        
        int getKey();
        T getValue();
        HashEntry * getNext();
        void setNext(HashEntry*);
        void setValue(T);


};

/*
    Function Name: getKey
    Parameters: none
    Returns: none
    Purpose: return key
*/
template <class T>
int HashEntry<T>::getKey()
{
    return key;
}
/*
    Function Name: getValue
    Parameters: none
    Returns: none
    Purpose: return Value
*/
template <class T>
T HashEntry<T>::getValue()
{
    return value;
}
/*
    Function Name: getNext
    Parameters: none
    Returns: none
    Purpose: return next
*/
template <class T>
HashEntry<T> * HashEntry<T>::getNext()
{
    return next;
}
/*
    Function Name: setnumID
    Parameters: HashEntry pointer to next
    Returns: none
    Purpose: to initialize next to this-> next which is next that is in the constructor.
*/
template <class T>
void HashEntry<T>::setNext(HashEntry* next)
{
    this->next = next;
}
/*
    Function Name: setValue()
    Parameters: none
    Returns: none
    Purpose: initialize value to value.
*/
template <class T>
void HashEntry<T>::setValue(T v)
{
    value = v;
}
#endif
