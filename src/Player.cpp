#include "Player.h"

void Player::Attack()
{
	printf("Player�̍U��  %d�̃_���[�W\n\n", ATK);
}

void Player::HpDown(int num)
{
	HP -= num;
	printf("Player��%d�_���[�W���󂯂��B ���݂�HP %d\n\n", num, HP);
}

void Player::Heal()
{
	HP += HEAL;
	printf("Player��%d�񕜂����B ���݂�HP %d\n\n", HEAL, HP);
}

bool Player::IsDead()
{
	// HP��0�ȉ��Ȃ�true
	if (HP <= 0)
	{
		printf("Player�͓|�ꂽ\n\n");
		return true;
	}
	return false;
}
