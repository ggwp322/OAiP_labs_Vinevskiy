
/* ��������� ������ ����������
������������ ������ �2
������� �5
������� :����� ������������ ������������� ��������� �������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<conio.h>
void main(){
	setlocale(LC_ALL, "Rus");
	printf("������� ����� �������");
	int C;
	scanf_s("%d", C);
    int array[100];
	int k=1;
	for (int i = 0; i < C; i++){
		printf("������� ������� �������");
	}
	int result;
	int result = scanf_s("%f", array[i]);
	if (result == 0){
		printf("������");
		array[i] = 0;
	}
	if (array[i] < 0 && result != 0){
		k = k * array[i];
	}
		printf("������������ ������������� ��������� ������� ����� %f", k);
		_getch();
}
