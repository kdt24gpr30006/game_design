#include "Enemy.h"

void Enemy::Attack() const
{
	printf("%sの攻撃 %dのダメージ\n\n", Name, ATK);
}

void Enemy::HpDown(int num)
{
	HP -= num;
	printf("%sは%d ダメージを受けた。現在のHP %d\n\n", Name, num, HP);
}

bool Enemy::IsDead() const
{
	// HPが0以下ならtrue
	if (HP <= 0)
	{
		printf("%sは倒れた\n\n", Name);
		return true;
	}
	return false;
}
