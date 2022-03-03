//
//  Meeseeks.hpp
//  
//
//  Created by Jalen Bowens on 4/4/20.
//

#ifndef MEESEEKS_H
#define MEESEEKS_H
#include <iostream>

using namespace std;

class Meeseeks
{
	private:
		int numID;
		string Name;
		string Des;
		string timeLimit;
		
	public:
		Meeseeks () {}
		Meeseeks (string,string,string,int);
		void setnumID(int);
		void setName(string);
		void setDes(string);
		void settL(string); // set the time limit
		int getnumID() const;
		string getName() const;
		string getDes() const; // get description
		string gettL() const; // get time limit
        friend ostream &operator << (ostream &strm, Meeseeks &member);
};



#endif /* Meeseeks_hpp */
