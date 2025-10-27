#include "Enemy.h"

void Enemy::Attack() const
{
	printf("%s�̍U�� %d�̃_���[�W\n\n", Name, ATK);
}

void Enemy::HpDown(int num)
{
	HP -= num;
	printf("%s��%d �_���[�W���󂯂��B���݂�HP %d\n\n", Name, num, HP);
}

bool Enemy::IsDead() const
{
	// HP��0�ȉ��Ȃ�true
	if (HP <= 0)
	{
		printf("%s�͓|�ꂽ\n\n", Name);
		return true;
	}
	return false;
}
