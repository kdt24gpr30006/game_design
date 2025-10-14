#include <iostream>
#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Init()
{
	printf("タイトルシーン\n\n");
}

void TitleScene::Update()
{
	while (true)
	{
		printf("1でゲームシーン 2で終了\n\n");

		// 入力された数値を保存
		int inputNum = 0;
		std::cin >> inputNum;

		// 1だとゲームシーンに切り替え
		if (inputNum == 1)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		// 2だと終了
		else if (inputNum == 2)
		{
			exit(0);
			break;
		}
		else
		{
			printf("無効な数字です\n\n");
		}
	}
}
