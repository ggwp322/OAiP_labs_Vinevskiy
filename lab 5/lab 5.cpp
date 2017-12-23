/*
Виневский Максим Викторович
Лабораторная работа №5.
Вариант №5
Задание: Написать программу, которая записывает с клавиатуры в файл структуру согласно выданному варианту задания. В качестве разделителя полей структуры использовать символ табуляции. В программе реализовать:
а) дополнение существующего массива структур новыми структурами;
б) поиск структуры с заданным значением выбранного элемента;
в) вывод на экран содержимого массива структур;
г) упорядочение массива структур по заданному полю (элементу), например государство по численности.
«Студент»: фамилия, имя, отчество, дата рождения, факультет, кафедра, группа, домашний адрес, успеваемость (плохо, удовлетворительно, хорошо, отлично).
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024 
#define STRUCTURE_LENGTH 512

struct student{
	char	name[MAX_LENGTH];
	char	surname[MAX_LENGTH];
	char	patronymic[MAX_LENGTH];
	char    data[MAX_LENGTH];
	char	faculty[MAX_LENGTH];
	char	department[MAX_LENGTH];
	char    group[MAX_LENGTH];
	char    address[MAX_LENGTH];
	char    assessment[MAX_LENGTH];
}stud[STRUCTURE_LENGTH];

void mainMenu();
int checkNumber(int max);
void choiceFunction(int inquiry);
void enterStruct(void);
void searchStruct(void);
void outPutMonitor(void);
int initialization();
int number = initialization();
int struc = 0;
int n, k, j;
void outConcole(int k);
void outFile(int number);
void sortingStruct(void);
void sort(int k, int j);
int sorting = 0;
int search = 0;
void print(int number);
void searchByField(struct student, int new_number, int struc, int field);
void searchStruct(void);
int compareStruct(struct student, char field, int i, char *Search);
void sortingStruct(void);
int sortByField(struct student, int field, int i);
void  sortByField(struct student, int new_number, int field);

int main(){
	system("chcp 1251");
	system("cls");
	int inquiry = 0;
	do{
		printf("\nЧто вы хотите сделать?\n");
		mainMenu();
		inquiry = checkNumber(5);
		choiceFunction(inquiry);
	} while (inquiry != 5);
	return 0;
}

void mainMenu(){
	printf("1)Внести новую структуру\n");
	printf("2)Поиск\n");
	printf("3)Вывод всех студентов на экран\n");
	printf("4)Сортировка\n");
	printf("5)Завершение работы программы\n");
	printf("Ответ: ");
}

int checkNumber(int max){
	int number = 0;
	while (!scanf("%d", &number) || number < 1 || number > max){
		while (getchar() != '\n');
		printf("Ошибка ввода. Пожалуйста, повторите снова: ");
	}
	if (getchar() != '\n'){
		while (getchar() != '\n');
		printf("Ошибка ввода. Пожалуйста, повторите снова: ");
		number = checkNumber(max);
	}
	return number;
}

void choiceFunction(int inquiry){
	switch (inquiry){
	case 1:
		enterStruct();
		break;
	case 2:
		searchStruct();
		break;
	case 3:
		outPutMonitor();
		break;
	case 4:
		sortingStruct();
		break;
	case 5:
		exit(0);
	}
}

void enterStruct(void){
	int i = 0;
	printf("Введите кол-во студентов: ");
	scanf_s("%d", &n);
	for (i; i < n; i++){
		printf("Студент № %d----------\n ", i + 1);
		printf("Введите имя студента: ");
		scanf("%s", &stud[i].name);

		printf("Введите фамилию студента: ");
		scanf("%s", &stud[i].surname);

		printf("Введите отчество студента: ");
		scanf("%s", &stud[i].patronymic);

		printf("Введите дату рождения студента в формате(GGGG/MM/DD): ");
		scanf("%s", &stud[i].data);

		printf("Введите факультет студента: ");
		scanf("%s", &stud[i].faculty);

		printf("Введите кафедру студента: ");
		scanf("%s", &stud[i].department);

		printf("Введите группу студента: ");
		scanf("%s", &stud[i].group);

		printf("Введите домашний адресс студента: ");
		scanf("%s", &stud[i].address);

		printf("Введите успеваемость студента (плохо, удовлетворительно, хорошо, отлично): ");
		scanf("%s", &stud[i].assessment);
		printf("\n\n");

		FILE *File = fopen("StructFile.txt", "a");
		fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].surname, &stud[i].patronymic, &stud[i].data, &stud[i].faculty, &stud[i].department, &stud[i].group, &stud[i].address, &stud[i].ocenka);
		fclose(File);
	}
}

void searchStruct(void){
	int new_number;
	printf("Поиск:\n1.По имени\n2.По фамилии\n3.По отчеству\n4.По дате рождения\n5.По факультету\n6.По кафедре\n7.По группе\n8.По домашний адрессу\n9.По успеваемость студента (плохо, удовлетворительно, хорошо, отлично)\n");
	printf("Введите пункт: ");
	scanf("%d", &new_number);
	if ((new_number >= 0) && (new_number <= 9)){
		switch (new_number){
		case 1: searchByField(stud, new_number, struc, search);
			break;
		case 2:searchByField(stud, new_number, struc, search);
			break;
		case 3:searchByField(stud, new_number, struc, search);
			break;
		case 4:searchByField(stud, new_number, struc, search);
			break;
		case 5:searchByField(stud, new_number, struc, search);
			break;
		case 6:searchByField(stud, new_number, struc, search);
			break;
		case 7:searchByField(stud, new_number, struc, search);
			break;
		case 8:searchByField(stud, new_number, struc, search);
			break;
		case 9:searchByField(stud, new_number, struc, search);
			break;
		}
	}
}

void searchByField(struct *sterud, int new_number, int struc, int field){
		char Search[MAX_LENGTH];
		scanf("%s", &Search);
		for (int i = 0; i < new_number; i++){
			if ((compareStruct(stud, field, i, Search)) == 0){
				struc++;
				printf(" Введите номер структуры-> %d\n", i + 1);
				outConsole(i);
			}
		}
		if (struc == 0){
			printf("Структура не найденна\n");
		}
		struc = 0;
		system("pause");
		system("cls");
	}

int compareStruct(struct student, char field, int i, char *Search){
	int code;
	switch (field) {
	case 1:code = strcmp(Search, stud[i].name); 
	case 2:code = strcmp(Search, stud[i].surname);
	case 3:code = strcmp(Search, stud[i].patronymic);
	case 4:code = strcmp(Search, stud[i].data);
	case 5:code = strcmp(Search, stud[i].faculty);
	case 6:code = strcmp(Search, stud[i].department);
	case 7:code = strcmp(Search, stud[i].group);
	case 8:code = strcmp(Search, stud[i].address);
	case 9:code = strcmp(Search, stud[i].assessment);
	}
}

void outConsole(int i){
	printf("имя: %s\t", &stud[i].name);
	printf("фамилия: %s\t", &stud[i].surname);
	printf("отчество: %s\t", &stud[i].patronymic);
	printf("дата: %s\t", &stud[i].data);
	printf("факультет: %s\t", &stud[i].faculty);
	printf("кафедра%s\t", &stud[i].department);
	printf("группа: %s\t", &stud[i].group);
	printf("адрес: %s\t", &stud[i].address);
	printf("оценка: %s\t", &stud[i].assessment);
}

void outPutMonitir(void){
	printf("---вывод на экран---\n");
	if (number == 0){
		printf("нет структур\n");
	}
	else{
		print(number);
	}
}

void print(int number){
	for (int k = 0; k < number; k++){
		outConsole(k);
	}
}

int initialization(){
	FILE *File = fopen("StructFile.txt", "r");
	FILE *File1 = fopen("StructFile.txt", "r");
	int i = 0;
	if (File != NULL){
		while (fscanf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &stud[i].name, &stud[i].surname, &stud[i].patronymic, &stud[i].data, &stud[i].faculty, &stud[i].department, &stud[i].group, &stud[i].address, &stud[i].assessment) != EOF){
			fscanf(File1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &stud[i].name, &stud[i].surname, &stud[i].patronymic, &stud[i].data, &stud[i].faculty, &stud[i].department, &stud[i].group, &stud[i].address, &stud[i].assessment);
			i++;
		}
	}
	else{
		printf("---файл отсутствует---");
		system("pause");
		exit(0);
	}
	fclose(File);
	fclose(File1);

	return i;
}

void outFile(int number){
	FILE *File = fopen("StructFile.txt", "w");
	for (int i = 0; i < number; i++){
		fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].surname, &stud[i].patronymic, &stud[i].data, &stud[i].faculty, &stud[i].department, &stud[i].group, &stud[i].address, &stud[i].assessment);
	}
	fclose(File);
}

void sortingStruct(void){
	int new_number;
	printf("Введите по каким данным вы хотите упорядочить студентов:\n1.По фамилии\n2.По Имени\n3.По отчеству\n4.По дате рождения\n5.По факультету\n6.По кафедре\n7.По группе\n8.По домашний адрессу\n9.По успеваемость студента (плохо, удовлетворительно, хорошо, отлично)\n");
	printf("Введите пункт: ");
	scanf("%d", &new_number);
	if ((new_number >= 0) && (new_number <= 9)){
		switch (new_number){
			{
		case 1:sortByField(stud, number, sorting);
			break;
		case 2:sortByField(stud, number, sorting);
			break;
		case 3:sortByField(stud, number, sorting);
			break;
		case 4:sortByField(stud, number, sorting);
			break;
		case 5:sortByField(stud, number, sorting);
			break;
		case 6:sortByField(stud, number, sorting);
			break;
		case 7:sortByField(stud, number, sorting);
			break;
		case 8:sortByField(stud, number, sorting);
			break;
		case 9:sortByField(stud, number, sorting);
			break;
			}
		}
	}
}

void  sortByField(struct student, int new_number, int field){
	for (int i = 0; i < number; i++){
		for (int j = 0; j < number - i - 1; j++){
			if ((compareByField1(stud, field, j)) < 0){
				student Buff = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = Buff;
			}
		}
	}
	print(number);
	(stud, new_number);
	system("pause");
	system("cls");
}

int compareStruct(struct student, int field, int i){
	int code;
	switch (field) {
	case 1:code = strcmp(stud[i + 1].name, stud[i].name);
	case 2:code = strcmp(stud[i + 1].surname, stud[i].surname);
	case 3:code = strcmp(stud[i + 1].patronymic, stud[i].patronymic);
	case 4:code = strcmp(stud[i + 1].data, stud[i].data);
	case 5:code = strcmp(stud[i + 1].faculty, stud[i].faculty);
	case 6:code = strcmp(stud[i + 1].department, stud[i].department);
	case 7:code = strcmp(stud[i + 1].group, stud[i].group);
	case 8:code = strcmp(stud[i + 1].address, stud[i].address);
	case 9:code = strcmp(stud[i + 1].assessment, stud[i].assessment);
	}
}
