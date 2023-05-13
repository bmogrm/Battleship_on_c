#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct player{
	int hits[10][10];
	int ships[10][10];
	int score[5];
	int difficult; // 1 - �������, 2 - ����������� ������� ���������
} player; 

void game();
void choose_difficult(player *im);
void player_score();

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
	printf("��������� � ���������� . . .\n\n");
	system("pause");
	system("cls");
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
