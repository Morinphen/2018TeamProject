#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�}�b�v
class CObjMap : public CObj
{
	public:
		CObjMap() {};
		~CObjMap() {};
		void Init();
		void Action();
		void Draw();

		//��Ƀ����X�^�[���o�Ă��邩���f����ϐ�
		bool S_position, S_position2;

		bool ES_position, ES_position2;

		bool L_position;
		bool R_position;

		bool m_f;

		bool PTrun;

		//�E�B���h�E���o�Ă��邩���f����ϐ�
		bool WiSummon;

		//�J�[�h�e�L�X�g�\���p������
		char name[256];
		char text2[5][64];

		bool Wtouch;//���킪�N���b�N���ꂽ�Ƃ��A�I���ɂȂ�

		bool WSummon;//���킪�������ꂽ�Ƃ��A�I���ɂȂ�
		int Cooltime;//�l�X�ȕ����������ꂽ�Ƃ��Ɏg�p����N�[���^�C���p�ϐ�

		//Pcard[0][i]=��l���̏��,Pcard[1][i]=�E�̖����̏��,Pcard[2][i]=���̖����̏��
		//Pcard[i][0]=HP,Pcard[i][1]=ATACK,Pcard[i][2]=Guard,Pcard[i][3]=�����X�^�[�ԍ�,Pcard[i][4]=�����HP1,Pcard[i][5]=����̃i���o�[����1,Pcard[i][6]=�����HP2,Pcard[i][7]=����̃i���o�[����2
		int PCard[3][8];//�v���C���[�̃J�[�h���

		int WPosition[6];//�v���C���[�̕���̏ꏊ���

		//�G�̃J�[�h���i���j
		int ECard[8];
		int	ECard2[8];
		int	ECard3[8];

		int EAtackt;
	private:

};