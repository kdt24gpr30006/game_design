#pragma once
#include <algorithm>
#include <string>
#include "ModelBase.h"

class Player : public ModelBase
{
	// ‰ñ•œ—Ê
	int HEAL = 0;

public:

	Player() : ModelBase("ƒvƒŒƒCƒ„[", 100, 15), HEAL(30) {}
	~Player() {}
	
	// ‰ñ•œ—Êæ“¾
	int GetHeal() const
	{
		return HEAL;
	}

	// ‰ñ•œ
	void Heal()
	{
		HP += HEAL;
	}
};