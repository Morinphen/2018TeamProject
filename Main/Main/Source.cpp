#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

int main(void)
{
	srand((unsigned)time(NULL));
	int i = rand() % 100 + 1;
	if (i > 0 && i <= 3) {
		printf("ピックアップが出ました");
	}
	else if (i >= 4 && i <= 6) {
		printf("すりぬけました");
	}

	else if (i >= 7 && i <= 65) {
		printf("☆４です");
	}
	else{
		printf("☆３です");
	}
	_getch();
	return 0;
}