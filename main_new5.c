#define _CRT_SECURE_NO_WARNINGS
#include <string.h> 
#include <stdbool.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 6
#define COLUMN 10 //isFull - draw_screen - enter number - checker

int menu_organizer(int players_choice);
int choose_difficulty(int difficulty);
char draw_screen(char game_tablet[ROW][COLUMN]);
char enter_number(char defaut_arr[3]);

int check_all(int access, char arr[ROW][COLUMN], char array[3]);
int check_row(char arr[ROW][COLUMN]);
int check_side(char arr[ROW][COLUMN]);
int check_corner(char arr[ROW][COLUMN]);

char load(int file_type, char arr[ROW][COLUMN]);
int isFull(char arr[ROW][COLUMN]);
char gameplay(char arr[ROW][COLUMN]);


int main() {
    setlocale(LC_CTYPE, "RUS");

    printf("Игра ЧИСЛОБУС\n\n");
    printf("Выберите:\n");
    printf("1 - начать игру и выбрать уровень сложности.\n");
    printf("2 - правила игры.\n");
    printf("3 - выйти из игры.\n\n");
    
    int players_choice;
    scanf("%d", &players_choice);

    char arr[ROW][COLUMN];

    int difficulty = choose_difficulty(menu_organizer(players_choice));
    load(difficulty, arr);

    gameplay(arr);
    return 0;
}

char load(int file_type, char arr[ROW][COLUMN]) {
    char fname[10];
    sprintf(fname, "%d", file_type);

    FILE *pf;
    pf = fopen(strcat(fname, ".txt"), "r");

    if (pf == NULL) {
        printf("Ошибка при открытии файла\n");
        return -1;
    }

    for (int i = 0; i < ROW - 1; i++) {
        for (int j = 0; j < COLUMN; j++) fscanf(pf, "%c ", &arr[i][j]);
    }
    fclose(pf);
    return 0;
} 


int isFull(char arr[ROW][COLUMN]) {
    int check = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (arr[i][j] == '-') {
                check = -1;
                break;
            };
        }
    }
    if (check == 0) return 0;
    else return -1;
}

char gameplay(char arr[ROW][COLUMN]) {

    int check = isFull(arr);
    if (check == -1) {
        char default_arr[3];

        draw_screen(arr);
        enter_number(default_arr);
        
        int default_checker = check_all(0, arr, default_arr);
        if (default_checker == 0) {
            arr[(int)default_arr[1]][(int)default_arr[0]] = default_arr[2];
            gameplay(arr);
        }
        else {
            printf("Введено неправильное число!\n");
            gameplay(arr);
        }
        return -1;
    }
    else printf("\n\tВы выйграли! Поздравляем!");
    
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
        break;
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
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Ошибка! Неверно введён уровень сложности!");
            return -1;
            break;
        }
}

char draw_screen(char game_tablet[ROW][COLUMN]) {

    for (int c = 0; c < COLUMN; c++) {
        printf("  X%d ", c);
    }
    printf("\n");

    for (int i = 0; i < ROW - 1; ++i) {
        printf("___________________________________________________");
        printf("\n");

        for (int j = 0; j < COLUMN; j++) {
            printf("| %2c ", game_tablet[i][j]);
        }
        printf("|");

        if (i < 5) {
            printf(" Y%d ", i);
        }

        printf("\n");
    }

    int results[COLUMN] = {20, 23, 11, 28, 27, 12, 26, 27, 23, 28};

    printf("___________________________________________________");
    printf("\n");

    for (int j = 0; j < COLUMN; j++) {
        printf("| %2d ", results[j]);
    }
    printf("|");
    return 0;
}

char enter_number(char default_arr[3]) {
    int cord_i, cord_j;;

    printf("\n");
    printf("Выберите координату X (0-9): ");
    scanf("%d", &cord_j);
    getchar();

    printf("Выберите координату Y (0-4): ");
    scanf("%d", &cord_i);
    getchar();

    if ((0 <= cord_j) && (cord_j <= 9))  {
        if ((0 <= cord_i) && (cord_i <= 4)) {
            printf("Выберите число, которое хотите вставить: ");
            char buffer_number;
            scanf("%c", &buffer_number);
            getchar();

            default_arr[0] = (char)cord_j;
            default_arr[1] = (char)cord_i;
            default_arr[2] = buffer_number;
            return 0;
        } 
        else {
            printf("Координата не входит в диапазон!\n\n");
            return -1;
        };
    }
    else {
        printf("Координата не входит в диапазон!\n\n");
        return -1;
    };

}

int check_all(int access, char arr[ROW][COLUMN], char array[3]) {
    int s1, s2, s3;
    s1 = check_row(arr);
    s2 = check_side(arr);
    s3 = check_corner(arr);
    access = s1 + s2 + s3;
    if (access == 0) return 0;
    else return -1;
}

int check_row(char arr[ROW][COLUMN]) {
    int check = 0;
    for (int i = 0; i < ROW - 1; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (arr[i][j] == arr[i][j + 1]) check++;
        }
    }
    if (check == 0) return 0;
    else return 1;
}

int check_side(char arr[ROW][COLUMN]) {
    int check = 0;
    for (int i = 1; i < ROW - 2; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if ((arr[i][j] == arr[i - 1][j]) || (arr[i][j] == arr[i + 1][j])) check++;
        }
    }
    if (check == 0) return 0;
    else return 1;
}

int check_corner(char arr[ROW][COLUMN]) {
    int check = 0;
    for (int i = 0; i < ROW - 2; i++) {
        for (int j = 1; j < COLUMN - 1; j++) {
            if ((arr[i][j] == arr[i + 1][j - 1]) || (arr[i][j] == arr[i + 1][j + 1])) check++;
        }
    }
    for (int i = 1; i < ROW - 1; i++) {
        for (int j = 1; j < COLUMN - 1; j++) {
            if ((arr[i][j] == arr[i - 1][j - 1]) || (arr[i][j] == arr[i - 1][j + 1])) check++;
        }
    }
    if (check == 0) return 0;
    else return 1;
}