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
	hensu2 = 0;
	hensu3 = 99;
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
			hako = hand[i];
			hand[i] = hand[i + 1];
			hand[i + 1] = hako;
		}
	}

	for (int j = 0; j < sc->Cnanber; j++)
	{
		if (basyo[j] == NULL)
		{
			int ka = 0;
			basyo[j] = basyo[j + 1] - 1;
			basyo[j + 1] = ka;
		}
	}

	if (hensu <= hensu2)//手札をずらし終えたら、初期値に戻す
	{
		hensu = 99;
		hensu2 = 0;
		hensu3 = 99;
	}
}

//ドロー
void CObjEnemyHand::Draw()
{

}