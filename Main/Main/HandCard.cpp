//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"HandCard.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjHand::Init()
{
	hensu = 99;
}

//�A�N�V����
void CObjHand::Action()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	for (int i = 0; i < sc->Cnanber; i++)
	{
		if (hand[i] == NULL)
		{
			int hako = 0;
			hako = hand[i]-1;
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

//�h���[
void CObjHand::Draw()
{

}