#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int rounds, int magCapacity)
		: Weapon(range,damage), rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	void showMe() override;

	int Rounds() { return rounds_; }
	int MagCapacity() { return magCapacity_; }

	void Rounds(int newRounds) {
		if (newRounds > 0 && newRounds <= magCapacity_)
			rounds_ = newRounds;
	}
	void MagCapacity(int newCapacity) {
		if (newCapacity > 0)
			magCapacity_ = newCapacity;
	}

private:
	int rounds_, magCapacity_;
};

