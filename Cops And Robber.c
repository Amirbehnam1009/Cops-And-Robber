#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define max 100
char Screen[max][max];
int Rows;
int Cols;
int PoliceMoves = 0;
int ThiefMoves = 0;
int Total = 0;
char temp[max][max];
char temp_k[25];
int allmoves[9][2];
void FillTempWithSpace() {
	int x, y;
	for (x = 0; x < Rows; x++)
	{
		for (y = 0; y < Cols; y++)
		{
			temp[x][y] = ' ';
		}
	}
}
int GetRand(int a)
{
	return rand() % a;
}
void GetFreeNode(int *i, int *j) {
	*i = GetRand(Rows);
	*j = GetRand(Cols);
	while (Screen[*i][*j] != ' ')
	{
		*i = GetRand(Rows);
		*j = GetRand(Cols);
	}
};
void Add_Thief() {
	int m, n;
	GetFreeNode(&m, &n);
	Screen[m][n] = 'T';
}
void Add_Police(int count, int k) {
	int i;
	for (i = 0; i < k; i++)
	{
		int a, b;
		GetFreeNode(&a, &b);
		Screen[a][b] = count +'0';
	}
}
void Print() {
	int i, j;
	printf("\n");
	for (j = 0; j < Cols; j++)
		printf("---");
	printf("\n");

	for (i = 0; i < Rows; i++)
	{
		printf("|");

      for (j = 0; j < Cols; j++)
		{
			if (Screen[i][j] == 'T') {
				printf("T |");
			}
			else if (Screen[i][j] == ' ') {
				printf("  |");
			}
			else {
				printf("D%c|", Screen[i][j]);
			}
		}
		printf("\n");
		for (j = 0; j < Cols; j++)
			printf("---");
		printf("\n");
	}
}
void FillAllMoves() {
	int i, j, k = 0;
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			allmoves[k][0] = i;
			allmoves[k][1] = j;
			k++;
		}
	}
}
int IsValid(int a, int b) {
	if (a> -1 && a < Rows)
	{
		if (b > -1 && b < Cols)
		{
				return 1;
		}
	}
	return 0;
}
void canGo(int a, int b, int *m, int *n) {
	int i, j, k = 0;
	int t = 8;
	while (t != 0)
	{
		t--;
		int r = GetRand(9);
		i = allmoves[r][0];
		j = allmoves[r][1];
		if (IsValid(a+ i, b + j) == 1 && Screen[a + i][b + j]) {
			*m = a + i;
			*n = b+ j;
			return;
		}
	}
	*m = a;
	*n = b;
	return;
}
void ThiefPosition(int *a, int *b) {
	int i, j;
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			if (Screen[i][j] == 'T') {
				*a = i;
				*b = j;
				return;
			}
		}
	}
}
void canGoToThief(int a, int b, int *m, int *n) {
	int c,d;
	ThiefPosition(&c, &d);
	int i = c - a;
	if (i <= -2)
	{
		i = -1;
	}
	if (i >= 2)
	{
		i = 1;
	}
	int j = d - b;
	if (j >= 2)
	{
		j = 1;
	}
	if (j <= -2)
	{
		j = -1;
	}
	*m =a + i;
	*n =b + j;
	return;
}
void IsNear() {
	int i, j;
	int c = 0;
	int m, n;
	ThiefPosition(&m, &n);
	for (i = -2; i <= 2; i++)
	{
		for (j = -2; j <= 2; j++)
		{
			if (i != 0 && j != 0)
				if (IsValid(m + i, n + j)==1 && Screen[m + i][n + j] != ' ')
				{
					temp_k[c] = Screen[m+ i][n + j];
					c++;
				}
		}
	}
	for (i = c; i < 25; i++)
	{
		temp_k[c] = ' ';
	}
}
int win() {
	int a,b;
	ThiefPosition(&a, &b);
	int i, j;
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if (i != 0 || j != 0)
			{
				if (IsValid(a + i, b + j))
					if (Screen[a+ i][b + j] != ' ')
					{
						return 1;
					}
			}
		}
	}
	return 0;
}
void Seocond() {
	Total++;
	int i, j, z;
	IsNear();
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			if (Screen[i][j] != ' ')
			{
				int m, n;
				canGo(i, j, &m, &n);
				if (Screen[i][j] == 'T')
					ThiefMoves++;
				else
					PoliceMoves++;
				for (z = 0; z < 25; z++)
				{
					if (temp_k[z] == Screen[i][j])
					{
						int a,b;
						canGoToThief(i, j, &a, &b);
						if (IsValid(a,b) && Screen[a][b] == ' ') {
							m = a;
							n ==b;
						}
					}
				}
				temp[m][n] = Screen[i][j];
			}
		}
	}
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			Screen[i][j] = temp[i][j];
		}
	}
	FillTempWithSpace();
}
int main() {
	printf("\nrows: "); scanf("%d", &Rows);
	printf("\ncols: "); scanf("%d", &Cols);
	int PoliceStation;
	printf("\ntedad kalantariha: "); scanf("%d", &PoliceStation);
	FillTempWithSpace();
	FillAllMoves();
	int j;
	int i;
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Cols; j++)
		{
			Screen[i][j] = ' ';
		}
	}
	for (i = 0; i < PoliceStation; i++)
	{
		int t;
		printf("\ntedad police dar kalantari shomare%d: ", (i+1));
		scanf("%d", &t);
		Add_Police(i, t);
	}
	Add_Thief();
	while (1)
	{
		system("cls");
		Seocond();
		Print();
		Sleep(1000);
		if (win() == 1)
		{
			break;
		}
	}
	system("cls");
	Print();
	printf("\nThank You For Playing! ");
	printf("\nThief Moves!: %d", ThiefMoves);
	printf("\nPolice Moves!: %d", PoliceMoves);
	printf("\nTotal Time: %d", Total );
}



