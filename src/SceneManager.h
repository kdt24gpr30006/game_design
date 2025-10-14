#pragma once
#include <memory>

// �V�[���Ǘ��N���X
class Scene
{
public:
	Scene() {}
	~Scene() {}

	// ������
	virtual void Init() = 0;
	// �X�V
	virtual void Update() = 0;
	// �I��
	virtual void Exit() = 0;
};


class GameObject
{
	// ���݂̃V�[��
	std::unique_ptr<Scene> scene;

	// �R���X�g���N�^�ƃf�X�g���N�^
	GameObject() {}
	~GameObject() {}

public:

	// �R�s�[�Ƒ���֎~
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

	// �V���O���g���C���X�^���X�̎擾
	static GameObject& GetInstance()
	{
		static GameObject instance;
		return instance;
	}

	// �V�[���̐ݒ�
	void SetScene(std::unique_ptr<Scene> newScene);
	// �X�V
	void Update() { scene->Update(); }
};