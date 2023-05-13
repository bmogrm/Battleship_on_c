#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct player{
	int hits[10][10];
	int ships[10][10];
	int score[5];
	int difficult; // 1 - обычный, 2 - продвинутый уровень сложности
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
		printf("Добро пожаловая в BATTLESHIP!\n\n\tГлавное меню:\n\n1) Начать игру\n"
		"2) Сменить уровень сложности\n3) Таблица рекордов\n0) Выход\n\nВыберите желаемое действие: ");
		while (1){
			fflush(stdin);
			scanf("%d", &choose);
			if (choose >= 0 && choose <= 3)
				break;
			printf("\a\nВыберите действие от 0 до 3!\n");
		}
		switch(choose) {
			case 1: // Начать игру
				system("cls");
				game();
				break;
			case 2: // Сменить уровень сложности
				
				system("cls");
				choose_difficult(&im);
				break;	
			case 3: // Таблица рекордов
				system("cls");
				player_score();
				break;		
		}
	} while (choose != 0);

	return 0;
	
}

void game(){
	printf("Находится в разработке . . .\n\n");
	system("pause");
	system("cls");
}

void choose_difficult(player *im){
	int choose = NULL;
	printf("Выбор уровня сложности:\n\n1) Нормальный уровень сложности\n2) Продвинутый уровень сложности\n\n");
	while(1){
		printf("Ваш выбор: ");
		fflush(stdin);
		scanf("%d", &choose);
		if(choose == 1){
			printf("Вы выбрали НОРМАЛЬНЫЙ уровень сложности!\n\n");
			break;
		}
		if(choose == 2){
			printf("Вы выбрали ПРОДВИНУТЫЙ уровень сложности!\n\n");
			break;
		}
		printf("Выбранного уровня сложности не существует!\a\n\n");
	}
	im->difficult = choose;
	system("pause");
	system("cls");
}

void player_score(){
	printf("Находится в разработке . . .\n\n");
	system("pause");
	system("cls");
}
