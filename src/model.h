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
		string currentWord,
			   currentPhrase;
	public:
		Model();
		string getCurrentWord();
		void setCurrentWord(string w);
		string getCurrentPhrase();
		void setCurrentPhrase(string ph);
		void addLetterToCurrenPhrase(string l);
		void clearCurrentWord();
		void clearCurrentPhrase();
		void loadLetters();
		void addLetterToAlphabet(string d, string v, string t);
		void printLetters();
		int getAlphabetSize();
		Letter* getLetterAtIndex(int x);
		~Model();
};

#endif
