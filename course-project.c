#include <locale.h>
#include <stdio.h>
/*подключаемые заголовочные файлы*/
#define ROW 6
#define COL 10
#define ROW_1 (int[COL]){5, 3, 0, 8, 7, 2, 1, 9, 6, 4} 
#define ROW_2 (int[COL]){6, 8, 4, 9, 3, 5, 7, 2, 1, 0}
#define ROW_3 (int[COL]){0, 7, 3, 2, 6, 1, 4, 5, 8, 9}
#define ROW_4 (int[COL]){2, 5, 1, 4, 3, 0, 8, 9, 7, 6}
#define ROW_5 (int[COL]){7, 0, 3, 5, 8, 4, 6, 2, 1, 9}
/*константы для настройки работы приложения*/

void draw_screen(int game_tablet[ROW][COL], int, int);
/*конструктор для структуры draw_screen*/

void answer_peak(int gametablet[ROW][COL]);

void finish_flag();

int main()
{
    setlocale(LC_ALL, "RUS");
    finish_flag();
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

void answer_peak(int gametablet[ROW][COL]) {
    int cord_i, cord_j, rez_num;
    int board[ROW][COL];
    
    FILE* pf;
    pf = fopen(strcat(fname, ".txt"), "r");

    if (pf == NULL) {
        printf("Ошибка при открытии файла\n");
        return -1;
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            fscanf(pf, "%c ", &board[i][j]);
    }


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
        if (rez_num == board[0][cord_j]) {
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
        if (rez_num == board[1][cord_j]) {
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
        if (rez_num == board[2][cord_j]) {
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
        if (rez_num == board[3][cord_j]) {
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
        if (rez_num == board[4][cord_j]) {
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

void finish_flag() {

    int game_tablet[ROW][COL] = {
        {5, -1, 0, -1, 7, -1, 1, -1, -1, -1},
        {6, 8, 4, 9, -1, 5, -1, 2, 1, 0},
        {-1, -1, -1, -1, 6, 1, -1, 5, -1, 9},
        {-1, -1, -1, 4, -1, -1, 8, -1, 7, -1},
        {7, -1, 3, 5, -1, -1, 6, -1, 1, 9},
        {20, 23, 11, 28, 27, 12, 26, 27, 23, 28}
    }; /*указание начального игрового поля*/

    int game_over = 0;
   
    while (game_over != 1) {
        int flag = 0;
        int integer = 0;

        while (integer < ROW - 1) {
            switch (integer) {
            case 0:
                for (int j = 0; j < COL; j++) {
                    if (game_tablet[0][j] == ROW_1[j]) flag += 1;
                }
                break;

            case 1:
                for (int j = 0; j < COL; j++) {
                    if (game_tablet[1][j] == ROW_2[j]) flag += 1;
                }
                break;

            case 2:
                for (int j = 0; j < COL; j++) {
                    if (game_tablet[2][j] == ROW_3[j]) flag += 1;
                }
                break;

            case 3:
                for (int j = 0; j < COL; j++) {
                    if (game_tablet[3][j] == ROW_4[j]) flag += 1;
                }
                break;

            case 4:
                for (int j = 0; j < COL; j++) {
                    if (game_tablet[4][j] == ROW_5[j]) flag += 1;
                }
                break;
            }
            integer++;
        }

        if (flag == 50) {
            game_over++;
            printf("\nВЫЙГРЫШ");
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
