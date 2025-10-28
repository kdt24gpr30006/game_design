#pragma once
#include "SceneManager.h"
#include "TitleView.h"

class TitleScene : public Scene
{
	std::string sceneName = "タイトル";
	std::unique_ptr<TitleView> view;

public:
	TitleScene() {}
	~TitleScene() {}
	// 初期化
	void Init() override;
	// 更新
	void Update() override;
};