#pragma once
#include "View.h"

#include <iostream>

class BattleView : public View 
{

public:

// ���f���֌W
	// �_���[�W�\��
	void ShowDamage(std::string name, int atk)
	{
		printf("%s�̍U��  %d�̃_���[�W\n\n", name.c_str(), atk);
	}
	// HP�\��
	void ShowHp(std::string name, int hp)
	{
		printf("%s��HP %d\n\n", name.c_str(), hp);
	}
	// �񕜕\��
	void ShowHeal(std::string name, int heal)
	{
		printf("%s��%d�񕜂����B", name.c_str(), heal);
	}
	// ���ꂽ�\��
	void ShowDead(std::string name)
	{
		printf("%s�͓|�ꂽ\n\n", name.c_str());
	}

// �Q�[���֌W
	// ���s
	void ShowResult(bool isWin)
	{
		if (isWin)
		{
			std::printf("You Win!\n\n");
		}
		else
		{
			std::printf("You Lose...\n\n");
		}
	}
	// �������
	void InputManual1()
	{
		printf("1�ōU�� 2�ŉ�\n\n");
	}

	void InputManual2()
	{
		printf("�������͂��Ă�������");
	}

	// ����~�X
	void InputMiss()
	{
		printf("1��2����͂��Ă�������\n\n");
	}
};