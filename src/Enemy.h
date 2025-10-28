#pragma once
#include "EnemyData.h"
#include <algorithm>
#include <string>
#include "ModelBase.h"

class Enemy : public ModelBase
{
	// ID
	int ID;

public:

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
};