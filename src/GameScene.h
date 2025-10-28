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
	std::string sceneName = "�Q�[��";

	std::vector<PoolHandle<Enemy>> enemy;
	std::unique_ptr<Player> player;
	std::unique_ptr<BattleView> view;

public:
	
	GameScene() {}
	~GameScene() {}

	// �v���C���[�̃^�[��
	void PlayerTrun();

	// �G�̃^�[��
	void EnemyTrun();

	// �Q�[���I��
	void GameEnd(bool isWin);

	// ������
	void Init() override;
	// �X�V
	void Update() override;
};