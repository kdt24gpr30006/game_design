#pragma once
#include <string>

class ModelBase
{
protected:
	// �X�e�[�^�X
	std::string Name;
	int HP;
	int ATK;
public:

	ModelBase() : Name(""), HP(0), ATK(0) {}
	ModelBase(std::string name, int hp, int atk) : Name(name), HP(hp), ATK(atk) {}
	virtual ~ModelBase() {}

	// ���O
	std::string GetName() const
	{
		return Name;
	}

	// �U��
	int GetAtk() const
	{
		return ATK;
	}

	// HP
	int GetHp() const
	{
		return HP;
	}

	// ����ł��邩
	bool IsAlive() const
	{
		return HP <= 0;
	}

	// �_���[�W���󂯂�
	void HpDown(int num)
	{
		HP -= num;
		HP = std::max(0, HP);
	}
};
