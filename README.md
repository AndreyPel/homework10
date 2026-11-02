# Домашнее задание к работе 10

## Условие задачи

Составьте программу, которая для заданной пользователем фигуры, параллелограмма предлагает меню выбора одной из операций

## 1. Алгоритм и блок-схема
### Алгоритм решения
1. **НАЧАЛО**
2. Инициализация переменных: symvol, h, a, alpha, continue_flag = 1;
3. While пока continue_flag != 0:
5. Ввод переменных: symvol, h, a, alpha
6. Перевести угол из градусов в радианы: alpha_rad = alpha * M_PI / 180.0;
7. Вычислить горизонтальное смещение: shift = (int)round(1.0 / tan(alpha_rad) * 0.5);
8. Если shift < 1, то установить shift = 1;
9. for для i от 0 до h-1:
    - Вычислить отступ: offset = (h - 1 - i) * shift
    - for для j от 0 до offset-1:
         - Вывести пробел
    - for для j от 0 до a-1:
         - Вывести символ symvol
10. Вывести запрос "Продолжить? (Да - введите любое число, Нет - введите 0)"
11. Ввести continue_flag
12. **КОНЕЦ**

### Блок-схема
![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://github.com/AndreyPel/homework9/blob/master/Схема9.png)

## 2. Реализация программы
![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://github.com/AndreyPel/homework9/blob/master/РеализацияПрограммы9.png)

## 3. Результаты работы программы

![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://github.com/AndreyPel/homework9/blob/master/РезультатПрограммы9.png)

## 4. Информация о разработчике
  **Пелагин Андрей Александрович БИЦТ 262**
