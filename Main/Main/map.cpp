//�g�p����w�b�_�[�t�@�C��
#include"GameHead.h"
#include"map.h"

//�g�p����l�[���X�y�[�X
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
	//���킪�������ꂽ�Ƃ��A
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