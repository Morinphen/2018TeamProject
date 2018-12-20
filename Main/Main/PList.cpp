//使用するヘッダーファイル
#include"PList.h"
#include"GameHead.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define N 256;

//使用するネームスペース
using namespace GameL;

typedef struct str {
	char yomi[256];
	float f_data[5];
} data;

void CObjPlist::Init()
{
	/*FILE *fp;
	char fname[] = "CardList.csv";
	int ret;
	char line[256];
	char str1[256];
	char str2[256];
	float a, b, c, d;
	float f1, f2, f3, f4;
	int i = 0;

	data data[5];*/
}

char* CObjPlist::Action(char **name, int type, int *nanber, int *hp, int *atack, int *guard, char **text)
{
	FILE *fp;
	char fname[] = "CardList.csv";
	int ret;
	char line[256];
	char str1[256];
	char str2[256];
	int a, b, c, d, e;
	float f1, f2, f3, f4;
	int i = 0;
	fp = fopen(fname, "r"); // ファイルを開く。失敗するとNULLを返す。

	while ((ret = fscanf(fp, "%[^,],%d,%d,%d,%d,%d,%[^\n] ,", str1, &a, &b, hp, atack, guard, str2) != EOF))//名前、カード番号、コスト、体力、攻撃力、防御力、テキストを入れる
	{
		if (a == type)
		{
			*name = str1;
			*text = str2;
			break;
		}
	}

	fclose(fp); // ファイルを閉じる
	return str1;
}

void CObjPlist::Draw()
{

}