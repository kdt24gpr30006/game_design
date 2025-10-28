#pragma once
#include "View.h"

#include <iostream>

class BattleView : public View 
{

public:

// モデル関係
	// ダメージ表示
	void ShowDamage(std::string name, int atk)
	{
		printf("%sの攻撃  %dのダメージ\n\n", name.c_str(), atk);
	}
	// HP表示
	void ShowHp(std::string name, int hp)
	{
		printf("%sのHP %d\n\n", name.c_str(), hp);
	}
	// 回復表示
	void ShowHeal(std::string name, int heal)
	{
		printf("%sは%d回復した。", name.c_str(), heal);
	}
	// やられた表示
	void ShowDead(std::string name)
	{
		printf("%sは倒れた\n\n", name.c_str());
	}

// ゲーム関係
	// 勝敗
	void ShowResult(bool isWin)
	{
		if (isWin)
		{
			std::printf("You Win!\n\n");
		}
		else
		{
			std::printf("You Lose...\n\n");
		}
	}
	// 操作説明
	void InputManual1()
	{
		printf("1で攻撃 2で回復\n\n");
	}

	void InputManual2()
	{
		printf("何か入力してください");
	}

	// 操作ミス
	void InputMiss()
	{
		printf("1か2を入力してください\n\n");
	}
};