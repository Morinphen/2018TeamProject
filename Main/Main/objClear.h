#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjClear :public CObj
{
public:
	CObjClear() {};
	~CObjClear() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
	bool m_l;
	bool gc;
	bool BGM;
	int t_t;//top�̒l
	int t_b;//bottom�̒l
	int i, j;//������܂ł̃J�E���g�EBGM����܂ł̃J�E���g
	int cou;


};