#include "EnemyFactor.h"
#include "Enemy.h"

// データテーブル
const EnemyData EnemyFactory::EnemyTable[] = 
{
    { 1, "Slime", 20, 5},
    { 2, "Goblin", 45, 10},
    { 3, "Dragon", 100, 20}
};

// データテーブルのサイズ
const int EnemyFactory::EnemyTableSize = sizeof(EnemyFactory::EnemyTable) / sizeof(EnemyFactory::EnemyTable[0]);

// プールを容量 10 で初期化
ObjectPool<Enemy> EnemyFactory::enemyPool(10);

PoolHandle<Enemy> EnemyFactory::CreateEnemy(int ID)
{
    for (int i = 0; i < EnemyTableSize; ++i)
    {
        if (EnemyTable[i].ID == ID)
        {
            auto handle = enemyPool.Acquire();
            handle->SetData(EnemyTable[i]);
            return handle;
        }
    }

    throw std::runtime_error("Invalid Enemy ID");
}
