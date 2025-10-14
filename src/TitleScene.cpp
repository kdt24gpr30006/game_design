#include <iostream>
#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Init()
{
	printf("�^�C�g���V�[��\n\n");
}

void TitleScene::Update()
{
	while (true)
	{
		printf("1�ŃQ�[���V�[�� 2�ŏI��\n\n");

		// ���͂��ꂽ���l��ۑ�
		int inputNum = 0;
		std::cin >> inputNum;

		// 1���ƃQ�[���V�[���ɐ؂�ւ�
		if (inputNum == 1)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		// 2���ƏI��
		else if (inputNum == 2)
		{
			exit(0);
			break;
		}
		else
		{
			printf("�����Ȑ����ł�\n\n");
		}
	}
}
