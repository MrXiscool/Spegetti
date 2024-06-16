#include <iostream>
#include "Headers/Spegetti_Demo.h"

using namespace Spegetti_Demo;

int main() {

	Start();

	while (Running) {

		Loop();
	
	}

	End();

	return 0;

}