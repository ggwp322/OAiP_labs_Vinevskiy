/*
Виневский Максим Викторович
Индивидуальная работа
Вариант №5
*/

#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 512

#include <string.h>
#include <fstream>
#include <conio.h>
#include <locale>
#include <stdio.h>

int clientsSize = 0;
int serviceSize = 0;
int usingbyservicesSize = 0;
int keysSize = 0;

struct Clients{
	int FIO;
	int numberphone;
	int contractdate;
	int endcontract;
	float debt;
	float credit;
};

struct Service{
	char servername;
	int code;
	int cost;
	int mera;
};

struct UsingByServices{
	int numberphone;
	int code;
	int during;
	int interval;
};

char* clientsFile = "clients.txt";
char* servicesFile = "service.txt";
char* usingByServicesFile = "usingbyservices.txt";
char* reportFile = "report.txt";

int getSize(char* loc);
Clients* clientBase();
Service* serviceBase();
UsingByServices* usingbyservicesBase();

int main(){
	system("chcp 1251");
	system("cls");

	FILE* clientsFile = fopen("clients.txt", "r");
	FILE* servicesFile = fopen("service.txt", "r");
	FILE* usingByServicesFile = fopen("usingbyservices.txt", "r");
	FILE* reportFile = fopen("report.txt", "w");

	Clients* CBase = clientBase();
	Service* SBase = serviceBase();
	UsingByServices* BBase = usingbyservicesBase();

	if (fileNotExist(clientsFile, servicesFile, usingByServicesFile, reportFile)) {
		return 0;
	}

	fclose(clientsFile);
	fclose(servicesFile);
	fclose(usingByServicesFile);

	system("pause");
	return 0;
}

int fileNotExist(FILE *clientsFile, FILE *servicesFile, FILE *usingByServicesFile, FILE *reportFile) {
	if (clientsFile == NULL || servicesFile == NULL || usingByServicesFile == NULL || reportFile == NULL) {
		printf("no file\n");
		return true;
	}
	else {
		return false;
	}
}

Clients* clientBase(){
	FILE *Client = fopen("clients.txt", "r");
	Clients* CBase = (Clients*)(malloc(sizeof(Clients)*clientsSize));
	int inc = 0;
	while (!feof(Client)){
		char buff[100];
		fgets(buff, 100, Client);
		if (strcmp(buff, "\n")){
			char* tokken = NULL;
			CBase[inc].FIO = atof(strtok_s(buff, ",", &tokken));
			CBase[inc].numberphone = atof(strtok_s(NULL, ", ", &tokken));
			CBase[inc].contractdate = atof(strtok_s(NULL, ", ", &tokken));
			CBase[inc].endcontract =atof(strtok_s(NULL, ",", &tokken));
			CBase[inc].debt = atof(strtok_s(NULL, ",", &tokken));
			CBase[inc].credit = atof(strtok_s(NULL, ",", &tokken));
			inc++;
		}
	}
	return CBase;
}

Service* serviceBase(){
	Service* SBase = (Service*)(malloc(sizeof(Service)*serviceSize));
	FILE* SFile = fopen(servicesFile, "r");
	int inc = 0;
	while (!feof(SFile)){
		char buff[100];
		fgets(buff, LENGTH, SFile);
		if (strcmp(buff, "\n")){
			char* tokken = NULL;
			SBase[inc].servername = atof(strtok_s(buff, ",", &tokken));
			SBase[inc].code = atoi(strtok_s(NULL, ",", &tokken));
			SBase[inc].cost = atof(strtok_s(NULL, ",", &tokken));
			SBase[inc].mera = atof(strtok_s(NULL, ",", &tokken));
			inc++;
		}
	}
	return SBase;
}

UsingByServices* usingbyservicesBase(){
	UsingByServices* UBase = (UsingByServices*)(malloc(sizeof(Service)*usingbyservicesSize));
	FILE* UFile = fopen(usingByServicesFile, "r");
	int inc = 0;
	while (!feof(UFile)){
		char buff[100];
		fgets(buff, LENGTH, UFile);
		char* tokken = NULL;
		UBase[inc].numberphone = atoi(strtok_s(buff, ", ", &tokken));
		UBase[inc].code = atoi(strtok_s(NULL, ",", &tokken));
		UBase[inc].during = atoi(strtok_s(NULL, ",", &tokken));
		UBase[inc].interval = atoi(strtok_s(NULL, ",", &tokken));
		inc++;
	}
	return UBase;
}

void outFile(Clients* CBase, Service* SBase, UsingByServices* UBase){

}



	


