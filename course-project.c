#define _CRT_SECURE_NO_WARNINGS

#include <string.h> 
#include <stdbool.h>
#include <locale.h>
#include <stdio.h>
/*подключаемые заголовочные файлы*/
#define ROW 6
#define COL 10
/*константы для настройки работы приложения*/

int load_file(int array[ROW - 1][COL]);
void draw_screen(int game_tablet[ROW][COL], int, int);
void answer_peak(int gametablet[ROW][COL]);

void finish_flag_easy();
void finish_flag_normal();
void finish_flag_hard();

void choose_path();
void menu_peak();

int main()
{
    setlocale(LC_ALL, "RUS");
    menu_peak();
}


void draw_screen(int game_tablet[ROW][COL], int height, int width) {

    for (int c = 0; c < width; c++) {
        printf("  X%d ", c);
    }
    printf("\n");

    for (int i = 0; i < height; ++i) {
        printf("___________________________________________________");
        printf("\n");

        for (int j = 0; j < width; j++) {
            printf("| %2d ", game_tablet[i][j]);
        }
        printf("|");

        if (i < 5) {
            printf(" Y%d ", i);
        }

        printf("\n");
    }
}

int load_file(int array[ROW - 1][COL]) {

    int task_num = 1;
    char fname[10];

    sprintf(fname, "%d", task_num);

    FILE* pf;
    pf = fopen(strcat(fname, ".txt"), "r");

    if (pf == NULL) {
        printf("Ошибка при открытии файла\n");
        return -1;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
            fscanf(pf, "%d ", &array[i][j]);
    }
    fclose(pf);
    return 0;
}

void answer_peak(int gametablet[ROW][COL]) {
    int cord_i, cord_j, rez_num;
    int checker_array[ROW - 1][COL];
    load_file(checker_array);

    printf("\n");
    printf("Выберите координату X (0-9): ");
    scanf("%d", &cord_j);
    getchar();

    printf("Выберите координату Y (0-4): ");
    scanf("%d", &cord_i);
    getchar();

    switch (cord_i)
    {
    case 0:
        printf("Выберите число, которое хотите вставить: ");
        scanf("%d", &rez_num);
        getchar();
        if (rez_num == checker_array[cord_i][cord_j]) {
            gametablet[cord_i][cord_j] = rez_num;
        }
        else {
            printf("Число неверное, попробуйте ещё раз!\n\n");
        }
        break;

    case 1:
        printf("Выберите число, которое хотите вставить: ");
        scanf("%d", &rez_num);
        getchar();
        if (rez_num == checker_array[cord_i][cord_j]) {
            gametablet[cord_i][cord_j] = rez_num;
        }
        else {
            printf("Число неверное, попробуйте ещё раз!\n\n");
        }
        break;

    case 2:
        printf("Выберите число, которое хотите вставить: ");
        scanf("%d", &rez_num);
        getchar();
        if (rez_num == checker_array[cord_i][cord_j]) {
            gametablet[cord_i][cord_j] = rez_num;
        }
        else {
            printf("Число неверное, попробуйте ещё раз!\n\n");
        }
        break;

    case 3:
        printf("Выберите число, которое хотите вставить: ");
        scanf("%d", &rez_num);
        getchar();
        if (rez_num == checker_array[cord_i][cord_j]) {
            gametablet[cord_i][cord_j] = rez_num;
        }
        else {
            printf("Число неверное, попробуйте ещё раз!\n\n");
        }
        break;

    case 4:
        printf("Выберите число, которое хотите вставить: ");
        scanf("%d", &rez_num);
        getchar();
        if (rez_num == checker_array[cord_i][cord_j]) {
            gametablet[cord_i][cord_j] = rez_num;
        }
        else {
            printf("Число неверное, попробуйте ещё раз!\n\n");
        }
        break;

    default:
        printf("Координата не входит в диапазон!\n\n");
        break;
    }
}

void finish_flag_easy() {

    int game_tablet[ROW][COL] = {
        {5, 3, 0, 8, 7, -1, 1, -1, -1, -1},
        {6, 8, 4, 9, -1, 5, -1, 2, 1, 0},
        {-1,7, 3, -1, 6, 1, 4, 5, -1, 9},
        {-1, 5, 1, 4, -1, 0, 8, -1, 7,6},
        {7, 0, 3, 5, -1, -1, 6, -1, 1, 9},
        {20, 23, 11, 28, 27, 12, 26, 27, 23, 28}
    }; /*указание начального игрового поля*/

    int final_checker[ROW - 1][COL];
    load_file(final_checker);

    int game_over = 0;

    while (game_over != 1) {
        int flag = 0;

        for (int i = 0; i < ROW - 1; i++) {
            for (int j = 0; j < COL; j++) {
                if ((int)game_tablet[i][j] == final_checker[i][j]) flag += 1;
            }
        }

        if (flag == 50) {
            game_over++;
            printf("\n\tВы выйграли! Поздравляем!");
        }

        else {
            draw_screen(game_tablet, ROW, COL);
            /*функция отрисовки игрового поля
            game_tablet - двумерный массив
            height - высота поля (кол-во строк)
            width - ширина поля (кол-во столбцов)*/

            answer_peak(game_tablet);
            /*функция выбора координаты на игровом поле
            и числа для постановки его на поле и проверки
            его на правильность ввода*/
        }
    }
}

