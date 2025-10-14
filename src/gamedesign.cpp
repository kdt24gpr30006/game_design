#include <iostream>
#include "SceneManager.h"
#include "TitleScene.h"

int main()
{
	GameObject& game = GameObject::GetInstance();
	game.SetScene(std::make_unique<TitleScene>());

	// ゲームループ
	while (true)
	{
		game.Update();
	}
}
