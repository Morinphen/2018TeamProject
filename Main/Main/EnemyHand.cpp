//シヨウスルヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"EnemyHand.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
//使用するネームスペース

//イニシャライズ
void CObjEnemyHand::Init()
{
	hensu = 99;
}

//アクション
void CObjEnemyHand::Action()
{
	CObjEnemyDeck*sc = (CObjEnemyDeck*)Objs::GetObj(OBJ_ENEMY_DECK);
	for (int i = 0; i < sc->Cnanber; i++)
	{
		if (hand[i] == NULL)
		{
			int hako = 0;
			hako = hand[i] - 1;
			hand[i] = hand[i + 1];
			hand[i + 1] = hako;
		}
	}
	if (hensu == 0) {
		for (int j = 0; j < sc->Cnanber; j++)
		{
			if (basyo[j] == NULL)
			{
				int ka = 0;
				basyo[j] = basyo[j + 1] - 1;
				basyo[j + 1] = ka;
			}
		}
	}
}

//ドロー
void CObjEnemyHand::Draw()
{

}