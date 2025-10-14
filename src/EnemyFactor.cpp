#include "EnemyFactor.h"
#include "Enemy.h"

// �f�[�^�e�[�u��
const EnemyData EnemyFactory::EnemyTable[] = 
{
    { 1, "Slime", 20, 5},
    { 2, "Goblin", 45, 10},
    { 3, "Dragon", 100, 20}
};

// �f�[�^�e�[�u���̃T�C�Y
const int EnemyFactory::EnemyTableSize = sizeof(EnemyFactory::EnemyTable) / sizeof(EnemyFactory::EnemyTable[0]);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
    // �f�[�^�e�[�u��������
    for (int i = 0; i < EnemyTableSize; ++i) 
    {
        if (EnemyTable[i].ID == ID) 
        {
            // ID �����������ꍇ�͐V���� Enemy �I�u�W�F�N�g�𐶐����ĕԂ�
            return new Enemy(EnemyTable[i]);
        }
    }

    // ID ��������Ȃ������ꍇ�� nullptr ��Ԃ�
    return nullptr;
}
