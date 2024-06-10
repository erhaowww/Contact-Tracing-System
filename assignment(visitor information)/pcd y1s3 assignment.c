#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include <ctype.h>
#pragma warning(disable:4996)

//sanitization
void sanitizationRecordLogo();
void addSanitizationRecord();
void modifySanitizationRecord();
void searchSanitizationRecord();
void displaySanitizationRecord();
void deleteSanitizationRecord();
void backupSanitizationRecord();
void recoverSanitizationRecord();
void scheduleSanitizationRecord();
void menuSanitizationRecord();
void header();
void line();
void change(int j, int k);

//visitor information
void visitorInFormationLogo();
void displayVisitorInformation();
void addVisitorInformation();
void modifyVisitorInformation();
void searchVisitorInformation();
void deleteVisitorInformation();
void reportVisitorInformation();
void menuVisitorInformation();

//visitor visit and exit
void visitAndExitRecordLogo();
void mainMenuVisitAndExit();
void addVisitAndExitRecords();
void displayVisitAndExitRecords();
void modifyVisitAndExitRecords();
void deleteVisitAndExitRecords();
void searchVisitAndExitRecords();
void backUpVisitAndExitRecords();
void modifyVisitAndExitRecords();
void backUpVisitAndExitRecords();

//staff
void staffAddFunction();
void staffDisplayFunction();
void staffSearchFunction();
void staffModifyFunction();
void staffDeleteFunction();
void staffReportFunction();
void staffSigninFunction();
void staffLoginFunction();
void staffStartFunction();
void staffMenu();
void staffRecordLogo();

//color
void red();
void yellow();
void reset();


//mainlogo
void logo();

//other
void fileFunction(FILE** file, char fileName[50], char mode[3], char filetype[4]);
void table();
void tableII();
void tarUc();
void heart();
int validationCompareTime(int, int, int, int, char* chosen, char type[30]);
int validationString(char string[100], char validName[20]);
int validationDate(int, int, int);
int validationTime(int, int);

//together
typedef struct {
	int day, month, year;
}Date;
typedef struct {
	int hr, min;
}Time;

//santinization
typedef struct {
	char name[40];
	char contactPerson[25];
	char contactNumber[13];
	Time activeTimeStart, activeTimeEnd;
}Company;
typedef struct {
	Date date;
	Time startTime;
	Time endTime;
	char venue[20];
	Company sanitizationCompany;
}Records;

//staff
typedef struct
{
	char staffName[15], gender[7];
	char faculty[6], position[15];
	char phoneNum[13];
	int staffAge;
}staffModule;
typedef struct
{
	staffModule staffData;
	Time time;
	Date date;
	double temp;
	char staffID[5];
	char activities[30];
}staffModulePro;
typedef struct
{
	char id[11], password[11];
}login;

//visitor information
typedef struct {
	char name[20];
	char ic[15];
	char gender;
	int age;
}VisitorDetail;
typedef struct {
	VisitorDetail personalData;
	char category[15];
	char latestVisit[20];
	Date date;
	Time time;
	char contactNum[20];
	double temperature;
}Details;

//visit and exit
typedef struct {
	char code[10];
	Date date;
	Time time;
	char Icno[20];
	char venueId[7];
}Visitor;
typedef struct {
	Visitor visitor;
	double visitTemperature;
	char purposeVisit[30];
}Visit;
typedef struct {
	Visitor visitor;
	char phoneNumber[20];
}Exit;

void main() {
	int choice;

	logo();
	do {
	
		printf("\n\n+============================================================+\n");
		printf("|                          MAIN                              |\n");
		printf("+============================================================+\n");
		printf("|            Please select your option down below:           |\n");
		printf("|              1. VISITOR INFORMATION MODULE                 |\n");
		printf("|              2. VISITS AND EXITS MODULE                    |\n");
		printf("|              3. SANITIZATION RECORDS MODULE                |\n");
		printf("|              4. ADMINISTRATIVE STAFF MODULE                |\n");
		printf("|              5. EXIT                                       |\n");
		printf("+============================================================+\n\n");
		rewind(stdin);
		printf("Enter your choice >> ");
		scanf("%d", &choice);
		system("cls");
		switch (choice) {
		case 1:
			menuVisitorInformation();
			break;
		case 2:
			mainMenuVisitAndExit();
			break;
		case 3:
			menuSanitizationRecord();
			break;
		case 4:
			staffStartFunction();
			break;
		case 5:
			exit(-1);
			system("pause");
			break;
		default:
			red();
			printf("<ERROR>Please enter a valid number (1 to 5)\n");
			reset();
		}

	} while (choice != 5);

	

}

