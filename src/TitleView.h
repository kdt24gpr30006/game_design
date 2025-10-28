#pragma once
#include "View.h"

#include <iostream>

class TitleView : public View
{
public:
// ゲーム関係

	// 操作説明
	void InputManual()
	{
		printf("1でゲームシーン 2で終了\n\n");
	}
	// 操作ミス
	void InputMiss()
	{
		printf("1か2を入力してください\n\n");
	}
};

