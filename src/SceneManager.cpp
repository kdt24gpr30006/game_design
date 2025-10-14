#include "SceneManager.h"

void GameObject::SetScene(std::unique_ptr<Scene> newScene)
{
	// シーンが存在する場合は終了処理
	if (scene)
	{
		scene->Exit();
	}
	// 新しいシーンに切り替え
	scene = std::move(newScene);
	// 新しいシーンの初期化
	scene->Init();
}