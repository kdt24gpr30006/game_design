#pragma once
#include "SceneManager.h"

class TitleScene : public Scene
{
public:
	TitleScene() {}
	~TitleScene() {}
	// ������
	void Init() override;
	// �X�V
	void Update() override;
	// �I��
	void Exit() override;
};