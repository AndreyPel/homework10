#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

float area_parallelogram(float a, float h) {
    return a * h;
}

void draw_parallelogram(int a, int h, float alpha) {
    float alpha_rad = alpha * M_PI / 180.0f;

    int shift = (int)roundf(1.0f / tanf(alpha_rad) * 0.5f);
    if (shift < 1) shift = 1;

    printf("Параллелограмм (основание=%d, высота=%d, угол=%.1f°):\n", a, h, alpha);

    for (int i = 0; i < h; i++) {
        int offset = (h - 1 - i) * shift;

        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        for (int j = 0; j < a; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void draw_parallelogram_char(char symvol, int a, int h, float alpha) {
    float alpha_rad = alpha * M_PI / 180.0f;

    int shift = (int)roundf(1.0f / tanf(alpha_rad) * 0.5f);
    if (shift < 1) shift = 1;

    printf("Параллелограмм (символ='%c', основание=%d, высота=%d, угол=%.1f°):\n",
        symvol, a, h, alpha);

    for (int i = 0; i < h; i++) {
        int offset = (h - 1 - i) * shift;

        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        for (int j = 0; j < a; j++) {
            printf("%c", symvol);
        }
        printf("\n");
    }
}

int get_base() {
    int a;
    printf("Введите основание параллелограмма: ");
    scanf("%d", &a);
    return a;
}

int get_height() {
    int h;
    printf("Введите высоту параллелограмма: ");
    scanf("%d", &h);
    return h;
}

float get_angle() {
    float alpha;
    printf("Введите угол альфа (в градусах): ");
    scanf("%f", &alpha);
    return alpha;
}


int compare_parallelogram(int a1, int h1, int a2, int h2) {
    float area1 = area_parallelogram((float)a1, (float)h1);
    float area2 = area_parallelogram((float)a2, (float)h2);
    return (int)(area1 - area2);
}

void definition_parallelogram() {
    printf("Параллелограмм — это четырёхугольник, у которого\n");
    printf("противоположные стороны попарно параллельны и равны.\n");
    printf("Площадь вычисляется по формуле: S = a * h,\n");
    printf("где a — основание, h — высота.\n");
}

int main() {
    setlocale(LC_ALL, "RUS");

    int operation;
    int continue_flag = 1;
    char current_symbol = '*';

    while (continue_flag != 0) {
        printf("\n========== ПАРАЛЛЕЛОГРАММ ==========\n");
        printf("Меню операций:\n");
        printf("1) Рассчитать площадь\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Сравнить два параллелограмма\n");
        printf("Ваш выбор: ");
        scanf("%d", &operation);

        switch (operation) {
        case 1: {
            int a = get_base();
            int h = get_height();

            float s = area_parallelogram((float)a, (float)h);
            printf("Площадь параллелограмма: %.2f\n", s);
            break;
        }
        case 2: {
            definition_parallelogram();
            break;
        }
        case 3: {
            int sub_choice;
            printf("\n--- Рисование параллелограмма ---\n");
            printf("1) Выбрать новый символ\n");
            printf("2) Использовать текущий символ ('%c')\n", current_symbol);
            printf("Ваш выбор: ");
            scanf("%d", &sub_choice);

            int a = get_base();
            int h = get_height();
            float alpha = get_angle();

            if (sub_choice == 1) {
                printf("Введите символ для рисования: ");
                scanf(" %c", &current_symbol);
                draw_parallelogram_char(current_symbol, a, h, alpha);
            }
            else if (sub_choice == 2) {
                draw_parallelogram_char(current_symbol, a, h, alpha);
            }
            else {
                printf("Неверный выбор! Используется символ по умолчанию '*'.\n");
                draw_parallelogram(a, h, alpha);
            }
            break;
        }
        case 4: {
            printf("\n--- Сравнение двух параллелограммов ---\n");

            printf("Параллелограмм 1:\n");
            int a1 = get_base();
            int h1 = get_height();

            printf("Параллелограмм 2:\n");
            int a2 = get_base();
            int h2 = get_height();

            int diff = compare_parallelogram(a1, h1, a2, h2);
            printf("Разница площадей: %d\n", diff);
            if (diff > 0)
                printf("Параллелограмм 1 больше.\n");
            else if (diff < 0)
                printf("Параллелограмм 2 больше.\n");
            else
                printf("Параллелограммы равны по площади.\n");
            break;
        }
        default:
            printf("Неверная операция!\n");
        }

        printf("\nПродолжить? (Да - любое число, Нет - 0): ");
        scanf("%d", &continue_flag);
    }

    return 0;
}