//visitor information
void visitorInFormationLogo() {
	Sleep(200);
	red();
	printf("           $$\\           $$\\  $$\\                              $$\\           $$$$$$$$\\                                          $$\\     $$\\                     \n");
	Sleep(200);
	printf("           \\__|          \\__| $$ |                             \\__|          $$  _____|                                         $$ |    \\__|                    \n");
	Sleep(200);
	printf("$$\\    $$\\ $$\\  $$$$$$$\\ $$\\$$$$$$\\   $$$$$$\\   $$$$$$\\        $$\\ $$$$$$$\\  $$ |    $$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\  \n");
	Sleep(200);
	printf("\\$$\\  $$  |$$ |$$  _____|$$ \\_$$  _| $$  __$$\\ $$  __$$\\       $$ |$$  __$$\\ $$$$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\ \n");
	Sleep(200);
	yellow();
	printf(" \\$$\\$$  / $$ |\\$$$$$$\\  $$ | $$ |   $$ /  $$ |$$ |  \\__|      $$ |$$ |  $$ |$$  __|$$ /  $$ |$$ |  \\__|$$ / $$ / $$ | $$$$$$$ |$$ |    $$ |$$ /  $$ |$$ |  $$ |\n");
	Sleep(200);
	printf("  \\$$$  /  $$ | \\____$$\\ $$ | $$ |$$\\$$ |  $$ |$$ |            $$ |$$ |  $$ |$$ |   $$ |  $$ |$$ |      $$ | $$ | $$ |$$  __$$ |$$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |\n");
	Sleep(200);
	printf("   \\$  /   $$ |$$$$$$$  |$$ | \\$$$$  \\$$$$$$  |$$ |            $$ |$$ |  $$ |$$ |   \\$$$$$$  |$$ |      $$ | $$ | $$ |\\$$$$$$$ |\\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |\n");
	Sleep(200);
	printf("    \\_/    \\__|\\_______/ \\__|  \\____/ \\______/ \\__|            \\__|\\__|  \\__|\\__|    \\______/ \\__|      \\__| \\__| \\__| \\_______| \\____/ \\__| \\______/ \\__|  \\__|\n");
	reset();
}
void menuVisitorInformation() {
	int menu;

	visitorInFormationLogo();

	do {
		printf("\n\n+============================================================+\n");
		printf("|                            MENU                            |\n");
		printf("+============================================================+\n");
		printf("|            Please select your option down below:           |\n");
		printf("|                     1. ADD RECORD                          |\n");
		printf("|                     2. SEARCH RECORD                       |\n");
		printf("|                     3. MODIFY RECORD                       |\n");
		printf("|                     4. DISPLAY RECORD                      |\n");
		printf("|                     5. DELETE RECORD                       |\n");
		printf("|                     6. RECORD REPORT                       |\n");
		printf("|                     7. RUTURN TO MAIN PAGE                 |\n");
		printf("|                     8. EXIT PROGRAM                        |\n");
		printf("+============================================================+\n\n");

		menu = 0;
		printf("Please enter your choice (1 to 8) : ");
		rewind(stdin);
		scanf("%d", &menu);


		switch (menu) {
		case 1:
			addVisitorInformation(); break;
		case 2:
			searchVisitorInformation(); break;
		case 3:
			modifyVisitorInformation(); break;
		case 4:
			displayVisitorInformation(); break;
		case 5:
			deleteVisitorInformation(); break;
		case 6:
			reportVisitorInformation(); break;
		case 7:
			system("cls");
			main(); break;
		case 8:
			exit(-1); break;
		default:
			red();
			printf("<ERROR>You have enter invalid number/character, Please re-enter again<ERROR>\n\n");
			reset();

		}

	} while (menu != 8);


	system("pause");
}
void addVisitorInformation() {

	Details visitor;
	int num;
	char yesNo;
	FILE* fptr;
	SYSTEMTIME t;

	fileFunction(&fptr, "Visitor Information.dat", "ab", "bin");

	do {

		do {
			rewind(stdin);
			printf("\nEnter Visitor Name : ");
			gets(visitor.personalData.name);
		} while (validationString(visitor.personalData.name, "person name"));

		for (int i = 0; i < strlen(visitor.personalData.name); i++) {
			visitor.personalData.name[i] = toupper(visitor.personalData.name[i]);
		}

		do {
			do {
				printf("\nEnter Visitor IC NO (xxxxxx-xx-xxxx) : ");
				gets(visitor.personalData.ic);

				if (strlen(visitor.personalData.ic) != 14) {

					red();
					printf("<ERROR>Invalid!!!Please enter full IC NO include with '-' character.<ERROR>\n");
					reset();
				}
				else {
					if (visitor.personalData.ic[6] != '-' || visitor.personalData.ic[9] != '-') {
						red();
						printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
						reset();
					}
				}


			} while (strlen(visitor.personalData.ic) != 14 || visitor.personalData.ic[6] != '-' || visitor.personalData.ic[9] != '-');


			for (num = 0; num < strlen(visitor.personalData.ic); num++) {
				if (num == 6 || num == 9) {
					continue;
				}
				else if (isdigit(visitor.personalData.ic[num]) == 0) {
					red();
					printf("<ERROR>You have enter invalid character!!!Please enter IC NO with number only<ERROR>\n");
					reset();
					break;
				}
				else if (num == strlen(visitor.personalData.ic) - 1) {
					break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
				}
			}

		} while (isdigit(visitor.personalData.ic[num]) == 0);

		if (visitor.personalData.ic[13] % 2 == 0) //use the last ic number to identify visitor's gender
			visitor.personalData.gender = 'F'; // last number is even number , gender is female
		else
			visitor.personalData.gender = 'M';

		GetLocalTime(&t); // get the real time year

		if (visitor.personalData.ic[0] == '0' || visitor.personalData.ic[0] == '1' || (visitor.personalData.ic[0] == '2' && visitor.personalData.ic[1] <= '1')) { // use 1st and 2nd ic number to find visitor's age

			visitor.personalData.age = t.wYear - (2000 + (((visitor.personalData.ic[0] - 48) * 10) + (visitor.personalData.ic[1] - 48)));
		}
		else {
			visitor.personalData.age = t.wYear - (1900 + (((visitor.personalData.ic[0] - 48) * 10) + (visitor.personalData.ic[1] - 48)));
		}


		do {
			printf("\nEnter Visitor Category (eg. TUTOR): ");
			rewind(stdin);
			gets(visitor.category);
		} while (validationString(visitor.category, "person name"));

		for (int i = 0; i < strlen(visitor.category); i++) {
			visitor.category[i] = toupper(visitor.category[i]);
		}

		do {
			rewind(stdin);
			printf("\nEnter Visitor Latest Venue Visited : ");
			gets(visitor.latestVisit);
		} while (validationString(visitor.latestVisit, "venue"));

		for (int i = 0; i < strlen(visitor.latestVisit); i++) {
			visitor.latestVisit[i] = toupper(visitor.latestVisit[i]);
		}

		do {

			printf("\nEnter Date (dd/mm/yyyy) : ");
			rewind(stdin);
			scanf("%d/%d/%d", &visitor.date.day, &visitor.date.month, &visitor.date.year);
		} while (validationDate(visitor.date.day, visitor.date.month, visitor.date.year));

		do {
			printf("\nEnter Time Visited [INTERNATIONAL TIME] (hh:mm) : ");
			rewind(stdin);
			scanf("%d:%d", &visitor.time.hr, &visitor.time.min);
		} while (validationTime(visitor.time.hr, visitor.time.min));


		do {
			printf("\nEnter Visitor Contact Number (012-34567890) : ");
			rewind(stdin);
			gets(visitor.contactNum);
		} while (validationString(visitor.contactNum, "contact number"));


		do {
			printf("\nEnter Visitor Temperature : ");
			rewind(stdin);
			scanf("%lf", &visitor.temperature);

			if (!(visitor.temperature > 35 && visitor.temperature < 42)) {
				red();
				printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
				reset();
			}

		} while (!(visitor.temperature > 35 && visitor.temperature < 42));

		fwrite(&visitor, sizeof(Details), 1, fptr);

		do {
			printf("\nDo you want to continue (Y/y = Yes, N/n = No)? > ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}

		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');


	fclose(fptr);


}
void searchVisitorInformation() {
	Details visitor[100];
	int choice, day, month, year, no, record, count = 0;
	double temperature;
	char venue[20], yesNo;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb", "bin");

	while (fread(&visitor[count], sizeof(Details), 1, fptr) != 0) {
		count++;
	}

	do {
		record = 0;
		no = 1;
		choice = 0;
		do {

			printf("\n+==========================================================+\n");
			printf("|      Search The Visitor(s) Information according to :    |\n");
			printf("|                   1. VENUE                               |\n");
			printf("|                   2. DATE                                |\n");
			printf("|                   3. TEMPERATURE                         |\n");
			printf("+==========================================================+\n\n");

			printf("Enter your choice : ");
			rewind(stdin);
			scanf("%d", &choice);

			if (!(choice >= 1 && choice <= 3)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to 3)!!!<ERROR>\n");
				reset();
			}

		} while (!(choice >= 1 && choice <= 3));

		if (choice == 1) {
			do {
				printf("\nEnter the Venue : ");
				rewind(stdin);
				gets(venue);
			} while (validationString(venue, "venue"));

			for (int i = 0; i < strlen(venue); i++) {
				venue[i] = toupper(venue[i]);
			}


			printf("\n+====+=============================+===================+==========+======+=====================+=============+==================+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER %-3s|AGE %-2s|CATEGORY %-12s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+==========+======+=====================+=============+==================+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (strcmp(visitor[k].latestVisit, venue) == 0) {
					printf("|%2d. |%-29s|%-19s|%-10c|%-6d|%-21s|%02d/%02d/%-7d|%02d:%02d %-12s|%-20s|%.1lf %-9s|\n", no, visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].date.day, visitor[k].date.month, visitor[k].date.year, visitor[k].time.hr, visitor[k].time.min, "", visitor[k].contactNum, visitor[k].temperature, "");
					printf("+====+=============================+===================+==========+======+=====================+=============+==================+====================+==============+\n");
					no++;
					record++;
				}
				else if (k == count - 1 && record == 0) {
					printf("No record found\n");
				}

			}

			printf("\n<%d record(s) listed>\n", record);
		}
		else if (choice == 2) {
			do {
				printf("\nEnter Date (dd/mm/yyyy) : ");
				rewind(stdin);
				scanf("%d/%d/%d", &day, &month, &year);
			} while (validationDate(day, month, year));

			printf("\n+====+=============================+===================+==========+======+=====================+================================+=================+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER %-3s|AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-12s|TIME VISITED %-4s|CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+==========+======+=====================+================================+=================+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (day == visitor[k].date.day && month == visitor[k].date.month && year == visitor[k].date.year) {
					printf("|%2d. |%-29s|%-19s|%-10c|%-6d|%-21s|%-32s|%02d:%02d %-11s|%-20s|%.1lf %-9s|\n", no, visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].latestVisit, visitor[k].time.hr, visitor[k].time.min, "", visitor[k].contactNum, visitor[k].temperature, "");
					printf("+====+=============================+===================+==========+======+=====================+================================+=================+====================+==============+\n");
					no++;
					record++;
				}
				else if (k == count - 1 && record == 0) {
					printf("No record found\n");
				}
			}
			printf("\n<%d record(s) listed>\n", record);
		}
		else {
			do {
				printf("\nEnter Temperature (more than): >");
				scanf("%lf", &temperature);

				if (!(temperature > 35 && temperature < 42)) {
					red();
					printf("<ERROR>Please enter a valid visitor temperature (> 35 and < 42)<ERROR>\n");
					reset();
				}

			} while (!(temperature > 35 && temperature < 42));

			printf("\n+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (temperature < visitor[k].temperature) {
					printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].latestVisit, visitor[k].date.day, visitor[k].date.month, visitor[k].date.year, visitor[k].time.hr, visitor[k].time.min, "", visitor[k].contactNum, visitor[k].temperature, "");
					printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
					no++;
					record++;
				}
				else if (k == count - 1 && record == 0) {
					printf("No record found\n");
				}
			}
			printf("\n<%d record(s) listed>\n", record);
		}

		do {
			printf("\ncontinue to search more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');
	fclose(fptr);



}
void modifyVisitorInformation() {
	Details readVisitor;
	Details visitor[100];
	int count = 0, record = 0, num, no, j, modifyOption;
	char venue[20], decide, yesNo;
	SYSTEMTIME t;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb", "bin");

	while (fread(&readVisitor, sizeof(Details), 1, fptr) != 0) {
		visitor[count] = readVisitor;
		count++;
	}

	fclose(fptr);

	do {
		displayVisitorInformation();
		no = 0;

		if (count == 0) {
			printf("\nNO RECORD FOUND\n");
			break;
		}
		do {
			printf("\nEnter NO. of visitor to be modified : >NO. ");
			rewind(stdin);
			scanf("%d", &no);

			if (!(no > 0 && no <= count)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", count);
				reset();
			}

		} while (!(no > 0 && no <= count));


		j = no - 1;

		printf("\nPREVIOUS DATA : \n");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].date.day, visitor[j].date.month, visitor[j].date.year, visitor[j].time.hr, visitor[j].time.min, "", visitor[j].contactNum, visitor[j].temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

		do {
			printf("\nSure to Modify(Y/y = Yes, N/n = No)? : ");
			rewind(stdin);
			scanf("%c", &decide);

			if (toupper(decide) != 'Y' && toupper(decide) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}

		} while (toupper(decide) != 'Y' && toupper(decide) != 'N');

		if (toupper(decide) == 'Y') {
			modifyOption = 0;
			do {
				printf("+============================================================+\n");
				printf("|              Enter the number that you want to edit :      |\n");
				printf("|                     1. VISITOR NAME                        |\n");
				printf("|                     2. IC NO                               |\n");
				printf("|                     3. CATEGORY                            |\n");
				printf("|                     4. LATEST VENUE VISIT                  |\n");
				printf("|                     5. DATE                                |\n");
				printf("|                     6. TIME VISITED                        |\n");
				printf("|                     7. CONTACT NUMBER                      |\n");
				printf("|                     8. TEMPERATURE                         |\n");
				printf("|                     9. MODIFY ALL                          |\n");
				printf("+============================================================+\n");
				printf("Enter the number to select eg.(1-9) :");
				rewind(stdin);
				scanf("%d", &modifyOption);

				if (!(modifyOption >= 1 && modifyOption <= 9))
				{
					red();
					printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
					reset();
				}
			} while (!(modifyOption >= 1 && modifyOption <= 9));

			switch (modifyOption) {
			case 1:
				do {
					rewind(stdin);
					printf("\nEnter New Visitor Name : ");
					gets(visitor[j].personalData.name);
				} while (validationString(visitor[j].personalData.name, "person name"));


				for (int i = 0; i < strlen(visitor[j].personalData.name); i++) {
					visitor[j].personalData.name[i] = toupper(visitor[j].personalData.name[i]);
				}
				break;

			case 2:
				do {

					do {
						printf("\nEnter New Visitor IC NO (xxxxxx-xx-xxxx) : ");
						gets(visitor[j].personalData.ic);

						if (strlen(visitor[j].personalData.ic) != 14) {

							red();
							printf("<ERROR>Invalid!!!Please enter full IC NO include with '-' character.<ERROR>\n");
							reset();
						}
						else {
							if (visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-') {
								red();
								printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
								reset();
							}
						}


					} while (strlen(visitor[j].personalData.ic) != 14 || visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-');


					for (num = 0; num < strlen(visitor[j].personalData.ic); num++) {
						if (num == 6 || num == 9) {
							continue;
						}
						else if (isdigit(visitor[j].personalData.ic[num]) == 0) {
							red();
							printf("<ERROR>You have enter invalid character!!!Please enter IC NO with number only<ERROR>\n");
							reset();
							break;
						}
						else if (num == strlen(visitor[j].personalData.ic) - 1) {
							break; //避免num跳回去加多一次value //to avoid num to be added one more time
						}
					}

				} while (isdigit(visitor[j].personalData.ic[num]) == 0);

				if (visitor[j].personalData.ic[13] % 2 == 0)
					visitor[j].personalData.gender = 'F';
				else
					visitor[j].personalData.gender = 'M';

				GetLocalTime(&t);

				if (visitor[j].personalData.ic[0] == '0' || visitor[j].personalData.ic[0] == '1' || (visitor[j].personalData.ic[0] == '2' && visitor[j].personalData.ic[1] <= '1')) {

					visitor[j].personalData.age = t.wYear - (2000 + (((visitor[j].personalData.ic[0] - 48) * 10) + (visitor[j].personalData.ic[1] - 48)));
				}
				else {
					visitor[j].personalData.age = t.wYear - (1900 + (((visitor[j].personalData.ic[0] - 48) * 10) + (visitor[j].personalData.ic[1] - 48)));
				}
				break;

			case 3:
				do {
					printf("\nEnter New Visitor Category (eg. TUTOR): ");
					rewind(stdin);
					gets(visitor[j].category);
				} while (validationString(visitor[j].category, "person name"));

				for (int i = 0; i < strlen(visitor[j].category); i++) {
					visitor[j].category[i] = toupper(visitor[j].category[i]);
				}
				break;

			case 4:
				do {
					printf("\nEnter New Lastest Venue Visit : ");
					rewind(stdin);
					gets(visitor[j].latestVisit);
				} while (validationString(visitor[j].latestVisit, "venue"));

				for (int i = 0; i < strlen(visitor[j].latestVisit); i++) {
					visitor[j].latestVisit[i] = toupper(visitor[j].latestVisit[i]);
				}
				break;

			case 5:
				do {
					visitor[j].date.day = 0;// delete the previous data that saved in these variables
					visitor[j].date.month = 0;
					visitor[j].date.year = 0;

					printf("\nEnter New Date (dd/mm/yyyy): ");
					rewind(stdin);
					scanf("%d/%d/%d", &visitor[j].date.day, &visitor[j].date.month, &visitor[j].date.year);
				} while (validationDate(visitor[j].date.day, visitor[j].date.month, visitor[j].date.year));
				break;

			case 6:
				do {
					visitor[j].time.hr = -1; //delete the previous data that saved in these variables
					visitor[j].time.min = -1;

					printf("\nEnter New Time Visited (hh:mm) : ");
					rewind(stdin);
					scanf("%d:%d", &visitor[j].time.hr, &visitor[j].time.min);
				} while (validationTime(visitor[j].time.hr, visitor[j].time.min));
				break;

			case 7:
				do {
					printf("\nEnter New Visitor Contact Number (123-45678900) : ");
					rewind(stdin);
					gets(visitor[j].contactNum);
				} while (validationString(visitor[j].contactNum, "contact number"));
				break;

			case 8:
				do {
					printf("\nEnter New Temperature of Visitor : ");
					scanf("%lf", &visitor[j].temperature);

					if (!(visitor[j].temperature > 35 && visitor[j].temperature < 42)) {
						red();
						printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
						reset();
					}

				} while (!(visitor[j].temperature > 35 && visitor[j].temperature < 42));
				break;

			default:
				do {
					rewind(stdin);
					printf("\nEnter New Visitor Name : ");
					gets(visitor[j].personalData.name);
				} while (validationString(visitor[j].personalData.name, "person name"));


				for (int i = 0; i < strlen(visitor[j].personalData.name); i++) {
					visitor[j].personalData.name[i] = toupper(visitor[j].personalData.name[i]);
				}

				do {

					do {
						printf("\nEnter New Visitor IC NO (xxxxxx-xx-xxxx) : ");
						gets(visitor[j].personalData.ic);

						if (strlen(visitor[j].personalData.ic) != 14) {

							red();
							printf("<ERROR>Invalid!!!Please enter full IC NO include with '-' character.<ERROR>\n");
							reset();
						}
						else {
							if (visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-') {
								red();
								printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
								reset();
							}
						}


					} while (strlen(visitor[j].personalData.ic) != 14 || visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-');


					for (num = 0; num < strlen(visitor[j].personalData.ic); num++) {
						if (num == 6 || num == 9) {
							continue;
						}
						else if (isdigit(visitor[j].personalData.ic[num]) == 0) {
							red();
							printf("<ERROR>You have enter invalid character!!!Please enter IC NO with number only<ERROR>\n");
							reset();
							break;
						}
						else if (num == strlen(visitor[j].personalData.ic) - 1) {
							break; //避免num跳回去加多一次value //to avoid num to be added one more time
						}
					}

				} while (isdigit(visitor[j].personalData.ic[num]) == 0);

				if (visitor[j].personalData.ic[13] % 2 == 0)
					visitor[j].personalData.gender = 'F';
				else
					visitor[j].personalData.gender = 'M';

				GetLocalTime(&t);

				if (visitor[j].personalData.ic[0] == '0' || visitor[j].personalData.ic[0] == '1' || (visitor[j].personalData.ic[0] == '2' && visitor[j].personalData.ic[1] <= '1')) {

					visitor[j].personalData.age = t.wYear - (2000 + (((visitor[j].personalData.ic[0] - 48) * 10) + (visitor[j].personalData.ic[1] - 48)));
				}
				else {
					visitor[j].personalData.age = t.wYear - (1900 + (((visitor[j].personalData.ic[0] - 48) * 10) + (visitor[j].personalData.ic[1] - 48)));
				}

				do {
					printf("\nEnter New Visitor Category (eg. TUTOR): ");
					rewind(stdin);
					gets(visitor[j].category);
				} while (validationString(visitor[j].category, "person name"));

				for (int i = 0; i < strlen(visitor[j].category); i++) {
					visitor[j].category[i] = toupper(visitor[j].category[i]);
				}

				do {
					printf("\nEnter New Lastest Venue Visit : ");
					rewind(stdin);
					gets(visitor[j].latestVisit);
				} while (validationString(visitor[j].latestVisit, "venue"));

				for (int i = 0; i < strlen(visitor[j].latestVisit); i++) {
					visitor[j].latestVisit[i] = toupper(visitor[j].latestVisit[i]);
				}
				
				do {
					visitor[j].date.day = 0;// delete the previous data that saved in these variables
					visitor[j].date.month = 0;
					visitor[j].date.year = 0;

					printf("\nEnter New Date (dd/mm/yyyy): ");
					rewind(stdin);
					scanf("%d/%d/%d", &visitor[j].date.day, &visitor[j].date.month, &visitor[j].date.year);
				} while (validationDate(visitor[j].date.day, visitor[j].date.month, visitor[j].date.year));

				do {
					visitor[j].time.hr = -1; //delete the previous data that saved in these variables
					visitor[j].time.min = -1;

					printf("\nEnter New Time Visited (hh:mm) : ");
					rewind(stdin);
					scanf("%d:%d", &visitor[j].time.hr, &visitor[j].time.min);
				} while (validationTime(visitor[j].time.hr, visitor[j].time.min));

				do {
					printf("\nEnter New Visitor Contact Number (123-45678900) : ");
					rewind(stdin);
					gets(visitor[j].contactNum);
				} while (validationString(visitor[j].contactNum, "contact number"));

				do {
					printf("\nEnter New Temperature of Visitor : ");
					scanf("%lf", &visitor[j].temperature);

					if (!(visitor[j].temperature > 35 && visitor[j].temperature < 42)) {
						red();
						printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
						reset();
					}

				} while (!(visitor[j].temperature > 35 && visitor[j].temperature < 42));

			}

			printf("\n\nLoading");
			for (int i = 0; i < 8; i++)
			{
				Sleep(300);
				printf(".");

			}
			printf("\nMODIFY SUCCESSFULLY\n");

			printf("\nNEW RECORD : \n");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].date.day, visitor[j].date.month, visitor[j].date.year, visitor[j].time.hr, visitor[j].time.min, "", visitor[j].contactNum, visitor[j].temperature, "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n\n");
			record++;

			fileFunction(&fptr, "Visitor Information.dat", "wb", "bin");
			fwrite(&visitor, sizeof(Details), count, fptr);
			fclose(fptr);

		}


		do {
			printf("\ncontinue to modify more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

	printf("\n<%d record(s) modified>\n", record);



}
void displayVisitorInformation() {
	Details visitor;
	FILE* fptr;
	SYSTEMTIME t;
	int no = 1, record = 0;

	fileFunction(&fptr, "Visitor Information.dat", "rb", "bin");

	GetLocalTime(&t);
	printf("\nVisitor Information - as until %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
	printf("\n+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
	printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
	printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");


	while (fread(&visitor, sizeof(Details), 1, fptr) != 0) {
		printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor.personalData.name, visitor.personalData.ic, visitor.personalData.gender, visitor.personalData.age, visitor.category, visitor.latestVisit, visitor.date.day, visitor.date.month, visitor.date.year, visitor.time.hr, visitor.time.min, "", visitor.contactNum, visitor.temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		no++;
		record++;
	}

	printf("\n<%d records listed>\n", record);

	fclose(fptr);

}
void deleteVisitorInformation() {
	Details readVisitor;
	Details visitor[100];
	int count = 0, deleted = 0, num, no, j;
	char decide, yesNo;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb", "bin");

	while (fread(&readVisitor, sizeof(Details), 1, fptr) != 0) {
		visitor[count] = readVisitor;
		count++;
	}

	fclose(fptr);

	do {
		displayVisitorInformation();
		no = 0;

		if (count == 0) {
			printf("\nNO RECORD FOUND\n");
			break;
		}
		do {
			printf("\nEnter NO. of visitor to be deleted : >NO. ");
			rewind(stdin);
			scanf("%d", &no);

			if (!(no > 0 && no <= count)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", count);
				reset();
			}

		} while (!(no > 0 && no <= count));

		j = no - 1;

		printf("\nVisitor Information : \n");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].date.day, visitor[j].date.month, visitor[j].date.year, visitor[j].time.hr, visitor[j].time.min, "", visitor[j].contactNum, visitor[j].temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

		do {
			printf("\nConfirm to delete the record(s) ? (Y/y = yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &decide);

			if (toupper(decide) != 'Y' && toupper(decide) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(decide) != 'Y' && toupper(decide) != 'N');

		if (toupper(decide) == 'Y') {
			if (!(j == count - 1)) {

				for (int k = j; k < count - 1; k++) {
					visitor[k] = visitor[k + 1];
				}
			}
			count--;

			printf("\n");
			printf("Loading");
			for (int i = 0; i < 8; i++)
			{
				Sleep(300);
				printf(".");

			}

			fileFunction(&fptr, "Visitor Information.dat", "wb", "bin");
			fwrite(&visitor, sizeof(Details), count, fptr);
			fclose(fptr);

			printf("\nDELETE SUCCESSFULLY\n");

			deleted++;
		}

		do {
			printf("\ncontinue to delete more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

	printf("\n<%d record(s) deleted>\n", deleted);
}
void reportVisitorInformation() {
	Details visitor[100];
	FILE* fptr;
	int no = 0, count = 0, choice;
	char yesNo;

	fileFunction(&fptr, "Visitor Information.dat", "rb", "bin");

	while (fread(&visitor[count], sizeof(Details), 1, fptr) != 0) {
		count++;
	}

	fclose(fptr);

	do {
		choice = 0;
		do {

			printf("\n\n+============================================================+\n");
			printf("|                      VISITOR REPOERT                       |\n");
			printf("+============================================================+\n");
			printf("|            Please select your option down below:           |\n");
			printf("|              1. STUDENT                                    |\n");
			printf("|              2. TARUC STAFF                                |\n");
			printf("|              3. MALE                                       |\n");
			printf("|              4. FEMALE                                     |\n");
			printf("|              5. VISITOR WITH HIGH TEMPERATURE              |\n");
			printf("+============================================================+\n\n");


			printf("Enter your choice : ");
			rewind(stdin);
			scanf("%d", &choice);

			if (!(choice >= 1 && choice <= 5)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to 5)!!!<ERROR>\n");
				reset();
			}

		} while (!(choice >= 1 && choice <= 5));

		if (choice == 1) {
			printf("\n %70s CATEGORY : STUDENT\n", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (strcmp(visitor[i].category, "STUDENT") == 0) {
					if (visitor[i].temperature < 37.4) {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
					}
					else {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature);
						red();
						printf("(HIGH)    ");
						reset();
						printf("|\n");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
				}

			}
			if (no == 0)
				printf("\n<No record found>\n");
			else
				printf("\n<There are total of %d student(s)>\n", no);
		}

		else if (choice == 2) {
			no = 0;
			printf("\n\n %70s CATEGORY : TARUC STAFF\n", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (strcmp(visitor[i].category, "STUDENT") != 0) {
					if (visitor[i].temperature < 37.4) {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature);
						red();
						printf("(HIGH)    ");
						reset();
						printf("|\n");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
				}
			}
			if (no == 0)
				printf("\n<No record found>\n");
			else
				printf("\n<There are total of %d TARUC staff(s)>\n", no);
		}

		else if (choice == 3) {
			no = 0;
			printf("\n\n %70s GENDER : Male\n", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (visitor[i].personalData.gender == 'M') {
					if (visitor[i].temperature < 37.4) {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature);
						red();
						printf("(HIGH)    ");
						reset();
						printf("|\n");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
					}
				}
			}
			if (no == 0)
				printf("\n<No record found>\n");
			else
				printf("\n<There are total of %d Male(s)>\n", no);
		}

		else if (choice == 4) {
			no = 0;
			printf("\n\n %70s GENDER : Female\n", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (visitor[i].personalData.gender == 'F') {
					if (visitor[i].temperature < 37.4) {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature);
						red();
						printf("(HIGH)    ");
						reset();
						printf("|\n");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
					}
				}
			}
			if (no == 0)
				printf("\n<No record found>\n");
			else
				printf("\n<There are total of %d Female(s)>\n", no);
		}

		else {
			no = 0;
			red();
			printf("\n\n %70s Visitor with HIGH TEMPERATURE\n", "");
			reset();
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (visitor[i].temperature >= 37.4) {
					no++;
					printf("|%2d. |%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].date.day, visitor[i].date.month, visitor[i].date.year, visitor[i].time.hr, visitor[i].time.min, "", visitor[i].contactNum, visitor[i].temperature, "");
					printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

				}

			}
			if (no == 0)
				printf("\n<No record found>\n");
			else
				printf("\n<There are total of %d Visitor(s) with HIGH TEMPERATURE>\n", no);

		}

		do {
			printf("\ncontinue to see more reports?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

}

//sanitization record
void sanitizationRecordLogo() {
	Sleep(200);
	red();
	printf("                             $$\\  $$\\     $$\\                   $$\\     $$\\                                                                                   $$\\ \n");
	Sleep(200);
	printf("                             \\__| $$ |    \\__|                  $$ |    \\__|                                                                                  $$ |\n");
	Sleep(200);
	printf(" $$$$$$$\\ $$$$$$\\  $$$$$$$\\  $$\\$$$$$$\\   $$\\ $$$$$$$$\\$$$$$$\\$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\         $$$$$$\\   $$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$$ |\n");
	Sleep(200);
	printf("$$  _____|\\____$$\\ $$  __$$\\ $$ \\_$$  _|  $$ |\\____$$  \\____$$\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\       $$  __$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$ |\n");
	Sleep(200);
	printf("\\$$$$$$\\  $$$$$$$ |$$ |  $$ |$$ | $$ |    $$ |  $$$$ _/$$$$$$$ |$$ |    $$ |$$ /  $$ |$$ |  $$ |      $$ |  \\__|$$$$$$$$ |$$ /      $$ /  $$ |$$ |  \\__|$$ /  $$ |\n");
	Sleep(200);
	yellow();
	printf(" \\____$$\\$$  __$$ |$$ |  $$ |$$ | $$ |$$\\ $$ | $$  _/ $$  __$$ |$$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |      $$ |      $$   ____|$$ |      $$ |  $$ |$$ |      $$ |  $$ |\n");
	Sleep(200);
	printf("$$$$$$$  \\$$$$$$$ |$$ |  $$ |$$ | \\$$$$  |$$ |$$$$$$$$\\$$$$$$$ |\\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |      $$ |      \\$$$$$$$\\ \\$$$$$$$\\ \\$$$$$$  |$$ |      \\$$$$$$$ |\n");
	Sleep(200);
	printf("\\_______/ \\_______|\\__|  \\__|\\__|  \\____/ \\__|\\________\\_______| \\____/ \\__| \\______/ \\__|  \\__|      \\__|       \\_______| \\_______| \\______/ \\__|       \\_______|\n");
	reset();
}
void addSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "a", "txt");
	char chosen, yesNo;
	Records sanitizationRecords;
	printf("\nSanitization Records\n");
	printf("====================\n");
	do {
		//to prevent bug of repeat second time 
		sanitizationRecords.date.day = -1, sanitizationRecords.date.month = -1, sanitizationRecords.date.year = -1;
		sanitizationRecords.sanitizationCompany.activeTimeStart.hr = -1, sanitizationRecords.sanitizationCompany.activeTimeStart.min = -1;
		sanitizationRecords.sanitizationCompany.activeTimeEnd.hr = -1, sanitizationRecords.sanitizationCompany.activeTimeEnd.min = -1;

		do {
			printf("Enter Date(day-month-year)>");
			rewind(stdin);
			scanf("%d-%d-%d", &sanitizationRecords.date.day, &sanitizationRecords.date.month, &sanitizationRecords.date.year);
		} while (validationDate(sanitizationRecords.date.day, sanitizationRecords.date.month, sanitizationRecords.date.year));

		do {
			chosen = 'n';
			do {
				printf("Enter start time(XX:XX)>");
				rewind(stdin);
				scanf("%d:%d", &sanitizationRecords.startTime.hr, &sanitizationRecords.startTime.min);
			} while (validationTime(sanitizationRecords.startTime.hr, sanitizationRecords.startTime.min));

			do {
				printf("Enter end time(XX:XX)>");
				rewind(stdin);
				scanf("%d:%d", &sanitizationRecords.endTime.hr, &sanitizationRecords.endTime.min);
			} while (validationCompareTime(sanitizationRecords.startTime.hr, sanitizationRecords.startTime.min, sanitizationRecords.endTime.hr, sanitizationRecords.endTime.min, &chosen, "sanitization time") || validationTime(sanitizationRecords.startTime.hr, sanitizationRecords.startTime.min));

		} while (chosen == 'y' || chosen == 'Y');

		do {
			printf("Enter venue>");
			rewind(stdin);
			scanf("%[^\n]", &sanitizationRecords.venue);
		} while (validationString(sanitizationRecords.venue, "venue"));

		do {
			printf("Enter sanitization company name>");
			rewind(stdin);
			scanf("%[^\n]", &sanitizationRecords.sanitizationCompany.name);
		} while (validationString(sanitizationRecords.sanitizationCompany.name, "company name"));

		do {
			printf("Enter contact person>");
			rewind(stdin);
			scanf("%[^\n]", &sanitizationRecords.sanitizationCompany.contactPerson);
		} while (validationString(sanitizationRecords.sanitizationCompany.contactPerson, "person name"));

		do {
			printf("Enter mobile phone contact number >");
			rewind(stdin);
			scanf("%[^\n]", &sanitizationRecords.sanitizationCompany.contactNumber);
		} while (validationString(sanitizationRecords.sanitizationCompany.contactNumber, "contact number"));

		do {
			chosen = 'n';
			do {
				printf("Enter start active time(XX:XX)>");
				rewind(stdin);
				scanf("%d:%d", &sanitizationRecords.sanitizationCompany.activeTimeStart.hr, &sanitizationRecords.sanitizationCompany.activeTimeStart.min);
			} while (validationTime(sanitizationRecords.sanitizationCompany.activeTimeStart.hr, sanitizationRecords.sanitizationCompany.activeTimeStart.min));

			do {
				printf("Enter end active time(XX:XX)>");
				rewind(stdin);
				scanf("%d:%d", &sanitizationRecords.sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords.sanitizationCompany.activeTimeEnd.min);
			} while (validationTime(sanitizationRecords.sanitizationCompany.activeTimeEnd.hr, sanitizationRecords.sanitizationCompany.activeTimeEnd.min) || validationCompareTime(sanitizationRecords.sanitizationCompany.activeTimeStart.hr, sanitizationRecords.sanitizationCompany.activeTimeStart.min, sanitizationRecords.sanitizationCompany.activeTimeEnd.hr, sanitizationRecords.sanitizationCompany.activeTimeEnd.min, &chosen, "active time"));

		} while (chosen == 'y' || chosen == 'Y');


		fprintf(file, "%02d-%02d-%04d|", sanitizationRecords.date.day, sanitizationRecords.date.month, sanitizationRecords.date.year);
		fprintf(file, "%02d:%02d|", sanitizationRecords.startTime.hr, sanitizationRecords.startTime.min);
		fprintf(file, "%02d:%02d|", sanitizationRecords.endTime.hr, sanitizationRecords.endTime.min);
		fprintf(file, "%s|", sanitizationRecords.venue);
		fprintf(file, "%s|", sanitizationRecords.sanitizationCompany.name);
		fprintf(file, "%s|", sanitizationRecords.sanitizationCompany.contactPerson);
		fprintf(file, "%s|", sanitizationRecords.sanitizationCompany.contactNumber);
		fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords.sanitizationCompany.activeTimeStart.hr, sanitizationRecords.sanitizationCompany.activeTimeStart.min, sanitizationRecords.sanitizationCompany.activeTimeEnd.hr, sanitizationRecords.sanitizationCompany.activeTimeEnd.min);

		printf("Do you want to add another information?(y/n)");
		do {
			rewind(stdin);
			scanf("%c", &yesNo);
		} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N');
		if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N') {
			printf("Error!Please re-enter again>");
		}
	} while (yesNo == 'y' || yesNo == 'Y');
	fclose(file);
}
void modifySanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	char chosen, yesNo;
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	//enter number to choose record that want to modify
	int choice, j = 0, day, month, year, venue[20];
	char companyName[40];
	do {
		yesNo = 'n';
		int count = 0, moreThanOne = 0;
		do {
			printf("+============================================================+\n");
			printf("|                  Modify Record according to:               |\n");
			printf("|                     1. SANITIZATION COMPANY                |\n");
			printf("|                     2. DATE                                |\n");
			printf("|                     3. VENUE                               |\n");
			printf("|                     4. BACK                                |\n");
			printf("|                     0. EXIT                                |\n");
			printf("+============================================================+\n");
			printf("Please enter your choice:");
			rewind(stdin);
			scanf("%d", &choice);
			if (choice > 4 || choice < 0) {
				printf("Invalid!\n");
			}
		} while (choice > 4 || choice < 0);
		if (choice == 1) {
			do {
				printf("Enter Company Name:");
				rewind(stdin);
				scanf("%[^\n]", &companyName);
			} while (validationString(companyName, "company name"));

			for (j = 0; j < i; j++) {
				if (strcmp(sanitizationRecords[j].sanitizationCompany.name, companyName) == 0) {
					moreThanOne++;
					if (moreThanOne > 1) {
						printf("\nThis is another information need to edit\n");
					}
					do {
						rewind(stdin);
						printf("Enter Date(day-month-year)>");
						scanf("%d-%d-%d", &sanitizationRecords[j].date.day, &sanitizationRecords[j].date.month, &sanitizationRecords[j].date.year);
					} while (validationDate(sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year));

					do {
						do {
							rewind(stdin);
							printf("Enter start time(XX:XX)>");
							scanf("%d:%d", &sanitizationRecords[j].startTime.hr, &sanitizationRecords[j].startTime.min);
						} while (validationTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min));

						do {
							printf("Enter end time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].endTime.hr, &sanitizationRecords[j].endTime.min);
						} while (validationCompareTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min, &chosen, "sanitization time") || validationTime(sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min));
					} while (chosen == 'y' || chosen == 'Y');

					do {
						printf("Enter venue>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].venue);
					} while (validationString(sanitizationRecords[j].venue, "venue"));

					do {
						printf("Enter contact person>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactPerson);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactPerson, "person name"));

					do {
						printf("Enter mobile phone contact number >");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactNumber);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactNumber, "contact number"));

					do {
						chosen = 'n';
						do {
							printf("Enter start active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeStart.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min));

						do {
							printf("Enter end active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min) || validationCompareTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min, &chosen, "active time"));
					} while (chosen == 'y' || chosen == 'Y');
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 2) {
			do {
				printf("Enter Date(day-month-year):");
				rewind(stdin);
				scanf("%d-%d-%d", &day, &month, &year);
			} while (validationDate(day, month, year));

			for (j = 0; j < i; j++) {
				if (day == sanitizationRecords[j].date.day && month == sanitizationRecords[j].date.month && year == sanitizationRecords[j].date.year) {
					moreThanOne++;
					if (moreThanOne > 1) {
						printf("\nThis is another information need to edit\n");
					}
					do {
						do {
							rewind(stdin);
							printf("Enter start time(XX:XX)>");
							scanf("%d:%d", &sanitizationRecords[j].startTime.hr, &sanitizationRecords[j].startTime.min);
						} while (validationTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min));

						do {
							printf("Enter end time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].endTime.hr, &sanitizationRecords[j].endTime.min);
						} while (validationCompareTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min, &chosen, "sanitization time") || validationTime(sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min));
					} while (chosen == 'y' || chosen == 'Y');
					do {
						printf("Enter venue>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].venue);
					} while (validationString(sanitizationRecords[j].venue, "venue"));

					do {
						printf("Enter sanitization company name>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.name);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.name, "company name"));

					do {
						printf("Enter contact person>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactPerson);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactPerson, "person name"));

					do {
						printf("Enter mobile phone contact number >");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactNumber);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactNumber, "contact number"));
					do {
						chosen = 'n';
						do {
							printf("Enter start active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeStart.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min));

						do {
							printf("Enter end active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min) || validationCompareTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min, &chosen, "active time"));
					} while (chosen == 'y' || chosen == 'Y');
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 3) {
			do {
				rewind(stdin);
				printf("Enter Venue:");
				scanf("%[^\n]", &venue);
			} while (validationString(venue, "venue"));

			for (j = 0; j < i; j++) {
				if (strcmp(sanitizationRecords[j].venue, venue) == 0) {
					moreThanOne++;
					if (moreThanOne > 1) {
						printf("\nThis is another information need to edit\n");
					}
					do {
						rewind(stdin);
						printf("Enter Date(day-month-year)>");
						scanf("%d-%d-%d", &sanitizationRecords[j].date.day, &sanitizationRecords[j].date.month, &sanitizationRecords[j].date.year);
					} while (validationDate(sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year));
					do {
						do {
							rewind(stdin);
							printf("Enter start time(XX:XX)>");
							scanf("%d:%d", &sanitizationRecords[j].startTime.hr, &sanitizationRecords[j].startTime.min);
						} while (validationTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min));

						do {
							printf("Enter end time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].endTime.hr, &sanitizationRecords[j].endTime.min);
						} while (validationCompareTime(sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min, &chosen, "sanitization time") || validationTime(sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min));

					} while (chosen == 'y' || chosen == 'Y');

					do {
						printf("Enter sanitization company name>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.name);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.name, "company name"));

					do {
						printf("Enter contact person>");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactPerson);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactPerson, "person name"));

					do {
						printf("Enter mobile phone contact number >");
						rewind(stdin);
						scanf("%[^\n]", &sanitizationRecords[j].sanitizationCompany.contactNumber);
					} while (validationString(sanitizationRecords[j].sanitizationCompany.contactNumber, "contact number"));
					do {
						chosen = 'n';
						do {
							printf("Enter start active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeStart.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min));

						do {
							printf("Enter end active time(XX:XX)>");
							rewind(stdin);
							scanf("%d:%d", &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
						} while (validationTime(sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min) || validationCompareTime(sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min, &chosen, "active time"));
					} while (chosen == 'y' || chosen == 'Y');
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 4) {}
		else {
			exit(-1);
		}
		if (count == i) {
			printf("There are no element you search inside the file\n");
		}
		j = 0;
		fileFunction(&file, "sanitization_record.txt", "w", "txt");
		while (j < i) {
			fprintf(file, "%02d-%02d-%04d|", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
			fprintf(file, "%02d:%02d|", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min);
			fprintf(file, "%02d:%02d|", sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
			fprintf(file, "%s|", sanitizationRecords[j].venue);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.name);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactPerson);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactNumber);
			fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
			j++;
		}
		if (choice != 4 && choice != 0) {
			printf("Do you want to modify another information?(y/n)");
			do {
				rewind(stdin);
				scanf("%c", &yesNo);
			} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N');
			if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N') {
				printf("Error!Please re-enter again>");
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');

	fclose(file);
}
void displaySanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	if (i != 0) {
		printf("\n\n");
		header();
		for (int j = 0; j < i; j++) {
			printf("| %02d-%02d-%04d |", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
			printf(" %02d:%02d-%02d:%02d |", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
			printf(" %20s |", sanitizationRecords[j].venue);
			printf(" %40s |", sanitizationRecords[j].sanitizationCompany.name);
			printf(" %25s |", sanitizationRecords[j].sanitizationCompany.contactPerson);
			printf(" %15s |", sanitizationRecords[j].sanitizationCompany.contactNumber);
			printf(" %02d:%02d-%02d:%02d |\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
			if (j + 1 < i) {
				for (int l = 0; l < 154; l++) {
					if (l == 0 || l == 13 || l == 27 || l == 50 || l == 93 || l == 121 || l == 139)
						printf("+");
					else if (l == 153)
						printf("+\n");
					else
						printf("-");
				}
			}
		}
		line();
		printf("\n|%70s%02d are listed%69s|\n", "", i, "");
		line();
		printf("\n");
	}
	else {
		printf("no data inside the file\n");
	}

}
void searchSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	//enter number to choose record that want to search
	int choice, j, day, month, year, venue[20], count;
	char companyName[40], yesNo;
	do {
		yesNo = 'n', count = 0;
		do {
			rewind(stdin);
			printf("+============================================================+\n");
			printf("|                  Search Record according to:               |\n");
			printf("|                     1. SANITIZATION COMPANY                |\n");
			printf("|                     2. DATE                                |\n");
			printf("|                     3. VENUE                               |\n");
			printf("|                     4. BACK                                |\n");
			printf("|                     0. EXIT                                |\n");
			printf("+============================================================+\n");
			printf("Please enter your choice : ");
			scanf("%d", &choice);
			if (choice > 4 || choice < 0) {
				red();
				printf("Invalid!\n");
				reset();
			}
		} while (choice > 4 || choice < 0);

		if (choice == 1) {
			do {
				printf("Enter Company Name:");
				rewind(stdin);
				scanf("%[^\n]", &companyName);
			} while (validationString(companyName, "company name"));

			header();
			for (j = 0; j < i; j++) {
				if (strcmp(sanitizationRecords[j].sanitizationCompany.name, companyName) == 0) {
					printf("| %02d-%02d-%04d |", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
					printf(" %02d:%02d-%02d:%02d |", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
					printf(" %20s |", sanitizationRecords[j].venue);
					printf(" %40s |", sanitizationRecords[j].sanitizationCompany.name);
					printf(" %25s |", sanitizationRecords[j].sanitizationCompany.contactPerson);
					printf(" %15s |", sanitizationRecords[j].sanitizationCompany.contactNumber);
					printf(" %02d:%02d-%02d:%02d |\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 2) {
			do {
				printf("Enter Date(day-month-year):");
				rewind(stdin);
				scanf("%d-%d-%d", &day, &month, &year);
			} while (validationDate(day, month, year));
			header();
			for (j = 0; j < i; j++) {
				if (day == sanitizationRecords[j].date.day && month == sanitizationRecords[j].date.month && year == sanitizationRecords[j].date.year) {
					printf("| %02d-%02d-%04d |", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
					printf(" %02d:%02d-%02d:%02d |", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
					printf(" %20s |", sanitizationRecords[j].venue);
					printf(" %40s |", sanitizationRecords[j].sanitizationCompany.name);
					printf(" %25s |", sanitizationRecords[j].sanitizationCompany.contactPerson);
					printf(" %15s |", sanitizationRecords[j].sanitizationCompany.contactNumber);
					printf(" %02d:%02d-%02d:%02d |\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 3) {
			do {
				rewind(stdin);
				printf("Enter Venue:");
				scanf("%[^\n]", &venue);
			} while (validationString(venue, "venue"));
			header();
			for (j = 0; j < i; j++) {
				if (strcmp(venue, sanitizationRecords[j].venue) == 0) {
					printf("| %02d-%02d-%04d |", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
					printf(" %02d:%02d-%02d:%02d |", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
					printf(" %20s |", sanitizationRecords[j].venue);
					printf(" %40s |", sanitizationRecords[j].sanitizationCompany.name);
					printf(" %25s |", sanitizationRecords[j].sanitizationCompany.contactPerson);
					printf(" %15s |", sanitizationRecords[j].sanitizationCompany.contactNumber);
					printf(" %02d:%02d-%02d:%02d |\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
				}
				else {
					count++;
				}
			}
		}
		else if (choice == 4) {}
		else {
			exit(-1);
		}
		if (count == i) {
			printf("there are no records match with the name your type\n");
		}
		else {
			line();
			printf("\n");
		}
		if (choice != 4 && choice != 0) {
			printf("Do you want to search another information?(y/n)");
			do {
				rewind(stdin);
				scanf("%c", &yesNo);
			} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N');
			if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N') {
				printf("Error!Please re-enter again>");
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');
}
void deleteSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	//enter number to choose record that want to delete
	int choice, j = 0, day, month, year, venue[20], deleteCount = 0;
	char companyName[40], yesNo;
	do {
		yesNo = 'n';
		do {
			printf("+============================================================+\n");
			printf("|                  Delete Record according to:               |\n");
			printf("|                     1. SANITIZATION COMPANY                |\n");
			printf("|                     2. DATE                                |\n");
			printf("|                     3. VENUE                               |\n");
			printf("|                     4. BACK                                |\n");
			printf("|                     0. EXIT                                |\n");
			printf("+============================================================+\n");
			printf("Please enter your choice : ");
			rewind(stdin);
			scanf("%d", &choice);
			if (choice > 4 || choice < 0) {
				printf("Invalid!\n");
			}
			rewind(stdin);
		} while (choice > 4 || choice < 0);
		if (choice == 1) {
			do {
				printf("Enter Company Name:");
				rewind(stdin);
				scanf("%[^\n]", &companyName);
			} while (validationString(companyName, "company name"));

			for (j = 0; j < i; j++) {
				if (strcmp(sanitizationRecords[j].sanitizationCompany.name, companyName) == 0) {
					deleteCount++;
					for (int l = j; l < i; l++) {
						sanitizationRecords[l] = sanitizationRecords[l + 1];
					}
					j--;
				}
			}
		}
		else if (choice == 2) {
			do {
				printf("Enter Date(day-month-year):");
				rewind(stdin);
				scanf("%d-%d-%d", &day, &month, &year);
			} while (validationDate(day, month, year));
			for (j = 0; j < i; j++) {
				if (day == sanitizationRecords[j].date.day && month == sanitizationRecords[j].date.month && year == sanitizationRecords[j].date.year) {
					deleteCount++;
					for (int l = j; l < i; l++) {
						sanitizationRecords[l] = sanitizationRecords[l + 1];
					}
					j--;
				}

			}
		}
		else if (choice == 3) {
			do {
				rewind(stdin);
				printf("Enter Venue:");
				scanf("%[^\n]", &venue);
			} while (validationString(venue, "venue"));

			for (j = 0; j < i; j++) {
				if (strcmp(venue, sanitizationRecords[j].venue) == 0) {
					deleteCount++;
					for (int l = j; l < i; l++) {
						sanitizationRecords[l] = sanitizationRecords[l + 1];
					}
					j--;
				}
			}
		}
		else if (choice == 4) {}
		else {
			exit(-1);
		}
		if (deleteCount <= 0) {
			printf("There are no file inside");
		}
		printf("\n");
		j = 0;
		fileFunction(&file, "sanitization_record.txt", "w", "txt");
		while (j < i - deleteCount) {
			fprintf(file, "%02d-%02d-%04d|", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
			fprintf(file, "%02d:%02d|", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min);
			fprintf(file, "%02d:%02d|", sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
			fprintf(file, "%s|", sanitizationRecords[j].venue);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.name);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactPerson);
			fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactNumber);
			fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
			j++;
		}
		if (choice != 4 && choice != 0) {
			printf("Do you want to delete another information?(y/n)");
			do {
				rewind(stdin);
				scanf("%c", &yesNo);
			} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N');
			if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N') {
				printf("Error!Please re-enter again>");
			}
		}
	} while (yesNo == 'y' || yesNo == 'Y');
	fclose(file);
}
void backupSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	fileFunction(&file, "sanitization_record_backup.txt", "w", "txt");
	for (int j = 0; j < i; j++) {
		fprintf(file, "%02d-%02d-%04d|", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
		fprintf(file, "%02d:%02d|", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min);
		fprintf(file, "%02d:%02d|", sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
		fprintf(file, "%s|", sanitizationRecords[j].venue);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.name);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactPerson);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactNumber);
		fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
	}

	fclose(file);
}
void recoverSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record_backup.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);
	fileFunction(&file, "sanitization_record.txt", "w", "txt");
	for (int j = 0; j < i; j++) {
		fprintf(file, "%02d-%02d-%04d|", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
		fprintf(file, "%02d:%02d|", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min);
		fprintf(file, "%02d:%02d|", sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
		fprintf(file, "%s|", sanitizationRecords[j].venue);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.name);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactPerson);
		fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactNumber);
		fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
	}
	fclose(file);
}
void menuSanitizationRecord() {
	sanitizationRecordLogo();
	int choice;
	do {
		do {
			printf("\n+============================================================+\n");
			printf("|                           Menu                             |\n");
			printf("+============================================================+\n");
			printf("|            Please select your option down below:           |\n");
			printf("|                     1. ADD RECORD                          |\n");
			printf("|                     2. MODIFY RECORD                       |\n");
			printf("|                     3. SEARCH RECORD                       |\n");
			printf("|                     4. DISPLAY RECORD                      |\n");
			printf("|                     5. DELETE RECORD                       |\n");
			printf("|                     6. SCHEDULE RECORD                     |\n");
			printf("|                     7. BACKUP RECORD                       |\n");
			printf("|                     8. RECOVER RECORD                      |\n");
			printf("|                     9. RETURN TO MAIN PAGE                 |\n");
			printf("|                    10. EXIT                                |\n");
			printf("+============================================================+\n");
			printf("Please enter your choice (1 to 10) : ");
			rewind(stdin);
			scanf("%d", &choice);
		} while (choice < 1 || choice > 10);
		switch (choice) {
		case 1:
			addSanitizationRecord();
			break;
		case 2:
			modifySanitizationRecord();
			break;
		case 3:
			searchSanitizationRecord();
			break;
		case 4:
			displaySanitizationRecord();
			break;
		case 5:
			deleteSanitizationRecord();
			break;
		case 6:
			scheduleSanitizationRecord();
			break;
		case 7:
			backupSanitizationRecord();
			break;
		case 8:
			recoverSanitizationRecord();
			break;
		case 9:
			system("cls");
			main();
			break;
		case 10:
			exit(-1);
			break;
		default:
			printf("ERROR!Please re-enter again\n");
		}
	} while (choice != 10);
}
void scheduleSanitizationRecord() {
	FILE* file;
	fileFunction(&file, "sanitization_record.txt", "r", "txt");
	Records sanitizationRecords[100];
	int i = 0, count = 0;
	while (fscanf(file, "%d-%d-%d|", &sanitizationRecords[i].date.day, &sanitizationRecords[i].date.month, &sanitizationRecords[i].date.year) != EOF) {
		fscanf(file, "%d:%d|", &sanitizationRecords[i].startTime.hr, &sanitizationRecords[i].startTime.min);
		fscanf(file, "%d:%d|", &sanitizationRecords[i].endTime.hr, &sanitizationRecords[i].endTime.min);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].venue);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.name);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactPerson);
		fscanf(file, "%[^|]|", &sanitizationRecords[i].sanitizationCompany.contactNumber);
		fscanf(file, "%d:%d-%d:%d\n", &sanitizationRecords[i].sanitizationCompany.activeTimeStart.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeStart.min, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.hr, &sanitizationRecords[i].sanitizationCompany.activeTimeEnd.min);
		i++;
	}
	fclose(file);

	int j;
	for (j = 0; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if (sanitizationRecords[j].date.year == sanitizationRecords[k].date.year) {
				if (sanitizationRecords[j].date.month == sanitizationRecords[j].date.month) {
					if (sanitizationRecords[j].date.day == sanitizationRecords[k].date.day) {
						if (sanitizationRecords[j].startTime.hr == sanitizationRecords[k].startTime.hr) {
							if (sanitizationRecords[j].startTime.min == sanitizationRecords[k].startTime.min) {
								if (sanitizationRecords[j].endTime.hr == sanitizationRecords[k].endTime.hr) {
									if (sanitizationRecords[j].endTime.min < sanitizationRecords[k].endTime.min) {
										change(j, k, &sanitizationRecords);
									}
								}
								else if (sanitizationRecords[j].endTime.hr > sanitizationRecords[k].endTime.hr) {
									change(j, k, &sanitizationRecords);
								}
							}
							else if (sanitizationRecords[j].startTime.min > sanitizationRecords[k].startTime.min) {
								change(j, k, &sanitizationRecords);
							}
						}
						else if (sanitizationRecords[j].startTime.hr > sanitizationRecords[k].startTime.hr) {
							change(j, k, &sanitizationRecords);
						}
					}
					else if (sanitizationRecords[j].date.day > sanitizationRecords[k].date.day) {
						change(j, k, &sanitizationRecords);
					}

				}
				else if (sanitizationRecords[j].date.month > sanitizationRecords[j].date.month) {
					change(j, k, &sanitizationRecords);
				}
			}
			else if (sanitizationRecords[j].date.year > sanitizationRecords[k].date.year) {
				change(j, k, &sanitizationRecords);
			}
		}
	}
	if (i != 0) {
		printf("\n\n");
		header();
		for (j = 0; j < i; j++) {
			printf("| %02d-%02d-%04d |", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
			printf(" %02d:%02d-%02d:%02d |", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min, sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
			printf(" %20s |", sanitizationRecords[j].venue);
			printf(" %40s |", sanitizationRecords[j].sanitizationCompany.name);
			printf(" %25s |", sanitizationRecords[j].sanitizationCompany.contactPerson);
			printf(" %15s |", sanitizationRecords[j].sanitizationCompany.contactNumber);
			printf(" %02d:%02d-%02d:%02d |\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
		}
		line();
		printf("\n");

		char yesNo;
		do {
			rewind(stdin);
			printf("Do you want to reschedule the time like this in file?(y/n)");
			scanf("%c", &yesNo);
		} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'N' && yesNo != 'n');
		if (yesNo == 'y' || yesNo == 'Y') {
			fileFunction(&file, "sanitization_record.txt", "w", "txt");
			j = 0;
			while (j < i) {
				fprintf(file, "%02d-%02d-%04d|", sanitizationRecords[j].date.day, sanitizationRecords[j].date.month, sanitizationRecords[j].date.year);
				fprintf(file, "%02d:%02d|", sanitizationRecords[j].startTime.hr, sanitizationRecords[j].startTime.min);
				fprintf(file, "%02d:%02d|", sanitizationRecords[j].endTime.hr, sanitizationRecords[j].endTime.min);
				fprintf(file, "%s|", sanitizationRecords[j].venue);
				fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.name);
				fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactPerson);
				fprintf(file, "%s|", sanitizationRecords[j].sanitizationCompany.contactNumber);
				fprintf(file, "%02d:%02d-%02d:%02d\n", sanitizationRecords[j].sanitizationCompany.activeTimeStart.hr, sanitizationRecords[j].sanitizationCompany.activeTimeStart.min, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.hr, sanitizationRecords[j].sanitizationCompany.activeTimeEnd.min);
				j++;
			}
			fclose(file);
		}
	}
	else {
		printf("no data inside the file\n");
	}

}

void change(int j, int k, Records sanitizationRecords[100]) {
	Records temp;
	temp = sanitizationRecords[j];

	sanitizationRecords[j] = sanitizationRecords[k];

	sanitizationRecords[k] = temp;
}
void header() {
	line();
	printf("\n");
	printf("|%12s|%13s|%22s|%42s|%27s|%17s|%13s|\n", " DATE ", " TIME ", " VENUE ", " SANITIZATION COMPANY NAME ", " CONTACT PERSON ", " CONTACT NUMBER ", " ACTIVE TIME ");
	line();
	printf("\n");
}
void line() {
	for (int i = 0; i < 154; i++) {
		printf("=");
	}
}

//staff
void staffRecordLogo() {
	red();
	Sleep(200);
	printf(" $$$$$$\\    $$\\               $$$$$$\\   $$$$$$\\        $$$$$$$\\                                                $$\\ \n");
	Sleep(200);
	printf("$$  __$$\\   $$ |             $$  __$$\\ $$  __$$\\       $$  __$$\\                                               $$ |\n");
	Sleep(200);
	printf("$$ /  \\__|$$$$$$\\   $$$$$$\\  $$ /  \\__|$$ /  \\__|      $$ |  $$ | $$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$$ |\n");
	Sleep(200);
	printf("\\$$$$$$\\  \\_$$  _|  \\____$$\\ $$$$\\     $$$$\\           $$$$$$$  |$$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$ |\n");
	Sleep(200);
	yellow();
	printf(" \\____$$\\   $$ |    $$$$$$$ |$$  _|    $$  _|          $$  __$$< $$$$$$$$ |$$ /      $$ /  $$ |$$ |  \\__|$$ /  $$ |\n");
	Sleep(200);
	printf("$$\\   $$ |  $$ |$$\\$$  __$$ |$$ |      $$ |            $$ |  $$ |$$   ____|$$ |      $$ |  $$ |$$ |      $$ |  $$ |\n");
	Sleep(200);
	printf("\\$$$$$$  |  \\$$$$  \\$$$$$$$ |$$ |      $$ |            $$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ \\$$$$$$  |$$ |      \\$$$$$$$ |\n");
	Sleep(200);
	printf(" \\______/    \\____/ \\_______|\\__|      \\__|            \\__|  \\__| \\_______| \\_______| \\______/ \\__|       \\_______|\n");
	reset();
}
void staffMenu() {

	int option;
	do
	{
		printf("+============================================================+\n");
		printf("|                           Menu                             |\n");
		printf("+============================================================+\n");
		printf("|            Please select your option down below:           |\n");
		printf("|                     1. ADD RECORD                          |\n");
		printf("|                     2. SEARCH RECORD                       |\n");
		printf("|                     3. MODIFY RECORD                       |\n");
		printf("|                     4. DISPLAY RECORD                      |\n");
		printf("|                     5. DELETE RECORD                       |\n");
		printf("|                     6. TEMPERATURE REPORT                  |\n");
		printf("|                     7. RETURN TO MAIN PAGE                 |\n");
		printf("|                     8. EXIT PROGRAME                       |\n");
		printf("+============================================================+\n");
		printf("Enter the number to select eg.(1-8) :");
		rewind(stdin);
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			staffAddFunction(); break;
		case 2:
			staffSearchFunction(); break;
		case 3:
			staffModifyFunction(); break;
		case 4:
			staffDisplayFunction(); break;
		case 5:
			staffDeleteFunction(); break;
		case 6:
			staffReportFunction(); break;
		case 7:
			system("cls");
			main(); break;
		case 8:
			exit(-1); break;
		default:
			red();
			printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
			reset();
		}

	} while (option < 1 || option > 8);

	system("pause");

}
void staffAddFunction()
{
	staffModulePro newModul;
	FILE* staffM;
	int num, position;

	fileFunction(&staffM, "modul.bin", "ab", "bin");

	char option;
	do
	{
		printf("+============================================================+\n");
		printf("Please enter new details down below\n");
		do
		{
			printf("Enter staff name : ");
			rewind(stdin);
			scanf("%[^\n]", &newModul.staffData.staffName);
			for (int i = 0; i < strlen(newModul.staffData.staffName); i++) {
				newModul.staffData.staffName[i] = toupper(newModul.staffData.staffName[i]);
			}
			for (num = 0; num < strlen(newModul.staffData.staffName); num++) {
				if (isalpha(newModul.staffData.staffName[num]) == 0) {
					if (newModul.staffData.staffName[num] != ' ') {
						red();
						printf("<ERROR>Please enter a valid staff name<ERROR>\n");
						reset();
						break;
					}
				}
				else if (num == strlen(newModul.staffData.staffName) - 1) {
					break;//to avoid num to be added one more time
				}
			}
		} while (isalpha(newModul.staffData.staffName[num]) == 0);

		do
		{
			printf("Enter gender (M)ale / (F)emale : ");
			rewind(stdin);
			scanf("%[^\n]", &newModul.staffData.gender);
			for (int i = 0; i < strlen(newModul.staffData.gender); i++) {
				newModul.staffData.gender[i] = toupper(newModul.staffData.gender[i]);
			}
			if (strcmp(newModul.staffData.gender, "M") == 0 || strcmp(newModul.staffData.gender, "MALE") == 0) {
				strcpy(newModul.staffData.gender, "MALE");
			}
			else if (strcmp(newModul.staffData.gender, "F") == 0 || strcmp(newModul.staffData.gender, "FEMALE") == 0) {
				strcpy(newModul.staffData.gender, "FEMALE");
			}
			else {
				red();
				printf("<ERROR>Please enter again with (M)ale / (F)emale <ERROR>\n");
				reset();
			}
		} while (strcmp(newModul.staffData.gender, "MALE") != 0 && strcmp(newModul.staffData.gender, "FEMALE") != 0);

		do
		{
			printf("Enter age : ");
			rewind(stdin);
			scanf("%d", &newModul.staffData.staffAge);
			if (newModul.staffData.staffAge < 12 || newModul.staffData.staffAge > 100)
			{
				red();
				printf("<ERROR>Please enter your real age !<ERROR>\n");
				reset();
			}
		} while (newModul.staffData.staffAge < 12 || newModul.staffData.staffAge > 100);

		do
		{
			printf("Enter position with number eg.(1. Manager/ 2. Staff/ 3. Other) : ");
			rewind(stdin);
			scanf("%d", &position);
			if (position == 1) {
				strcpy(newModul.staffData.position, "MANAGER");
			}
			else if (position == 2) {
				strcpy(newModul.staffData.position, "STAFF");
			}
			else if (position == 3) {
				printf("Other position : ");
				rewind(stdin);
				scanf("%[^\n]", &newModul.staffData.position);
				for (int i = 0; i < strlen(newModul.staffData.position); i++) {
					newModul.staffData.position[i] = toupper(newModul.staffData.position[i]);
				}
			}
			else {
				red();
				printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n");
				reset();
			}
		} while (position < 1 || position>3);

		do
		{
			printf("Faculty eg.(FOCS/FOAS/LIB) : ");
			rewind(stdin);
			scanf("%[^\n]", &newModul.staffData.faculty);
			for (int i = 0; i < strlen(newModul.staffData.faculty); i++) {
				newModul.staffData.faculty[i] = toupper(newModul.staffData.faculty[i]);
			}
			for (num = 0; num < strlen(newModul.staffData.faculty); num++) {
				if (isalpha(newModul.staffData.faculty[num]) == 0) {
					if (newModul.staffData.faculty[num] != ' ') {
						red();
						printf("<ERROR>Please enter a valid faculty<ERROR>\n");
						reset();
						break;
					}
				}
				else if (num == strlen(newModul.staffData.faculty) - 1) {
					break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
				}

			}
		} while (isalpha(newModul.staffData.faculty[num]) == 0);

		do {
			printf("Enter staff temperature eg(36.0) : ");
			rewind(stdin);
			scanf("%lf", &newModul.temp);

			if (!(newModul.temp > 35 && newModul.temp < 42)) {
				red();
				printf("<ERROR>Please enter a valid visitor temperature ( More than 35.0c and Less than 42.0c )<ERROR>\n");
				reset();
			}

		} while (!(newModul.temp > 35 && newModul.temp < 42));

		do {
			do {
				printf("Enter staff phone number eg.(012-3456789) : ");
				rewind(stdin);
				scanf("%[^\n]", &newModul.staffData.phoneNum);

				if (!(strlen(newModul.staffData.phoneNum) >= 11 && strlen(newModul.staffData.phoneNum) <= 13)) {
					red();
					printf("<ERROR>Please enter a valid/full contact number<ERROR>\n");
					reset();
				}
				else
					if (newModul.staffData.phoneNum[3] != '-') {
						red();
						printf("<ERROR>Please use '-' a dash in the fourth place!!!<ERROR>\n");
						reset();
					}

			} while (!(strlen(newModul.staffData.phoneNum) >= 11 && strlen(newModul.staffData.phoneNum) <= 13) || newModul.staffData.phoneNum[3] != '-');

			for (num = 0; num < strlen(newModul.staffData.phoneNum); num++) {
				if (num == 3) {
					continue;
				}
				else if (isdigit(newModul.staffData.phoneNum[num]) == 0) {
					red();
					printf("<ERROR>You have enter invalid character!!!Please enter contact number with number only<ERROR>\n");
					reset();
					break;
				}
				else if (num == strlen(newModul.staffData.phoneNum) - 1)
					break;
			}

		} while (isdigit(newModul.staffData.phoneNum[num]) == 0);

		do {
			printf("Enter date (day/month/year) : ");
			rewind(stdin);
			scanf("%d/%d/%d", &newModul.date.day, &newModul.date.month, &newModul.date.year);
		} while (validationDate(newModul.date.day, newModul.date.month, newModul.date.year));

		do {
			printf("Enter Time Visite in [international time] format (hours:minute) : ");
			rewind(stdin);
			scanf("%d:%d", &newModul.time.hr, &newModul.time.min);
			if (newModul.time.hr < 0 || newModul.time.hr>23 || newModul.time.min < 0 || newModul.time.min >59)
			{
				red();
				printf("<ERROR>Please use enter a valid time !<ERROR>\n");
				reset();
			}
		} while (newModul.time.hr < 0 || newModul.time.hr>23 || newModul.time.min < 0 || newModul.time.min >59);

		printf("Enter activities : ");
		rewind(stdin);
		scanf("%[^\n]", &newModul.activities);
		for (int i = 0; i < strlen(newModul.activities); i++) {
			newModul.activities[i] = toupper(newModul.activities[i]);
		}

		do
		{
			printf("Enter a new id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
			rewind(stdin);
			scanf("%[^\n]", &newModul.staffID);
			for (int i = 0; i < strlen(newModul.staffID); i++) {
				newModul.staffID[i] = toupper(newModul.staffID[i]);
			}
			for (num = 0; num < strlen(newModul.staffID); num++) {
				if (isalpha(newModul.staffID[0]) == 0 || isdigit(newModul.staffID[1]) == 0 || isdigit(newModul.staffID[2]) == 0 || isdigit(newModul.staffID[3]) == 0) {
					if (newModul.staffID[num] != ' ') {
						red();
						printf("<ERROR>Please enter a valid ID<ERROR>\n");
						reset();
						break;
					}
				}
				else if (num == strlen(newModul.staffID) - 1) {
					break;//to avoid num to be added one more time
				}

			}
		} while (isalpha(newModul.staffID[0]) == 0 || isdigit(newModul.staffID[1]) == 0 || isdigit(newModul.staffID[2]) == 0 || isdigit(newModul.staffID[3]) == 0);

		fwrite(&newModul, sizeof(staffModulePro), 1, staffM);

		printf("\nThese data that you key-in have been recorded :D\n");
		do {
			printf("Continew to add a new recorded? (Yes/No) :");
			scanf("%c", &option);

			if (toupper(option) != 'Y' && toupper(option) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(option) != 'Y' && toupper(option) != 'N');

		printf("+============================================================+\n\n");

	} while (toupper(option) == 'Y');

	fclose(staffM);

	if (toupper(option) == 'N')
	{
		staffMenu();
	}

}
void staffSearchFunction()
{
	staffModulePro newModul[200];
	FILE* staffM;

	fileFunction(&staffM, "modul.bin", "rb", "bin");

	int choose, numcase4;
	int number = 1, total = 0;
	int options, day, month, year, checker, totalmodul = 0;
	char id[5], gender[7], position[15], faculty[5];
	char lastoption;

	while (fread(&newModul[totalmodul], sizeof(staffModulePro), 1, staffM) != 0) {
		totalmodul++;
	}

	do
	{
		number = 1;
		do
		{
			printf("+============================================================+\n");
			printf("|              Search information according to :             |\n");
			printf("|                     1. STAFF ID                            |\n");
			printf("|                     2. GENDER                              |\n");
			printf("|                     3. POSITION                            |\n");
			printf("|                     4. FACULTY                             |\n");
			printf("|                     5. RECORDED DATE                       |\n");
			printf("|                     6. EXIT PROGRAM                        |\n");
			printf("+============================================================+\n");
			printf("Enter the number to select eg.(1-6) :");
			rewind(stdin);
			scanf("%d", &options);
			if (options < 1 || options > 6)
			{
				red();
				printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
				reset();
			}
		} while (options < 1 || options > 6);

		switch (options)
		{
		case 1:
			do
			{
				int num;
				printf("Enter a id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
				rewind(stdin);
				scanf("%[^\n]", &id);
				for (int i = 0; i < strlen(id); i++) {
					id[i] = toupper(id[i]);
				}
				for (num = 0; num < strlen(id); num++) {
					if (isalpha(id[0]) == 0 || isdigit(id[1]) == 0 || isdigit(id[2]) == 0 || isdigit(id[3]) == 0) {
						if (id[num] != ' ') {
							red();
							printf("<ERROR>Please enter a valid ID<ERROR>\n");
							reset();
							break;
						}
					}
					else if (num == strlen(id) - 1) {
						break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
					}

				}
			} while (isalpha(id[0]) == 0 || isdigit(id[1]) == 0 || isdigit(id[2]) == 0 || isdigit(id[3]) == 0);

			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

			for (int k = 0; k < totalmodul; k++) {
				if (strcmp(newModul[k].staffID, id) == 0) {
					printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[k].staffData.staffName, newModul[k].staffData.gender, newModul[k].staffData.staffAge, newModul[k].staffData.position, newModul[k].staffData.faculty, newModul[k].temp, "", newModul[k].date.day, newModul[k].date.month, newModul[k].date.year, "", newModul[k].time.hr, newModul[k].time.min, "", newModul[k].staffData.phoneNum, newModul[k].staffID, newModul[k].activities);
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
					number++;
					total++;
				}
				else if (k == totalmodul - 1 && total == 0)
				{
					printf("|%-4s|", "");
					red();
					printf("No record found !%-4s", "");
					reset();
					printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
				}
			}
			printf("(Total of %d record found)\n\n", total);
			fclose(staffM);

			break;

		case 2:
			do
			{
				printf("Enter gender (M)ale / (F)emale : ");
				rewind(stdin);
				scanf("%[^\n]", &gender);
				for (int i = 0; i < strlen(gender); i++) {
					gender[i] = toupper(gender[i]);
				}
				if (strcmp(gender, "M") == 0 || strcmp(gender, "MALE") == 0) {
					strcpy(gender, "MALE");
				}
				else if (strcmp(gender, "F") == 0 || strcmp(gender, "FEMALE") == 0) {
					strcpy(gender, "FEMALE");
				}
				else {
					red();
					printf("<ERROR>Please enter again with (M)ale / (F)emale <ERROR>\n");
					reset();
				}
			} while (strcmp(gender, "MALE") != 0 && strcmp(gender, "FEMALE") != 0);

			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

			for (int k = 0; k < totalmodul; k++) {
				if (strcmp(newModul[k].staffData.gender, gender) == 0) {
					printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[k].staffData.staffName, newModul[k].staffData.gender, newModul[k].staffData.staffAge, newModul[k].staffData.position, newModul[k].staffData.faculty, newModul[k].temp, "", newModul[k].date.day, newModul[k].date.month, newModul[k].date.year, "", newModul[k].time.hr, newModul[k].time.min, "", newModul[k].staffData.phoneNum, newModul[k].staffID, newModul[k].activities);
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
					number++;
					total++;
				}
				else if (k == totalmodul - 1 && total == 0)
				{
					printf("|%-4s|", "");
					red();
					printf("No record found !%-4s", "");
					reset();
					printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
				}
			}
			printf("(Total of %d record found)\n\n", total);
			fclose(staffM);

			break;

		case 3:
			do
			{
				printf("Enter position with number eg.(1. Manager/ 2. Staff/ 3. Other) : ");
				rewind(stdin);
				scanf("%d", &choose);
				if (choose == 1) {
					strcpy(position, "MANAGER");
				}
				else if (choose == 2) {
					strcpy(position, "STAFF");
				}
				else if (choose == 3) {
					printf("Other position : ");
					rewind(stdin);
					scanf("%[^\n]", &position);
					for (int i = 0; i < strlen(position); i++) {
						position[i] = toupper(position[i]);
					}
				}
				else {
					red();
					printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n");
					reset();
				}
			} while (choose < 1 || choose > 3);

			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

			for (int k = 0; k < totalmodul; k++) {
				if (strcmp(newModul[k].staffData.position, position) == 0) {
					printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[k].staffData.staffName, newModul[k].staffData.gender, newModul[k].staffData.staffAge, newModul[k].staffData.position, newModul[k].staffData.faculty, newModul[k].temp, "", newModul[k].date.day, newModul[k].date.month, newModul[k].date.year, "", newModul[k].time.hr, newModul[k].time.min, "", newModul[k].staffData.phoneNum, newModul[k].staffID, newModul[k].activities);
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
					number++;
					total++;
				}
				else if (k == totalmodul - 1 && total == 0)
				{
					printf("|%-4s|", "");
					red();
					printf("No record found !%-4s", "");
					reset();
					printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
				}
			}
			printf("(Total of %d record found)\n\n", total);
			fclose(staffM);

			break;

		case 4:
			do
			{
				printf("Faculty eg.(FOCS/FOAS/LIB) : ");
				rewind(stdin);
				scanf("%[^\n]", &faculty);
				for (int i = 0; i < strlen(faculty); i++) {
					faculty[i] = toupper(faculty[i]);
				}
				for (numcase4 = 0; numcase4 < strlen(faculty); numcase4++) {
					if (isalpha(faculty[numcase4]) == 0) {
						if (faculty[numcase4] != ' ') {
							red();
							printf("<ERROR>Please enter a valid faculty<ERROR>\n");
							reset();
							break;
						}
					}
					else if (numcase4 == strlen(faculty) - 1) {
						break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
					}

				}
			} while (isalpha(faculty[numcase4]) == 0);

			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

			for (int k = 0; k < totalmodul; k++) {
				if (strcmp(newModul[k].staffData.faculty, faculty) == 0) {
					printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[k].staffData.staffName, newModul[k].staffData.gender, newModul[k].staffData.staffAge, newModul[k].staffData.position, newModul[k].staffData.faculty, newModul[k].temp, "", newModul[k].date.day, newModul[k].date.month, newModul[k].date.year, "", newModul[k].time.hr, newModul[k].time.min, "", newModul[k].staffData.phoneNum, newModul[k].staffID, newModul[k].activities);
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
					number++;
					total++;
				}
				else if (k == totalmodul - 1 && total == 0)
				{
					printf("|%-4s|", "");
					red();
					printf("No record found !%-4s", "");
					reset();
					printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
				}
			}
			printf("(Total of %d record found)\n\n", total);
			fclose(staffM);

			break;

		case 5:
			do {
				printf("Enter date (day/month/year) : ");
				rewind(stdin);
				scanf("%d/%d/%d", &day, &month, &year);
			} while (validationDate(day, month, year));

			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

			for (int k = 0; k < totalmodul; k++) {
				if (day == newModul[k].date.day && month == newModul[k].date.month && year == newModul[k].date.year) {
					printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[k].staffData.staffName, newModul[k].staffData.gender, newModul[k].staffData.staffAge, newModul[k].staffData.position, newModul[k].staffData.faculty, newModul[k].temp, "", newModul[k].date.day, newModul[k].date.month, newModul[k].date.year, "", newModul[k].time.hr, newModul[k].time.min, "", newModul[k].staffData.phoneNum, newModul[k].staffID, newModul[k].activities);
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
					number++;
					total++;
				}
				else if (k == totalmodul - 1 && total == 0)
				{
					printf("|%-4s|", "");
					red();
					printf("No record found !%-4s", "");
					reset();
					printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
					printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
				}
			}
			printf("(Total of %d record found)\n\n", total);
			fclose(staffM);

			break;

		case 6:
			staffMenu();
			break;

		default:
			red();
			printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
			reset();
		}



		do {
			total = 0;
			printf("Do you want to continue search? (Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &lastoption);

			if (toupper(lastoption) != 'Y' && toupper(lastoption) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(lastoption) != 'Y' && toupper(lastoption) != 'N');

	} while (toupper(lastoption) == 'Y');

	if (toupper(lastoption) == 'N')
	{
		staffMenu();
	}
}
void staffModifyFunction()
{
	staffModulePro newModul[200];
	staffModulePro moduls;
	FILE* staffM;

	fileFunction(&staffM, "modul.bin", "rb", "bin");

	int totalModuls = 0, totalModify = 0, modifyOption, number, i, num, position;
	char id[5], name[20], option1, decide;

	while (fread(&moduls, sizeof(staffModulePro), 1, staffM) != 0) {
		newModul[totalModuls] = moduls;
		totalModuls++;
	}

	fclose(staffM);

	do
	{
		staffModulePro display;
		FILE* staffM;

		fileFunction(&staffM, "modul.bin", "rb", "bin");

		printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

		int number = 1, total = 0;
		while (fread(&display, sizeof(staffModulePro), 1, staffM) != 0) {
			printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", display.staffData.staffName, display.staffData.gender, display.staffData.staffAge, display.staffData.position, display.staffData.faculty, display.temp, "", display.date.day, display.date.month, display.date.year, "", display.time.hr, display.time.min, "", display.staffData.phoneNum, display.staffID, display.activities);
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			number++;
			total++;
		}
		printf("(Total of %d recorded)\n\n", total);
		fclose(staffM);
		number = 0;
		do
		{
			printf("\nEnter NO. of data to be modify : NO.");
			rewind(stdin);
			scanf("%d", &number);

			if (!(number > 0 && number <= totalModuls)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", totalModuls);
				reset();
			}
		} while (!(number > 0 && number <= totalModuls));

		i = number - 1;

		printf("\nPREVIOUS DATA : \n");
		printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[i].staffData.staffName, newModul[i].staffData.gender, newModul[i].staffData.staffAge, newModul[i].staffData.position, newModul[i].staffData.faculty, newModul[i].temp, "", newModul[i].date.day, newModul[i].date.month, newModul[i].date.year, "", newModul[i].time.hr, newModul[i].time.min, "", newModul[i].staffData.phoneNum, newModul[i].staffID, newModul[i].activities);
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

		do {
			printf("\nSure to Modify(Y/y = Yes, N/n = No)? : ");
			rewind(stdin);
			scanf("%c", &decide);

			if (toupper(decide) != 'Y' && toupper(decide) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}

		} while (toupper(decide) != 'Y' && toupper(decide) != 'N');

		if (toupper(decide) == 'Y')
		{
			do
			{
				printf("+============================================================+\n");
				printf("|              Enter the data that you want to edit          |\n");
				printf("|                     1. STAFF NAME                          |\n");
				printf("|                     2. GENDER                              |\n");
				printf("|                     3. AGE                                 |\n");
				printf("|                     4. POSITION                            |\n");
				printf("|                     5. FACULTY                             |\n");
				printf("|                     6. TEMPERATURE                         |\n");
				printf("|                     7. DATE                                |\n");
				printf("|                     8. TIME VISITED                        |\n");
				printf("|                     9. CONTACT NUMBER                      |\n");
				printf("|                    10. STAFF ID                            |\n");
				printf("|                    11. ACTIVITIES                          |\n");
				printf("|                    12. MODIFY ALL                          |\n");
				printf("|                    13. EXIT PROGRAM                        |\n");
				printf("+============================================================+\n");
				printf("Enter the number to select eg.(1-13) :");
				rewind(stdin);
				scanf("%d", &modifyOption);
				if (modifyOption < 1 || modifyOption > 13)
				{
					red();
					printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
					reset();
				}
			} while (modifyOption < 1 || modifyOption > 13);

			switch (modifyOption)
			{
			case 1:
				do
				{
					printf("\nEnter a new staff name : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.staffName);
					for (int j = 0; j < strlen(newModul[i].staffData.staffName); j++) {
						newModul[i].staffData.staffName[j] = toupper(newModul[i].staffData.staffName[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffData.staffName); num++) {
						if (isalpha(newModul[i].staffData.staffName[num]) == 0) {
							if (newModul[i].staffData.staffName[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid staff name<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffData.staffName) - 1) {
							break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffData.staffName[num]) == 0);
				totalModify++;
				break;

			case 2:
				do
				{
					printf("\nEnter a new gender (M)ale / (F)emale : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.gender);
					for (int x = 0; x < strlen(newModul[i].staffData.gender); x++) {
						newModul[i].staffData.gender[x] = toupper(newModul[i].staffData.gender[x]);
					}
					if (strcmp(newModul[i].staffData.gender, "M") == 0 || strcmp(newModul[i].staffData.gender, "MALE") == 0) {
						strcpy(newModul[i].staffData.gender, "MALE");
					}
					else if (strcmp(newModul[i].staffData.gender, "F") == 0 || strcmp(newModul[i].staffData.gender, "FEMALE") == 0) {
						strcpy(newModul[i].staffData.gender, "FEMALE");
					}
					else {
						red();
						printf("<ERROR>Please enter again with (M)ale / (F)emale <ERROR>\n");
						reset();
					}
				} while (strcmp(newModul[i].staffData.gender, "MALE") != 0 && strcmp(newModul[i].staffData.gender, "FEMALE") != 0);
				totalModify++;
				break;

			case 3:
				do
				{
					printf("\nEnter a new age : ");
					rewind(stdin);
					scanf("%d", &newModul[i].staffData.staffAge);
					if (newModul[i].staffData.staffAge < 12 || newModul[i].staffData.staffAge > 100)
					{
						red();
						printf("<ERROR>Please enter your real age !<ERROR>\n");
						reset();
					}
				} while (newModul[i].staffData.staffAge < 12 || newModul[i].staffData.staffAge > 100);
				totalModify++;
				break;

			case 4:
				do
				{
					printf("\nEnter a new position with number eg.(1. Manager/ 2. Staff/ 3. Other) : ");
					rewind(stdin);
					scanf("%d", &position);
					if (position == 1) {
						strcpy(newModul[i].staffData.position, "MANAGER");
					}
					else if (position == 2) {
						strcpy(newModul[i].staffData.position, "STAFF");
					}
					else if (position == 3) {
						printf("Other position : ");
						rewind(stdin);
						scanf("%[^\n]", &newModul[i].staffData.position);
						for (int h = 0; h < strlen(newModul[i].staffData.position); h++) {
							newModul[i].staffData.position[h] = toupper(newModul[i].staffData.position[h]);
						}
					}
					else {
						red();
						printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n");
						reset();
					}
				} while (position < 1 || position>3);
				totalModify++;
				break;

			case 5:
				do
				{
					printf("\nEnter a new faculty eg.(FOCS/FOAS/LIB) : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.faculty);
					for (int j = 0; j < strlen(newModul[i].staffData.faculty); j++) {
						newModul[i].staffData.faculty[j] = toupper(newModul[i].staffData.faculty[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffData.faculty); num++) {
						if (isalpha(newModul[i].staffData.faculty[num]) == 0) {
							if (newModul[i].staffData.faculty[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid faculty<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffData.faculty) - 1) {
							break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffData.faculty[num]) == 0);
				totalModify++;
				break;

			case 6:
				do {
					printf("Enter a new staff temperature eg(36.0) : ");
					rewind(stdin);
					scanf("%lf", &newModul[i].temp);

					if (!(newModul[i].temp > 35 && newModul[i].temp < 42)) {
						red();
						printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
						reset();
					}

				} while (!(newModul[i].temp > 35 && newModul[i].temp < 42));
				totalModify++;
				break;

			case 7:
				do {
					printf("\nEnter a new date (day/month/year) : ");
					rewind(stdin);
					scanf("%d/%d/%d", &newModul[i].date.day, &newModul[i].date.month, &newModul[i].date.year);
				} while (validationDate(newModul[i].date.day, newModul[i].date.month, newModul[i].date.year));
				totalModify++;
				break;

			case 8:
				do {
					printf("\nEnter a new Time Visite in [international time] format (hours:minute) : ");
					rewind(stdin);
					scanf("%d:%d", &newModul[i].time.hr, &newModul[i].time.min);
					if (newModul[i].time.hr < 0 || newModul[i].time.hr>23 || newModul[i].time.min < 0 || newModul[i].time.min >60)
					{
						red();
						printf("<ERROR>Please use enter a valid time !<ERROR>\n");
						reset();
					}
				} while (newModul[i].time.hr < 0 || newModul[i].time.hr>23 || newModul[i].time.min < 0 || newModul[i].time.min >60);
				totalModify++;
				break;

			case 9:
				do {
					do {
						printf("\nEnter a new staff phone number eg.(012-3456789) : ");
						rewind(stdin);
						scanf("%[^\n]", &newModul[i].staffData.phoneNum);

						if (!(strlen(newModul[i].staffData.phoneNum) >= 11 && strlen(newModul[i].staffData.phoneNum) <= 13)) {
							red();
							printf("<ERROR>Please enter a valid/full contact number<ERROR>\n");
							reset();
						}
						else
							if (newModul[i].staffData.phoneNum[3] != '-') {
								red();
								printf("<ERROR>Please use '-' a dash in the fourth place!!!<ERROR>\n");
								reset();
							}

					} while (!(strlen(newModul[i].staffData.phoneNum) >= 11 && strlen(newModul[i].staffData.phoneNum) <= 13) || newModul[i].staffData.phoneNum[3] != '-');

					for (num = 0; num < strlen(newModul[i].staffData.phoneNum); num++) {
						if (num == 3) {
							continue;
						}
						else if (isdigit(newModul[i].staffData.phoneNum[num]) == 0) {
							red();
							printf("<ERROR>You have enter invalid character!!!Please enter contact number with number only<ERROR>\n");
							reset();
							break;
						}
						else if (num == strlen(newModul[i].staffData.phoneNum) - 1)
							break;
					}

				} while (isdigit(newModul[i].staffData.phoneNum[num]) == 0);
				totalModify++;
				break;

			case 10:
				do
				{
					printf("Enter a new id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffID);
					for (int j = 0; j < strlen(newModul[i].staffID); j++) {
						newModul[i].staffID[j] = toupper(newModul[i].staffID[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffID); num++) {
						if (isalpha(newModul[i].staffID[0]) == 0 || isdigit(newModul[i].staffID[1]) == 0 || isdigit(newModul[i].staffID[2]) == 0 || isdigit(newModul[i].staffID[3]) == 0) {
							if (newModul[i].staffID[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid ID<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffID) - 1) {
							break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffID[0]) == 0 || isdigit(newModul[i].staffID[1]) == 0 || isdigit(newModul[i].staffID[2]) == 0 || isdigit(newModul[i].staffID[3]) == 0);
				totalModify++;
				break;

			case 11:
				printf("\nEnter a new ACTIVITIES : ");
				rewind(stdin);
				scanf("%[^\n]", &newModul[i].activities);
				for (int j = 0; j < strlen(newModul[i].activities); j++) {
					newModul[i].activities[j] = toupper(newModul[i].activities[j]);
				}
				totalModify++;
				break;

			case 12://burh
				do
				{
					printf("\nEnter a new staff name : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.staffName);
					for (int j = 0; j < strlen(newModul[i].staffData.staffName); j++) {
						newModul[i].staffData.staffName[j] = toupper(newModul[i].staffData.staffName[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffData.staffName); num++) {
						if (isalpha(newModul[i].staffData.staffName[num]) == 0) {
							if (newModul[i].staffData.staffName[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid staff name<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffData.staffName) - 1) {
							break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffData.staffName[num]) == 0);

				do
				{
					printf("Enter a new gender (M)ale / (F)emale : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.gender);
					for (int x = 0; x < strlen(newModul[i].staffData.gender); x++) {
						newModul[i].staffData.gender[x] = toupper(newModul[i].staffData.gender[x]);
					}
					if (strcmp(newModul[i].staffData.gender, "M") == 0 || strcmp(newModul[i].staffData.gender, "MALE") == 0) {
						strcpy(newModul[i].staffData.gender, "MALE");
					}
					else if (strcmp(newModul[i].staffData.gender, "F") == 0 || strcmp(newModul[i].staffData.gender, "FEMALE") == 0) {
						strcpy(newModul[i].staffData.gender, "FEMALE");
					}
					else {
						red();
						printf("<ERROR>Please enter again with (M)ale / (F)emale <ERROR>\n");
						reset();
					}
				} while (strcmp(newModul[i].staffData.gender, "MALE") != 0 && strcmp(newModul[i].staffData.gender, "FEMALE") != 0);

				do
				{
					printf("Enter a new age : ");
					rewind(stdin);
					scanf("%d", &newModul[i].staffData.staffAge);
					if (newModul[i].staffData.staffAge < 12 || newModul[i].staffData.staffAge > 100)
					{
						red();
						printf("<ERROR>Please enter your real age !<ERROR>\n");
						reset();
					}
				} while (newModul[i].staffData.staffAge < 12 || newModul[i].staffData.staffAge > 100);

				do
				{
					printf("Enter a new position with number eg.(1. Manager/ 2. Staff/ 3. Other) : ");
					rewind(stdin);
					scanf("%d", &position);
					if (position == 1) {
						strcpy(newModul[i].staffData.position, "MANAGER");
					}
					else if (position == 2) {
						strcpy(newModul[i].staffData.position, "STAFF");
					}
					else if (position == 3) {
						printf("Other position : ");
						rewind(stdin);
						scanf("%[^\n]", &newModul[i].staffData.position);
						for (int h = 0; h < strlen(newModul[i].staffData.position); h++) {
							newModul[i].staffData.position[h] = toupper(newModul[i].staffData.position[h]);
						}
					}
					else {
						red();
						printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n");
						reset();
					}
				} while (position < 1 || position>3);

				do
				{
					printf("Enter a new faculty eg.(FOCS/FOAS/LIB) : ");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffData.faculty);
					for (int j = 0; j < strlen(newModul[i].staffData.faculty); j++) {
						newModul[i].staffData.faculty[j] = toupper(newModul[i].staffData.faculty[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffData.faculty); num++) {
						if (isalpha(newModul[i].staffData.faculty[num]) == 0) {
							if (newModul[i].staffData.faculty[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid faculty<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffData.faculty) - 1) {
							break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffData.faculty[num]) == 0);

				do {
					printf("Enter a new date (day/month/year) : ");
					rewind(stdin);
					scanf("%d/%d/%d", &newModul[i].date.day, &newModul[i].date.month, &newModul[i].date.year);
				} while (validationDate(newModul[i].date.day, newModul[i].date.month, newModul[i].date.year));

				do {
					printf("Enter a new Time Visite in [international time] format (hours:minute) : ");
					rewind(stdin);
					scanf("%d:%d", &newModul[i].time.hr, &newModul[i].time.min);
					if (newModul[i].time.hr < 0 || newModul[i].time.hr>23 || newModul[i].time.min < 0 || newModul[i].time.min >60)
					{
						red();
						printf("<ERROR>Please use enter a valid time !<ERROR>\n");
						reset();
					}
				} while (newModul[i].time.hr < 0 || newModul[i].time.hr>23 || newModul[i].time.min < 0 || newModul[i].time.min >60);

				do {
					do {
						printf("Enter a new staff phone number eg.(012-3456789) : ");
						rewind(stdin);
						scanf("%[^\n]", &newModul[i].staffData.phoneNum);
						if (!(strlen(newModul[i].staffData.phoneNum) >= 11 && strlen(newModul[i].staffData.phoneNum) <= 13)) {
							red();
							printf("<ERROR>Please enter a valid/full contact number<ERROR>\n");
							reset();
						}
						else
							if (newModul[i].staffData.phoneNum[3] != '-') {
								red();
								printf("<ERROR>Please use '-' a dash in the fourth place!!!<ERROR>\n");
								reset();
							}

					} while (!(strlen(newModul[i].staffData.phoneNum) >= 11 && strlen(newModul[i].staffData.phoneNum) <= 13) || newModul[i].staffData.phoneNum[3] != '-');

					for (num = 0; num < strlen(newModul[i].staffData.phoneNum); num++) {
						if (num == 3) {
							continue;
						}
						else if (isdigit(newModul[i].staffData.phoneNum[num]) == 0) {
							red();
							printf("<ERROR>You have enter invalid character!!!Please enter contact number with number only<ERROR>\n");
							reset();
							break;
						}
						else if (num == strlen(newModul[i].staffData.phoneNum) - 1)
							break;
					}

				} while (isdigit(newModul[i].staffData.phoneNum[num]) == 0);

				do
				{
					printf("Enter a new id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
					rewind(stdin);
					scanf("%[^\n]", &newModul[i].staffID);
					for (int j = 0; j < strlen(newModul[i].staffID); j++) {
						newModul[i].staffID[j] = toupper(newModul[i].staffID[j]);
					}
					for (num = 0; num < strlen(newModul[i].staffID); num++) {
						if (isalpha(newModul[i].staffID[0]) == 0 || isdigit(newModul[i].staffID[1]) == 0 || isdigit(newModul[i].staffID[2]) == 0 || isdigit(newModul[i].staffID[3]) == 0) {
							if (newModul[i].staffID[num] != ' ') {
								red();
								printf("<ERROR>Please enter a valid ID<ERROR>\n");
								reset();
								break;
							}
						}
						else if (num == strlen(newModul[i].staffID) - 1) {
							break; //to avoid num to be added one more time
						}

					}
				} while (isalpha(newModul[i].staffID[0]) == 0 || isdigit(newModul[i].staffID[1]) == 0 || isdigit(newModul[i].staffID[2]) == 0 || isdigit(newModul[i].staffID[3]) == 0);


				printf("Enter a new ACTIVITIES : ");
				rewind(stdin);
				scanf("%[^\n]", &newModul[i].activities);
				for (int j = 0; j < strlen(newModul[i].activities); j++) {
					newModul[i].activities[j] = toupper(newModul[i].activities[j]);
				}
				totalModify = totalModify + 10;
				break;

			case 13:
				staffMenu();
				break;

			default:
				red();
				printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
				reset();
				break;
			}

			printf("\nMODIFIED DATA :\n");
			printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[i].staffData.staffName, newModul[i].staffData.gender, newModul[i].staffData.staffAge, newModul[i].staffData.position, newModul[i].staffData.faculty, newModul[i].temp, "", newModul[i].date.day, newModul[i].date.month, newModul[i].date.year, "", newModul[i].time.hr, newModul[i].time.min, "", newModul[i].staffData.phoneNum, newModul[i].staffID, newModul[i].activities);
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			printf("You have modified (%d) data.\n\n", totalModify);


			fileFunction(&staffM, "modul.bin", "wb", "bin");
			if (staffM == NULL)
			{
				perror("Error");
				exit(-1);
			}
			fwrite(&newModul, sizeof(staffModulePro), totalModuls, staffM);
			fclose(staffM);
		}

		do {
			printf("Did you want to continew to modify ? (Y/y = yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &option1);

			if (toupper(option1) != 'Y' && toupper(option1) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(option1) != 'Y' && toupper(option1) != 'N');

	} while (toupper(option1) == 'Y');

	if (toupper(option1) == 'N')
	{
		staffMenu();
	}

}
void staffDisplayFunction()
{
	staffModulePro newModul;
	FILE* staffM;

	fileFunction(&staffM, "modul.bin", "rb", "bin");

	printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
	printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
	printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

	int number = 1, total = 0;
	while (fread(&newModul, sizeof(staffModulePro), 1, staffM) != 0) {
		printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul.staffData.staffName, newModul.staffData.gender, newModul.staffData.staffAge, newModul.staffData.position, newModul.staffData.faculty, newModul.temp, "", newModul.date.day, newModul.date.month, newModul.date.year, "", newModul.time.hr, newModul.time.min, "", newModul.staffData.phoneNum, newModul.staffID, newModul.activities);
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		number++;
		total++;
	}
	if (total == 0) {
		printf("|%-4s|", "");
		red();
		printf("No record found !%-4s", "");
		reset();
		printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("(Total of %d high temperature record)\n\n", total);
		staffMenu();
	}

	printf("(Total of %d recorded)\n\n", total);
	fclose(staffM);

	staffMenu();

}
void staffDeleteFunction()
{
	staffModulePro newModul[200];
	staffModulePro moduls;
	FILE* staffM;

	fileFunction(&staffM, "modul.bin", "rb", "bin");

	int totalModuls = 0, totalDelete = 0, option, number, i;
	char option1, option2;

	while (fread(&moduls, sizeof(staffModulePro), 1, staffM) != 0) {
		newModul[totalModuls] = moduls;
		totalModuls++;
	}

	fclose(staffM);

	do
	{
		staffModulePro display;
		FILE* staffM;

		fileFunction(&staffM, "modul.bin", "rb", "bin");

		printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		if (totalModuls == 0) {
			printf("|%-4s|", "");
			red();
			printf("No record found !%-4s", "");
			reset();
			printf("|%-14s|%-9s|%-15s|%-11s|%-15s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n\n");
			staffMenu();
		}

		int number = 1, total = 0;
		while (fread(&display, sizeof(staffModulePro), 1, staffM) != 0) {
			printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", display.staffData.staffName, display.staffData.gender, display.staffData.staffAge, display.staffData.position, display.staffData.faculty, display.temp, "", display.date.day, display.date.month, display.date.year, "", display.time.hr, display.time.min, "", display.staffData.phoneNum, display.staffID, display.activities);
			printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
			number++;
			total++;
		}
		printf("(Total of %d recorded)\n\n", total);
		fclose(staffM);

		number = 0;
		do
		{
			printf("\nEnter NO. of data to be delete : NO.");
			rewind(stdin);
			scanf("%d", &number);

			if (!(number > 0 && number <= totalModuls)) {
				red();
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", totalModuls);
				reset();
			}
		} while (!(number > 0 && number <= totalModuls));

		i = number - 1;

		printf("\nSTAFF DATA : \n");
		printf("\n+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-3s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");
		printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC%-10s|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", number, "", newModul[i].staffData.staffName, newModul[i].staffData.gender, newModul[i].staffData.staffAge, newModul[i].staffData.position, newModul[i].staffData.faculty, newModul[i].temp, "", newModul[i].date.day, newModul[i].date.month, newModul[i].date.year, "", newModul[i].time.hr, newModul[i].time.min, "", newModul[i].staffData.phoneNum, newModul[i].staffID, newModul[i].activities);
		printf("+====+=====================+==============+=========+===============+===========+===============+=============+==================+====================+=========+===============================+\n");

		do {
			printf("Confirm to delete the data ? (Y/y = yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &option1);

			if (toupper(option1) != 'Y' && toupper(option1) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(option1) != 'Y' && toupper(option1) != 'N');

		if (toupper(option1) == 'Y') {
			if (!(i == totalModuls - 1)) {

				for (int k = i; k < totalModuls - 1; k++) {
					newModul[k] = newModul[k + 1];
				}
			}
			totalModuls--;

			fileFunction(&staffM, "modul.bin", "wb", "bin");
			fwrite(&newModul, sizeof(staffModulePro), totalModuls, staffM);
			fclose(staffM);
			totalDelete++;
		}

		do {
			printf("\nContinue to delete more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &option2);

			if (toupper(option2) != 'Y' && toupper(option2) != 'N') {
				red();
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				reset();
			}
		} while (toupper(option2) != 'Y' && toupper(option2) != 'N');

	} while (toupper(option2) == 'Y');

	printf("\n<%d records deletedd>\n", totalDelete);

	if (toupper(option2) == 'N')
	{
		staffMenu();
	}

}
void staffReportFunction() {
	staffModulePro newModul[200];
	FILE* staffM;
	int no = 0, count = 0, choice;
	char yesNo;

	fileFunction(&staffM, "modul.bin", "rb", "bin");

	while (fread(&newModul[count], sizeof(staffModulePro), 1, staffM) != 0) {
		count++;
	}

	fclose(staffM);
	int number = 1, total = 0;

	printf("\n+====+=====================+==============+=========+===============+===========+================+=============+==================+====================+=========+===============================+\n");
	printf("|NO  |STAFF NAME %-10s|GENDER %-7s|AGE %-5s|POSITION %-6s|FACULTY %-3s|TEMPERATURE %-4s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|STAFF ID |ACTIVITIES %-20s|\n", "", "", "", "", "", "", "", "", "", "");
	printf("+====+=====================+==============+=========+===============+===========+================+=============+==================+====================+=========+===============================+\n");
	if (count == 0) {
		printf("|%-4s|", "");
		red();
		printf("No record found !%-4s", "");
		reset();
		printf("|%-14s|%-9s|%-15s|%-11s|%-16s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+================+=============+==================+====================+=========+===============================+\n");
		printf("(Total of %d high temperature record)\n\n", total);
		staffMenu();
	}

	for (int i = 0; i < count; i++) {

		if (newModul[i].temp > 37.4) {
			printf("|%2d.%-1s|%-21s|%-14s|%-9d|%-15s|%-11s|%0.1lfC", number, "", newModul[i].staffData.staffName, newModul[i].staffData.gender, newModul[i].staffData.staffAge, newModul[i].staffData.position, newModul[i].staffData.faculty, newModul[i].temp);
			red();
			printf("(High Temp)", "");
			reset();
			printf("|%02d/%02d/%4d%-3s|%02d:%02d%-13s|%-20s|%-9s|%-31s|\n", newModul[i].date.day, newModul[i].date.month, newModul[i].date.year, "", newModul[i].time.hr, newModul[i].time.min, "", newModul[i].staffData.phoneNum, newModul[i].staffID, newModul[i].activities);
			printf("+====+=====================+==============+=========+===============+===========+================+=============+==================+====================+=========+===============================+\n");
			number++;
			total++;
		}

	}
	if (total == 0) {
		printf("|%-4s|", "");
		red();
		printf("No record found !%-4s", "");
		reset();
		printf("|%-14s|%-9s|%-15s|%-11s|%-16s|%-13s|%-18s|%-20s|%-9s|%-31s|\n", "", "", "", "", "", "", "", "", "", "");
		printf("+====+=====================+==============+=========+===============+===========+================+=============+==================+====================+=========+===============================+\n");
		printf("(Total of %d high temperature record)\n\n", total);
		staffMenu();
	}
	printf("(Total of %d high temperature record)\n\n", total);
	staffMenu();
}
void staffStartFunction() {
	staffRecordLogo();
	int options;
	do {
		printf("+============================================================+\n");
		printf("|                           Start                            |\n");
		printf("+============================================================+\n");
		printf("|            Please select your option down below:           |\n");
		printf("|               1. LOGIN (IF YOU HAVE AN ACC)                |\n");
		printf("|         2. SIGN IN (IF YOU WANT TO CREATE A NEW ACC)       |\n");
		printf("|                  3. RETURN TO MAIN PAGE                    |\n");
		printf("+============================================================+\n");
		printf("Enter the number to select eg.(1-3) :");
		rewind(stdin);
		scanf("%d", &options);

		switch (options)
		{
		case 1:
			staffLoginFunction(); break;
		case 2:
			staffSigninFunction(); break;
		case 3:
			system("cls");
			main(); break;
		default:
			red();
			printf("<ERROR>You have enter an invalid number, Please re-enter.<ERROR>\n\n");
			reset();
		}

	} while (options < 1 || options > 3);
}
void staffLoginFunction() {
	login signindata[200];
	FILE* staffM;
	char loginid[11], loginpass[11];
	int total = 0;
	char option;

	staffM = fopen("login.bin", "rb");

	if (staffM == NULL)
	{
		red();
		printf("Unable to open the file. And there are no data inside the file.\n");
		printf("You can try to sign in for a new account :D\n");
		reset();
		staffStartFunction();
	}


	do
	{
		int num;
		printf("Enter id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
		rewind(stdin);
		scanf("%[^\n]", &loginid);
		for (int i = 0; i < strlen(loginid); i++) {
			loginid[i] = toupper(loginid[i]);
		}
		for (num = 0; num < strlen(loginid); num++) {
			if (isalpha(loginid[0]) == 0 || isdigit(loginid[1]) == 0 || isdigit(loginid[2]) == 0 || isdigit(loginid[3]) == 0) {
				if (loginid[num] != ' ') {
					red();
					printf("<ERROR>Please enter a valid ID<ERROR>\n");
					reset();
					break;
				}
			}
			else if (num == strlen(loginid) - 1) {
				break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
			}

		}
	} while (isalpha(loginid[0]) == 0 || isdigit(loginid[1]) == 0 || isdigit(loginid[2]) == 0 || isdigit(loginid[3]) == 0);
	printf("Enter password (10 input limited) : ");
	rewind(stdin);
	scanf("%[^\n]", &loginpass);

	while (fread(&signindata[total], sizeof(login), 1, staffM) != 0) {
		total++;
	}
	fclose(staffM);

	for (int k = 0; k < total; k++) {

		if (strcmp(signindata[k].id, loginid) == 0 && strcmp(signindata[k].password, loginpass) == 0) {
			printf("Login complete welcome!\n");
			staffMenu();
		}
		else if (k == total - 1) {
			red();
			printf("No record found ! But you can try to sign in a new acocunt :D\n");
			reset();
			staffStartFunction();
		}
	}
}
void staffSigninFunction() {
	login signindata;
	FILE* staffM;

	staffM = fopen("login.bin", "ab");

	do
	{
		int num;
		printf("Enter a new id in ((M)anager / (S)taff + 3 number) eg.(M202) :");
		rewind(stdin);
		scanf("%[^\n]", &signindata.id);
		for (int i = 0; i < strlen(signindata.id); i++) {
			signindata.id[i] = toupper(signindata.id[i]);
		}
		for (num = 0; num < strlen(signindata.id); num++) {
			if (isalpha(signindata.id[0]) == 0 || isdigit(signindata.id[1]) == 0 || isdigit(signindata.id[2]) == 0 || isdigit(signindata.id[3]) == 0) {
				if (signindata.id[num] != ' ') {
					red();
					printf("<ERROR>Please enter a valid ID<ERROR>\n");
					reset();
					break;
				}
			}
			else if (num == strlen(signindata.id) - 1) {
				break; //to avoid num to be added one more time
			}

		}
	} while (isalpha(signindata.id[0]) == 0 || isdigit(signindata.id[1]) == 0 || isdigit(signindata.id[2]) == 0 || isdigit(signindata.id[3]) == 0);
	printf("Enter a new password (10 input limited) : ");
	rewind(stdin);
	scanf("%[^\n]", &signindata.password);

	fwrite(&signindata, sizeof(login), 1, staffM);
	printf("Account have been created ! Now you can try to login :D\n");
	fclose(staffM);
	staffStartFunction();
}

//visitor visit and exit
void visitAndExitRecordLogo() {
	Sleep(200);
	red();
	printf("$$\\    $$\\ $$\\           $$\\  $$\\           $$\\   $$\\       $$$$$$$$\\          $$\\  $$\\           $$$$$$$\\                                                $$\\ \n");
	Sleep(200);
	printf("$$ |   $$ |\\__|          \\__| $$ |          $$$\\  $$ |      $$  _____|         \\__| $$ |          $$  __$$\\                                               $$ |\n");
	Sleep(200);
	printf("$$ |   $$ |$$\\  $$$$$$$\\ $$\\$$$$$$\\         $$$$\\ $$ |      $$ |     $$\\   $$\\ $$\\$$$$$$\\         $$ |  $$ | $$$$$$\\   $$$$$$$\\  $$$$$$\\   $$$$$$\\   $$$$$$$ |\n");
	Sleep(200);
	printf("\\$$\\  $$  |$$ |$$  _____|$$ \\_$$  _|        $$ $$\\$$ |      $$$$$\\   \\$$\\ $$  |$$ \\_$$  _|        $$$$$$$  |$$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ $$  __$$ |\n");
	Sleep(200);
	yellow();
	printf(" \\$$\\$$  / $$ |\\$$$$$$\\  $$ | $$ |          $$ \\$$$$ |      $$  __|   \\$$$$  / $$ | $$ |          $$  __$$< $$$$$$$$ |$$ /      $$ /  $$ |$$ |  \\__|$$ /  $$ |\n");
	Sleep(200);
	printf("  \\$$$  /  $$ | \\____$$\\ $$ | $$ |$$\\       $$ |\\$$$ |      $$ |      $$  $$<  $$ | $$ |$$\\       $$ |  $$ |$$   ____|$$ |      $$ |  $$ |$$ |      $$ |  $$ |\n");
	Sleep(200);
	printf("   \\$  /   $$ |$$$$$$$  |$$ | \\$$$$  |      $$ | \\$$ |      $$$$$$$$\\$$  /\\$$\\ $$ | \\$$$$  |      $$ |  $$ |\\$$$$$$$\\ \\$$$$$$$\\ \\$$$$$$  |$$ |      \\$$$$$$$ |\n");
	Sleep(200);
	printf("    \\_/    \\__|\\_______/ \\__|  \\____/       \\__|  \\__|      \\________\\__/  \\__|\\__|  \\____/       \\__|  \\__| \\_______| \\_______| \\______/ \\__|       \\_______|");
	reset();
}
void mainMenuVisitAndExit()
{
	visitAndExitRecordLogo();
	int selection;
	do {
		rewind(stdin);
		printf("\n...................................... TAR UC Sejahtera Tracking Sytstem ...............................................\n");
		printf("\n");
		printf("\t+=======================================================================================+     \n");
		printf("\t|\t\t\t\tWelcome To Visit And Exit Module\t\t\t|     \n");
		printf("\t|\t\t\t\t1.Add Records    \t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t2.Display Records\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t3.Modify Records\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t4.Delete Records\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t5.Search Records\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t6.Back Up Records     \t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t7.Return To Main Page\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t8.Exit Program\t\t\t\t\t\t|     \n");
		printf("\t|\t\t\t\t                 \t\t\t\t\t|     \n");
		printf("\t+=======================================================================================+     \n");
		printf("\t+=======================================================================================+     \n");
		printf("\t|\t\t\t\tPlease Enter Your Selection >>>\t\t\t\t|     \n");
		printf("\t+=======================================================================================+     \n");
		scanf("%d", &selection);

		switch (selection) {
		case 1:
			addVisitAndExitRecords();
			break;
		case 2:
			displayVisitAndExitRecords();
			break;
		case 3:
			modifyVisitAndExitRecords();
			break;
		case 4:
			deleteVisitAndExitRecords();
			break;
		case 5:
			searchVisitAndExitRecords();
			break;
		case 6:
			backUpVisitAndExitRecords();
			break;
		case 7:
			system("cls");
			main();
			break;
		case 8:
			exit(-1);
			break;
		default:
			red();
			printf("You Have Enter The Wrong/Invalid Selection !\n");
			printf("\n");
			printf("Please Type In According TO The Table\n");
			printf("\n");
			reset();
		}
	} while (selection != 7);
}
void addVisitAndExitRecords()
{
	FILE* fptr;
	int selection, selection2, num = 0;
	int choice;
	Visit in;
	Exit ex;

	do {
		printf("Please Select The Records You Want To Add \n1.Visit Records\n2.Exit Records\nPlease Enter Your Choice >>>");
		scanf("%d", &selection);
	} while (selection != 1 && selection != 2);
	switch (selection)
	{
	case 1:
	{
		fileFunction(&fptr, "visitRecord.txt", "a", "txt");

		do {
			table();
			printf("| Enter Visit details |\n");
			table();
			do {
				printf("Please Enter Your Visit Code (eg :V001) :");
				scanf("%s", &in.visitor.code);
			} while (validationString(in.visitor.code, "code"));

			do {
				printf("Please Enter The Date of Visit (eg:1/1/2021): ");
				rewind(stdin);
				scanf("%d/%d/%d", &in.visitor.date.day, &in.visitor.date.month, &in.visitor.date.year);
			} while (validationDate(in.visitor.date.day, in.visitor.date.month, in.visitor.date.year));

			do {
				printf("Please Enter The Time You Enter Tar UC (hh:mm) : ");
				rewind(stdin);
				scanf("%d:%d", &in.visitor.time.hr, &in.visitor.time.min);
			} while (validationTime(in.visitor.time.hr, in.visitor.time.min));

			do {
				rewind(stdin);
				printf("Kindly Enter Your IC Number (eg:0123456-78-9012) : ");
				gets(in.visitor.Icno);

				if (strlen(in.visitor.Icno) != 14)
				{
					red();
					printf("<ERROR>Please Enter Your Ic Number With The dash '-'<ERROR>\n");
					printf("<ERROR>Keep Repeating The Same Error ?\t            <ERROR>\n");
					printf("<ERROR>Try To Enter The Ic Number In a Proper Way ! <ERROR>\n");
					reset();
				}
				else {
					if (in.visitor.Icno[6] != '-' || in.visitor.Icno[9] != '-') {
						red();
						printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
						reset();
					}
				}


			} while (strlen(in.visitor.Icno) != 14 || in.visitor.Icno[6] != '-' || in.visitor.Icno[9] != '-');


			for (num = 0; num < strlen(in.visitor.Icno); num++) {
				if (num == 6 || num == 9) {
					continue;
				}
				else if (isdigit(in.visitor.Icno[num]) == 0) {
					red();
					printf("<ERROR>You Have Enter The INvalid Character || Please Key In Again According To The Example<ERROR>\n");
					reset();
					break;
				}
				else if (num == strlen(in.visitor.Icno) - 1) {
					break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
				}
			}while (isdigit(in.visitor.Icno[num]) == 0);

			do {
				printf("Please Enter The Venue ID (eg:Lab A) :");
				rewind(stdin);
				scanf("%s", &in.visitor.venueId);
			} while (validationString(in.visitor.venueId, "venue"));

			do {
				rewind(stdin);
				printf("Kindly Key In Your Temperature (eg :36.5) :");
				scanf("%lf", &in.visitTemperature);

				if (!(in.visitTemperature > 35 && in.visitTemperature < 42)) {
					red();
					printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
					reset();
				}

			} while (!(in.visitTemperature > 35 && in.visitTemperature < 42));

			printf("Please Key In Your Purpose of Visit:");
			rewind(stdin);
			scanf("%[^\n]", &in.purposeVisit);


			fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%lf|%s\n", in.visitor.code, in.visitor.date.day, in.visitor.date.month, in.visitor.date.year, in.visitor.time.hr, in.visitor.time.min, in.visitor.Icno, in.visitor.venueId, in.visitTemperature, in.purposeVisit);
			fclose(fptr);


			printf("Do You Wanna Add Others Visit Details? (Y/N) : ");
			rewind(stdin);
			scanf("%c", &selection2);

		} while (selection2 == 'Y' || selection2 == 'y');

		return mainMenuVisitAndExit();
		break;
	}
	case 2:
	{

		fileFunction(&fptr, "exitRecord.txt", "a", "txt");
		do {
			table();
			printf("| Enter Exit details |\n");
			table();
			do {
				printf("Please Enter Your Exit Code (eg :E001) :");
				scanf("%s", &in.visitor.code);
			} while (validationString(in.visitor.code, "code"));
			do {
				printf("Please Enter The Date of Visit (eg:1/1/2021): ");
				rewind(stdin);
				scanf("%d/%d/%d", &in.visitor.date.day, &in.visitor.date.month, &in.visitor.date.year);
			} while (validationDate(in.visitor.date.day, in.visitor.date.month, in.visitor.date.year));
			do {
				printf("Please Enter The Time You Enter Tar UC (hh:mm) : ");
				rewind(stdin);
				scanf("%d:%d", &in.visitor.time.hr, &in.visitor.time.min);
			} while (validationTime(in.visitor.time.hr, in.visitor.time.min));

			do {
				rewind(stdin);
				printf("Kindly Enter Your IC Number (eg:0123456-78-9012) : ");
				gets(in.visitor.Icno);

				if (strlen(in.visitor.Icno) != 14)
				{
					red();
					printf("<ERROR>Please Enter Your Ic Number With The dash '-'<ERROR>\n");
					printf("<ERROR>Keep Repeating The Same Error ?\t            <ERROR>\n");
					printf("<ERROR>Try To Enter The Ic Number In a Proper Way ! <ERROR>\n");


					reset();
				}
				else {
					if (in.visitor.Icno[6] != '-' || in.visitor.Icno[9] != '-') {
						red();
						printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
						reset();
					}
				}


			} while (strlen(in.visitor.Icno) != 14 || in.visitor.Icno[6] != '-' || in.visitor.Icno[9] != '-');


			for (num = 0; num < strlen(in.visitor.Icno); num++) {
				if (num == 6 || num == 9) {
					continue;
				}
				else if (isdigit(in.visitor.Icno[num]) == 0) {
					red();
					printf("<ERROR>You Have Enter The Invalid Character || Please Key In Again According To The Example<ERROR>\n");
					reset();
					break;
				}
				else if (num == strlen(in.visitor.Icno) - 1) {
					break; //±ÜÃânumÌø»ØÈ¥¼Ó¶àÒ»´Îvalue //to avoid num to be added one more time
				}
			}while (isdigit(in.visitor.Icno[num]) == 0);
			do {
				printf("Please Enter The Venue ID (eg:Lab A) :");
				rewind(stdin);
				scanf("%s", &in.visitor.venueId);
			} while (validationString(in.visitor.venueId, "venue"));

			do {
				printf("Please Key In Your Contact Number (eg:012-3456789 ):");
				rewind(stdin);
				gets(ex.phoneNumber);
			} while (validationString(ex.phoneNumber, "contact number"));

			fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%s\n", in.visitor.code, in.visitor.date.day, in.visitor.date.month, in.visitor.date.year, in.visitor.time.hr, in.visitor.time.min, in.visitor.Icno, in.visitor.venueId, ex.phoneNumber);
			fclose(fptr);

			printf("Add next visit details? (Y/N) ->>> ");
			rewind(stdin);
			scanf("%c", &choice);

		} while (choice == 'Y' || choice == 'y');
		break;
	}
	default:
		red();
		printf("Error");
		reset();
	}

}
void displayVisitAndExitRecords()
{
	int count = 0;
	int selection;
	FILE* fptr;
	Visit in;
	Exit ex;

	printf("Please Select The Records You Want To Add \n1.Display Visit Records\n2.Display Exit Records\nPlease Enter Your Choice >>>");
	scanf("%d", &selection);

	switch (selection)
	{
	case 1:
	{
		fileFunction(&fptr, "visitRecord.txt", "r", "txt");
		printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
		time_t t;   // not a primitive datatype
		time(&t);
		printf("\t\t\t\t                                    Visit Records as at %s", ctime(&t));
		printf("===========================================================================================================================================================================================\n");
		printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
		printf("===========================================================================================================================================================================================\n");

		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%lf|%[^\n]\n", &in.visitor.code, &in.visitor.date.day, &in.visitor.date.month, &in.visitor.date.year, &in.visitor.time.hr, &in.visitor.time.min, &in.visitor.Icno, &in.visitor.venueId, &in.visitTemperature, &in.purposeVisit) != EOF)
		{
			printf("%-15s\t", in.visitor.code);
			printf("     %02d/%02d/%4d\t\t\t", in.visitor.date.day, in.visitor.date.month, in.visitor.date.year);
			printf("   %02d:%02d\t\t", in.visitor.time.hr, in.visitor.time.min);
			printf("   %-15s\t", in.visitor.Icno);
			printf("     %-5s\t\t      ", in.visitor.venueId);
			printf("%.1lf\t\t\t", in.visitTemperature);
			printf("     %-20s\n", in.purposeVisit);
			count++;
		}
		printf("\n\t\t\t\t\t\t\t\t\t<Total %d Visit records listed>\n", count);
		printf("===========================================================================================================================================================================================\n");

		fclose(fptr);
		break;
	}

	case 2:
	{
		fileFunction(&fptr, "exitRecord.txt", "r", "txt");


		printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
		time_t t;   // not a primitive datatype
		time(&t);
		printf("\t\t\t\t                                    Exit Records as at %s", ctime(&t));
		printf("===========================================================================================================================================================================================\n");
		printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
		printf("===========================================================================================================================================================================================\n");


		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%[^|]|\n", &ex.visitor.code, &ex.visitor.date.day, &ex.visitor.date.month, &ex.visitor.date.year, &ex.visitor.time.hr, &ex.visitor.time.min, &ex.visitor.Icno, &ex.visitor.venueId, &ex.phoneNumber) != EOF)
		{
			printf("%-15s\t", ex.visitor.code);
			printf("    %02d/%02d/%4d\t\t\t", ex.visitor.date.day, ex.visitor.date.month, ex.visitor.date.year);
			printf("%02d:%02d\t\t\t", ex.visitor.time.hr, ex.visitor.time.min);
			printf("%-5s\t\t\t", ex.visitor.Icno);
			printf("%-5s\t\t\t", ex.visitor.venueId);
			printf("%-20s\n", ex.phoneNumber);
			count++;
		}
		printf("\n\t\t\t\t\t\t\t\t\t<Total %d Exit records listed>\n", count);
		printf("===========================================================================================================================================================================================\n");
		fclose(fptr);
		break;
	}
	default:
		red();
		printf("Error");
		reset();
	}
}
void deleteVisitAndExitRecords()
{
	FILE* fptr;
	int selection;

	Visit in[100];
	Exit ex[100];
	int  pCount = 0, found = 0;
	char visitCode[10], more;
	do {
		printf("Please Select The Records You Want To Delete \n1.Visit Records\n2.Exit Records\nPlease Enter Your Choice >>>");
		scanf("%d", &selection);
	} while (selection != 1 && selection != 2);

	if (selection == 1)
	{
		fileFunction(&fptr, "visitRecord.txt", "r", "txt");

		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%lf|%[^\n]\n", &in[pCount].visitor.code, &in[pCount].visitor.date.day, &in[pCount].visitor.date.month, &in[pCount].visitor.date.year, &in[pCount].visitor.time.hr, &in[pCount].visitor.time.min, &in[pCount].visitor.Icno, &in[pCount].visitor.venueId, &in[pCount].visitTemperature, &in[pCount].purposeVisit) != EOF)
		{
			pCount++;
		}
		fclose(fptr);

		do {
			found = 1;
			do {
				printf("Enter Visit code to delete record ->>>");
				rewind(stdin);
				scanf("%s", &visitCode);
			} while (validationString(visitCode, "code"));


			for (int i = 0; i < pCount; i++) {
				if (visitCode == in[i].visitor.code) {


					for (int i = 0; i < pCount; i++) {
						in[i] = in[i + 1];
					}

				}
			}
			pCount--;

			printf("Any more to delete? (Y=yes || N=no) : ");
			rewind(stdin);
			scanf("%c", &more);

		} while (more == 'Y' || more == 'y');
		fptr = fopen("visitRecord.txt", "w");

		for (int i = 0; i < pCount; i++) {
			fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%lf|%s\n", in[pCount].visitor.code, in[pCount].visitor.date.day, in[pCount].visitor.date.month, in[pCount].visitor.date.year, in[pCount].visitor.time.hr, in[pCount].visitor.time.min, in[pCount].visitor.Icno, in[pCount].visitor.venueId, in[pCount].visitTemperature, in[pCount].purposeVisit);
		}
		fclose(fptr);
		printf("Delete record sucessful...\n");
		printf("Thanks For Using Our System !\n");
		heart();

		return mainMenuVisitAndExit();
	}
	else {
		fileFunction(&fptr, "exitRecord.txt", "r", "txt");
		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%[^|]|\n", &in[pCount].visitor.code, &in[pCount].visitor.date.day, &in[pCount].visitor.date.month, &in[pCount].visitor.date.year, &in[pCount].visitor.time.hr, &in[pCount].visitor.time.min, &in[pCount].visitor.Icno, &in[pCount].visitor.venueId, &ex[pCount].phoneNumber) != EOF)
		{
			pCount++;
		}
		fclose(fptr);

		do {
			found = 1;
			do {
				printf("Enter Exit code to delete record ->>>");
				rewind(stdin);
				scanf("%s", &visitCode);
			} while (validationString(visitCode, "code"));
			for (int i = 0; i < pCount; i++) {
				if (visitCode == in[i].visitor.code) {


					{
						for (int i = 0; i < pCount; i++) {
							ex[i] = ex[i + 1];
						}
					}
				}
			}
			pCount--;

			printf("Any more to delete? (Y=yes) : ");
			rewind(stdin);
			scanf("%c", &more);

		} while (more == 'Y' || more == 'y');
		fptr = fopen("exitRecord.txt", "w");

		for (int i = 0; i < pCount; i++) {
			fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%s\n", in[pCount].visitor.code, in[pCount].visitor.date.day, in[pCount].visitor.date.month, in[pCount].visitor.date.year, in[pCount].visitor.time.hr, in[pCount].visitor.time.min, in[pCount].visitor.Icno, in[pCount].visitor.venueId, ex[pCount].phoneNumber);

		}
		fclose(fptr);
		printf("Your Record Has Been Deleted\n");
		printf("Thanks For Using Our System !\n");
		heart();
		return mainMenuVisitAndExit();
	}

}
void searchVisitAndExitRecords()
{
	FILE* fptr;
	Visit in[100];
	Exit ex[100];
	char vcode[10];
	char date[10];
	char time[8];
	char visitIcno[20];
	char venueId[7];
	char research;

	int x = 0, found = 0, count = 0, pCount = 0;
	int  typeSearch, selection;

	printf("Please Select The Records You Want To Search \n1.Visit Records\n2.Exit Records\nPlease Enter Your Choice >>>");
	scanf("%d", &selection);


	if (selection == 1)
	{
		fileFunction(&fptr, "visitRecord.txt", "r", "txt");
		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%lf|%[^|]|\n", &in[x].visitor.code, &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year, &in[x].visitor.time.hr, &in[x].visitor.time.min, &in[x].visitor.Icno, &in[x].visitor.venueId, &in[x].visitTemperature, &in[x].purposeVisit) != EOF)
		{
			pCount++;
		}
		fclose(fptr);


		do {
			red();
			printf("===================\n");
			reset();
			printf("| Search based on | \n");
			red();
			printf("===================\n\n");
			reset();
			printf("1.Visit Code\n");
			printf("2.Date\n");
			printf("3.Time\n");
			printf("4.Visitor IC No\n");
			printf("5.Venue ID\n");
			printf("Please enter your choice ->>>");
			scanf("%d", &typeSearch);


			switch (typeSearch)
			{
			case 1:
			{

				printf("Visit Code:");
				scanf("%s", &vcode);


				printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");



				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(vcode, in[x].visitor.code) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);

					}
				}
				break;
			}

			case 2:
			{
				printf("Date of visit (eg:1/1/2021): ");
				rewind(stdin);
				scanf("%s", &date);
				printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");

				for (x = 0; x < pCount && found == 0; x++)
				{
					if (strcmp(date, in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year) == 0)
					{

						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);
					}
				}
				break;
			}
			case 3:
			{
				printf("Time of visit : ");
				rewind(stdin);
				scanf("%s", &time);

				printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");
				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(time, in[x].visitor.time.hr, in[x].visitor.time.min) == 0)
					{

						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);
					}
				}
				break;
			}

			case 4:
			{
				printf("Visitor IC No  ");
				rewind(stdin);
				scanf("%s", &visitIcno);

				printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");

				for (x = 0; x < pCount && found == 0; x++)
				{
					if (strcmp(visitIcno, in[x].visitor.Icno) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);
					}
				}
				break;
			}
			case 5:
			{
				printf("Venue ID  :");
				rewind(stdin);
				scanf("%s", &venueId);

				printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");

				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(venueId, in[x].visitor.venueId) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);
					}
				}
				break;
			}
			default:
			{
				red();
				printf("You Have Type The Wrong Number ! Please Type In Again \n");
				reset();
				printf("===================\n");
				printf("| Search based on | \n");
				printf("===================\n\n");
				printf("1.Visit Code\n");
				printf("2.Date\n");
				printf("3.Time\n");
				printf("4.Visitor IC No\n");
				printf("5.Venue ID\n");
				printf("Please enter your choice ->>>");
				scanf("%d", &typeSearch);
				break;
			}
			}
			printf("==================================");
			printf("\nAny more to search (Y/N) ? ->>> ");
			rewind(stdin);
			scanf("%c", &research);

		} while (research == 'Y' || research == 'y');
		fclose(fptr);
		return mainMenuVisitAndExit();

	}
	else
	{
		fileFunction(&fptr, "exitRecord.txt", "r", "txt");
		while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%[^|]|\n", &in[x].visitor.code, &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year, &in[x].visitor.time.hr, &in[x].visitor.time.min, &in[x].visitor.Icno, &in[x].visitor.venueId, &ex[x].phoneNumber) != EOF)
		{
			pCount++;
		}
		do {
			printf("===================\n");
			printf("| Search based on | \n");
			printf("===================\n\n");
			printf("1.Exit Code\n");
			printf("2.Date\n");
			printf("3.Time\n");
			printf("4.Visitor IC No\n");
			printf("5.Venue ID\n");
			printf("6.Phone Number\n");
			printf("Please enter your choice ->>>");
			scanf("%d", &typeSearch);

			switch (typeSearch)
			{
			case 1:
			{
				printf("Exit Code:");
				scanf("%s", &in[x].visitor.code);

				printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");
				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(in[x].visitor.code, in[x].visitor.code) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("%-5s\t\t\t", in[x].visitor.Icno);
						printf("%-5s\t\t\t", in[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);
					}
					break;
				}
			}
			case 2:
			{  printf("Date:");
			scanf("%02d/02d/04d", &date);
			printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
			printf("===========================================================================================================================================================================================\n");
			printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
			printf("===========================================================================================================================================================================================\n");

			for (x = 0; x < pCount && found == 0; x++)
			{
				if (strcmp(in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year, in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year) == 0)
				{
					printf("%-15s\t", in[x].visitor.code);
					printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
					printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
					printf("%-5s\t\t\t", in[x].visitor.Icno);
					printf("%-5s\t\t\t", in[x].visitor.venueId);
					printf("%-20s\n", ex[x].phoneNumber);
				}
			}
			break;
			}
			case 3:
			{
				printf("Time:");
				scanf("%s", &time);
				printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");


				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(time, in[x].visitor.time.hr, in[x].visitor.time.min) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("%-5s\t\t\t", in[x].visitor.Icno);
						printf("%-5s\t\t\t", in[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);
					}
				}
				break;
			}
			case 4:
			{
				printf("Visitor IC No:");
				scanf("%s", &in[x].visitor.Icno);
				printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");
				for (x = 0; x < pCount && found == 0; x++)
				{
					if (strcmp(in[x].visitor.Icno, in[x].visitor.Icno) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("%-5s\t\t\t", in[x].visitor.Icno);
						printf("%-5s\t\t\t", in[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);
					}
				}
				break;
			}
			case 5:
			{
				printf("Venue ID:");
				scanf("%s", &venueId);
				printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");

				for (x = 0; x < pCount && found == 0; x++)
				{

					if (strcmp(venueId, in[x].visitor.venueId) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("%-5s\t\t\t", in[x].visitor.Icno);
						printf("%-5s\t\t\t", in[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);
					}
				}
				break;
			}
			case 6:
			{
				printf("Phone Number:");
				scanf("%s", &ex[x].phoneNumber);
				printf("\n-------------------------------------------------------------------------------------[Exit Details]---------------------------------------------------------------------------------------\n");
				printf("===========================================================================================================================================================================================\n");
				printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
				printf("===========================================================================================================================================================================================\n");
				for (x = 0; x < pCount && found == 0; x++)
				{
					if (strcmp(ex[x].phoneNumber, ex[x].phoneNumber) == 0)
					{
						printf("%-15s\t", in[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("%-5s\t\t\t", in[x].visitor.Icno);
						printf("%-5s\t\t\t", in[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);
					}
				}
				break;
			}
			default:
			{
				printf("Incorrect Number. Enter again \n");
				printf("Search based on-> :\n");
				printf("1.Exit Code\n");
				printf("2.Date\n");
				printf("3.Time\n");
				printf("4.Visitor IC No\n");
				printf("5.Venue ID\n");
				printf("6.Phone Number\n");
				printf("Please enter your choice ->>>");
				scanf("%d", &typeSearch);
				break;
			}
			}
			printf("=============================\n");
			printf("Any more to search (Y/N) ? ->>> ");
			rewind(stdin);
			scanf("%c", &research);

		} while (research == 'Y' || research == 'y');
		fclose(fptr);
		return mainMenuVisitAndExit();

	}
}
void modifyVisitAndExitRecords()
{

	FILE* fptr;
	Visit in[100];
	Exit ex[100];


	//local variable
	char code[10];
	char moreRecord;
	char sureModify;
	int num;

	int x = 0, found = 0;
	int selection;
	int pCount = 0;
	do {
		do {
			printf("Please Select The Records You Want To Add \n1.Modify Visit Records\n2.Modify Exit Records\nPlease Enter Your Choice >>>");
			scanf("%d", &selection);
		} while (selection != 1 && selection != 2);

		if (selection == 1)
		{
			fileFunction(&fptr, "visitRecord.txt", "r", "txt");

			while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%lf|%[^\n]\n", &in[x].visitor.code, &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year, &in[x].visitor.time.hr, &in[x].visitor.time.min, &in[x].visitor.Icno, &in[x].visitor.venueId, &in[x].visitTemperature, &in[x].purposeVisit) != EOF)
			{
				pCount++;
				fclose(fptr);
			}

			do {
				do {
					printf("\n==================================\n");
					printf("Please Enter Your Visit code to be modified->>>");
					rewind(stdin);
					scanf("%s", code);
				} while (code, "code");

				for (x = 0; x < 100 && found == 0; x++)
				{
					if (strcmp(code, in[x].visitor.code) == 0)
					{
						printf("\n Visit details that want to be modified\n");
						printf("\n-------------------------------------------------------------------------------------[Visit Details]---------------------------------------------------------------------------------------\n");
						printf("===========================================================================================================================================================================================\n");
						printf("Visit Code %-7s Date Visit Tar Uc %-8s Time Visit Tar Uc %-8s Visitor Ic Number %-8s Venue ID %-9s Visitor Temperature %-10s Purpose of Visit\n", "", "", "", "", "", "", "", "", "");
						printf("===========================================================================================================================================================================================\n");
						printf("%-15s\t", in[x].visitor.code);
						printf("     %02d/%02d/%4d\t\t\t", in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year);
						printf("   %02d:%02d\t\t", in[x].visitor.time.hr, in[x].visitor.time.min);
						printf("   %-15s\t", in[x].visitor.Icno);
						printf("     %-5s\t\t      ", in[x].visitor.venueId);
						printf("%.1lf\t\t\t", in[x].visitTemperature);
						printf("     %-20s\n", in[x].purposeVisit);

						do {
							printf("Enter new date:");
							rewind(stdin);
							scanf("%d/%d/%d", &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year);
						} while (validationDate(in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year));

						do {
							printf("Enter new time:");
							rewind(stdin);
							scanf("%d:%d", &in[x].visitor.time.hr, &in[x].visitor.time.min);
						} while (validationTime(in[x].visitor.time.hr, in[x].visitor.time.min));

						do {
							rewind(stdin);
							printf("Enter New IC Number (eg:0123456-78-9012) : ");
							gets(in[x].visitor.Icno);

							if (strlen(in[x].visitor.Icno) != 14)
							{
								red();
								printf("<ERROR>Please Enter Your Ic Number With The dash '-'<ERROR>\n");
								printf("<ERROR>Keep Repeating The Same Error ?\t            <ERROR>\n");
								printf("<ERROR>Try To Enter The Ic Number In a Proper Way ! <ERROR>\n");
								reset();
							}
							else {
								if (in[x].visitor.Icno[6] != '-' || in[x].visitor.Icno[9] != '-') {
									red();
									printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
									reset();
								}
							}
						} while (strlen(in[x].visitor.Icno) != 14 || in[x].visitor.Icno[6] != '-' || in[x].visitor.Icno[9] != '-');

						do {
							printf("Enter new venue id:");
							rewind(stdin);
							scanf("%[^\n]", &in[x].visitor.venueId);
						} while (validationString(in[x].visitor.venueId, "venue"));

						do {
							rewind(stdin);
							printf("Enter New Temperature (eg :36.5) :");
							scanf("%lf", &in[x].visitTemperature);

							if (!(in[x].visitTemperature > 35 && in[x].visitTemperature < 42)) {
								red();
								printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
								reset();
							}

						} while (!(in[x].visitTemperature > 35 && in[x].visitTemperature < 42));

						printf("Please Key In Your Purpose of Visit:");
						rewind(stdin);
						scanf("%[^\n]", &in[x].purposeVisit);

						do {
							printf("\n=============================\n");
							printf("Sure to modify (Y/N) ? ->>> ");
							rewind(stdin);
							scanf("%c", &sureModify);
						} while (sureModify != 'Y' && sureModify != 'y' && sureModify == 'N' && sureModify == 'n');

						if (sureModify == 'Y' || sureModify == 'y') {
							fptr = fopen("visitRecord.txt", "w");
							for (x = 0; x < 100; x++) {
								fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%lf|%s\n", in[x].visitor.code, in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year, in[x].visitor.time.hr, in[x].visitor.time.min, in[x].visitor.Icno, in[x].visitor.venueId, in[x].visitTemperature, in[x].purposeVisit);
								tableII();
								fclose(fptr);
								return mainMenuVisitAndExit();
							}
						}
						else if (sureModify == 'N' || sureModify == 'n')
						{
							printf("This Modify have been Cancel\n");
							printf("Thanks For Using Our System !");
							heart();
							fclose(fptr);
						}
					}
				}

			} while (moreRecord == 'Y' || moreRecord == 'y');
		}
		if (selection == 2)
		{

			fileFunction(&fptr, "exitRecord.txt", "a", "txt");


			while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%[^|]|\n", &in[x].visitor.code, &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year, &in[x].visitor.time.hr, &in[x].visitor.time.min, &in[x].visitor.Icno, &in[x].visitor.venueId, &ex[x].phoneNumber) != EOF)
			{
				pCount++;
			}
			fclose(fptr);

			do {
				do {
					printf("\n==================================\n");
					printf("Enter Exit code to be modified->>> ");
					scanf("%s", &code);
				} while (code, "code");

				for (x = 0; x < pCount; x++)
				{
					if (strcmp(code, ex[x].visitor.code) == 0)
					{
						printf("\n Exit details that want to be modified\n");
						printf("===========================================================================================================================================================================================\n");
						printf("Exit Code %-7s Date Exit Tar Uc %-8s Time Exit Tar Uc %-10s Visitor Ic Number %-12s Venue Id %-14s Visitor Phone Number\n", "", "", "", "", "", "");
						printf("===========================================================================================================================================================================================\n");

						printf("%-15s\t", ex[x].visitor.code);
						printf("    %02d/%02d/%4d\t\t\t", ex[x].visitor.date.day, ex[x].visitor.date.month, ex[x].visitor.date.year);
						printf("%02d:%02d\t\t\t", ex[x].visitor.time.hr, ex[x].visitor.time.min);
						printf("%-5s\t\t\t", ex[x].visitor.Icno);
						printf("%-5s\t\t\t", ex[x].visitor.venueId);
						printf("%-20s\n", ex[x].phoneNumber);

						do {
							printf("Enter new date:");
							rewind(stdin);
							scanf("%d/%d/%d", &in[x].visitor.date.day, &in[x].visitor.date.month, &in[x].visitor.date.year);
						} while (validationDate(ex[x].visitor.date.day, ex[x].visitor.date.month, ex[x].visitor.date.year));

						do {
							printf("Enter new time:");
							rewind(stdin);
							scanf("%d:%d", &in[x].visitor.time.hr, &in[x].visitor.time.min);
						} while (validationTime(ex[x].visitor.time.hr, ex[x].visitor.time.min));

						do {
							rewind(stdin);
							printf("Enter New IC Number (eg:0123456-78-9012) : ");
							gets(in[x].visitor.Icno);

							if (strlen(in[x].visitor.Icno) != 14)
							{
								red();
								printf("<ERROR>Please Enter Your Ic Number With The dash '-'<ERROR>\n");
								printf("<ERROR>Keep Repeating The Same Error ?\t            <ERROR>\n");
								printf("<ERROR>Try To Enter The Ic Number In a Proper Way ! <ERROR>\n");
								reset();
							}
							else {
								if (in[x].visitor.Icno[6] != '-' || in[x].visitor.Icno[9] != '-') {
									red();
									printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
									reset();
								}
							}
						} while (strlen(ex[x].visitor.Icno) != 14 || ex[x].visitor.Icno[6] != '-' || ex[x].visitor.Icno[9] != '-');

						do {
							printf("Enter new venue id:");
							rewind(stdin);
							scanf("%[^\n]", &in[x].visitor.venueId);
						} while (validationString(ex[x].visitor.venueId, "venue"));

						do {
							printf("Please Key In Your Contact Number (eg:012-3456789 ):");
							rewind(stdin);
							gets(ex[x].phoneNumber);
						} while (validationString(ex[x].phoneNumber, "contact number"));

						do {
							printf("\n=============================\n");
							printf("Sure to modify (Y/N) ? ->>> ");
							rewind(stdin);
							scanf("%c", &sureModify);
						} while (sureModify == 'Y' && sureModify == 'y' && sureModify == 'N' && sureModify == 'n');

						if (sureModify == 'Y' || sureModify == 'y') {
							fptr = fopen("exitRecord.txt", "w");
							for (x = 0; x < 100; x++) {
								fprintf(fptr, "%s|%d/%d/%d|%d:%d|%s|%s|%lf|%s\n", in[x].visitor.code, in[x].visitor.date.day, in[x].visitor.date.month, in[x].visitor.date.year, in[x].visitor.time.hr, in[x].visitor.time.min, in[x].visitor.Icno, in[x].visitor.venueId, in[x].visitTemperature, in[x].purposeVisit);
								tableII();
								fclose(fptr);
								return mainMenuVisitAndExit();
							}
						}
						else if (sureModify == 'N' || sureModify == 'n')
						{
							printf("Modify have been cancel.....\n");
							printf("Thanks For Using Our System !");
							heart();
							fclose(fptr);
						}

					}
				}
			} while (moreRecord == 'Y' || moreRecord == 'y');
		}
		do {
			printf("\n\n=============================\n");
			printf("Do You Have Any More to Modify ? (Y/N) >>>");
			rewind(stdin);
			scanf("%c", &moreRecord);
			if (moreRecord != 'Y' && moreRecord != 'y' && moreRecord != 'N' && moreRecord != 'n') {
				red();
				printf("Error!!Please reenter again");
				reset();
			}
		} while (moreRecord != 'Y' && moreRecord != 'y' && moreRecord != 'N' && moreRecord != 'n');


	} while (moreRecord == 'Y' || moreRecord == 'y');
}
void backUpVisitAndExitRecords()
{
	FILE* fptr;
	FILE* fptr2;
	int selection;
	char sureBackup;
	Visit in;
	Exit ex;
	int count = 0;

	printf("Please Select The Records You Want To Search \n1.Visit Records\n2.Exit Records\nPlease Enter Your Choice >>>");
	scanf("%d", &selection);

	if (selection == 1)
	{
		fileFunction(&fptr, "visitRecord.txt", "r", "txt");
		fileFunction(&fptr2, "visitRecordBackUpData.txt", "a", "txt");

		printf("\n====================================================\n");
		printf("Are you sure want to back up visit records (Y/N) ? ->>> ");
		rewind(stdin);
		scanf("%c", &sureBackup);

		while (sureBackup == 'Y' || sureBackup == 'y') {
			while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%lf|%[^\n]\n", &in.visitor.code, &in.visitor.date.day, &in.visitor.date.month, &in.visitor.date.year, &in.visitor.time.hr, &in.visitor.time.min, &in.visitor.Icno, &in.visitor.venueId, &in.visitTemperature, &in.purposeVisit) != EOF)
			{
				count++;
			}
			printf("You Have Successful Back Up Your Data\n\n");
			fclose(fptr);
			fclose(fptr2);
			return mainMenuVisitAndExit();
		}


		while (sureBackup == 'N' || sureBackup == 'n') {
			printf("Current Back Up Has Been Cancel\n");
			printf("Thanks For Using Our System !\n");
			heart();

			return mainMenuVisitAndExit();
		}


	}
	else
	{
		fileFunction(&fptr, "exitRecord.txt", "r", "txt");
		fileFunction(&fptr2, "exitRecordBackUpData.txt", "a", "txt");


		printf("\n====================================================\n");
		printf("Are you sure want to back up visit records (Y/N) ? ->>> ");
		rewind(stdin);
		scanf("%c", &sureBackup);

		while (sureBackup == 'Y' || sureBackup == 'y') {
			while (fscanf(fptr, "%[^|]|%d/%d/%d|%d:%d|%[^|]|%[^|]|%[^|]|\n", &ex.visitor.code, &ex.visitor.date.day, &ex.visitor.date.month, &ex.visitor.date.year, &ex.visitor.time.hr, &ex.visitor.time.min, &ex.visitor.Icno, &ex.visitor.venueId, &ex.phoneNumber) != EOF)
			{
				count++;
			}

			printf("You Have Successful Back Up Your Data\n\n");
			fclose(fptr);
			fclose(fptr2);
			return mainMenuVisitAndExit();
		}


		while (sureBackup == 'N' || sureBackup == 'n') {
			printf("Current Back Up Has Been Cancel\n");
			printf("Thanks For Using Our System !\n");
			heart();
		}
		return mainMenuVisitAndExit();
	}

}
void heart()
{
	red();

	int i, j;
	const int n = 10;
	const int time = 0.2;

	for (i = n / 2; i <= n; i += 2)
	{
		for (j = 1; j < n - i; j += 2)
		{
			Sleep(time);
			printf(" ");
			Sleep(time);

		}

		for (j = 1; j <= i; j++)
		{
			Sleep(time);
			printf("V");
			Sleep(time);

		}

		for (j = 1; j <= n - i; j++)
		{
			Sleep(time);
			printf(" ");
			Sleep(time);

		}

		for (j = 1; j <= i; j++)
		{
			Sleep(time);

			printf("V");
			Sleep(time);

		}
		Sleep(time);

		printf("\n");
		Sleep(time);

	}

	for (i = n; i >= 1; i--)
	{
		for (j = i; j < n; j++)
		{
			Sleep(time);

			printf(" ");
			Sleep(time);

		}

		for (j = 1; j <= (i * 2) - 1; j++)
		{
			Sleep(10);
			printf("v");
			Sleep(time);

		}

		Sleep(time);

		printf("\n");
		Sleep(time);

	}
	reset();
	return 0;
}


//validation
int validationDate(int day, int month, int year) {
	SYSTEMTIME t;
	GetLocalTime(&t);
	int repeat = 0;
	if (day < 1 || day > 31 || month < 1 || month > 12 || year <2019 || year > t.wYear) {
		repeat = 1;
		goto date;
	}
	if (year <= t.wYear) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 31 || day < 1) {
				repeat = 1;
				goto date;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0) {
				if (day > 29 || day < 1) {
					repeat = 1;
					goto date;
				}
			}
			else {
				if (day > 28 || day < 1) {
					repeat = 1;
					goto date;
				}
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30 || day < 1) {
				repeat = 1;
				goto date;
			}
		}
	}
	else {
		repeat = 1;
		goto date;
	}
	if (year == t.wYear) {
		if (month > t.wMonth) {
			repeat = 1;
		}
		else if (month < t.wMonth && month >= 1) {
			repeat = 0;
		}
		else {
			if (day <= t.wDay && day >= 1) {
				repeat = 0;
			}
			else {
				repeat = 1;
			}
		}
	}
date:
	if (repeat == 1) {
		red();
		printf("ERROR!!! PLEASE RE-ENTER AGAIN\n");
		reset();
	}
	return repeat;
}
int validationTime(int hr, int min) {
	int repeat;
	if (hr > 23 || hr < 0 || min>59 || min < 0) {
		repeat = 1;
	}
	else {
		repeat = 0;
	}
	if (repeat == 1) {
		red();
		printf("ERROR!!! PLEASE RE-ENTER AGAIN\n");
		reset();
	}
	return repeat;
}
int validationCompareTime(int startHr, int startMin, int endHr, int endMin, char* chosen, char type[30]) {
	int repeat = 0;
	if (endHr < startHr) {
		repeat = 1;
	}
	else {
		int diffMin; char yesNo;
		diffMin = (endHr * 60 + endMin) - (startHr * 60 + startMin);
		if (diffMin < 30 && diffMin > 0) {
			do {
				printf("Are you sure the %s from start until the end just %d min?(y/n) >> ", type, diffMin);
				rewind(stdin);
				scanf("%c", &yesNo);
			} while (yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n');
			if (yesNo == 'y' || yesNo == 'Y') {
				repeat = 0;
			}
			else {
				do {
					rewind(stdin);
					printf("Do you want to recorrect again the start %s?(y/n)", type);
					scanf("%c", &*chosen);
				} while (*chosen != 'Y' && *chosen != 'y' && *chosen != 'N' && *chosen != 'n');
				if (*chosen == 'Y' || *chosen == 'y') {
					repeat = 0;
				}
				else {
					repeat = 1;
				}
			}
		}
		else if (diffMin >= 30) {
			repeat = 0;
		}
		else {
			//repeat start time
			printf("PLEASE RE-ENTER AGAIN\n");
			repeat = 0;
			*chosen = 'y';
		}
	}
activeTime:
	if (repeat == 1) {
		printf("PLEASE RE-ENTER AGAIN\n");
	}
	return repeat;
}
int validationString(char string[100], char validName[20]) {
	int repeat = 0;
	if (strcmp(validName, "venue") == 0 || strcmp(validName, "person name") == 0) {
		for (int i = 0; i < strlen(string); i++) {
			if (!(isalpha(string[i]))) {
				if (string[i] != ' ') {
					repeat = 1;
					break;
				}
			}
		}
	}
	else if (strcmp(validName, "company name") == 0) {
		for (int i = 0; i < strlen(string); i++) {
			if (!(isalpha(string[i]))) {
				if (string[i] != ' ' && string[i] != '.') {
					repeat = 1;
					break;
				}
			}
		}
	}
	else if (strcmp(validName, "contact number") == 0) {
		for (int i = 0; i < strlen(string); i++) {
			if (i == 3) {
				continue;
			}
			else if (!(isdigit(string[i]))) {
				repeat = 1;
				goto contactNumber;
			}
		}
		if (strlen(string) != 11 && strlen(string) != 12) {
			repeat = 1;
			goto contactNumber;
		}
		for (int i = 4; i < strlen(string); i++) {
			if (string[i] > '9' || string[i] < '0') {
				repeat = 1;
				goto contactNumber;
			}
		}
		if (string[0] == '0' && string[1] == '1' && string[3] == '-') {
			repeat = 0;
		}
		else {
			repeat = 1;
		}
	}
	else if (strcmp(validName, "code") == 0) {
		for (int i = 0; i < strlen(string); i++) {
			if (i == 0) {
				if (!(isalpha(string[i]))) {
					repeat = 1;
					break;
				}
			}
			else {
				if (!(isdigit(string[i]))) {
					repeat = 1;
					break;
				}
			}
		}
	}
	//check error
	else {
		red();
		printf("VALID NAME ERROR\n");
		reset();
	}
contactNumber:
	if (repeat == 1) {
		red();
		printf("ERROR!!! PLEASE RE-ENTER AGAIN\n");
		reset();
	}
	return repeat;
}



//other
void fileFunction(FILE** file, char fileName[50], char mode[3], char filetype[4]) {
	if (strcmp(filetype, "txt") == 0) {
		char yesNo;
		*file = fopen(fileName, mode);
		if (strcmp(mode, "a") == 0 || strcmp(mode, "r")) {
			if (*file == NULL) {
				do {
					printf("%s can't open or there are no %s in the folder.\nDo you want to create %s?(Y/N)\n", fileName, fileName, fileName);
					rewind(stdin);
					scanf("%c", &yesNo);
					if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'N' && yesNo != 'n') {
						red();
						printf("<ERROR>You have enter an invalid character, Please re-enter again<ERROR>\n\n");
						reset();
					}
				} while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'N' && yesNo != 'n');
				if (yesNo == 'y' || yesNo == 'y') {
					fclose(*file);
					*file = fopen("fileName", "w");
					if (*file == NULL) {
						printf("%s can't open\n", fileName);
						exit(1);
					}
					fclose(*file);
					printf("File is created.Restart program to run it.\n");
				}
			}
		}
		else if (strcmp(mode, "w") == 0) {
			if (*file == NULL) {
				printf("%s can't open to write\n", fileName);
				exit(1);
			}
		}
	}
	else if (strcmp(filetype, "bin") == 0) {
		char yesNo;
		*file = fopen(fileName, mode);

		if (*file == NULL) {
			if (strcmp(mode, "ab") == 0 || strcmp(mode, "rb") == 0) {
				red();
				perror("Error");
				reset();

				do {
					rewind(stdin);
					printf("Do you want to create the file (Y/y = Yes, N/n = No)? ");
					scanf("%c", &yesNo);

					if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
						red();
						printf("<ERROR>You have enter an invalid character, Please re-enter again<ERROR>\n\n");
						reset();
					}
				} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

				if (toupper(yesNo) == 'Y') {
					*file = fopen(fileName, "wb"); //open file
				}
				else
					exit(-1);
			}
		}
	}
}
void red() {
	printf("\033[0;31m");
}
void yellow() {
	printf("\033[0;33m");
}
void reset() {
	printf("\033[0m");
}
void table()
{
	red();
	printf("+======================+\n");
	reset();
}
void tableII()
{
	red();
	printf("+=========================+\n");
	reset();
}

//main logo
void logo() {
	Sleep(200);
	yellow();
	printf("$$$$$$$$\\ $$$$$$\\ $$$$$$$\\ $$\\   $$\\ $$$$$$\\         $$$$$$\\ $$$$$$$$\\  $$$$$\\ $$$$$$\\ $$\\   $$\\$$$$$$$$\\$$$$$$$$\\$$$$$$$\\  $$$$$$\\  \n");
	Sleep(200);
	printf("\\__$$  __$$  __$$\\$$  __$$\\$$ |  $$ $$  __$$\\       $$  __$$\\$$  _____| \\__$$ $$  __$$\\$$ |  $$ \\__$$  __$$  _____$$  __$$\\$$  __$$\\ \n");
	Sleep(200);
	printf("   $$ |  $$ /  $$ $$ |  $$ $$ |  $$ $$ /  \\__|      $$ /  \\__$$ |          $$ $$ /  $$ $$ |  $$ |  $$ |  $$ |     $$ |  $$ $$ /  $$ |\n");
	Sleep(200);
	printf("   $$ |  $$$$$$$$ $$$$$$$  $$ |  $$ $$ |            \\$$$$$$\\ $$$$$\\        $$ $$$$$$$$ $$$$$$$$ |  $$ |  $$$$$\\   $$$$$$$  $$$$$$$$ |\n");
	Sleep(200);
	red();
	printf("   $$ |  $$  __$$ $$  __$$<$$ |  $$ $$ |             \\____$$\\$$  __| $$\\   $$ $$  __$$ $$  __$$ |  $$ |  $$  __|  $$  __$$<$$  __$$ |\n");
	Sleep(200);
	printf("   $$ |  $$ |  $$ $$ |  $$ $$ |  $$ $$ |  $$\\       $$\\   $$ $$ |    $$ |  $$ $$ |  $$ $$ |  $$ |  $$ |  $$ |     $$ |  $$ $$ |  $$ |\n");
	Sleep(200);
	printf("   $$ |  $$ |  $$ $$ |  $$ \\$$$$$$  \\$$$$$$  |      \\$$$$$$  $$$$$$$$\\$$$$$$  $$ |  $$ $$ |  $$ |  $$ |  $$$$$$$$\\$$ |  $$ $$ |  $$ |\n");
	Sleep(200);
	printf("   \\__|  \\__|  \\__\\__|  \\__|\\______/ \\______/        \\______/\\________\\______/\\__|  \\__\\__|  \\__|  \\__|  \\________\\__|  \\__\\__|  \\__|\n");
	reset();

}
