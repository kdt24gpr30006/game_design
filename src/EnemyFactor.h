#pragma once
#include "EnemyData.h"

// �O���錾
class Enemy;

class EnemyFactory
{
	// �G�f�[�^�e�[�u��
    static const EnemyData EnemyTable[];
	// �f�[�^�e�[�u���̃T�C�Y
    static const int EnemyTableSize;

public:
	// �G�I�u�W�F�N�g�𐶐�����֐�
    static Enemy* CreateEnemy(int ID);
};