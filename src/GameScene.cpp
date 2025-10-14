#include <iostream>
#include "GameScene.h"
#include "TitleScene.h"
#include "EnemyFactor.h"

void GameScene::PlayerTrun()
{
	// コマンド説明
	printf("1で攻撃 2で回復\n\n");

	// 入力
	int select = 0;
	std::cin >> select;

	// 1が入力されたら攻撃
	if (select == 1)
	{
		player->Attack();
		for (const auto& e : enemy)
		{
			e->HpDown(player->ATK);
		}
	}
	// 2が入力されたら回復
	else if (select == 2)
	{
		player->Heal();
	}
	// それ以外ならもう一度
	else
	{
		printf("1か2を入力してください\n\n");
		return;
	}
}

void GameScene::EnemyTrun()
{
	// 敵の攻撃
	enemy[0]->Attack();
	player->HpDown(enemy[0]->ATK);
}

void GameScene::GameEnd(bool isWin)
{
	// 勝敗結果表示
	if (isWin == true)
	{
		std::printf("You Win!\n\n");
	}
	else
	{
		std::printf("You Lose...\n\n");
	}

	// タイトルシーンに変更
	GameObject::GetInstance().SetScene(std::make_unique<TitleScene>());
}

void GameScene::Init()
{
	printf("ゲームシーン\n\n");

	// 敵を生成
	enemy.push_back(std::unique_ptr<Enemy>(EnemyFactory::CreateEnemy(3)));
	printf("%sが現れた！\n\n", enemy[0]->Name);

	// プレイヤーを生成
	player = std::make_unique<Player>();
}

void GameScene::Update()
{
	// どっちかがやられるまで戦闘ループ
	while (true)
	{
		// プレイヤーのターン
		PlayerTrun();

		// 敵が死んでいたら終了
		if (enemy[0]->IsDead())
		{
			GameEnd(true);
			break;
		}

		// 敵のターン
		EnemyTrun();

		// プレイヤーが死んでいたら終了
		if (player->IsDead())
		{
			GameEnd(false);
			break;
		}
	}
}