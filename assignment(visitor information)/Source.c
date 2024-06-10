#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

typedef struct {
	char name[20];
	char ic[15];
	char gender;
	int age;
}Visitor;

typedef struct {
	Visitor personalData;
	char category[15];
	char latestVisit[20];
	int day, month, year;
	int hrs, min;
	char contactNum[20];
	double temperature;
}Details;

void main() {
	Details visitor[6];
	FILE* fptr;
	fptr = fopen("Visitor Information.dat", "rb");
	if (!fptr) {
		printf("error");
	}
	fread(&visitor, sizeof(Details), 3, fptr);

	for (int i = 0; i < 3; i++) {
		printf(" %-20s %-4s %-14s %-5s %3c %-10s %-2d %-7s %-10s %-5s %-10s %-14s %02d/%02d/%4d %-7s %02d:%02d %-10s %-15s %-5s %.1lf\n", visitor[i].personalData.name, "", visitor[i].personalData.ic, "", visitor[i].personalData.gender, "", visitor[i].personalData.age, "", visitor[i].category, "", visitor[i].latestVisit, "", visitor[i].day, visitor[i].month, visitor[i].year, "", visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, "", visitor[i].temperature);
		
	}
	fclose(fptr);
	system("pause");
}