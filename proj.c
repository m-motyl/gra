#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>

void moveBall(bool, bool, int*, int*);
void bounce(int t[][50],bool*, bool*, int, int, int*);
void show(int t[][50], int n);
char getch();

int main()
{
	int field[20][50] = {
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1} };
	int padX = 24, padX2 = 25, padX3 = 26;
	int padY = 17, padY2 = 17, padY3 = 17;

	int ballX = 25;
	int ballY = 10;

	bool moveUD = false;
	bool moveRL = false;
	
	int score = 0;
	char c;
	char username[20];

	do
	{
		system("clear");
		printf("STEROWANIE : a, d\nKONIEC GRY : x\n");
		show(field, 20);
		
		field[ballY][ballX] = 0;

		moveBall(moveRL, moveUD, &ballY, &ballX);
		bounce(field, &moveRL, &moveUD, ballY, ballX, &score);

		field[ballY][ballX] = 5;

		c = getch();
		
		field[padY][padX]   = 0;
		field[padY2][padX2] = 0;
		field[padY3][padX3] = 0;

		switch (c)
		{
			 case 'a': 
				if (field[padY][padX - 1] == 0){
					padX--;
					padX2--;
					padX3--;
				}
				break;
			 case 'd':
				if (field[padY3][padX3 + 1] == 0){
					padX++;
					padX2++;
					padX3++;
				}
				break;
		}

		field[padY][padX]   = 3;
		field[padY2][padX2] = 3;
		field[padY3][padX3] = 3;

	if(field[ballY + 1][ballX] == 4)
	    break;
	} while (c != 'x');

	printf("\nKONIEC GRY\n");
	printf("TWOJ WYNIK : %d\n", score);
	sleep(1);

	printf("ZAPISAC WYNIK? t|n ");
	c = getch();
	printf("\n");
	switch (c)
	{
		case 't':{
				FILE *plik;
				if((plik = fopen("wyniki.txt", "a+")) == NULL)
				{
					printf("COS POSZLO NIE TAK\n");
					exit(1);	
				}
				printf("NAZWA UZYTKOWNIKA: ");
				scanf("%s", username);
				fprintf(plik, "%s %d\n", username, score);
				fclose(plik);
				printf("ZAPISANO!\n"); break;
			}
		case 'n':
			printf("NIE ZAPISANO!\n"); break;
	}
	return 0;
}

void show(int t[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < 50; j++)
			switch(t[i][j])
			{
				case 0: printf(" "); break;
				case 1: printf("|"); break;
				case 2: printf("_"); break;
				case 3: printf("-"); break;
				case 4: printf("_"); break;
				case 5: printf("x"); break;
			}
		printf("\n");
	}
	return;
}

char getch()
{
	system("/bin/stty raw");
	char ret = getchar();
	system("/bin/stty cooked");
	return ret;
}


void moveBall(bool moveRL, bool moveUD, int *ballY, int *ballX)
{

	if(moveRL == true && moveUD == true){
		(*ballY)++;		
		(*ballX)++;
	}
	else if(moveRL == true && moveUD == false){
    		(*ballY)--;
	        (*ballX)++;
	}
	else if(moveRL == false && moveUD == true){
		(*ballY)++;
		(*ballX)--;
	}
	else if (moveRL == false && moveUD == false){
		(*ballY)--;
		(*ballX)--;
	}
	return;
}


void bounce(int t[][50],bool *moveRL, bool *moveUD, int ballY, int ballX, int *score)
{
	if(t[ballY - 1][ballX] == 2){
		*moveUD = true;
	}
	if(t[ballY][ballX] == 3){
		*moveUD = false;
		(*score)++;
	}
	if(t[ballY][ballX - 1] == 1 || t[ballY][ballX + 1] == 1){
		if(*moveRL == false)
			*moveRL = true;
		else
			*moveRL = false;
	}
	return;
}
