//使用するヘッダーファイル
#include"GameHead.h"
#include"map.h"

#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

void CObjMap::Init()
{
	S_position = false;
	S_position2 = false;

	ES_position = false;
	ES_position2 = false;

	L_position = true;
	R_position = true;

	WiSummon = false;

	ESummont = 0;
	EAtackt = 0;

	m_f = false;
	Wtouch = false;
	PTrun = false;
	WSummon = false;
	Cooltime = 0;

	DamegT = 0;
	EDamegT = 0;

	D_x = 0;
	ED_x = 0;

	D_y = 569;
	ED_y = 313;

	D_inbi = 1;
}

void CObjMap::Action()
{
	//武器が召喚されたとき、
	if (WSummon == true) {
		Cooltime++;
		if (Cooltime == 10){
			Cooltime = 0;
			WSummon = false;
		}
	}

	if (EAtackt >= 41)
	{
		EAtackt++;
		if (EAtackt >= 50) {
			EAtackt = 0;
		}
	}

	if (ESummont >= 11)
	{
		ESummont++;
		if (ESummont >= 50) {
			ESummont = 0;
		}
	}
}

void CObjMap::Draw()
{
	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	//dameg
	float dameg[4] = { 1.0f,0.0f,0.0f,D_inbi };

	if (D_x != 0)
	{
		SetPrio(100);
		//ダメージテキストの移動、透明度変更
		D_y--;
		ED_y++;
		D_inbi -= 0.01f;

		swprintf_s(str, L"%d", EDamegT);
		Font::StrDraw(str, D_x, D_y, 50, dameg);
		swprintf_s(str, L"%d", DamegT);
		Font::StrDraw(str, ED_x, ED_y, 50, dameg);
		if (D_y == 469)
		{
			SetPrio(10);
			D_x = 0;
			ED_x = 0;
			D_y = 589;
			ED_y = 313;
			D_inbi = 1;
		}
	}
}