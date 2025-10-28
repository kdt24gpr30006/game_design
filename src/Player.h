#pragma once
#include <algorithm>
#include <string>
#include "ModelBase.h"

class Player : public ModelBase
{
	// �񕜗�
	int HEAL = 0;

public:

	Player() : ModelBase("�v���C���[", 100, 15), HEAL(30) {}
	~Player() {}
	
	// �񕜗ʎ擾
	int GetHeal() const
	{
		return HEAL;
	}

	// ��
	void Heal()
	{
		HP += HEAL;
	}
};