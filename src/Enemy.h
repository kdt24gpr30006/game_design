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

	Enemy() : ID(-1) {}
	Enemy(const EnemyData& argData) { SetData(argData); }

	// データセット
	void SetData(const EnemyData& argData)
	{
		ID = argData.ID;
		Name = argData.Name;
		HP = argData.HP;
		ATK = argData.ATK;
	}
};