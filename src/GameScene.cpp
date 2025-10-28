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

	// 1が入力されたら攻撃
	if (inputNum == 1)
	{
		enemy[0]->HpDown(player->GetAtk());

		// 情報表示
		view->ShowDamage(player->GetName(), player->GetAtk());
		view->ShowHp(enemy[0]->GetName(), enemy[0]->GetHp());
	}
	// 2が入力されたら回復
	else if (inputNum == 2)
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
	// 敵の攻撃
	player->HpDown(enemy[0]->GetAtk());

	// 情報表示
	view->ShowDamage(enemy[0]->GetName(), enemy[0]->GetAtk());
	view->ShowHp(player->GetName(), player->GetHp());
}

void GameScene::GameEnd(bool isWin)
{
	// 勝敗結果表示
	view->ShowResult(isWin);

	view->InputManual2();

	// 何か入力されたら
	int a = 0;
	if (std::cin >> a)
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

	// 敵をプールから取得
	auto e = EnemyFactory::CreateEnemy(3);
	enemy.push_back(std::move(e));

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

		// 敵が死んでいたら終了
		if (enemy[0]->IsAlive())
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