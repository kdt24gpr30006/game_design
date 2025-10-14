#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "SceneManager.h"
#include "Enemy.h"
#include "Player.h"

class GameScene : public Scene
{
	std::vector<std::unique_ptr<Enemy>> enemy;
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