#include "Player.h"

void Player::Attack()
{
	printf("Playerの攻撃  %dのダメージ\n\n", ATK);
}

void Player::HpDown(int num)
{
	HP -= num;
	printf("Playerは%dダメージを受けた。 現在のHP %d\n\n", num, HP);
}

void Player::Heal()
{
	HP += HEAL;
	printf("Playerは%d回復した。 現在のHP %d\n\n", HEAL, HP);
}

bool Player::IsDead()
{
	// HPが0以下ならtrue
	if (HP <= 0)
	{
		printf("Playerは倒れた\n\n");
		return true;
	}
	return false;
}
