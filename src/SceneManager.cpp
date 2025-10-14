#include "SceneManager.h"

void GameObject::SetScene(std::unique_ptr<Scene> newScene)
{
	// 新しいシーンに切り替え
	scene = std::move(newScene);
	// 新しいシーンの初期化
	scene->Init();
}