/*
Виневский Максим Викторович
Лабораторная работа №4.
Вариант №5
Задание: Написать программу, которая в данных из файла заменяет
мягкий знак на твердый и записывает результат в другой файл.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 512

#include <stdio.h>
#include <locale>
#include <conio.h>

void isFileExist(FILE *filein);
void transferText(FILE *filein, FILE *fileout);

void main(){
	system("chcp 1251");
	system("cls");

	FILE *filein, *fileout;

	filein = fopen("input.txt", "r");
	fileout = fopen("output.txt", "w");

	isFileExist(filein);
	transferText(filein, fileout);

	fclose(filein);
	fclose(fileout);
	_getch();
}

void isFileExist(FILE *filein) {
	if (filein == NULL) {
		printf("No data '%s'", filein);
		_getch();
	}
}

void transferText(FILE *filein, FILE *fileout) {
	char text[MAX_LEN];

	while (fgets(text, sizeof(text), filein) != NULL)
		for (int i = 0; text[i]; i++) {
			if (text[i] == 'ь') {
				text[i] = 'ъ';
			}
			fprintf(fileout, "%c", text[i]);
		}
}