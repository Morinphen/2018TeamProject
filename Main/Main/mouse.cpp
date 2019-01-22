//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\HitBoxManager.h"
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"mouse.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjmouse::Init()
{
	m_r = false;
	m_f = false;

	EChoice = false;
	Flee = true;

	m_mouse_x = 0.0f;//�}�E�X��X���W
	m_mouse_y = 0.0f;//�}�E�X��Y���W

	//�����蔻��쐬
	Hits::SetHitBox(this, m_mouse_x, m_mouse_y, 2, 2, ELEMENT_PLAYER, OBJ_PLAYER, 1);
	
}

//�A�N�V����
void CObjmouse::Action()
{
	m_r = Input::GetMouButtonR();

	//�}�E�X���W�擾
	m_mouse_x =(float) Input::GetPosX();
	m_mouse_y =(float) Input::GetPosY();

	//�����蔻��X�V
	CHitBox*hit = Hits::GetHitBox(this);

	//��D�̃J�[�h�ɐG�ꂽ�Ƃ�
	if (hit->CheckObjNameHit(OBJ_CARD) != nullptr)
	{
		Touch = true;
		Flee = false;
	}

	//��l���ɐG�ꂽ�Ƃ�
	else if (hit->CheckObjNameHit(OBJ_FIELD_PLAYER) != nullptr)
	{
		Choice[0] = 1;
		Flee = false;
	}

	//�E���̖����ɐG�ꂽ�Ƃ�
	else if (hit->CheckObjNameHit(OBJ_FIELD_PLAYER2) != nullptr)
	{
		Choice[1] = 1;
		Flee = false;
	}
	//�����̖����ɐG�ꂽ�Ƃ�
	else if (hit->CheckObjNameHit(OBJ_FIELD_PLAYER3) != nullptr)
	{
		Choice[2] = 1;
		Flee = false;
	}

	//�G�ɐG�ꂽ�Ƃ�
	else if (hit->CheckObjNameHit(OBJ_FIELD_ENEMY) != nullptr)
	{
		EChoice = true;
		Flee = false;
	}

	else if (hit->CheckObjNameHit(OBJ_FIELD_ENEMY2) != nullptr)
	{
		EChoice2 = true;
		Flee = false;
	}

	else if (hit->CheckObjNameHit(OBJ_FIELD_ENEMY3) != nullptr)
	{
		EChoice3 = true;
		Flee = false;
	}

	//�ǂ���Y�����Ȃ��ꍇ�A���ׂĂO�ɂ��Ă���
	else
	{
		Touch = false;
		Choice[0] = 0;
		Choice[1] = 0;
		Choice[2] = 0;
		EChoice = false;
		EChoice2 = false;
		EChoice3 = false;
		Flee = true;
	}

	hit->SetPos(m_mouse_x, m_mouse_y);
}

//�h���[
void CObjmouse::Draw()
{
	//�F
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//----------------------------------------------------
	//�}�E�X���W�̒l�`��(�e�X�g�p�Ȃ̂ł̂��ɏ����\��)
	wchar_t str[128];
	swprintf_s(str, L"x:%f", m_mouse_x);
	Font::StrDraw(str,100,100,20,c);

	swprintf_s(str, L"y:%f", m_mouse_y);
	Font::StrDraw(str, 100, 120, 20, c);

	//----------------------------------------------------


	//----------------------------------------------------
	//�|�C���^�`��
	//�J�[�h�̑傫���͉��R�A�c�S�ɂ���
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_mouse_y;
	dst.m_left = 0.0f + m_mouse_x;
	dst.m_right = dst.m_left + 32.0f;
	dst.m_bottom = dst.m_top + 32.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}