#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct player{
	int hits[10][10];	// Сохранение состояний выстрелов
	int ships[10][10];	// Местоположение кораблей
	int score[5];		// Рекорды игрока (в разработке)
	int difficult; 		// 1 - обычный, 2 - продвинутый уровень сложности
} player; 

typedef enum{			// Перечисление состояний ячейки поля
	EMPTY = 0,
	SHOT,
	STRIKE,
	KILL,
	SHIP,
	COUNT
}FieldInfo;

char draw_symbol[COUNT] =  // Для отрисовки состояния поля по навзванию
{
	'~',	// EMPTY
	'*',	// SHOT
	'X',	// STRIKE
	'#',	// KILL
	'S'		// SHIP
};

#define FIELD_SIZE 10
//------- Функции для главного экрана игры -------------------------------------
void game(); 						// Начать игру
void choose_difficult(player *im);  // Выбрать сложность игры
void player_score();				// Таблица рекордов игрока
//------- Вспомогательные функции для game(); ----------------------------------
void draw_field();					// Отрисовка игрового поля

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
	draw_field();
	printf("Находится в разработке . . .\n\n");
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
