#include "TitleScene.h"
#include <iostream>
#include <Windows.h>
#include "GameScene.h"


void TitleScene::Init()
{
	printf("タイトルシーン\n\n");
}

void TitleScene::Update()
{
	while (true)
	{
		printf("1でゲームシーンへ\n\n");

		int inputNum = 0;
		std::cin >> inputNum;

		// 1だとゲームシーンに切り替え
		if (inputNum == 1)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		else
		{
			printf("無効な数字です\n\n");
		}
	}
}

void TitleScene::Exit()
{
}
