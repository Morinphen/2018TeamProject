#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int i = rand() % 100 + 1;
	if (i > 0 && i <= 3) {
		printf("�s�b�N�A�b�v���o�܂���");
	}
	else if (i >= 4 && i <= 6) {
		printf("����ʂ��܂���");
	}

	else if (i >= 7 && i <= 65) {
		printf("���S�ł�");
	}
	else{
		printf("���R�ł�");
	}
	_getch();
	return 0;
}