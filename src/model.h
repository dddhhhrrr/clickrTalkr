#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "letter.h"

#include <string>
#include <fstream>
#include <iostream>

class Model{
	private:
		vector<Letter*> alphabet;
		
	public:
		Model();
		void loadLetters();
		void addLetterToAlphabet(string d, string v, string t);
		void printLetters();
		int getAlphabetSize();
		Letter* getLetterAtIndex(int x);
		~Model();
};

#endif
