/*
  Виневский Максим Викторович
  Лабораторная работа №3.
  Вариант №5
  Задание:Написать программу, которая во вводимом с клавиатуры тексте заменит буквы «ь» на «ъ» и выведет результат на экран.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 512

#include <stdio.h>
#include <conio.h>
#include <locale.>

int main()
{
	system("chcp 1251");
	system("cls");

	char str[MAX_LENGTH];
	printf("\tвведите ваш текст:\n");
	fgets(str, MAX_LENGTH, stdin);

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (str[i] == 'ь')
			str[i] = 'ъ';
	}

	printf("\tпроведена замена мягкого знака на твердый :\n");
	printf("%s", str);

	_getch();
	return 0;
}