/*
Виневский Максим Викторович
Лабораторная работа №4.
Вариант №5
Задание: Написать программу, которая в данных из файла заменяет
мягкий знак на твердый и записывает результат в другой файл.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale>
#include <conio.h>


#define MAX_LEN 512

void Error(FILE *filein);
void TransferText(FILE *filein, FILE *fileout);

 void main(){
	 system("chcp 1251");
	 system("cls");

	FILE *filein, *fileout;

	filein = fopen("sourceText.txt", "r");
	fileout = fopen ("newText.txt", "w");

	Error(filein);
	TransferText(filein, fileout);

	fclose(filein);
	fclose(fileout);
	_getch();
    }

    void Error(FILE *filein) {
	  if (filein == NULL) {
		 printf("No data '%s'", filein);
		 _getch();
	    }
    }

	void TransferText(FILE *filein, FILE *fileout) {
	char text[MAX_LEN];
	while (fgets(text, sizeof(text), filein) != NULL)
        for (int i = 0; text[i]; i++) {
			if (text[i] == 'ь') {
				text[i] = 'ъ';
			}
			fprintf(fileout, "%c", text[i]);
		}
    } 
