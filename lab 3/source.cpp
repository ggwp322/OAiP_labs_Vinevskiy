/*
  ��������� ������ ����������
  ������������ ������ �3.
  ������� �5
  �������:�������� ���������, ������� �� �������� � ���������� ������ ������� ����� ��� �� ��� � ������� ��������� �� �����.
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
	printf("\t������� ��� �����:\n");
	fgets(str, MAX_LENGTH, stdin);

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (str[i] == '�')
			str[i] = '�';
	}

	printf("\t��������� ������ ������� ����� �� ������� :\n");
	printf("%s", str);

	_getch();
	return 0;
}