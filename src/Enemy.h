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

	Enemy() = default;
	Enemy(const EnemyData& argData) { SetData(argData); }

	// �f�[�^�Z�b�g
	void SetData(const EnemyData& argData)
	{
		ID = argData.ID;
		Name = argData.Name;
		HP = argData.HP;
		ATK = argData.ATK;
	}

	// �U��
	void Attack() const;

	// �_���[�W���󂯂�
	void HpDown(int num);

	// ����ł��邩
	bool IsDead() const;
};