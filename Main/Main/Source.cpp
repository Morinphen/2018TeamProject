#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int a = 0;
	printf("どちらか選択してください 1.単発ガチャ 2.10連ガチャ\n");
	scanf_s("%d", &a);

	while (a < 0 || a > 2) {
		printf("どちらか選択してください 1.単発ガチャ 2.10連ガチャ\n");
		scanf_s("%d", &a);
	}
	if(a==1)
	{
		int i = rand() % 100 + 1;
		if (i > 0 && i <= 3) {
			printf("ピックアップが出ました\n\n");
		}
		else if (i >= 4 && i <= 6) {
			printf("すりぬけました\n\n");
		}

		else if (i >= 7 && i <= 65) {
			printf("☆４です\n\n");
		}
		else {
			printf("☆３です\n\n");
		}
	}
	else
	{
		for (int b = 0; b < 10; b++)
		{
			int i = rand() % 100 + 1;
			if (i > 0 && i <= 3) {
				printf("ピックアップが出ました\n\n");
			}
			else if (i >= 4 && i <= 6) {
				printf("すりぬけました\n\n");
			}

			else if (i >= 7 && i <= 65) {
				printf("☆４です\n\n");
			}
			else {
				printf("☆３です\n\n");
			}
		}
	}
	_getch();
	return 0;
}