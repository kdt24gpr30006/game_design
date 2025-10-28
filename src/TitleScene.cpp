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
		// それ以外ならもう一度
		else
		{
			view->InputMiss();
		}
	}
}
