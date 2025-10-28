#pragma once
#include "SceneManager.h"
#include "TitleView.h"

class TitleScene : public Scene
{
	std::string sceneName = "�^�C�g��";
	std::unique_ptr<TitleView> view;

public:
	TitleScene() {}
	~TitleScene() {}
	// ������
	void Init() override;
	// �X�V
	void Update() override;
};