//使用するヘッダーファイル
#include"GameHead.h"
#include"map.h"

//使用するネームスペース
using namespace GameL;

void CObjMap::Init()
{
	L_position = false;

	S_position = false;
	S_position2 = false;

	R_position = false;

	m_f = false;
	Wtouch = false;
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
}

void CObjMap::Draw()
{
	
}