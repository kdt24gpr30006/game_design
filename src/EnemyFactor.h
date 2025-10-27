#pragma once
#include "EnemyData.h"
#include "Enemy.h"
#include "ObjectPool.h"

// �O���錾
class Enemy;

class EnemyFactory
{
	// �G�f�[�^�e�[�u��
    static const EnemyData EnemyTable[];
	// �f�[�^�e�[�u���̃T�C�Y
    static const int EnemyTableSize;

	// �G�I�u�W�F�N�g�v�[��
	static ObjectPool<Enemy> enemyPool;

public:
	// �G�I�u�W�F�N�g�𐶐�����֐�
	static PoolHandle<Enemy> CreateEnemy(int ID);
};