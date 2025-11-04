#include <iostream>
#include "GameScene.h"
#include "TitleScene.h"
#include "EnemyFactor.h"

void GameScene::PlayerTrun()
{
	// コマンド説明
	view->InputManual1();

	// 入力された数値を保存
	int inputNum = 0;
	std::cin >> inputNum;

	const int INPUT_ATTACK = 1;
	const int INPUT_HEAL = 2;

	// 1が入力されたら攻撃
	if (inputNum == INPUT_ATTACK)
	{
		for (auto& enemy : enemies)
		{
		enemy->HpDown(player->GetAtk());

		// 情報表示
		view->ShowDamage(player->GetName(), player->GetAtk());
		view->ShowHp(enemy->GetName(), enemy->GetHp());
		}
	}
	// 2が入力されたら回復
	else if (inputNum == INPUT_HEAL)
	{
		player->Heal();

		// 情報表示
		view->ShowHeal(player->GetName(), player->GetHeal());
		view->ShowHp(player->GetName(), player->GetHp());
	}
	// それ以外ならもう一度
	else
	{
		view->InputMiss();
		return;
	}
}

void GameScene::EnemyTrun()
{
	for (const auto& enemy : enemies)
	{
		// 敵の攻撃
		player->HpDown(enemy->GetAtk());

		// 情報表示
		view->ShowDamage(enemy->GetName(), enemy->GetAtk());
		view->ShowHp(player->GetName(), player->GetHp());
	}
}

void GameScene::GameEnd(bool isWin)
{
	// 勝敗結果表示
	view->ShowResult(isWin);

	view->InputManual2();

	// 何か入力されたら
	int input = 0;
	if (std::cin >> input)
	{
		// タイトルシーンに変更
		GameObject::GetInstance().SetScene(std::make_unique<TitleScene>());
	}

}

void GameScene::Init()
{
	// コンソールクリア
	system("cls");

	// シーン名表示
	view->SceneName(sceneName);

	const int CREATE_ENEMY_ID = 3;

	// 敵をプールから取得
	auto createEnemy = EnemyFactory::CreateEnemy(CREATE_ENEMY_ID);
	enemies.push_back(std::move(createEnemy));

	// プレイヤーを生成
	player = std::make_unique<Player>();
	// ビューを生成
	view = std::make_unique<BattleView>();
}

void GameScene::Update()
{
	// どっちかがやられるまで戦闘ループ
	while (true)
	{
		// プレイヤーのターン
		PlayerTrun();
		
		// 敵がすべて死んでいるか
		bool isAllDead = true;
		for (const auto& enemy : enemies)
		{
			// 一体でも生きている
			if (enemy->IsAlive() == false)
			{
				isAllDead = false;
				break;
			}
		}
		// 死んでたら終了
		if (isAllDead == true)
		{
			GameEnd(true);
			break;
		}

		// 敵のターン
		EnemyTrun();

		// プレイヤーが死んでいたら終了
		if (player->IsAlive())
		{
			GameEnd(false);
			break;
		}
	}
}