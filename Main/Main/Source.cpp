#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int a = 0;
	printf("�ǂ��炩�I�����Ă������� 1.�P���K�`�� 2.10�A�K�`��\n");
	scanf_s("%d", &a);

	while (a < 0 || a > 2) {
		printf("�ǂ��炩�I�����Ă������� 1.�P���K�`�� 2.10�A�K�`��\n");
		scanf_s("%d", &a);
	}
	if(a==1)
	{
		int i = rand() % 100 + 1;
		if (i > 0 && i <= 3) {
			printf("�s�b�N�A�b�v���o�܂���\n\n");
		}
		else if (i >= 4 && i <= 6) {
			printf("����ʂ��܂���\n\n");
		}

		else if (i >= 7 && i <= 65) {
			printf("���S�ł�\n\n");
		}
		else {
			printf("���R�ł�\n\n");
		}
	}
	else
	{
		for (int b = 0; b < 10; b++)
		{
			int i = rand() % 100 + 1;
			if (i > 0 && i <= 3) {
				printf("�s�b�N�A�b�v���o�܂���\n\n");
			}
			else if (i >= 4 && i <= 6) {
				printf("����ʂ��܂���\n\n");
			}

			else if (i >= 7 && i <= 65) {
				printf("���S�ł�\n\n");
			}
			else {
				printf("���R�ł�\n\n");
			}
		}
	}
	_getch();
	return 0;
}