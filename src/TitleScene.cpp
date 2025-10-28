#include <iostream>
#include "TitleScene.h"
#include "GameScene.h"

void TitleScene::Init()
{
	// �R���\�[���N���A
	system("cls");

	// �V�[�����\��
	view->SceneName(sceneName);
}

void TitleScene::Update()
{
	while (true)
	{
		// �R�}���h����
		view->InputManual();

		// ���͂��ꂽ���l��ۑ�
		int inputNum = 0;
		std::cin >> inputNum;

		// 1���ƃQ�[���V�[���ɐ؂�ւ�
		if (inputNum == 1)
		{
			GameObject::GetInstance().SetScene(std::make_unique<GameScene>());
			break;
		}
		// 2���ƏI��
		else if (inputNum == 2)
		{
			exit(0);
			break;
		}
		// ����ȊO�Ȃ������x
		else
		{
			view->InputMiss();
		}
	}
}
