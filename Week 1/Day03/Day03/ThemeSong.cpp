#include "ThemeSong.h"
#include <iostream>
//add the definition in the cpp
void ThemeSong::BatTheme(int nas)
{
	for (size_t i = 0; i < nas; i++)
	{
		std::cout << "na ";
	}
	std::cout << "BATMAN!!!\n";
}