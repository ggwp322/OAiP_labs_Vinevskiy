/*
Виневский Максим Викторович
Лабораторная работа №4.
Вариант №5
Задание. Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. В программе реализовать:
а) дополнение существующего массива структур новыми структурами;
б) поиск структуры с заданным значением выбранного элемента;
в) вывод на экран содержимого массива структур;
г) упорядочение массива структур по заданному полю (элементу), например
государство по численности.
Варианты заданий:
5. «Студент»: фамилия, имя, отчество, дата рождения, факультет, кафедра, группа,
домашний адрес, успеваемость (плохо, удовлетворительно, хорошо, отлично).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024 
#define STRUCTURE_LENGTH 512

struct student{
	char	name[MAX_LENGTH];
	char	familia[MAX_LENGTH];
	char	otchestvo[MAX_LENGTH];
	char    data[MAX_LENGTH];
	char	fakyltet[MAX_LENGTH];
	char	kafedra[MAX_LENGTH];
	char    gruppa[MAX_LENGTH];
	char    adres[MAX_LENGTH];
	char    ocenka[MAX_LENGTH];
}stud[STRUCTURE_LENGTH];

int initialization();
void insert(int i);
void out(int i);
void seek(int i, int struc, char *Search, char *array);
void sort(int k, int j);
void print(int number);
void new_insert(int number);
void check();

void main(){
	system("chcp 1251");
	system("cls");
	char Search[MAX_LENGTH];
	int display = 0;
	int number = initialization();
	int sorting = 0;
	int search = 0;
	int i = 0;
	int struc = 0;
	int code;
	student **q = new student*[STRUCTURE_LENGTH];
	do{
		printf("1)vnesenie strukturi v fail\n");
		printf("2)poisk strukturi v faile\n");
		printf("3)vivod structur na ekran\n");
		printf("4)sortirovka dannih v faile\n");
		printf("5)zavershenie raboti programmi\n");
		scanf_s("%d", &display);
		system("cls");	

		switch (display){
		case 1:
			printf("--- dopolnit struktyry novoi zapisiy ---\n");
			if (number < STRUCTURE_LENGTH)	 
			{
				insert(number);
				number++;
				system("pause");
				system("cls");
			}
			else{
				printf("--- Vvedite max kol-vo structur ---");
			}
			break;
		case 2:
			if (number != 0){
				printf("---Vvedite nomer---\n");
				printf("\t1)name\n");
				printf("\t2)familia\n");
				printf("\t3)otchestvo\n");
				printf("\t4)data (v vide dd:mm:gggg)\n");
				printf("\t5)fakyltet\n");
				printf("\t6)kafedra\n");
				printf("\t7)gruppa\n");
				printf("\t8)adres\n");
				printf("\t9)ocenka\n");

				scanf_s("%d", &search);
				system("cls");

				switch (search){
				case 1: printf(" --- poisk po imeni --- \n");
					printf("vvedite imz\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].name);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 2:printf(" --- poisk po familii--- \n");
					printf("vvedite imz\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].familia);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 3:printf(" --- poisk po otchestvy --- \n");
					printf("vvedite otchestvo\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].otchestvo);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 4:printf(" --- poisk po date rojdeniz --- \n");
					printf("vvedite daty\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].data);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 5:printf(" --- poisk po fakyltety --- \n");
					printf("vvedite fakyltet\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].fakyltet);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 6:printf(" --- poisk po kafedre--- \n");
					printf("vvedite kafedryn -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].kafedra);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 7:printf(" --- poisk po gruppe --- \n");
					printf("vvedite gruppu\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].gruppa);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 8:printf(" --- poisk po adresy --- \n");
					printf("vvedite adres\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].adres);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 9:printf(" --- poisk po ocenke --- \n");
					printf("vvedite nomer\n -->");
					scanf("%s", &Search);
					for (i = 0; i < number; i++){
						seek(i, struc, Search, stud[i].ocenka);
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				}
			}
			else{
				printf("--- Zapolnennix structur net ---\n");
				system("pause");
			}
			system("cls");
			break;
		case 3:
			printf("---vivod na ekran soderjimogo structur---\n");
			if (number == 0)	{
				printf("zapolnennih structur net\n");
			}
			else{
				print(number);
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (number != 0){
				printf("(vvedite nomer)\n");
				printf("1.sortirovke po imeni.\n");
				printf("2.sortirovke po familii.\n");
				printf("3.sortirovke po otchestvy.\n");
				printf("4.sortirovke po date rojdeniz.\n");
				printf("5.sortirovke po fackyltety.\n");
				printf("6.sortirovke po kafedre.\n");
				printf("7.sortirovke po gryppe.\n");
				printf("8.sortirovke po adresy.\n");
				printf("9.sortirovke po ocenke.\n");


				scanf_s("%d", &sorting);
				system("cls");

				switch (sorting){
				case 1:printf(" --- po imeni --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].name, stud[j + 1].name);sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 2:printf(" --- po familii--- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].familia, stud[j + 1].familia);sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 3:printf(" --- po otchestvy --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].otchestvo, stud[j + 1].otchestvo); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 4:printf(" --- po date --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].data, stud[j + 1].data); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 5:printf(" --- po fakyltety--- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].fakyltet, stud[j + 1].fakyltet); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 6:printf(" --- po kafedre --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].kafedra, stud[j + 1].kafedra); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 7:printf(" --- po gruppe --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].gruppa, stud[j + 1].gruppa); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 8:printf(" --- po adresy --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].adres, stud[j + 1].adres); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				case 9:printf(" --- po ocenke --- \n");
					for (i = 0; i < number; i++){
						for (int j = 0; j < number - i - 1; j++){
							code = strcmp(stud[j].ocenka, stud[j + 1].ocenka); sort(code, j);
						}
					}
					print(number);
					new_insert(number);
					system("pause");
					system("cls");
					break;
				}
			}
			else{
				printf("--- zapolnenia structutr net ---\n");
				system("pause");
			}
			system("cls");
			break;
		case 5:
			exit(0);	
			break;
		default: printf("takogo net.");
		}
	} while (true);
	system("pause");
}

int initialization(){
	FILE *File = fopen("StructFile.txt", "r");
	FILE *File1 = fopen("StructFile.txt", "r");
	int i = 0;
	if (File != NULL){
		while (fscanf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka) != EOF){
			fscanf(File1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka);
			i++;
		}
	}
	else{
		printf("---faila net---");
		system("pause");
		exit(0);
	}
	fclose(File);
	fclose(File1);
	return i;
}

void seek(int i, int struc, char *Search, char * array)
{
	if (strcmp(Search, array) == 0){
		struc++;
		out(i);
	}
}

void sort(int k, int j){
	if (k > 0){
		student Buff = stud[j];
		stud[j] = stud[j + 1];
		stud[j + 1] = Buff;
	}
}

void print(int number){
	for (int i = 0; i < number; i++){
		out(i);
	}
}


void insert(int i){
	printf("---vvedite svoi dannie---\n");
	printf("vvedite svoe omz: ");
	scanf("%s", &stud[i].name);
	printf("vvedite svoy familiy: ");
	scanf("%s", &stud[i].familia);
	printf("vvedite svoe otchestvo: ");
	scanf("%s", &stud[i].otchestvo);
	printf("vvedite daty rojdeniz: ");
	scanf("%s", &stud[i].data);
	printf("vvedite fakyltet: ");
	scanf("%s", &stud[i].fakyltet);
	printf("vvedite kafedry: ");
	scanf("%s", &stud[i].kafedra);
	printf("vvedite gruppy: ");
	scanf("%s", &stud[i].gruppa);
	printf("vvedite adres: ");
	scanf("%s", &stud[i].adres);
	printf("vvedite ocenky: ");
	scanf("%s", &stud[i].ocenka);
	printf("konec vvoda.\n\n");

	FILE *File = fopen("StructFile.txt", "a");
	fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka);
	fclose(File);
}

void new_insert(int number){
	FILE *File = fopen("Sort.txt", "w");
	for (int i = 0; i < number; i++)
	{
		fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka);
	}
	fclose(File);
}

void out(int i){
	printf("imz: %s\t", &stud[i].name);
	printf("familia: %s\t", &stud[i].familia);
	printf("otchestvo: %s\t", &stud[i].otchestvo);
	printf("data: %s\t", &stud[i].data);
	printf("fakyltet: %s\t", &stud[i].fakyltet);
	printf("kafedra%s\t", &stud[i].kafedra);
	printf("gruppa: %s\t", &stud[i].gruppa);
	printf("adres: %s\t", &stud[i].adres);
	printf("ocenka: %s\t", &stud[i].ocenka);	
}





