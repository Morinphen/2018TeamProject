#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int a = 0;
	int kane = 0;
	int kaisu = 0;
	int piku = 0;
	int suri = 0;
	for (; a !=3;)
	{
		printf("�ǂꂩ�I�����Ă������� 1.�P���K�`�� 2.10�A�K�`�� 3.��߂�\n�� %d ���z %d\n�s�b�N�A�b�v %d\n����ʂ� %d\n",kaisu,kane,piku,suri);
		scanf_s("%d", &a);

		while (a < 0 || a > 3) {
			printf("�ǂꂩ�I�����Ă������� 1.�P���K�`�� 2.10�A�K�`�� 3.��߂�\n�� %d ���z %d�~\n�s�b�N�A�b�v%d\n����ʂ�%d\n", kaisu,kane, piku, suri);
			scanf_s("%d", &a);
		}

		if (a == 1)
		{
			kaisu++;
			kane += 300;
			int i = rand() % 100 + 1;
			if (i > 0 && i <= 3) {
				printf("�s�b�N�A�b�v���o�܂���\n\n");
				piku++;
			}
			else if (i >= 4 && i <= 6) {
				printf("����ʂ��܂���\n\n");
				suri++;
			}

			else if (i >= 7 && i <= 65) {
				printf("���S�ł�\n\n");
			}
			else if (i >= 66 && i <= 100) {
				printf("���R�ł�\n\n");
			}
		}

		else if(a==2)
		{
			for (int b = 0; b < 10; b++) {
				kaisu++;
				kane += 300;
				int i = rand() % 100 + 1;
				if (i > 0 && i <= 3) {
					printf("�s�b�N�A�b�v���o�܂���\n\n");
					piku++;
				}
				else if (i >= 4 && i <= 6) {
					printf("����ʂ��܂���\n\n");
					suri++;
				}

				else if (i >= 7 && i <= 65) {
					printf("���S�ł�\n\n");
				}
				else if (i >= 66 && i <= 100) {
					printf("���R�ł�\n\n");
				}
			}
		}

	}
	_getch();
	return 0;
}