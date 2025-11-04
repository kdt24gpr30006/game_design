#pragma once
#include <algorithm>
#include <string>
#include "ModelBase.h"

class Player : public ModelBase
{
	const int HP_MAX = 100;
	const int ATK_MAX = 15;
	const int HEAL_POWER = 30;

	// ‰ñ•œ—Ê
	int HEAL = 0;

public:

	Player() : ModelBase("ƒvƒŒƒCƒ„[", HP_MAX, ATK_MAX), HEAL(HEAL_POWER) {}
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
		// Å‘åHP‚ğ’´‚¦‚È‚¢‚æ‚¤‚É
		HP = std::min(HP, HP_MAX);
	}
};