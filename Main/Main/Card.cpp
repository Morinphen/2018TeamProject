//�V���E�X���w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Card.h"
#include"Deck.h"
#include"Cardlist.h"
#include"map.h"
#include"point.h"
#include"Window.h"
#include"GameL\Audio.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
	Number = sc->Cnanber;//�������J�[�h�̏��Ԃ̌Œ�
	Number2 = han->hand[Number -1];//�J�[�h�ԍ��̕ۑ�
	Number3 = han->basyo[Number - 1];//��D�̏��ԕϐ�

	Number4 = sc->Deck[sc->Card - 1];

	WhenEfe = false;
	PlayEfe = false;
	InduEfe = false;

	BDraw = 0;

	Opdraw = sc->Deck[sc->Card - 1];//�J�[�h�ԍ��̕ۑ�

	Updraw = 0;//�J�[�h�̕`��ʒu�̒���
	Rotdraw = 0;//�J�[�h�̉�]�`�撲��

	//�{�^���p�ϐ��̏�����
	Button = false;
	b_x = 0;
	b_y = 0;

	//�E�B���h�E�p�ϐ��̏�����
	WLcard = 0;
	WRcard = 0;
	Wcount = 0;
	WLupdraw = 0;
	WRupdraw = 0;

	Wset = false;
	LDcard = false;
	RDcard = false;

	//�X�e�[�^�X�̏�����
	Hp = 0;
	Atack = 0;
	Guard = 0;
	NTcard = 0;

	//������J�[�h�ʒu���䏉����
	CardHitCheck = false;

	//�}�E�X�Q�Ɨp�ϐ�������
	//CardHitCheck = false;

	//������J�[�h�ʒu���䏉����
	FSummon = false;
	FSummon2 = false;
	LWeapon = false;
	RWeapon = false;

	test = 1;
	//�U�������A��������������
	Punch = false;
	Pusave = false;
	Set = false;

	//�������䏉����
	StopSm = false;
	Summon = false;
	Wstop = false;
	WSetting = 0;

	Bat = 1;
	Bat2 = 1;

	m_c = true;

	Opdraw--;
	Opdraw = Opdraw / 10;

	while(Opdraw>15)
	{
		Opdraw -= 15;//x�ʒu�����炷
		Updraw++;
	}

	Tlong = 0;//�e�L�X�g�̕�����̒������Q�Ƃ���ϐ�

	m_f = false;

	Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_ENEMY, OBJ_CARD, 1);

	//float Volume = Audio::VolumeMaster(0.1f);
}

