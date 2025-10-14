#pragma once
#include <memory>

// シーン管理クラス
class Scene
{
public:
	Scene() {}
	~Scene() {}

	// 初期化
	virtual void Init() = 0;
	// 更新
	virtual void Update() = 0;
	// 終了
	virtual void Exit() = 0;
};


class GameObject
{
	// 現在のシーン
	std::unique_ptr<Scene> scene;

	// コンストラクタとデストラクタ
	GameObject() {}
	~GameObject() {}

public:

	// コピーと代入禁止
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

	// シングルトンインスタンスの取得
	static GameObject& GetInstance()
	{
		static GameObject instance;
		return instance;
	}

	// シーンの設定
	void SetScene(std::unique_ptr<Scene> newScene);
	// 更新
	void Update() { scene->Update(); }
};