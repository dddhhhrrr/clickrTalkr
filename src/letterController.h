//one object of this type exists per each letter in the model. this is used to perform an action depending on which letter was selected by the user

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
