
/* Виневский Максим Викторович
Лабораторная работа №2
Вариант №5
Задание :Найти произведение отрицательных элементов массива.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<conio.h>
void main(){
	setlocale(LC_ALL, "Rus");
	printf("Введите длину массива");
	int C;
	scanf_s("%d", C);
    int array[100];
	int k=1;
	for (int i = 0; i < C; i++){
		printf("Введите элемент массива");
	}
	int result;
	int result = scanf_s("%f", array[i]);
	if (result == 0){
		printf("Ошибка");
		array[i] = 0;
	}
	if (array[i] < 0 && result != 0){
		k = k * array[i];
	}
		printf("Произведение отрицательных элементов массива равно %f", k);
		_getch();
}
