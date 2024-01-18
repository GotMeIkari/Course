#define _CRT_SECURE_NO_WARNINGS
#include <string.h> 
#include <stdbool.h>
#include <locale.h>
#include <stdio.h>

#define ROW 6
#define COLUMN 10

int menu_organizer(int players_choice);
int choose_difficulty(int difficulty);
int* load_difficulty(int meter);

int check_row();
int check_corner();
int check_side();
int check_result();

int isFull();
int load();

int main() {
    setlocale(LC_CTYPE, "RUS");

    printf("Игра ЧИСЛОБУС\n\n");
    printf("Выберите:\n");
    printf("1 - начать игру и выбрать уровень сложности.\n");
    printf("2 - правила игры.\n");
    printf("3 - выйти из игры.\n\n");
    
    int players_choice;
    scanf("%d", &players_choice);

    menu_organizer(players_choice);
    int difficulty = menu_organizer(players_choice);
    printf("%d", difficulty);
    return 0;
}

int menu_organizer(int players_choice) {
    switch (players_choice) {
    case 1:
        printf("\nВыберите уровень сложности: ");
        printf("\n1 - Лёгкий");
        printf("\n2 - Средний");
        printf("\n3 - Сложный");
        printf("\n");

        int difficulty;
        scanf("%d", &difficulty);
        return difficulty;
    case 2:
        printf("\nЧислобус - головоломка, представляющая собой прямоугольную таблицу из девяти столбцов.\n");
        printf("В некоторых клетках уже стоят цифры от 1 до 9, остальные пусты.\n");
        printf("Для них нужно найти подходящие цифры. В нижней строке проставлены суммы для каждого столбца.\n");
        printf("Цифры в клетках касающиеся друг друга сторонами или углами должны отличаться.\n");
        printf("Также цифры не могут повторяться в строках. В столбцах повторение цифр разрешено.\n\n");

        main();
        return 0;
        break;
    case 3:
        printf("\nИгра окончена!");
        return 0;
        break;
    default:
        printf("\nВведено неправильное число!");
        return -1;
        break;
    }
}

int choose_difficulty(int difficulty) {
        switch (difficulty) {
        case 1:
            load_difficulty(1);
            return 0;
            break;
        case 2:
            load_difficulty(2);
            return 0;
            break;
        case 3:
            load_difficulty(3);
            return 0;
            break;
        default:
            printf("Ошибка! Неверно введён уровень сложности!");
            return -1;
            break;
        }
}
