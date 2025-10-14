#include <iostream>
#include "GameScene.h"
#include "TitleScene.h"
#include "EnemyFactor.h"

void GameScene::PlayerTrun()
{
	// �R�}���h����
	printf("1�ōU�� 2�ŉ�\n\n");

	// ����
	int select = 0;
	std::cin >> select;

	// 1�����͂��ꂽ��U��
	if (select == 1)
	{
		player->Attack();
		for (const auto& e : enemy)
		{
			e->HpDown(player->ATK);
		}
	}
	// 2�����͂��ꂽ���
	else if (select == 2)
	{
		player->Heal();
	}
	// ����ȊO�Ȃ������x
	else
	{
		printf("1��2����͂��Ă�������\n\n");
		return;
	}
}

void GameScene::EnemyTrun()
{
	// �G�̍U��
	enemy[0]->Attack();
	player->HpDown(enemy[0]->ATK);
}

void GameScene::GameEnd(bool isWin)
{
	// ���s���ʕ\��
	if (isWin == true)
	{
		std::printf("You Win!\n\n");
	}
	else
	{
		std::printf("You Lose...\n\n");
	}

	// �^�C�g���V�[���ɕύX
	GameObject::GetInstance().SetScene(std::make_unique<TitleScene>());
}

void GameScene::Init()
{
	printf("�Q�[���V�[��\n\n");

	// �G�𐶐�
	enemy.push_back(std::unique_ptr<Enemy>(EnemyFactory::CreateEnemy(3)));
	printf("%s�����ꂽ�I\n\n", enemy[0]->Name);

	// �v���C���[�𐶐�
	player = std::make_unique<Player>();
}

void GameScene::Update()
{
	// �ǂ������������܂Ő퓬���[�v
	while (true)
	{
		// �v���C���[�̃^�[��
		PlayerTrun();

		// �G������ł�����I��
		if (enemy[0]->IsDead())
		{
			GameEnd(true);
			break;
		}

		// �G�̃^�[��
		EnemyTrun();

		// �v���C���[������ł�����I��
		if (player->IsDead())
		{
			GameEnd(false);
			break;
		}
	}
}