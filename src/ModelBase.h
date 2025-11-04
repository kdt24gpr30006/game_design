#pragma once
#include <string>

class ModelBase
{
protected:
	// ステータス
	std::string Name;
	int HP;
	int ATK;
public:

	ModelBase() : Name(""), HP(-1), ATK(-1) {}
	ModelBase(std::string name, int hp, int atk) : Name(name), HP(hp), ATK(atk) {}
	virtual ~ModelBase() {}

	// 名前
	std::string GetName() const
	{
		return Name;
	}

	// 攻撃
	int GetAtk() const
	{
		return ATK;
	}

	// HP
	int GetHp() const
	{
		return HP;
	}

	// 死んでいるか
	bool IsAlive() const
	{
		return HP <= 0;
	}

	// ダメージを受ける
	void HpDown(int num)
	{
		HP -= num;
		// HPがマイナスにならないように
		HP = std::max(0, HP);
	}
};
