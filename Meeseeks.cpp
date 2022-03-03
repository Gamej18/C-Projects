//
//  Meeseeks.cpp
//  
//
//  Created by Jalen Bowens on 4/4/20.
//


#include <iostream>
#include <cstring>
#include "Meeseeks.h"

/*
Function Name: Constructor
Parameters: Variables to initialize to
Returns: nothing
Purpose: to call and initialize the variables to the ones in the Parameter.
*/
Meeseeks::Meeseeks(string N,string D,string tL,int key)
{
    Name = N;
    Des = D;
    timeLimit = tL;
    numID = key;
    
}
/*
    Function Name: getnumID
    Parameters: none
    Returns: none
    Purpose: return numID
*/
int Meeseeks::getnumID() const
{
    return numID;
}

/*
    Function Name: getName
    Parameters: none
    Returns: none
    Purpose: return getName
*/

string Meeseeks::getName() const
{
    return Name;
}

/*
    Function Name: getDes
    Parameters: none
    Returns: none
    Purpose: return getDes
*/
string Meeseeks::getDes() const
{
    return Des;
}

/*
    Function Name: gettL
    Parameters: none
    Returns: none
    Purpose: return timeLimit
*/
string Meeseeks::gettL() const
{
    return timeLimit;
}

/*
    Function Name: ostream &operator
    Parameters: ostream inseration variable and a Meeseeks Variable
    Returns: ostream &strm
    Purpose: to help print out my hashtable in nice and neat way.
*/
ostream &operator << (ostream &strm, Meeseeks &member)
{
    strm << "numID: " << member.getnumID() << ", NAME: " << member.getName();
    return strm;
}
