//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"

#include"Cardlist.h"

#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
CObjCard::CObjCard(float x,float y,int z)
{
	m_x = x;
	m_y = y;
	Type = z;//�J�[�h�̎�ނɂ���ă^�C�v��ς���
}

//�C�j�V�����C�Y
void CObjCard::Init()
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	Nanber = sc->Cnanber;//�������J�[�h�̏��Ԃ̌Œ�
	Nanber2 = han->hand[Nanber-1];//�J�[�h�ԍ��̕ۑ�
	Nanber3 = han->basyo[Nanber - 1];//��D�̏��ԕϐ�
	Nanber4 = sc->Card;

	Opdraw = sc->Card;//�J�[�h�ԍ��̕ۑ�
	Updraw = 0;//�J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//�J�[�h�̉�]�`�撲��

	//�X�e�[�^�X�̏�����
	Hp = 0;
	Atack = 0;
	Guard = 0;

	//�X�e�[�^�X�̎�@�O��HP���A�P�ōU���͂��A�Q�Ŏ���͂��J�[�h���ƂɎQ�Ƃł���
	SeedHp = 0;
	SeedAtack = 1;
	SeedGuard = 2;

	//������J�[�h�ʒu���䏉����
	CardHitCheck = false;

	FSummon = false;
	FSummon2 = false;
	LWeapon = false;
	RWeapon = false;

	test = 1;
	//�U�������A��������������
	Punch = false;
	Set = false;

	//�������䏉����
	StopSm = false;
	Summon = false;

	while(Opdraw>7)
	{
		Opdraw -= 7;//x�ʒu�����炷
		Updraw++;
	}
	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_CARD, OBJ_CARD, 1);
}

