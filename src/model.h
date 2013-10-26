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
			   phraseToSay;
	public:
		Model();
		string getCurrentWord();
		void setCurrentWord(string w);
		string getPhraseToSay();
		void setPhraseToSay(string ph);
		void addLetterToPhraseToSay(string l);
		void clearCurrentWord();
		void clearPhraseToSay();
		void loadLetters();
		void addLetterToAlphabet(string d, string v, string t);
		void printLetters();
		int getAlphabetSize();
		Letter* getLetterAtIndex(int x);
		~Model();
};

#endif
