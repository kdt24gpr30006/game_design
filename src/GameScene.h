#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "ObjectPool.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"

class GameScene : public Scene
{
	std::vector<PoolHandle<Enemy>> enemy;
	std::unique_ptr<Player> player;

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