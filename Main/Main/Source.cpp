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
		printf("どれか選択してください 1.単発ガチャ 2.10連ガチャ 3.やめる\n回数 %d 金額 %d\nピックアップ %d\nすりぬけ %d\n",kaisu,kane,piku,suri);
		scanf_s("%d", &a);

		while (a < 0 || a > 3) {
			printf("どれか選択してください 1.単発ガチャ 2.10連ガチャ 3.やめる\n回数 %d 金額 %d円\nピックアップ%d\nすりぬけ%d\n", kaisu,kane, piku, suri);
			scanf_s("%d", &a);
		}

		if (a == 1)
		{
			kaisu++;
			kane += 300;
			int i = rand() % 100 + 1;
			if (i > 0 && i <= 3) {
				printf("ピックアップが出ました\n\n");
				piku++;
			}
			else if (i >= 4 && i <= 6) {
				printf("すりぬけました\n\n");
				suri++;
			}

			else if (i >= 7 && i <= 65) {
				printf("☆４です\n\n");
			}
			else if (i >= 66 && i <= 100) {
				printf("☆３です\n\n");
			}
		}

		else if(a==2)
		{
			for (int b = 0; b < 10; b++) {
				kaisu++;
				kane += 300;
				int i = rand() % 100 + 1;
				if (i > 0 && i <= 3) {
					printf("ピックアップが出ました\n\n");
					piku++;
				}
				else if (i >= 4 && i <= 6) {
					printf("すりぬけました\n\n");
					suri++;
				}

				else if (i >= 7 && i <= 65) {
					printf("☆４です\n\n");
				}
				else if (i >= 66 && i <= 100) {
					printf("☆３です\n\n");
				}
			}
		}

	}
	_getch();
	return 0;
}