#include "SceneManager.h"

void GameObject::SetScene(std::unique_ptr<Scene> newScene)
{
	// �V�����V�[���ɐ؂�ւ�
	scene = std::move(newScene);
	// �V�����V�[���̏�����
	scene->Init();
}