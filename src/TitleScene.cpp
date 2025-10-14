#include "TitleScene.h"
#include <iostream>
#include <Windows.h>
#include "GameScene.h"


void TitleScene::Init()
{
	printf("�^�C�g���V�[��\n\n");
}

void TitleScene::Update()
{
	while (true)
	{
		printf("1�ŃQ�[���V�[����\n\n");

		int inputNum = 0;
		std::cin >> inputNum;

		// 1���ƃQ�[���V�[���ɐ؂�ւ�
		if (inputNum == 1)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		else
		{
			printf("�����Ȑ����ł�\n\n");
		}
	}
}

void TitleScene::Exit()
{
}
