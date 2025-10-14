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

Enemy* EnemyFactory::CreateEnemy(int ID)
{
    // データテーブルを検索
    for (int i = 0; i < EnemyTableSize; ++i) 
    {
        if (EnemyTable[i].ID == ID) 
        {
            // ID が見つかった場合は新しい Enemy オブジェクトを生成して返す
            return new Enemy(EnemyTable[i]);
        }
    }

    // ID が見つからなかった場合は nullptr を返す
    return nullptr;
}
