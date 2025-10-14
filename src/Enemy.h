#pragma once
#include "EnemyData.h"
#include <iostream>

class Enemy {

public:
	int ID;
	const char* Name;
	int HP;
	int ATK;

	Enemy(const EnemyData& argData) : ID(argData.ID), Name(argData.Name), HP(argData.HP), ATK(argData.ATK) {}

	// UŒ‚
	void Attack();

	// ƒ_ƒ[ƒW‚ğó‚¯‚é
	void HpDown(int num);

	// €‚ñ‚Å‚¢‚é‚©
	bool IsDead();
};