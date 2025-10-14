#include <iostream>
#include "SceneManager.h"
#include "TitleScene.h"

int main()
{
	//インスタンスのアドレスを保持
	GameObject& game = GameObject::GetInstance();

	// 最初はタイトルシーンに切り替え
	game.SetScene(std::make_unique<TitleScene>());

	// ゲームループ
	while (true)
	{
		game.Update();
	}
}
