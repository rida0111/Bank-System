#include <iostream>
#include "ClsLoginScreen.h"

using namespace std;

int main()
{
	
	while (true)
	{
		if(!ClsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	system("pause>0");

	return 0;
}
