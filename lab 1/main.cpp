 /* Виневский Максим Викторович
    Лабораторная работа №1
	Вариант №5
	Задание :Перевести лот в карат и выразить в унциях.
 */
#include<stdio.h>
#include<locale.h>
#include<conio.h>
void main(){
	setlocale(LC_ALL, "Rus");
	float a, b;
	double c;
	printf("Введите кол-во лот : ");
	int result = scanf_s("%f", &a);
	if (result == 0)
	{
		printf("ошибка \n");
	}
	else
	{
		b = a * 63.98631;
		printf("\n Это %.3f карат", b);
		c = a * 0.007054;
		printf(" и %.3f унций \n", c);
	}
	_getch();
}

