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

		bool L_position;
		bool S_position,S_position2;
		bool R_position;
		bool m_f;

		bool Wtouch;

		//Pcard[0][i]=��l���̏��,Pcard[1][i]=�E�̖����̏��,Pcard[2][i]=���̖����̏��
		//Pcard[i][0]=HP,Pcard[i][1]=ATACK,Pcard[i][2]=Guard,Pcard[i][3]=�����X�^�[�ԍ�,Pcard[i][4]=�����HP1,Pcard[i][5]=����̃i���o�[����1,Pcard[i][6]=�����HP2,Pcard[i][7]=����̃i���o�[����2
		int PCard[3][8];//�v���C���[�̃J�[�h���

		int WPosition[6];//�v���C���[�̕���̏ꏊ���

		//�G�̃J�[�h���i���j
		int ECard[6];
		int	ECard2[6];
		int	ECard3[6];
	private:

};