//�A�N�V����
void CObjCard::Action()
{
	m_l = Input::GetMouButtonL();
	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	//���N���b�N���ꂽ�Ƃ�
	if (m_l == true)
	{
		//�E���̃����X�^�[�ɐG��Ă���Ƃ�����𑕔�������
		if (mou->Choice[1] == 1 && Set == true) {

			for (int i = 2; i < 4; i++) {
				if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
				{

					m_x = 498 + 90 * (i - 2);

					m_y = 466;
					//�����X�^�[�̃p�����[�^����
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					//����̈ʒu�̉E�������𔻒f���A�����HP�ƃJ�[�h����ۑ�
					if (i - 2 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Nanber4;
						RWeapon = true;
					}
					else {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Nanber4;
						LWeapon = true;
					}

					//�F�����ɖ߂�
					test = 1;
					//�������������ɂ���
					Summon = true;
					//�I�����ꂽ�������ɖ߂�
					Set = false;
					//����̈ʒu��ۑ����Ă���
					pos->WPosition[i] = Nanber4;
				}

			}

		}
		//�����̃����X�^�[�ɐG��Ă���Ƃ�����𑕔�������
		if (mou->Choice[2] == 1 && Set == true){
			for (int i = 4; i < 6; i++) {
				if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
				{

					m_x = 906 + 90 * (i - 4);

					m_y = 466;
					pos->PCard[i / 2][1] += Atack;
					pos->PCard[i / 2][2] += Guard;

					if (i - 4 == 0) {
						pos->PCard[i / 2][4] = Hp;
						pos->PCard[i / 2][5] = Nanber4;
						RWeapon = true;
					}
					else  {
						pos->PCard[i / 2][6] = Hp;
						pos->PCard[i / 2][7] = Nanber4;
						LWeapon = true;
					}

					test = 1;
					Summon = true;
					Set = false;
					pos->WPosition[i] = Nanber4;
				}

			}

		}
		//���킪��������Ȃ������ꍇ���ɖ߂�
		if (Summon == false && Type == 2 || Type == 3)
		{
			test = 1;
			Set = false;
		}

		//�����X�^�[���G�ɍU�������Ƃ�
		if(mou->EChoice==true && Punch==true)
		{
			//FSummon=�E���̖����A�Ⴄ�ꍇ�͍���
			if (FSummon == true) {
				pos->ECard[0] -= pos->PCard[1][1] - pos->ECard[2];//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
				pos->PCard[1][0] -= pos->ECard[1] - pos->PCard[1][2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�
			}
			else
			{
				pos->ECard[0] -= pos->PCard[2][1] - pos->ECard[2];
				pos->PCard[2][0] -= pos->ECard[1] - pos->PCard[2][2];
			}
			//�I���������ɖ߂�
			test = 1;
			Punch = false;
		}

		else if (mou->EChoice2 == true && Punch == true)
		{
			if (FSummon == true) {
				pos->ECard2[0] -= pos->PCard[1][1] - pos->ECard2[2];
				pos->PCard[1][0] -= pos->ECard2[1] - pos->PCard[1][2];
			}
			else
			{
				pos->ECard2[0] -= pos->PCard[2][1] - pos->ECard2[2];
				pos->PCard[2][0] -= pos->ECard2[1] - pos->PCard[2][2];
			}
			test = 1;
			Punch = false;
		}

		else if (mou->EChoice3 == true && Punch == true)
		{
			if (FSummon == true) {
				pos->ECard3[0] -= pos->PCard[1][1] - pos->ECard3[2];
				pos->PCard[1][0] -= pos->ECard3[1] - pos->PCard[1][2];
			}
			else
			{
				pos->ECard3[0] -= pos->PCard[2][1] - pos->ECard3[2];
				pos->PCard[2][0] -= pos->ECard3[1] - pos->PCard[2][2];
			}
			test = 1;
			Punch = false;
		}

		else
		{
			test = 1;
			Punch = false;
		}

	}

	Setcard = sc->Cnanber;//�J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Nanber;//�J�[�h�̈ʒu�����ύX�p�Q
	/*if (Nanber - Reset > 0 && Reset != 0 && Reset > 0)
	{
		Reflag = true;
		han->hensu -= 1;
	}

	if (Reflag == true)
	{
		Nanber3 = Nanber3;
		Nanber--;
		Reflag = false;
	}*/

	if (Nanber3 - han->hensu3 > 0 && han->hensu>0)//���݂̏ꏊ���o�����J�[�h������̏ꍇ�A�ЂƂ��炷
	{
		Nanber--;//�ԍ����P���炷
		han->hensu2++;
	}

	Nanber3 = han->basyo[Nanber - 1];//��D�̏ꏊ���X�V

	L_position = pos->L_position;

	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	R_position = pos->R_position;
	
	if(Setcard <=5 && Summon == false)
	{
		//m_x = 250+(90* Posicard);
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 927 - (90 * i);
			}
		}
	}

	else if(Summon == false){
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Nanber2)
			{
				m_x = 927 - ((450 / (Setcard))*Posicard);
			}
		}
	}

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false)
	{
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���
		Rotdraw = 3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX
		if (m_l == true)
		{
			if (pos->m_f == false) {
				CObjCardlist* List = new CObjCardlist();//�֐��Ăяo��

				/*if (L_position == false && Type == 2)
				{
					Atack = List->Action(Type, Nanber, Atack);//�J�[�h�ԍ��ɉ����čU���͕ϓ�
					m_x = 543;
					m_y = 586;

					pos->L_position = true;

					delete List;
					hit->SetPos(m_x, m_y);
				}*/

				//�����X�^�[�̏ꍇ
				if (S_position == false && Type == 1 || S_position2 == false && Type == 1)
				{
					Hp = List->Action(Type, Nanber, SeedHp);//�J�[�h�ԍ��ɉ�����HP�ϓ�
					Atack = List->Action(Type,Nanber, SeedAtack);//�J�[�h�ԍ��ɉ����čU���͕ϓ�
					Guard = List->Action(Type, Nanber, SeedGuard);//�J�[�h�ԍ��ɉ����Ėh��͕ϓ�

					//�����̃X�y�[�X���J���Ă���ꍇ
					if (S_position == false) {
						m_x = 543;
						m_y = 586;
						//Hitbox���X�V���A�t�B�[���h���ł̏������ł���悤�ɂ���
						Hits::DeleteHitBox(this);
						Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);

						//�t�B�[���h�ɃJ�[�h����o�^
						pos->PCard[1][0] = Hp;
						pos->PCard[1][1] = Atack;
						pos->PCard[1][2] = Guard;
						//�������ꂽ����o�^
						pos->S_position = true;
						FSummon = true;
						Summon = true;
					}
					//�����łȂ��ꍇ�A�E�ɏ���
					else {
						m_x = 951;
						m_y = 586;
						Hits::DeleteHitBox(this);
						Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
						pos->PCard[2][0] = Hp;
						pos->PCard[2][1] = Atack;
						pos->PCard[2][2] = Guard;
						pos->S_position2 = true;
						FSummon2 = true;
						Summon = true;
					}

					delete List;
					hit->SetPos(m_x, m_y);
				}

				//����̏ꍇ
				else if (Type==2 || Type==3)
				{
					for (int i = 0; i < 6; i++) {

						//����𑕔��ł��錩��������ꍇ�A�I���ł���悤�ɂ���
						if (pos->WPosition[i]<=0)
						{
							test = 0;
							Set = true;
							break;
						}

					}

					Hp = List->Action(Type, Nanber, SeedHp);//�J�[�h�ԍ��ɉ�����HP�ϓ�
					Atack = List->Action(Type,Nanber, SeedAtack);//�J�[�h�ԍ��ɉ����čU���͕ϓ�
					Guard = List->Action(Type, Nanber, SeedGuard);//�J�[�h�ԍ��ɉ����Ď���͕ϓ�

					delete List;
				}

			}
		}

		else
		{
			pos->m_f = false;
		}
	}

	//�������ꂽ�����X�^�[�ɐG�ꂽ�ꍇ
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type==1)
	{
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = -3;
		SetPrio(11);
		if (m_l == true)
		{
			test = 0;
			Punch = true;
		}
	}
	else
	{
		CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = 0;
		SetPrio(10);
	}

	//�J�[�h���������ꂽ�Ƃ�
	if (Summon == true && StopSm==false) {
		han->hand[Nanber3 - 1] = 0;//�o�����J�[�h�̃J�[�h�ԍ����폜
		han->basyo[Nanber3 - 1] = 0;//�o�����J�[�h�̏ꏊ�����폜
		han->hensu = Setcard - Nanber3;//��D�̍��v�Əo�����J�[�h�̍�����ۑ�
		han->hensu3 = Nanber3;//�o�����J�[�h�̏ꏊ��ۑ�
		sc->Cnanber -= 1;//�J�[�h�̍��v�������P���炷
		pos->m_f = true;
		StopSm = true;
	}

	//�������ꂽ�����X�^�[�̏���
	if (Summon == true && Type==1)
	{
		//�E���A�����̃����X�^�[��HP�X�V
		if (FSummon == true)
		{
			Hp = pos->PCard[1][0];
		}
		else
		{
			Hp = pos->PCard[2][0];
		}

		//HP���O�ɂȂ����ꍇ�A�ʒu�����X�V���A����
		if (Hp <= 0)
		{
			if (FSummon == true)
			{
				pos->S_position = false;
				FSummon = false;
			}
			else
			{
				pos->S_position2 = false;
				FSummon2 = false;
			}

			Hits::DeleteHitBox(this);
			this->SetStatus(false);
		}
	}

	//�������ꂽ����̏���
	if (Summon == true && Type == 2||Type==3)
	{
		for (int i = 0; i < 3; i++)
		{
			//�J�[�h�̏���T���o���A�Y�������ꍇ�����J�n
			if (pos->PCard[i][5] == Nanber4 || pos->PCard[i][7] == Nanber4) {
				//�E���̏ꍇ��PCard[i][4]�̒l���A�����̏ꍇ��PCard[i][6]��HP���Q�Ƃ��A�X�V����
				if(RWeapon==true)
					Hp = pos->PCard[i][4];
				else
					Hp = pos->PCard[i][6];

				//���������X�^�[������邩�A����̑ϋv���O�ɂȂ����ꍇ����
				if (pos->PCard[i][0] <=0 || Hp==0)
				{
					pos->PCard[i][1] -= Atack;
					pos->PCard[i][2] -= Guard;
					pos->PCard[i][4] = 0;
					pos->PCard[i][5] = 0;

					for (int j = 0; j < 6; j++) {
						if (pos->WPosition[j] == Nanber4) {
							pos->WPosition[j] = 0;
							break;
						}
					}

					Hits::DeleteHitBox(this);
					this->SetStatus(false);
				}
			}
		}
	}

	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjCard::Draw()
{

	float c[4] = { 1.0f,test,1.0f,1.0f };
	float d[4] = { 1.0f,0.0f,0.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f+ (64.0f*Updraw);
	src.m_left = 0.0f + (64.0f*Opdraw);
	src.m_right = 64.0f + (64.0f*Opdraw);
	src.m_bottom = 64.0f+ (64.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 90.0f + m_x;
	dst.m_bottom = 120.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);
	
	//��ʍ���Ɋg��摜��\��������
	
	if (CardHitCheck == true)
	{

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}
	else
	{
		
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 12.0f;
		dst.m_left = 13.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 491.0f;

		Draw::Draw(0, &src, &dst, c, 0);
	}

	

	if (Summon == true) {
		wchar_t str[128];
		swprintf_s(str, L"%d�@%d�@%d", Atack, Hp, Guard);
		Font::StrDraw(str, m_x + 10, m_y + 100, 20, d);
	}
}