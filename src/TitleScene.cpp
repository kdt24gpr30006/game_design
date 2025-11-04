#include <iostream>
#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Init()
{
	// コンソールクリア
	system("cls");

	// シーン名表示
	view->SceneName(sceneName);
}

void TitleScene::Update()
{
	while (true)
	{
		// コマンド説明
		view->InputManual();

		// 入力された数値を保存
		int inputNum = 0;
		std::cin >> inputNum;

		const int INPUT_GAME = 1;
		const int INPUT_EXIT = 2;

		// 1だとゲームシーンに切り替え
		if (inputNum == INPUT_GAME)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		// 2だと終了
		else if (inputNum == INPUT_EXIT)
		{
			exit(0);
			break;
		}
		// それ以外ならもう一度
		else
		{
			view->InputMiss();
		}
	}
}
