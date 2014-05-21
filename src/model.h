#ifndef MODEL_H
#define MODEL_H
//contains an alphabet, the current word that is being formed, the current phrase that is being formed, and a list of words to be used to give the user suggestions

#include <vector>
#include "letter.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>


class Model{
	private:
		vector<Letter*> alphabet;
		string currentWord,
			   phraseToSay;
		string suggestion[4];

	public:
		Model();
		string getCurrentWord();
		void setCurrentWord(string w);
		string getPhraseToSay();
		void setPhraseToSay(string ph);
		void backspace();
		void addLetterToPhraseToSay(string l);
		void clearCurrentWord();
		void clearPhraseToSay();
		void loadLetters();
		void addLetterToAlphabet(string d, string v, string t);
		void addLetterToCurrentWord(string l);
		void updateCurrentWord(string l);
		void printLetters();
		int getAlphabetSize();
		Letter* getLetterAtIndex(int x);
		void setSuggestion(int index, char* str);
		string getSuggestion(int index);
		~Model();
};

#endif
