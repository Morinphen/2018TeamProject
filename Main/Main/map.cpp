//使用するヘッダーファイル
#include"GameHead.h"
#include"map.h"

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

	EAtackt = 0;

	m_f = false;
	Wtouch = false;
	PTrun = false;
	WSummon = false;
	Cooltime = 0;
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
}

void CObjMap::Draw()
{

}