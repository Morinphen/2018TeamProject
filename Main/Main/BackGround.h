#pragma once

#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�o�b�N�O���E���h(���̐��g)
class CObjBackGround : public CObj
{
public:
	CObjBackGround() {};
	~CObjBackGround() {};
	void Init();
	void Action();
	void Draw();

private:

};

//�I�u�W�F�N�g�F�o�b�N�O���E���h2(���̃u���b�N�w�i)
class CObjBackGround2: public CObj
{
public:
	CObjBackGround2() {};
	~CObjBackGround2() {};
	void Init();
	void Action();
	void Draw();

private:

};

//�I�u�W�F�N�g�F�o�b�N�O���E���h3(�E�̓��������K�w�i)
class CObjBackGround3 : public CObj
{
public:
	CObjBackGround3() {};
	~CObjBackGround3() {};
	void Init();
	void Action();
	void Draw();

	int Position[30][26]; //�����w�i�̈ʒu�ϐ�
	int time;
private:

};