#pragma once
#include <iostream>

class Player
{
public:

	// ステータス
	int HP = 0;
	int ATK = 0;
	int HEAL = 0;

	Player() : HP(100), ATK(15), HEAL(30) {}
	~Player() {}

	// 攻撃
	void Attack();

	// ダメージを受ける
	void HpDown(int num);

	// 回復
	void Heal();

	// 死んでいるか
	bool IsDead();
};