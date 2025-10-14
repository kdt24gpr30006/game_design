#pragma once
#include "EnemyData.h"

// 前方宣言
class Enemy;

class EnemyFactory
{
	// 敵データテーブル
    static const EnemyData EnemyTable[];
	// データテーブルのサイズ
    static const int EnemyTableSize;

public:
	// 敵オブジェクトを生成する関数
    static Enemy* CreateEnemy(int ID);
};