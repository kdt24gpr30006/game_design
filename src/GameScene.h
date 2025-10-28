#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "ObjectPool.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"
#include "BattleView.h"

class GameScene : public Scene
{
	std::string sceneName = "ゲーム";

	std::vector<PoolHandle<Enemy>> enemy;
	std::unique_ptr<Player> player;
	std::unique_ptr<BattleView> view;

public:
	
	GameScene() {}
	~GameScene() {}

	// プレイヤーのターン
	void PlayerTrun();

	// 敵のターン
	void EnemyTrun();

	// ゲーム終了
	void GameEnd(bool isWin);

	// 初期化
	void Init() override;
	// 更新
	void Update() override;
};