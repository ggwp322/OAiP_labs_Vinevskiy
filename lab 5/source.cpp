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
	char	familia[MAX_LENGTH];
	char	otchestvo[MAX_LENGTH];
	char    data[MAX_LENGTH];
	char	fakyltet[MAX_LENGTH];
	char	kafedra[MAX_LENGTH];
	char    gruppa[MAX_LENGTH];
	char    adres[MAX_LENGTH];
	char    ocenka[MAX_LENGTH];
}stud[STRUCTURE_LENGTH];

int n,k,j;
void mainMenu();
int checkNumber(int max);
void choiceFunction(int inquiry);
void enterStruct(void);
void search(void);
void output(void);
int initialization();
int number = initialization();
int struc = 0;
void out(int k);
void outFile(int number);
void sorting(void);
void sort(int k, int j);
void name(void);
void familia(void);
void otchestvo(void);
void data(void);
void fakyltet(void);
void kafedra(void);
void gruppa(void);
void adres(void);
void ocenka(void);
void sortingName();
void sortingFamilia();
void sortingOtchestvo();
void sortingData();
void sortingFakyltet();
void sortingKafedra();
void sortingGruppa();
void sortingAdres();
void sortingOcenka();
void print(int number);

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
		search();
		break;
	case 3:
		output();
		break;
	case 4:
		sorting();
		break;
	case 5:
		exit(0);
	}
}

void enterStruct(void)
{
	int i = 0;
	printf("Введите кол-во студентов: ");
	scanf_s("%d", &n);
	for (i; i < n; i++){
		printf("Студент № %d----------\n ", i + 1);
		printf("Введите имя студента: ");
		scanf("%s", &stud[i].name);

		printf("Введите фамилию студента: ");
		scanf("%s", &stud[i].familia);

		printf("Введите отчество студента: ");
		scanf("%s", &stud[i].otchestvo);

		printf("Введите дату рождения студента в формате(GGGG/MM/DD): ");
		scanf("%s", &stud[i].data);

		printf("Введите факультет студента: ");
		scanf("%s", &stud[i].fakyltet);

		printf("Введите кафедру студента: ");
		scanf("%s", &stud[i].kafedra);

		printf("Введите группу студента: ");
		scanf("%s", &stud[i].gruppa);

		printf("Введите домашний адресс студента: ");
		scanf("%s", &stud[i].adres);

		printf("Введите успеваемость студента (плохо, удовлетворительно, хорошо, отлично): ");
		scanf("%s", &stud[i].ocenka);
		printf("\n\n");

		FILE *File = fopen("StructFile.txt", "a");
		fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka);
		fclose(File);
	}
}

void search(void){
	int new_number;
	printf("Поиск:\n1.По имени\n2.По фамилии\n3.По отчеству\n4.По дате рождения\n5.По факультету\n6.По кафедре\n7.По группе\n8.По домашний адрессу\n9.По успеваемость студента (плохо, удовлетворительно, хорошо, отлично)\n");
	printf("Введите пункт: ");
	scanf("%d", &new_number);
	if ((new_number >= 0) && (new_number <= 9)){
		switch (new_number){
		case 1: name(); 
			break;
		case 2: familia(); 
			break;
		case 3: otchestvo(); 
			break;
		case 4: data(); 
			break;
		case 5: fakyltet(); 
			break;
		case 6: kafedra(); 
			break;
		case 7: gruppa(); 
			break;
		case 8: adres(); 
			break;
		case 9: ocenka(); 
			break;
		}
	}
}

void name(void){
	char name[MAX_LENGTH];
	printf("Введите фамилию: ");
	scanf("%s", &name);
	for (k = 0; k < n; k++){
		if ((strcmp(name, stud[k].name)) == 0){
			out(k);
		}
	}
}

void familia(void){
	char name[MAX_LENGTH];
	printf("Введите имя");
	scanf("%s", &familia);
	for (k = 0; k < n; k++){
		if ((strcmp(name, stud[k].familia)) == 0){
			out(k);
		}
	}
}

void otchestvo(void){
	char otchestvo[MAX_LENGTH];
	printf("Введите отчество: ");
	scanf("%s", &otchestvo);
	for (k = 0; k < n; k++){
		if ((strcmp(otchestvo, stud[k].otchestvo)) == 0){
			out(k);
		}
	}
}

void data(void){
	char data[MAX_LENGTH];
	printf("Введите дату рождения: ");
	scanf("%s", &data);
	for (k = 0; k < n; k++){
		if ((strcmp(data, stud[k].data)) == 0){
			out(k);
		}
	}
}

void fakyltet(void){
	char fakyltet[MAX_LENGTH];
	printf("Введите факультет: ");
	scanf("%s", &fakyltet);
	for (k = 0; k < n; k++){
		if ((strcmp(fakyltet, stud[k].fakyltet)) == 0)
		{
			out(k);
		}
	}
}

