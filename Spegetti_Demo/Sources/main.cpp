#include <iostream>
#include "Headers/Spegetti_Demo.h"

using namespace Spegetti_Demo;

int main() {

	Spegetti::Console::log("Project Started");

	Start();

	while (Running) {

		Loop();
	
	}

	End();
	
	Spegetti::Console::log("Finished Sucsefully");

	return 0;

}