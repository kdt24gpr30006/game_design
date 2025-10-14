#pragma once
#include <iostream>
#include "EnemyData.h"

class Enemy {

public:
	// �X�e�[�^�X
	int ID;
	const char* Name;
	int HP;
	int ATK;

	Enemy(const EnemyData& argData) : ID(argData.ID), Name(argData.Name), HP(argData.HP), ATK(argData.ATK) {}

	// �U��
	void Attack();

	// �_���[�W���󂯂�
	void HpDown(int num);

	// ����ł��邩
	bool IsDead();
};