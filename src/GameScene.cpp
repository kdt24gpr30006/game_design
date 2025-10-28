#include <iostream>
#include "GameScene.h"
#include "TitleScene.h"
#include "EnemyFactor.h"

void GameScene::PlayerTrun()
{
	// �R�}���h����
	view->InputManual1();

	// ���͂��ꂽ���l��ۑ�
	int inputNum = 0;
	std::cin >> inputNum;

	// 1�����͂��ꂽ��U��
	if (inputNum == 1)
	{
		enemy[0]->HpDown(player->GetAtk());

		// ���\��
		view->ShowDamage(player->GetName(), player->GetAtk());
		view->ShowHp(enemy[0]->GetName(), enemy[0]->GetHp());
	}
	// 2�����͂��ꂽ���
	else if (inputNum == 2)
	{
		player->Heal();

		// ���\��
		view->ShowHeal(player->GetName(), player->GetHeal());
		view->ShowHp(player->GetName(), player->GetHp());
	}
	// ����ȊO�Ȃ������x
	else
	{
		view->InputMiss();
		return;
	}
}

void GameScene::EnemyTrun()
{
	// �G�̍U��
	player->HpDown(enemy[0]->GetAtk());

	// ���\��
	view->ShowDamage(enemy[0]->GetName(), enemy[0]->GetAtk());
	view->ShowHp(player->GetName(), player->GetHp());
}

void GameScene::GameEnd(bool isWin)
{
	// ���s���ʕ\��
	view->ShowResult(isWin);

	view->InputManual2();

	// �������͂��ꂽ��
	int a = 0;
	if (std::cin >> a)
	{
		// �^�C�g���V�[���ɕύX
		GameObject::GetInstance().SetScene(std::make_unique<TitleScene>());
	}

}

void GameScene::Init()
{
	// �R���\�[���N���A
	system("cls");

	// �V�[�����\��
	view->SceneName(sceneName);

	// �G���v�[������擾
	auto e = EnemyFactory::CreateEnemy(3);
	enemy.push_back(std::move(e));

	// �v���C���[�𐶐�
	player = std::make_unique<Player>();
	// �r���[�𐶐�
	view = std::make_unique<BattleView>();
}

void GameScene::Update()
{
	// �ǂ������������܂Ő퓬���[�v
	while (true)
	{
		// �v���C���[�̃^�[��
		PlayerTrun();

		// �G������ł�����I��
		if (enemy[0]->IsAlive())
		{
			GameEnd(true);
			break;
		}

		// �G�̃^�[��
		EnemyTrun();

		// �v���C���[������ł�����I��
		if (player->IsAlive())
		{
			GameEnd(false);
			break;
		}
	}
}