//�A�N�V����
void CObjCard::Action()
{
	m_l = Input::GetMouButtonL();
	if (m_l == false)
		m_f = false;

	CHitBox*hit = Hits::GetHitBox(this);
	CObjmouse*mou = (CObjmouse*)Objs::GetObj(OBJ_MAUSE);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);
	CObjpoint* point = (CObjpoint*)Objs::GetObj(OBJ_POINT);
	CObjwindow* window = (CObjwindow*)Objs::GetObj(OBJ_WINDOW);

	if (sc->Turn == true)
	{
		PlayEfe = false;
		Pusave = false;
	}

	//��D�̃J�[�h�ɐG�ꂽ�Ƃ�
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false && pos->Wtouch == false)
	{
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���
		Rotdraw = -3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX

		CObjPlist* PList = new CObjPlist();//�֐��Ăяo��
		PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//�J�[�h�ԍ��ɉ�����HP�ϓ�
		Hp2 = Hp;
		Atack2 = Atack;
		Guard2 = Guard;

		//�J�[�h�̖��O�ƃe�L�X�g���o��������
		Cardname();

		if (m_l == true && m_c == true)
		{
			if (pos->m_f == false && point->Cost > 0)
			{
				CObjCardlist* List = new CObjCardlist();//�֐��Ăяo��

				Cadata = NTcard;

				if (point->Cost > Ccost)
				{
					//�L�����̏ꍇ
					if (S_position == false &&
						pos->Wtouch == false &&
						Type == 1 || S_position2 == false &&
						pos->Wtouch == false &&
						Type == 1 &&
						pos->PTrun == true &&
						point->Cost > 0)
					{
						//�����̃X�y�[�X���J���Ă���ꍇ
						if (S_position == false && point->Cost > 0 && pos->PTrun == true)
						{
							m_x = 543;
							m_y = 589;

							//Hitbox���X�V���A�t�B�[���h���ł̏������ł���悤�ɂ���
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);
							//�t�B�[���h�ɃJ�[�h����o�^
							pos->PCard[1][0] = Hp;
							pos->PCard[1][1] = Atack;
							pos->PCard[1][2] = Guard;
							pos->PCard[1][3] = Number4;
							//�������ꂽ����o�^
							pos->S_position = true;
							FSummon = true;
							Summon = true;
						}

						//�����łȂ��ꍇ�A�E�ɏ���
						else if (point->Cost > 0 && pos->PTrun == true)
						{
							m_x = 951;
							m_y = 589;
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
							pos->PCard[2][0] = Hp;
							pos->PCard[2][1] = Atack;
							pos->PCard[2][2] = Guard;
							pos->PCard[2][3] = Number4;
							pos->S_position2 = true;
							FSummon2 = true;
							Summon = true;
						}

						pos->m_f = true;
						hit->SetPos(m_x, m_y);
					}

					//����̏ꍇ
					else if (Type == 2 &&
						pos->Wtouch == false ||
						Type == 3 &&
						pos->Wtouch == false &&
						pos->PTrun == true)
					{
						for (int i = 0; i < 6; i++)
						{
							//����𑕔��ł��錩��������ꍇ�A�I���ł���悤�ɂ���
							if (pos->WPosition[i] <= 0)
							{
								Wwindow(&Wset, 0);
								test = 0;
								Set = true;
								pos->Wtouch = true;
								break;
							}
						}
					}

					//����̏ꍇ
					else if (Type == 4 &&
						pos->Wtouch == false &&
						pos->PTrun == true)
					{
						Wwindow(&Wset, 0);
						test = 0;
						pos->Wtouch = true;
						Set = true;
					}

					delete PList;
				}
			}
			else
			{
				pos->m_f = false;
			}
		}
	}
	//�E�B���h�E���o�Ă��Ȃ���ԂŁA�������ꂽ�����X�^�[�ɐG�ꂽ�ꍇ
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr &&
		Summon == true &&
		Type == 1 &&
		pos->WiSummon == false)
	{
		//�J�[�h�̖��O�ƃe�L�X�g���o��������
		Cardname();

		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���

		if (Button == false)
		{
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true && pos->WSummon == false && pos->PTrun == true)
		{
			Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
			m_f = true;
			BDraw = 1;
			b_x = mou->m_mouse_x;
			b_y = mou->m_mouse_y;
		}
	}

	//�E�B���h�E���o�Ă��Ȃ���ԂŁA�������ꂽ����ɐG�ꂽ�ꍇ
	else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr &&
		Summon == true &&
		Type >= 2 &&
		pos->WiSummon == false)
	{
		//�J�[�h�̖��O�ƃe�L�X�g���o��������
		Cardname();

		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���

		if (Button == false)
		{
			Rotdraw = -3;
		}

		SetPrio(11);

		if (m_l == true && Button == false && pos->PTrun == true)
		{
			Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
			m_f = true;
			BDraw = 0;
			b_x = mou->m_mouse_x;
			b_y = mou->m_mouse_y;
		}
	}

	else
	{
		CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
		Rotdraw = 0;
		if (Button == false || Wset == false)
			SetPrio(10);
	}

	//���N���b�N���ꂽ�Ƃ��̏���
	if (m_l == true)
	{
		//��l���ɃJ�[�h���g�p���鎞�̏���
		if (mou->m_mouse_x > 550 &&
			mou->m_mouse_x < b_x + 640 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 && 
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//�J�[�h������or�h��J�[�h�̎�
			if (Type == 2 || Type == 3)
			{
				for (int i = 0; i < 2; i++)
				{
					if (pos->WPosition[i] <= 0 && Summon == false)
					{
						m_x = 700 + 97 * i;
						m_y = 462;

						//�����X�^�[�̃p�����[�^����
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//����̈ʒu�̉E�������𔻒f���A�����HP�ƃJ�[�h�����t�B�[���h�ɕۑ�
						if (i == 0)
						{
							pos->PCard[i / 2][4] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;

								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}

							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;

								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}

							LWeapon = true;
						}
						//���ʊ֐��Ăяo��
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
						//�F�����ɖ߂�
						test = 1;
						//�������������ɂ���
						Summon = true;
						//�I�����ꂽ�������ɖ߂�
						Set = false;
						pos->Wtouch = false;
						//�����������������o�^
						pos->WSummon = true;
						//����̈ʒu��ۑ����Ă���
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}
			//����̎�
			if (Type == 4)
			{
				//���ʊ֐��Ăяo��
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 1);
				Wwindow(&Wset, 1);
				//�������������ɂ���
				Summon = true;
				Audio::Start(6);
			}
		}
		//�����̃����X�^�[�ɃJ�[�h���g�p���鎞�̏���
		if (mou->m_mouse_x > 700 &&
			mou->m_mouse_x < b_x + 790 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 &&
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//�J�[�h������or�h��J�[�h�̎�
			if (Type == 2 || Type == 3)
			{
				for (int i = 2; i < 4; i++)
				{
					if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
					{
						m_x = 496 + 97 * (i - 2);
						m_y = 462;

						//�����X�^�[�̃p�����[�^����
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//����̈ʒu�̉E�������𔻒f���A�����HP�ƃJ�[�h�����t�B�[���h�ɕۑ�
						if (i - 2 == 0) {
							pos->PCard[i / 2][4] = Hp;
							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}
							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}
							LWeapon = true;
						}
						//���ʊ֐��Ăяo��
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
						//�F�����ɖ߂�
						test = 1;
						//�������������ɂ���
						Summon = true;
						//�I�����ꂽ�������ɖ߂�
						Set = false;
						pos->Wtouch = false;
						//�����������������o�^
						pos->WSummon = true;
						//����̈ʒu��ۑ����Ă���
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}
			//����̎�
			if (Type == 4)
			{
				//���ʊ֐��Ăяo��
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 2);
				Wwindow(&Wset, 1);
				//�������������ɂ���
				Summon = true;
				Audio::Start(6);
			}
		}
		//�E���̃����X�^�[�ɃJ�[�h���g�p���鎞�̏���
		if (mou->m_mouse_x > 850 &&
			mou->m_mouse_x < b_x + 940 &&
			mou->m_mouse_y > 400 &&
			mou->m_mouse_y < 520 &&
			Wset == true &&
			pos->PTrun == true &&
			Set == true &&
			point->Cost>0)
		{
			//�J�[�h������or�h��J�[�h�̎�
			if (Type == 2 || Type == 3)
			{
				for (int i = 4; i < 6; i++)
				{
					if (pos->WPosition[i] <= 0 && i > 1 && Summon == false)
					{
						m_x = 904 + 97 * (i - 4);
						m_y = 462;
						pos->PCard[i / 2][1] += Atack;
						pos->PCard[i / 2][2] += Guard;

						//����̈ʒu�̉E�������𔻒f���A�����HP�ƃJ�[�h�����t�B�[���h�ɕۑ�
						if (i - 4 == 0)
						{
							pos->PCard[i / 2][4] = Hp;
							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][5] = k;
									WSetting = k;
									break;
								}
							}
							RWeapon = true;
						}
						else
						{
							pos->PCard[i / 2][6] = Hp;

							for (int k = 1; k < 7; k++)
							{
								Wstop = false;
								for (int j = 0; j < 6; j++)
								{
									if (pos->WPosition[j] == k)
									{
										Wstop = true;
									}
								}
								if (Wstop == true)
								{
									;
								}
								else
								{
									pos->PCard[i / 2][7] = k;
									WSetting = k;
									break;
								}
							}
							LWeapon = true;
						}
						//���ʊ֐��Ăяo��
						Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
						Wwindow(&Wset, 1);
						test = 1;
						Summon = true;
						Set = false;
						pos->Wtouch = false;
						pos->WSummon = true;
						//point--;
						pos->WPosition[i] = WSetting;
						Audio::Start(6);
					}
				}
			}

			//����̎�
			if (Type == 4)
			{
				//���ʊ֐��Ăяo��
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 3);
				Wwindow(&Wset, 1);
				//�������������ɂ���
				Summon = true;
				Audio::Start(6);
			}
		}

		//���킪��������Ȃ������ꍇ���ɖ߂�
		if (Summon == false && mou->Touch == false && mou->Flee == true && Type == 2 ||
			Summon == false && mou->Touch == false && mou->Flee == true && Type == 3 ||
			Summon == false && mou->Touch == false && mou->Flee == true && Type == 4)
		{
			if (m_c == true)
			{
				if (test == 0)
				{
					Wwindow(&Wset, 1);
				}
				test = 1;
				Set = false;
				pos->Wtouch = false;
			}
		}

		if (m_f == false)
		{
			//��l���ȊO�̃L����������̎�l���ɍU���������̏���
			if (mou->EChoice == true && Punch == true && pos->PTrun == true)
			{
				//FSummon=�E���̖����A�Ⴄ�ꍇ�͍���
				if (FSummon == true && pos->PTrun == true && Bat == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[1][1] - pos->ECard[2] > 0)
					{
						pos->ECard[0] -= pos->PCard[1][1] - pos->ECard[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard[1] - pos->PCard[1][2];//�G�̍U����-���g��HP�̕������_���[�W���󂯂�
					}
					Bat = 0;
					Audio::Start(8);
				}
				else if (pos->PTrun == true && Bat2 == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[2][1] - pos->ECard[2] > 0)
					{
						pos->ECard[0] -= pos->PCard[2][1] - pos->ECard[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard[1] - pos->PCard[2][2];
					}
					Audio::Start(8);
					Bat2 = 0;
				}
				//�I���������ɖ߂�
				test = 1;
				Punch = false;
				Pusave = true;
			}

			//��l���ȊO�̃L����������̍����̃L�����ɍU���������̏���
			else if (mou->EChoice2 == true && Punch == true && pos->PTrun == true)
			{
				//FSummon=�����̖����A�Ⴄ�ꍇ�͉E��
				if (FSummon == true && Bat == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[1][1] - pos->ECard2[2] > 0)
					{
						pos->ECard2[0] -= pos->PCard[1][1] - pos->ECard2[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard2[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard2[1] - pos->PCard[1][2];
					}
					Audio::Start(8);
					Bat = 0;
				}
				else if (Bat2 == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[2][1] - pos->ECard2[2] > 0)
					{
						pos->ECard2[0] -= pos->PCard[2][1] - pos->ECard2[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard2[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard2[1] - pos->PCard[2][2];
					}
					Audio::Start(8);
					Bat2 = 0;
				}
				//�I���������ɖ߂�
				test = 1;
				Punch = false;
				Pusave = true;
			}

			//��l���ȊO�̃L����������̉E���̃L�����ɍU���������̏���
			else if (mou->EChoice3 == true && Punch == true && pos->PTrun == true)
			{
				if (FSummon == true && Bat == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][4] > 0)
					{
						pos->PCard[1][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[1][6] > 0)
					{
						pos->PCard[1][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[1][1] - pos->ECard3[2] > 0)
					{
						pos->ECard3[0] -= pos->PCard[1][1] - pos->ECard3[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard3[1] - pos->PCard[1][2] > 0)
					{
						pos->PCard[1][0] -= pos->ECard3[1] - pos->PCard[1][2];
					}
					Bat = 0;
					Audio::Start(8);
				}
				else if (Bat2 == 1)
				{
					//������������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][4] > 0)
					{
						pos->PCard[2][4] -= 1;
					}
					//�Q�ڂ̕�����������Ă����ꍇ�A�ϋv�x����
					if (pos->PCard[2][6] > 0)
					{
						pos->PCard[2][6] -= 1;
					}
					//�G��HP�����g�̍U����-�G�̎���������_���[�W��^����
					if (pos->PCard[2][1] - pos->ECard3[2] > 0)
					{
						pos->ECard3[0] -= pos->PCard[2][1] - pos->ECard3[2];
					}
					//�G�̍U����-���g�̖h��͂̕������_���[�W���󂯂�
					if (pos->ECard3[1] - pos->PCard[2][2] > 0)
					{
						pos->PCard[2][0] -= pos->ECard3[1] - pos->PCard[2][2];
					}
					Bat2 = 0;
					Audio::Start(8);
				}
				//�I���������ɖ߂�
				test = 1;
				Punch = false;
				Pusave = true;
			}
			else if (Type == 1)
			{
				test = 1;
				Punch = false;
			}
		}
		m_c = false; //�N���b�N����������
	}
	else
	{
		m_c = true; //�N���b�N����������
	}

	//�{�^���o����
	if (test == 0)
	{
		Button = false;
	}

	if (Button == true)
	{
		SetPrio(12);

		if (m_f == false)
		{
			if (m_l == true)
			{
				//�{�^�����N���b�N���ꂽ�Ƃ�
				if (mou->m_mouse_x > b_x &&
					mou->m_mouse_x < b_x + 64 &&
					mou->m_mouse_y > b_y + 16 &&
					mou->m_mouse_y < b_y + 48 &&
					Type == 1)
				{
					Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
					Button = false;
					m_f = true;

					if (Type == 1)
					{
						test = 0;
						Punch = true;
					}

					m_l = false;
				}
				else
				{
					Button = false;
				}
			}
		}
		else
		{
			m_f = false;
		}
	}

	Setcard = sc->Cnanber;//�J�[�h�̈ʒu�����ύX�p

	Posicard = Setcard - Number;//�J�[�h�̈ʒu�����ύX�p�Q

	//���݂̏ꏊ���o�����J�[�h������̏ꍇ�A�ЂƂ��炷
	if (Number3 - han->hensu3 > 0 && han->hensu > 0)
	{
		Number--;//�ԍ����P���炷
		han->hensu2++;
	}

	Number3 = han->basyo[Number - 1];//��D�̏ꏊ���X�V

	//�����X�^�[�̈ʒu�X�V
	S_position = pos->S_position;
	S_position2 = pos->S_position2;

	if (Setcard <= 5 && Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 567 + (90 * i);
			}
		}
	}
	else if (Summon == false)
	{
		for (int i = 0; i < Setcard; i++)
		{
			if (han->hand[i] == Number2)
			{
				m_x = 927 - ((450 / (Setcard))*Posicard);
			}
		}
	}

	//��D�̃J�[�h�ɐG�ꂽ�Ƃ�
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == false && pos->Wtouch == false)
	{
		CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���
		Rotdraw = -3;//�J�[�h���R����]
		SetPrio(11);//�J�[�h�̕`��D��x�ύX

		//�J�[�h�̖��O�ƃe�L�X�g���o��������
		Cardname();

		if (m_l == true)
		{
			if (pos->m_f == false && point->Cost > 0) {

				CObjCardlist* List = new CObjCardlist();//�֐��Ăяo��
				CObjPlist* PList = new CObjPlist();//�֐��Ăяo��

				PList->Action(&Name, Number4, &Ccost, &NTcard, &Hp, &Atack, &Guard, &Text);//�J�[�h�ԍ��ɉ�����HP�ϓ�
				Cadata = NTcard;

				if (point->Cost > Ccost)
				{
					//�����X�^�[�̏ꍇ
					if (S_position == false && pos->Wtouch == false && Type == 1 || S_position2 == false && pos->Wtouch == false && Type == 1 && pos->PTrun == true && point->Cost > 0)
					{
						//�����̃X�y�[�X���J���Ă���ꍇ
						if (S_position == false && point->Cost > 0 && pos->PTrun == true) {
							m_x = 543;
							m_y = 589;
							//Hitbox���X�V���A�t�B�[���h���ł̏������ł���悤�ɂ���
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER2, 1);

							//�t�B�[���h�ɃJ�[�h����o�^
							pos->PCard[1][0] = Hp;
							pos->PCard[1][1] = Atack;
							pos->PCard[1][2] = Guard;
							pos->PCard[1][3] = Number4;
							//�������ꂽ����o�^
							pos->S_position = true;
							FSummon = true;
							Summon = true;
						}

						//�����łȂ��ꍇ�A�E�ɏ���
						else if (point->Cost > 0 && pos->PTrun == true) {
							m_x = 951;
							m_y = 589;
							Hits::DeleteHitBox(this);
							Hits::SetHitBox(this, m_x, m_y, 90, 120, ELEMENT_GREEN, OBJ_FIELD_PLAYER3, 1);
							pos->PCard[2][0] = Hp;
							pos->PCard[2][1] = Atack;
							pos->PCard[2][2] = Guard;
							pos->PCard[2][3] = Number4;
							pos->S_position2 = true;
							FSummon2 = true;
							Summon = true;
						}

						pos->m_f = true;
						hit->SetPos(m_x, m_y);
					}

					//����̏ꍇ
					else if (Type == 2 && pos->Wtouch == false || Type == 3 && pos->Wtouch == false && pos->PTrun == true)
					{
						for (int i = 0; i < 6; i++) {

							//����𑕔��ł��錩��������ꍇ�A�I���ł���悤�ɂ���
							if (pos->WPosition[i] <= 0)
							{
								Wwindow(&Wset, 0);
								test = 0;
								Set = true;
								pos->Wtouch = true;
								break;
							}

						}
					}

					//����̏ꍇ
					else if (Type == 4 && pos->Wtouch == false && pos->PTrun == true)
					{
						Wwindow(&Wset, 0);
						test = 0;
						pos->Wtouch = true;
						Set = true;
					}

					m_c = false; //�N���b�N����
					delete PList;
				}
				else
				{
					m_c = true; //�N���b�N����
				}
			}
			else
			{
				pos->m_f = false;
			}
		}
	}

		//�E�B���h�E���o�Ă��Ȃ���ԂŁA�������ꂽ�����X�^�[�ɐG�ꂽ�ꍇ
		else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type == 1
			&& pos->WiSummon == false)
		{
			//�J�[�h�̖��O�ƃe�L�X�g���o��������
			Cardname();

			CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���

			if (Button == false) {
				Rotdraw = -3;
			}

			SetPrio(11);

			if (m_l == true && pos->WSummon == false && pos->PTrun == true)
			{
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
				m_f = true;
				BDraw = 1;
				b_x = mou->m_mouse_x;
				b_y = mou->m_mouse_y;
			}
		}

		//�E�B���h�E���o�Ă��Ȃ���ԂŁA�������ꂽ����ɐG�ꂽ�ꍇ
		else if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr && Summon == true && Type >= 2
			&& pos->WiSummon == false)
		{
			//�J�[�h�̖��O�ƃe�L�X�g���o��������
			Cardname();

			CardHitCheck = true; //"�}�E�X���J�[�h�ɐG��Ă���"��Ԃɂ���

			if (Button == false) {
				Rotdraw = -3;
			}

			SetPrio(11);

			if (m_l == true && Button == false && pos->PTrun == true)
			{
				Effect(Cadata, &WhenEfe, &PlayEfe, &InduEfe, 0);
				m_f = true;
				BDraw = 0;
				b_x = mou->m_mouse_x;
				b_y = mou->m_mouse_y;
			}
		}

		else
		{
			CardHitCheck = false; //"�}�E�X���J�[�h�ɐG��Ă��Ȃ�"��Ԃɂ���
			Rotdraw = 0;
			if (Button == false || Wset == false)
				SetPrio(10);
		}

		if (Wset == true)
		{
			SetPrio(21);
		}

		//�J�[�h���������ꂽ�Ƃ�
		if (Summon == true && StopSm == false)
		{
			han->hand[Number3 - 1] = 0; //�o�����J�[�h�̃J�[�h�ԍ����폜
			han->basyo[Number3 - 1] = 0; //�o�����J�[�h�̏ꏊ�����폜
			han->hensu = Setcard - Number3; //��D�̍��v�Əo�����J�[�h�̍�����ۑ�
			han->hensu3 = Number3; //�o�����J�[�h�̏ꏊ��ۑ�
			sc->Cnanber -= 1; //�J�[�h�̍��v�������P���炷
			pos->m_f = true;
			StopSm = true;
			Audio::Start(11);
			point->Cost -= Ccost;//�R�X�g����
			if (Type == 4)
			{
				Hits::DeleteHitBox(this);
				this->SetStatus(false);
			}
		}

		//�������ꂽ�����X�^�[�̏���
		if (Summon == true && Type == 1)
		{
			//�E���A�����̃����X�^�[�̃X�e�[�^�X�X�V
			if (FSummon == true)
			{
				Hp = pos->PCard[1][0];
				Atack = pos->PCard[1][1];
				Guard = pos->PCard[1][2];
			}
			else
			{
				Hp = pos->PCard[2][0];
				Atack = pos->PCard[2][1];
				Guard = pos->PCard[2][2];
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
				Audio::Start(7);
			}
		}

		//�������ꂽ����̏���
		if (Summon == true && Type == 2 || Summon == true && Type == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				//�J�[�h�̏���T���o���A�Y�������ꍇ�����J�n
				if (pos->PCard[i][5] == WSetting || pos->PCard[i][7] == WSetting)
				{
					//�E���̏ꍇ��PCard[i][4]�̒l���A�����̏ꍇ��PCard[i][6]��HP���Q�Ƃ��A�X�V����
					if (RWeapon == true)
					{
						Hp = pos->PCard[i][4];
					}
					else
					{
						Hp = pos->PCard[i][6];
					}

					//���������X�^�[������邩�A����̑ϋv���O�ɂȂ����ꍇ����
					if (pos->PCard[i][0] <= 0 || Hp <= 0)
					{
						pos->PCard[i][1] -= Atack;
						pos->PCard[i][2] -= Guard;

						if (RWeapon == true)
						{
							pos->PCard[i][4] = 0;
							RWeapon = false;
						}
						else
						{
							pos->PCard[i][6] = 0;
							LWeapon = false;
						}

						for (int j = 0; j < 6; j++)
						{
							if (pos->WPosition[j] == WSetting)
							{
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

		if (sc->Turn == true)
		{
			Bat = 1;
			Bat2 = 1;
		}

	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjCard::Draw()
{
	float c[4] = { 1.0f,test,1.0f,1.0f };

	//�����̃����X�^�[���A�e�L�X�g�̐F
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };

	float e[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�����X�^�[�̃X�e�[�^�X�̐F
	float f[4] = { 1.0f,0.0f,0.0f,1.0f };

	//����ϋv�n�̐F
	float g[4] = { 1.0f,0.0f,0.0f,1.0f };

	//������l�̐F
	float h[4] = { 1.0f,0.0f,0.0f,0.7f };

	RECT_F src;
	RECT_F dst;

	wchar_t str[128];

	src.m_top = 0.0f+ (128.0f*Updraw);
	src.m_left = 0.0f + (128.0f*Opdraw);
	src.m_right = 128.0f + (128.0f*Opdraw);
	src.m_bottom = 128.0f+ (128.0f*Updraw);

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 128.0f + m_x;
	dst.m_bottom = 128.0f + m_y;

	Draw::Draw(0, &src, &dst, c, Rotdraw);

	//��ʍ���Ɋg��摜��\��������

	if (CardHitCheck == true)
	{
		CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

		dst.m_top = 12.0f;
		dst.m_left = 12.0f;
		dst.m_right = 371.0f;
		dst.m_bottom = 371.0f;

		wchar_t atr[256];
		wchar_t aatr[5][64];
		mbstowcs(atr, pos->name, 256);//�}���`�o�C�g�����C�h�ɕϊ�
		Font::StrDraw(atr, 40, 575, 20, d);//�e�L�X�g��\��

		for (int i = 0; i * 30 < Tlong; i++)
		{
			mbstowcs(aatr[i], pos->text2[i], 64);
			Font::StrDraw(aatr[i], 40, 670 + i * 20, 20, e);
		}

		//�쐬��
		if (Type == 1)
		{
			swprintf_s(str, L"�g  �o : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, f);
			swprintf_s(str, L"�U���� : %d(%d+%d)", Atack, Atack2, Atack - Atack2);
			Font::StrDraw(str, 40, 620, 20, h);
			swprintf_s(str, L"�h��� : %d(%d+%d)", Guard, Guard2, Guard - Guard2);
			Font::StrDraw(str, 40, 640, 20, h);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"�ϋv�l : %d/%d", Hp, Hp2);
			Font::StrDraw(str, 40, 600, 20, f);
			swprintf_s(str, L"�U���� : %d", Atack);
			Font::StrDraw(str, 40, 620, 20, h);
			swprintf_s(str, L"�h��� : %d", Guard);
			Font::StrDraw(str, 40, 640, 20, h);
		}

		Draw::Draw(0, &src, &dst, d, 0);
	}

	//�{�^���̕\��
	if (Button == true)
	{
		b_x = m_x - 20.0;
		b_y = m_y + 10.0;

		src.m_top = 0.0f;
		src.m_left = 0.0f + (BDraw * 64);
		src.m_right = 64.0f + (BDraw * 64);
		src.m_bottom = 64.0f;

		dst.m_top = 0.0f + b_y;
		dst.m_left = 0.0f + b_x;
		dst.m_right = 64.0f + b_x;
		dst.m_bottom = 64.0f + b_y;

		Draw::Draw(3, &src, &dst, c, Rotdraw);
	}

	//�E�B���h�E�̕\��
	if (Wset == true)
	{
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 256.0f;
		src.m_bottom = 128.0f;

		dst.m_top = 0.0f + 400;
		dst.m_left = 0.0f + 550;
		dst.m_right = 128.0f + 550;
		dst.m_bottom = 128.0f + 400;

		Draw::Draw(0, &src, &dst, e, 0.0f);

		if (LDcard == true)
		{
			while (WLcard > 15)
			{
				WLcard -= 15;
				WLupdraw++;
			}

			src.m_top = 0.0f + (128.0f*WLupdraw);
			src.m_left = 0.0f + (128.0f*WLcard);
			src.m_right = 128.0f + (128.0f*WLcard);
			src.m_bottom = 128.0f + (128.0f*WLupdraw);

			dst.m_top = 0.0f + 400;
			dst.m_left = 0.0f + 700;
			dst.m_right = 128.0f + 700;
			dst.m_bottom = 128.0f + 400;

			Draw::Draw(0, &src, &dst, e, 0.0f);
		}

		if (RDcard == true)
		{
			while (WRcard > 15)
			{
				WRcard -= 15;
				WRupdraw++;
			}

			src.m_top = 0.0f + (128.0f*WRupdraw);
			src.m_left = 0.0f + (128.0f*WRcard);
			src.m_right = 128.0f + (128.0f*WRcard);
			src.m_bottom = 128.0f + (128.0f*WRupdraw);

			dst.m_top = 0.0f + 400;
			dst.m_left = 0.0f + 850;
			dst.m_right = 128.0f + 850;
			dst.m_bottom = 128.0f + 400;

			Draw::Draw(0, &src, &dst, e, 0.0f);
		}
	}

	if (Summon == true)
	{
		if (Type == 1)
		{
			swprintf_s(str, L"%d�@%d�@%d", Atack, Hp, Guard);
			Font::StrDraw(str, m_x + 10, m_y + 100, 20, f);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"%d�@  %d", Atack, Guard);
			Font::StrDraw(str, m_x + 15, m_y + 100, 20, h);
		}
		if (Type == 2 || Type == 3)
		{
			swprintf_s(str, L"�@ %d", Hp);
			Font::StrDraw(str, m_x + 10, m_y + 100, 20, g);
		}
	}
}

//Effect�֐�
//�J�[�h�i���o�[�A���������ʁA�N�����ʁA�U�����ʂ̕ϐ����Ԃ�����ŏ�������
//Position�͏�������Ă���J�[�h�̏ꏊ�ɂ��A����鐔�l���ς��
//��{�I�ɏ������ꂽ�����X�^�[�ȂǂɐG��Ȃ��ꍇ�͂O������
void CObjCard::Effect(float _Cnanber, bool *When, bool *Play, bool *Indu, int Position)
{
	CObjDekc*sc = (CObjDekc*)Objs::GetObj(OBJ_DEKC);
	CObjHand*han = (CObjHand*)Objs::GetObj(OBJ_HAND);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	if (_Cnanber == 21)
	{
		//�`���̌��������A�J�[�h���P���h���[
		if (*When == false)
		{
			*When = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}

		//�`���̌��𑕔����Ă���ꍇ�A�^�b�v������J�[�h���P���h���[
		else if (*Play == false && Button == true)
		{
			*Play = true;
			sc->effect = true;
			sc->Action();
			han->Action();
		}
	}

	else if (_Cnanber == 1351)
	{
		pos->PCard[Position - 1][0]+=2;
	}

	if (Button == false && PlayEfe == false && Pusave == false)
	{
		Button=true;
	}
}

//Wwindow�֐�
//_set Wset������B����ŃE�B���h�E�̃I���I�t�����߂邱�Ƃ��ł���
//_delete ���̒��ɂ�ture,false������B�E�B���h�E��������������true�����悤�B�P�ł���
void CObjCard::Wwindow(bool *_set,bool _delete)
{
	CObjwindow* window = (CObjwindow*)Objs::GetObj(OBJ_WINDOW);
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);	

	//�E�B���h�E�����݂��Ȃ��ꍇ�A�E�B���h�E�������
	if (*_set == false)
	{
		window = new CObjwindow(500, 350,Type);
		Objs::InsertObj(window, OBJ_WINDOW, 10);
		*_set = true;
		pos->WiSummon = true;

		//�����Ƀ����X�^�[������ꍇ�A�I�����ɒǉ�
		if (pos->S_position == true)
		{
			WLcard = pos->PCard[1][3] - 1;
			WLcard = WLcard / 10;
			LDcard = true;
			Wcount++;
		}

		//�����Ƀ����X�^�[������ꍇ�A�I�����ɒǉ�
		if (pos->S_position2 == true)
		{
			WRcard = pos->PCard[2][3] - 1;
			WRcard = WRcard / 10;
			RDcard = true;
			Wcount++;
		}
	}

	else
	{
		if (_delete == true)
		{
			window->Wdelete = true;
			*_set = false;
			pos->WiSummon = false;
			LDcard = false;
			RDcard = false;
			WLupdraw = 0;
			WRupdraw = 0;
			Wcount = 0;
		}
	}
}

//Cardname�֐�
//Cardname()����͂���΁A�J�[�h�ɖ��O�ƃe�L�X�g���\�������悤�ɂȂ�
void CObjCard::Cardname()
{
	CObjMap* pos = (CObjMap*)Objs::GetObj(OBJ_MAP);

	FILE *fp;
	char fname[] = "CardList.csv";
	fp = fopen(fname, "r"); // �t�@�C�����J���B���s�����NULL��Ԃ��B
	int ret;
	int aaaa;//�_�~�[�f�[�^

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%d,%[^\n] ,", pos->name, &aaaa, &TextD, &aaaa, &aaaa, &aaaa, &aaaa, text) != EOF))//���O�A�J�[�h�ԍ��A�e�L�X�g������
	{
		if (TextD == Number4)//�J�[�h�ԍ�����v�����Ƃ��A�����J�n
		{
			Tlong = strlen(text);//�e�L�X�g�̒��������߂�
			for (int j = 0; j < 6; j++)
			{
				pos->text2[j][0] = '\0';
			}
			for (int i = 0; i * 30 < Tlong; i++)//15�����Â��s���Ă���
			{
				strncpy(pos->text2[i], text + i * 30, 30);
				pos->text2[i][30] = '\0';
			}
			break;
		}
	}

	fclose(fp); // �t�@�C�������
}