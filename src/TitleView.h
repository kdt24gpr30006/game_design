#pragma once
#include "View.h"

#include <iostream>

class TitleView : public View
{
public:
// �Q�[���֌W

	// �������
	void InputManual()
	{
		printf("1�ŃQ�[���V�[�� 2�ŏI��\n\n");
	}
	// ����~�X
	void InputMiss()
	{
		printf("1��2����͂��Ă�������\n\n");
	}
};

