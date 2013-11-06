//represents a letter, a vector of letters is used to create the virtual keyboard

#ifndef LETTER_H
#define LETTER_H

#include <string>
#include <iostream>
using namespace std;

class Letter{
	private:
		string letterToDisplay;
		string value;
		string type;
	
	public:
		Letter();
		Letter(string d, string v, string t);
		~Letter();
		void setLetterToDisplay(string d);
		string getLetterToDisplay();
		void setValue(string v);
		string getValue();
		void setType(string t);
		string getType();
};

#endif
