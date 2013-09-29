#ifndef LETTER_H
#define LETTER_H

#include <string>

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
