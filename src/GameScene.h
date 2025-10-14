#pragma once
#include "SceneManager.h"
#include <iostream>
#include "Enemy.h"
#include <memory>
#include <vector>
#include "Player.h"

class GameScene : public Scene
{
	std::vector<std::unique_ptr<Enemy>> enemy;
	std::unique_ptr<Player> player;

public:
	
	GameScene() {}
	~GameScene() {}
	// ‰Šú‰»
	void Init() override;
	// XV
	void Update() override;
	// I—¹
	void Exit() override;
};