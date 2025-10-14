#pragma once
#include <iostream>

class Player
{

public:

	int HP = 0;
	int ATK = 0;
	int HEAL = 0;

	Player() : HP(100), ATK(15), HEAL(30) {}
	~Player() {}

	// UŒ‚
	void Attack();

	// ƒ_ƒ[ƒW‚ğó‚¯‚é
	void HpDown(int num);

	// ‰ñ•œ
	void Heal();

	// €‚ñ‚Å‚¢‚é‚©
	bool IsDead();
};