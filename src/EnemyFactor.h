#pragma once
#include "EnemyData.h"
#include "Enemy.h"
#include "ObjectPool.h"

// 前方宣言
class Enemy;

class EnemyFactory
{
	// 敵データテーブル
    static const EnemyData EnemyTable[];
	// データテーブルのサイズ
    static const int EnemyTableSize;

	// 敵オブジェクトプール
	static ObjectPool<Enemy> enemyPool;

public:
	// 敵オブジェクトを生成する関数
	static PoolHandle<Enemy> CreateEnemy(int ID);
};