void kafedra(void){
	char kafedra[MAX_LENGTH];
	printf("Введите кафедру");
	scanf("%s", &kafedra);
	for (k = 0; k < n; k++){
		if ((strcmp(kafedra, stud[k].kafedra)) == 0){
			out(k);
		}
	}
}

void gruppa(void){
	char gruppa[MAX_LENGTH];
	printf("Введите группу");
	scanf("%s", &gruppa);
	for (k = 0; k < n; k++){
		if ((strcmp(gruppa, stud[k].gruppa)) == 0){
			out(k);
		}
	}
}

void adres(void){
	char adres[MAX_LENGTH];
	printf("Введите домашний адресс");
	scanf("%s", &adres);
	for (k = 0; k < n; k++){
		if ((strcmp(adres, stud[k].adres)) == 0){
			out(k);
		}
	}
}

void ocenka(void){
	char ocenka[MAX_LENGTH];
	printf("Введите успеваемость студента (плохо, удовлетворительно, хорошо, отлично");
	scanf("%s", &ocenka);
	for (k = 0; k < n; k++){
		if ((strcmp(ocenka, stud[k].ocenka)) == 0){
			out(k);
		}
	}
}

void output(void){
	printf("---вывод на экран---\n");
	if (number == 0){
		printf("нет структур\n");}
	else{
		print(number);
	}
}

void print(int number){
	for (int k = 0; k < number; k++){
		out(k);
	}
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
		fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &stud[i].name, &stud[i].familia, &stud[i].otchestvo, &stud[i].data, &stud[i].fakyltet, &stud[i].kafedra, &stud[i].gruppa, &stud[i].adres, &stud[i].ocenka);
	}
	fclose(File);
}

void sorting(void){
	int new_number;
	printf("Введите по каким данным вы хотите упорядочить студентов:\n1.По фамилии\n2.По Имени\n3.По отчеству\n4.По дате рождения\n5.По факультету\n6.По кафедре\n7.По группе\n8.По домашний адрессу\n9.По успеваемость студента (плохо, удовлетворительно, хорошо, отлично)\n");
	printf("Введите пункт: ");
	scanf("%d", &new_number);
	if ((new_number >= 0) && (new_number <= 9)){
		switch (new_number){
		case 1: sortingName(); 
			break;
		case 2: sortingFamilia(); 
			break;
		case 3: sortingOtchestvo();
			break;
		case 4: sortingData();
			break;
		case 5: sortingFakyltet();
			break;
		case 6: sortingKafedra();
			break;
		case 7: sortingGruppa();
			break;
		case 8: sortingAdres();
			break;
		case 9: sortingOcenka();
			break;
		}
	}
}

void sortingName(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].name, stud[k + 1].name) != 0){
			sort(k,j);
		}
	}
}

void sortingFamilia(){
	for (k = 0; k < (k - 1); k++){
		if (strcmp(stud[k].familia, stud[k + 1].familia) != 0){
			sort(k,j);
		}
	}
}

void sortingOtchestvo(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].otchestvo, stud[k + 1].otchestvo) != 0){
			sort(k, j);
		}
	}
}

void sortingData(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].data, stud[k + 1].data) != 0){
			sort(k, j);
		}
	}
}

void sortingFakyltet(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].fakyltet, stud[k + 1].fakyltet) != 0){
			sort(k, j);
		}
	}
}

void sortingKafedra(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].kafedra, stud[k + 1].kafedra) != 0){
			sort(k, j);
		}
	}
}

void sortingGruppa(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].gruppa, stud[k + 1].gruppa) != 0){
			sort(k, j);
		}
	}
}

void sortingAdres(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].adres, stud[k + 1].adres) != 0){
			sort(k, j);
		}
	}
}

void sortingOcenka(){
	for (k = 0; k < (n - 1); k++){
		if (strcmp(stud[k].ocenka, stud[k + 1].ocenka) != 0){
			sort(k, j);
		}
	}
}

void sort(int k, int j){
	if (k > 0){
		student Buff = stud[j];
		stud[j] = stud[j + 1];
		stud[j + 1] = Buff;
	}
}

void out(int i){
	printf("имя: %s\t", &stud[i].name);
	printf("фамилия: %s\t", &stud[i].familia);
	printf("отчество: %s\t", &stud[i].otchestvo);
	printf("дата: %s\t", &stud[i].data);
	printf("факультет: %s\t", &stud[i].fakyltet);
	printf("кафедра%s\t", &stud[i].kafedra);
	printf("группа: %s\t", &stud[i].gruppa);
	printf("адрес: %s\t", &stud[i].adres);
	printf("оценка: %s\t", &stud[i].ocenka);
}
