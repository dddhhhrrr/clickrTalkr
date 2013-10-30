#ifndef LETTER_CONTROLLER
#define LETTER_CONTROLLER

#include "model.h"
#include <iostream>
#include <string>

using namespace std;

class LetterController{

	private:
		Model &model;
		string value;
		string type;
	
	public:
		LetterController(Model &m, string v, string t);
		~LetterController();
		virtual void execute();	

};

#endif
