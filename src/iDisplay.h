
#include "display.h"
#include "skin_bubbly.h"
#include "skin_simpleBlack.h"


static class iDisplay{ //Parameterized factory

public static Display getDisplay(string skinName){
	switch(skinName){
		case "simple black": { return new skin_simpleBlack(); break; }
		case "bubbly": { return new skin_bubbly(); break; }
		
		default: { return new Display(); }
	}
}
