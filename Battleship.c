#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct player{
	int hits[10][10];	// ���������� ��������� ���������
	int ships[10][10];	// �������������� ��������
	int score[5];		// ������� ������ (� ����������)
	int difficult; 		// 1 - �������, 2 - ����������� ������� ���������
} player; 

typedef enum{			// ������������ ��������� ������ ����
	EMPTY = 0,
	SHOT,
	STRIKE,
	KILL,
	SHIP,
	COUNT
}FieldInfo;

char draw_symbol[COUNT] =  // ��� ��������� ��������� ���� �� ���������
{
	'~',	// EMPTY
	'*',	// SHOT
	'X',	// STRIKE
	'#',	// KILL
	'S'		// SHIP
};

#define FIELD_SIZE 10
//------- ������� ��� �������� ������ ���� -------------------------------------
void game(); 						// ������ ����
void choose_difficult(player *im);  // ������� ��������� ����
void player_score();				// ������� �������� ������
//------- ��������������� ������� ��� game(); ----------------------------------
void draw_field();					// ��������� �������� ����

int main(){
	system("chcp 1251 > nul");
	int choose = 0;
	
	player im;
	
	printf(">>>>>------------------------------<<<<<\n\n");
	printf("\t\tBATTLESHIP\n\n");
	printf(">>>>>------------------------------<<<<<\n\n");
	
	do {
		printf("����� ��������� � BATTLESHIP!\n\n\t������� ����:\n\n1) ������ ����\n"
		"2) ������� ������� ���������\n3) ������� ��������\n0) �����\n\n�������� �������� ��������: ");
		while (1){
			fflush(stdin);
			scanf("%d", &choose);
			if (choose >= 0 && choose <= 3)
				break;
			printf("\a\n�������� �������� �� 0 �� 3!\n");
		}
		switch(choose) {
			case 1: // ������ ����
				system("cls");
				game();
				break;
			case 2: // ������� ������� ���������
				
				system("cls");
				choose_difficult(&im);
				break;	
			case 3: // ������� ��������
				system("cls");
				player_score();
				break;		
		}
	} while (choose != 0);

	return 0;
	
}

void game(){
	draw_field();
	printf("��������� � ���������� . . .\n\n");
	system("pause");
	system("cls");
}
   
char *field[] = 
{
	"  ABCDIFGHKL        ABCDIFGHKL ",
    " *----------*      *----------*",
    "0|          |     0|          |",
    "1|          |     1|          |",
    "2|          |     2|          |",
    "3|          |     3|          |",
    "4|          |     4|          |",
    "5|          |     5|          |",
    "6|          |     6|          |",
    "7|          |     7|          |",
    "8|          |     8|          |",
    "9|          |     9|          |",
    " *----------*      *----------*"
	
};

void draw_field(){
	int i = 0, j = 0;
	printf("%s\n", field[0]);
	printf("%s\n", field[1]);
	for(i = 2; i < FIELD_SIZE+2; i++)
	{
		printf("%c%c", field[i][0], field[i][1]);
		for(j = 0; j < FIELD_SIZE; j++)
		{
			printf("%c", draw_symbol[EMPTY]);
		}
		printf("%c     ", field[i][12]);
		printf("%c%c", field[i][18], field[i][19]);
		for(j = 0; j < FIELD_SIZE; j++)
		{
			printf("%c", draw_symbol[EMPTY]);
		}
		printf("%c\n", field[i][30]);
	}
	printf("%s\n", field[12]);
}

void choose_difficult(player *im){
	int choose = NULL;
	printf("����� ������ ���������:\n\n1) ���������� ������� ���������\n2) ����������� ������� ���������\n\n");
	while(1){
		printf("��� �����: ");
		fflush(stdin);
		scanf("%d", &choose);
		if(choose == 1){
			printf("�� ������� ���������� ������� ���������!\n\n");
			break;
		}
		if(choose == 2){
			printf("�� ������� ����������� ������� ���������!\n\n");
			break;
		}
		printf("���������� ������ ��������� �� ����������!\a\n\n");
	}
	im->difficult = choose;
	system("pause");
	system("cls");
}

void player_score(){
	printf("��������� � ���������� . . .\n\n");
	system("pause");
	system("cls");
}
