/*
Виневский Максим Викторович
Лабораторная работа №2.
Вариант №5
Задание: Написать программу, которая вычисляет произведение отрицательных элементов
массива. Массив и его длина вводятся пользователем.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <conio.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 0

int check();
float checkarray();

int check()
{
	int number;
	scanf("%d", &number);
	if (getchar() != '\n')
	{
		printf("Ошибка ввода!Длина массива не должна содержать буквы, превышать %d и быть меньше 0!\nПовторите попытку ввода: ", MAX_LENGTH);
		while (getchar() != '\n');
		number = check();
	}
	return number;
}

float checkarray()
{
	float number;
	scanf("%f", &number);
	if (getchar() != '\n')
	{
		printf("Ошибка!\nПовторите ввод:");
		while (getchar() != '\n');
		number = checkarray();
	}
	return number;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float array[MAX_LENGTH];
	int length = 0;
	printf("Введите длину массива:");
	while (!scanf("%d", &length) || (length > MAX_LENGTH) || (length < MIN_LENGTH))
	{
		length = check();
		if (length > MAX_LENGTH || length < MIN_LENGTH)
		{
			printf("Ошибка ввода!Длина массива не должна содержать буквы, превышать %d и быть меньше 0!\nПовторите попытку ввода: ", MAX_LENGTH);
		}
	}
	for (int i = 0; i < length; i++)
	{
		printf("Введите элемент массива:", i);
		array[i] = checkarray();
	}

		int a = 0;
		float k = 1;
		for (int i = 0; i < length; i++)
		if (array[i] < 0)
		{
			k = k  * array[i];
			a = a + 1;
		}
		if (a != 0)
		{
			printf("Произведение отрицательных элементов массива равно %f", k);
		}
		else printf("Ошибка!Массив не содержит отрицательных элементов");
	_getch();
	return 0;
}
	