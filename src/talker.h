#ifndef TALKER_H
#define TALKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Talker{
	private:
		string prefix;
		string textToSay;
		string suffix;
		
	public:
		Talker();
		Talker(string s);
		~Talker();
		
		string getPrefix();
		void setPrefix(string p);
		string getTextToSay();
		void setTextToSay(string t);
		string getSuffix();
		void setSuffix(string s);
		void sayPhrase();
		void sayPhrase(string t);
};

#endif
