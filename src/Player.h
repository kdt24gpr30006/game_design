#pragma once
#include <iostream>

class Player
{
public:

	// �X�e�[�^�X
	int HP = 0;
	int ATK = 0;
	int HEAL = 0;

	Player() : HP(100), ATK(15), HEAL(30) {}
	~Player() {}

	// �U��
	void Attack();

	// �_���[�W���󂯂�
	void HpDown(int num);

	// ��
	void Heal();

	// ����ł��邩
	bool IsDead();
};