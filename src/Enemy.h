#pragma once
#include <iostream>
#include "EnemyData.h"

class Enemy {

public:
	// ステータス
	int ID;
	const char* Name;
	int HP;
	int ATK;

	Enemy(const EnemyData& argData) : ID(argData.ID), Name(argData.Name), HP(argData.HP), ATK(argData.ATK) {}

	// 攻撃
	void Attack();

	// ダメージを受ける
	void HpDown(int num);

	// 死んでいるか
	bool IsDead();
};