void finish_flag_normal() {

    int game_tablet[ROW][COL] = {
        {5, -1, 0, -1, 7, -1, 1, -1, -1, -1},
        {6, 8, 4, 9, -1, 5, -1, 2, 1, 0},
        {-1, -1, -1, -1, 6, 1, -1, 5, -1, 9},
        {-1, -1, -1, 4, -1, -1, 8, -1, 7, -1},
        {7, -1, 3, 5, -1, -1, 6, -1, 1, 9},
        {20, 23, 11, 28, 27, 12, 26, 27, 23, 28}
    }; /*указание начального игрового поля*/

    int final_checker[ROW - 1][COL];
    load_file(final_checker);

    int game_over = 0;

    while (game_over != 1) {
        int flag = 0;

        for (int i = 0; i < ROW - 1; i++) {
            for (int j = 0; j < COL; j++) {
                if ((int)game_tablet[i][j] == final_checker[i][j]) flag += 1;
            }
        }

        if (flag == 50) {
            game_over++;
            printf("\n\tВы выйграли! Поздравляем!");
        }

        else {
            draw_screen(game_tablet, ROW, COL);
            /*функция отрисовки игрового поля
            game_tablet - двумерный массив
            height - высота поля (кол-во строк)
            width - ширина поля (кол-во столбцов)*/

            answer_peak(game_tablet);
            /*функция выбора координаты на игровом поле
            и числа для постановки его на поле и проверки
            его на правильность ввода*/
        }
    }
}

void finish_flag_hard() {

    int game_tablet[ROW][COL] = {
        {-1, -1, 0, -1, 7, -1, 1, -1, -1, -1},
        {6, -1, 4, 9, -1, 5, -1, 2, 1, 0},
        {-1, -1, -1, -1, 6, 1, -1, -1, -1, 9},
        {-1, -1, -1, 4, -1, -1, 8, -1, 7, -1},
        {7, -1, 3, -1, -1, -1, 6, -1, 1, -1},
        {20, 23, 11, 28, 27, 12, 26, 27, 23, 28}
    }; /*указание начального игрового поля*/

    int final_checker[ROW - 1][COL];
    load_file(final_checker);

    int game_over = 0;

    while (game_over != 1) {
        int flag = 0;

        for (int i = 0; i < ROW - 1; i++) {
            for (int j = 0; j < COL; j++) {
                if ((int)game_tablet[i][j] == final_checker[i][j]) flag += 1;
            }
        }

        if (flag == 50) {
            game_over++;
            printf("\n\tВы выйграли! Поздравляем!");
        }

        else {
            draw_screen(game_tablet, ROW, COL);
            /*функция отрисовки игрового поля
            game_tablet - двумерный массив
            height - высота поля (кол-во строк)
            width - ширина поля (кол-во столбцов)*/

            answer_peak(game_tablet);
            /*функция выбора координаты на игровом поле
            и числа для постановки его на поле и проверки
            его на правильность ввода*/
        }
    }
}

void choose_path() {
    int menu_rez;
    scanf("%d", &menu_rez);

    switch (menu_rez) {
    case 1:

        printf("\nВыберите уровень сложности: ");
        printf("\n1 - Лёгкий");
        printf("\n2 - Средний");
        printf("\n3 - Сложный");
        printf("\n");

        int rez_difficulty;
        scanf("%d", &rez_difficulty);

        switch (rez_difficulty) {
        case 1:
            finish_flag_easy();
            break;
        case 2:
            finish_flag_normal();
            break;
        case 3:
            finish_flag_hard();
            break;
        default:
            printf("Ошибка! Неверно введён уровень сложности!");
            break;
        }
        break;
    case 2:
        printf("\nЧислобус - головоломка, представляющая собой прямоугольную таблицу из девяти столбцов.\n");
        printf("В некоторых клетках уже стоят цифры от 1 до 9, остальные пусты.\n");
        printf("Для них нужно найти подходящие цифры. В нижней строке проставлены суммы для каждого столбца.\n");
        printf("Цифры в клетках касающиеся друг друга сторонами или углами должны отличаться.\n");
        printf("Также цифры не могут повторяться в строках. В столбцах повторение цифр разрешено.\n\n");

        menu_peak();
        break;
    case 3:
        printf("\nИгра окончена!");
        break;
    default:
        printf("\nВведено неправильное число!");
        break;
    }

}
void menu_peak() {

    printf("Игра ЧИСЛОБУС\n\n");
    printf("Выберите:\n");
    printf("1 - начать игру и выбрать уровень сложности.\n");
    printf("2 - правила игры.\n");
    printf("3 - выйти из игры.\n\n");

    choose_path();
}
