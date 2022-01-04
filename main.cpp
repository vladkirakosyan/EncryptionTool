#include <iostream>
#include "encrypter.h"


int main()
{

	Encrypter a("Happy Christmas1");
	//b.rotateLeft();
	//b.rotateDown();
	a.setKey("DL");

	std::cout << a.getText() << std::endl;
	return 0;
}
