#include "letter.h"

using namespace std;

Letter::Letter(){
}

Letter::Letter(string d, string v, string t){
	letterToDisplay = d;
	value = v;
	type = t;
	cout << "Letter created!" << endl;
}
		
void Letter::setLetterToDisplay(string d){
	letterToDisplay = d;
}

string Letter::getLetterToDisplay(){
	return letterToDisplay;
}

void Letter::setValue(string v){
	value = v;
}

string Letter::getValue(){
	return value;
}

void Letter::setType(string t){
	type = t;
}

string Letter::getType(){
	return type;
}

Letter::~Letter(){
	cout << "Letter destroyed!" << endl;
}
