//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"EnemyHand.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawFont.h"
//�g�p����l�[���X�y�[�X

//�C�j�V�����C�Y
void CObjEnemyHand::Init()
{
	hensu = 99;
	hensu2 = 0;
	hensu3 = 99;
}

//�A�N�V����
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

	if (hensu <= hensu2)//��D�����炵�I������A�����l�ɖ߂�
	{
		hensu = 99;
		hensu2 = 0;
		hensu3 = 99;
	}
}

//�h���[
void CObjEnemyHand::Draw()
{

}