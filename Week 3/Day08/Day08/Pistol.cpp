#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "\nRounds: " << rounds_ << "\tMagazine Capacity: " << magCapacity_ << "\n";
}
