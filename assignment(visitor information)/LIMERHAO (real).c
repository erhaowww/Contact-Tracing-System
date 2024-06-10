#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<ctype.h>

#pragma warning(disable:4996)


void displayVisitor();
void addVisitor();
void modifyVisitor();
void searchVisitor();
void deleteVisitor();
void reportVisitor();
void fileFunction(FILE** file, char fileName[30], char mode[3]);


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


void fileFunction(FILE** file, char fileName[30], char mode[3]) {

	char yesNo;
	*file = fopen(fileName, mode);

	if (*file == NULL) {
		if (strcmp(mode, "ab") == 0) {
			printf("\033[0;31m");
			printf("Unable to open the Visitor Information.dat file\n");
			printf("\033[0m");

			do {
				printf("Do you want to create the file (Y/y = Yes, N/n = No)? ");
				rewind(stdin);
				scanf("%c", &yesNo);

				if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
					printf("\033[0;31m");
					printf("<ERROR>You have enter an invalid character, Please re-enter again<ERROR>\n\n");
					printf("\033[0m");
				}
			} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

			if (toupper(yesNo) == 'Y') {
				*file = fopen(fileName, "wb"); //open file


			}
			else
				exit(-1);
		}

		else if (strcmp(mode, "rb") == 0) {
			printf("\033[0;31m");
			printf("Unable to open the Visitor Information.dat file\n");
			printf("\033[0m");
			printf("Maybe try to add record first\n");

			do {
				printf("Do you want to add record(s) (Y/y = Yes, N/n = No)? ");
				rewind(stdin);
				scanf("%c", &yesNo);

				if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
					printf("\033[0;31m");
					printf("<ERROR>You have enter an invalid character, Please re-enter again<ERROR>\n\n");
					printf("\033[0m");
				}
			} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

			if (toupper(yesNo) == 'Y') {
				addVisitor();
			}
			else
				exit(-1);
			
		}

	}
	
}


void main() {
	int menu;

	printf("           $$\\           $$\\  $$\\                              $$\\           $$$$$$$$\\                                          $$\\     $$\\                     \n");
	Sleep(200);
	printf("           \\__|          \\__| $$ |                             \\__|          $$  _____|                                         $$ |    \\__|                    \n");
	Sleep(200);
	printf("$$\\    $$\\ $$\\  $$$$$$$\\ $$\\$$$$$$\\   $$$$$$\\   $$$$$$\\        $$\\ $$$$$$$\\  $$ |    $$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\$$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\  \n");
	Sleep(200);
	printf("\\$$\\  $$  |$$ |$$  _____|$$ \\_$$  _| $$  __$$\\ $$  __$$\\       $$ |$$  __$$\\ $$$$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\ \n");
	Sleep(200);
	printf(" \\$$\\$$  / $$ |\\$$$$$$\\  $$ | $$ |   $$ /  $$ |$$ |  \\__|      $$ |$$ |  $$ |$$  __|$$ /  $$ |$$ |  \\__|$$ / $$ / $$ | $$$$$$$ |$$ |    $$ |$$ /  $$ |$$ |  $$ |\n");
	Sleep(200);
	printf("  \\$$$  /  $$ | \\____$$\\ $$ | $$ |$$\\$$ |  $$ |$$ |            $$ |$$ |  $$ |$$ |   $$ |  $$ |$$ |      $$ | $$ | $$ |$$  __$$ |$$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |\n");
	Sleep(200);
	printf("   \\$  /   $$ |$$$$$$$  |$$ | \\$$$$  \\$$$$$$  |$$ |            $$ |$$ |  $$ |$$ |   \\$$$$$$  |$$ |      $$ | $$ | $$ |\\$$$$$$$ |\\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |\n");
	Sleep(200);
	printf("    \\_/    \\__|\\_______/ \\__|  \\____/ \\______/ \\__|            \\__|\\__|  \\__|\\__|    \\______/ \\__|      \\__| \\__| \\__| \\_______| \\____/ \\__| \\______/ \\__|  \\__|\n");

	
	
	
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
		printf("|                     7. EXIT PROGRAMME                      |\n");
		printf("+============================================================+\n\n");
		
		menu = 0;
		printf("Please enter your choice (1 to 7) : ");
		rewind(stdin);
		scanf("%d", &menu);


		switch (menu) {
		case 1:
			addVisitor(); break;
		case 2:
			searchVisitor(); break;
		case 3:
			modifyVisitor(); break;
		case 4:
			displayVisitor(); break;
		case 5:
			deleteVisitor(); break;
		case 6:
			reportVisitor(); break;
		case 7:
			printf("\nExit successfully\n\n"); break;
		default:
			printf("\033[0;31m");
			printf("<ERROR>You have enter invalid number/character, Please re-enter again<ERROR>\n\n");
			printf("\033[0m");

		}
		
	} while (menu != 7);

	
	system("pause");
}



void addVisitor() {

	Details visitor;
	int num;
	char yesNo;
	FILE* fptr;
	SYSTEMTIME t;

	fileFunction(&fptr, "Visitor Information.dat", "ab");

	do {

		do {
			rewind(stdin);
			printf("\nEnter Visitor Name : ");
			gets(visitor.personalData.name);

			for (num = 0; num < strlen(visitor.personalData.name); num++) {
				if (isalpha(visitor.personalData.name[num]) == 0) {
					if (visitor.personalData.name[num] != ' ') {
						printf("\033[0;31m");
						printf("<ERROR>Please enter a valid visitor name<ERROR>\n");
						printf("\033[0m");
						break;
					}
				}
				else if (num == strlen(visitor.personalData.name) - 1) {
					break; //避免num跳回去加多一次value //to avoid num to be added one more time
				}

			}

		} while (isalpha(visitor.personalData.name[num]) == 0);
		                         

		for (int i = 0; i < strlen(visitor.personalData.name); i++) {
			visitor.personalData.name[i] = toupper(visitor.personalData.name[i]);
		}
		


		do {

			do {
				printf("\nEnter Visitor IC NO (xxxxxx-xx-xxxx) : ");
				gets(visitor.personalData.ic);

				if (strlen(visitor.personalData.ic) != 14) {

					printf("\033[0;31m");
					printf("<ERROR>Invalid!!!Please enter full IC NO include with '-' character.<ERROR>\n");
					printf("\033[0m");
				}
				else {
					if (visitor.personalData.ic[6] != '-' || visitor.personalData.ic[9] != '-') {
						printf("\033[0;31m");
						printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
						printf("\033[0m");
					}
				}


			} while (strlen(visitor.personalData.ic) != 14 || visitor.personalData.ic[6] != '-' || visitor.personalData.ic[9] != '-');

		
			for (num = 0; num < strlen(visitor.personalData.ic); num++) {
				if (num == 6 || num == 9) {
					continue;
				}
				else if (isdigit(visitor.personalData.ic[num]) == 0) {
					printf("\033[0;31m");
					printf("<ERROR>You have enter invalid character!!!Please enter IC NO with number only<ERROR>\n");
					printf("\033[0m");
					break;
				}
				else if (num == strlen(visitor.personalData.ic) - 1) {
					break; //避免num跳回去加多一次value //to avoid num to be added one more time
				}
			}	

		} while (isdigit(visitor.personalData.ic[num]) == 0);

		if (visitor.personalData.ic[13] % 2 == 0)
			visitor.personalData.gender = 'F';
		else
			visitor.personalData.gender = 'M';

		GetLocalTime(&t);		
		
		if (visitor.personalData.ic[0] == '0' || visitor.personalData.ic[0] == '1' || (visitor.personalData.ic[0] == '2' && visitor.personalData.ic[1] <= '1')) {

			visitor.personalData.age = t.wYear - (2000 + (((visitor.personalData.ic[0] - 48) * 10) + (visitor.personalData.ic[1] - 48)));
		}
		else {
			visitor.personalData.age = t.wYear - (1900 + (((visitor.personalData.ic[0] - 48) * 10) + (visitor.personalData.ic[1] - 48)));
		}
		

		do {
			printf("\nEnter Visitor Category (eg. TUTOR): ");
			rewind(stdin);
			gets(visitor.category);

			for (num = 0; num < strlen(visitor.category); num++) {
				if (isalpha(visitor.category[num]) == 0) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid visitor category by using alphabet only<ERROR>\n");
					printf("\033[0m");
					break;
				}
				else if (num == strlen(visitor.category) - 1){
					break;
				}
			}

		} while (isalpha(visitor.category[num]) == 0);

		for (int i = 0; i < strlen(visitor.category); i++) {
			visitor.category[i] = toupper(visitor.category[i]);
		}

		printf("\nEnter Visitor Latest Venue Visited : ");
		gets(visitor.latestVisit);
		for (int i = 0; i < strlen(visitor.latestVisit); i++) {
			visitor.latestVisit[i] = toupper(visitor.latestVisit[i]);
		}

		do {
			
			printf("\nEnter Date (dd/mm/yyyy) : ");
			rewind(stdin);
			scanf("%d/%d/%d", &visitor.day, &visitor.month, &visitor.year);

			if (visitor.day <= 0 || visitor.day > 31 || visitor.month <= 0 || visitor.month > 12 || visitor.year < 2019 || visitor.year > 2021) {
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid date<ERROR>\n");
				printf("\033[0m");
			}
			
		} while (visitor.day <= 0 || visitor.day > 31 || visitor.month <= 0 || visitor.month > 12 || visitor.year < 2019 || visitor.year > 2021);
		
		do {
			printf("\nEnter Time Visited [INTERNATIONAL TIME] (hh:mm) : ");
			rewind(stdin);
			scanf("%d:%d", &visitor.hrs, &visitor.min);

			if (visitor.hrs < 0 || visitor.hrs>23 || visitor.min < 0 || visitor.min >59) {
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid time visited (eg. 17:20)<ERROR>\n");
				printf("\033[0m");
			}
		} while (visitor.hrs < 0 || visitor.hrs > 23 || visitor.min < 0 || visitor.min > 59);


		do {
			do {
				printf("\nEnter Visitor Contact Number (123-45678900) : ");
				rewind(stdin);
				gets(visitor.contactNum);

				if (!(strlen(visitor.contactNum) >= 11 && strlen(visitor.contactNum) <= 13)) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid/full contact number<ERROR>\n");
					printf("\033[0m");
				}
				else
					if (visitor.contactNum[3] != '-') {
						printf("\033[0;31m");
						printf("<ERROR>Please use only '-' character in fourth place!!!<ERROR>\n");
						printf("\033[0m");
					}

			} while (!(strlen(visitor.contactNum) >= 11 && strlen(visitor.contactNum) <= 13) || visitor.contactNum[3] != '-');

			for (num = 0; num < strlen(visitor.contactNum); num++) {
				if (num == 3 ) {
					continue;
				}
				else if (isdigit(visitor.contactNum[num]) == 0) {
					printf("\033[0;31m");
					printf("<ERROR>You have enter invalid character!!!Please enter contact number with number only<ERROR>\n");
					printf("\033[0m");
					break;
				}
				else if (num == strlen(visitor.contactNum) - 1)
					break;
			}

		} while (isdigit(visitor.contactNum[num]) == 0);


		do {
			printf("\nEnter Visitor Temperature : ");
			rewind(stdin);
			scanf("%lf", &visitor.temperature);

			if (!(visitor.temperature > 35 && visitor.temperature < 42)) {
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
				printf("\033[0m");
			}

		} while (!(visitor.temperature > 35 && visitor.temperature < 42));

		fwrite(&visitor, sizeof(Details), 1, fptr);

		do {
			printf("\nDo you want to continue (Y/y = Yes, N/n = No)? > ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}

		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');
	

	fclose(fptr);


}



void searchVisitor() {
	Details visitor[100];
	int choice, day, month, year, no, record, count = 0;
	double temperature;
	char venue[20], yesNo;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb");

	while (fread(&visitor[count], sizeof(Details), 1, fptr) != 0) {
		count++;
	}

	do {
		no = 1;
		record = 0;
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
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid number (1 to 3)!!!<ERROR>\n");
				printf("\033[0m");
			}

		} while (!(choice >= 1 && choice <= 3));

		if (choice == 1) {

			printf("\nEnter the Venue : ");
			rewind(stdin);
			gets(venue);

			for (int i = 0; i < strlen(venue); i++) {
				venue[i] = toupper(venue[i]);
			}


			printf("\n+====+=============================+===================+==========+======+=====================+=============+==================+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER %-3s|AGE %-2s|CATEGORY %-12s|DATE %-8s|TIME VISITED %-5s|CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+==========+======+=====================+=============+==================+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (strcmp(visitor[k].latestVisit, venue) == 0) {
					printf("|%d.%-2s|%-29s|%-19s|%-10c|%-6d|%-21s|%02d/%02d/%-7d|%02d:%02d %-12s|%-20s|%.1lf %-9s|\n", no, "", visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].day, visitor[k].month, visitor[k].year, visitor[k].hrs, visitor[k].min, "", visitor[k].contactNum, visitor[k].temperature, "");
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

				if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 2019 || year > 2021) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid date<ERROR>\n");
					printf("\033[0m");
				}

			} while (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 2019 || year >2021);

			printf("\n+====+=============================+===================+==========+======+=====================+================================+=================+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER %-3s|AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-12s|TIME VISITED %-4s|CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+==========+======+=====================+================================+=================+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (day == visitor[k].day && month == visitor[k].month && year == visitor[k].year) {
					printf("|%d.%-2s|%-29s|%-19s|%-10c|%-6d|%-21s|%-32s|%02d:%02d %-11s|%-20s|%.1lf %-9s|\n", no, "", visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].latestVisit, visitor[k].hrs, visitor[k].min, "", visitor[k].contactNum, visitor[k].temperature, "");
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
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid visitor temperature (> 35 and < 42)<ERROR>\n");
					printf("\033[0m");
				}

			} while (!(temperature > 35 && temperature < 42));

			printf("\n+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int k = 0; k < count; k++) {
				if (temperature < visitor[k].temperature) {
					printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[k].personalData.name, visitor[k].personalData.ic, visitor[k].personalData.gender, visitor[k].personalData.age, visitor[k].category, visitor[k].latestVisit, visitor[k].day, visitor[k].month, visitor[k].year, visitor[k].hrs, visitor[k].min, "", visitor[k].contactNum, visitor[k].temperature, "");
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
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');
	fclose(fptr);



}



void modifyVisitor() {
	Details readVisitor;
	Details visitor[100];
	int count = 0, record = 0, num, no, j;
	char venue[20], decide, yesNo;
	SYSTEMTIME t;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb");
	
	while (fread(&readVisitor, sizeof(Details), 1, fptr) != 0) {
		visitor[count] = readVisitor;
		count++;
	}

	fclose(fptr);
	
	do {
		displayVisitor();
		no = 0;
		do {
			printf("\nEnter NO. of visitor to be modified : >NO. ");
			rewind(stdin);
			scanf("%d", &no);

			if (!(no > 0 && no <= count)) {
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", count);
				printf("\033[0m");
			}

		} while (!(no > 0 && no <= count));
	

		j = no - 1;

		printf("\nPREVIOUS DATA : \n");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].day, visitor[j].month, visitor[j].year, visitor[j].hrs, visitor[j].min, "", visitor[j].contactNum, visitor[j].temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		
		do {
			printf("\nSure to Modify(Y/y = Yes, N/n = No)? : ");
			rewind(stdin);
			scanf("%c", &decide);

			if (toupper(decide) != 'Y' && toupper(decide) != 'N') {
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}

		} while (toupper(decide) != 'Y' && toupper(decide) != 'N');

		if (toupper(decide) == 'Y') {
			printf("MODIFY DATA  \n");
			printf("---------------------------------\n");


			do {
				rewind(stdin);
				printf("\nEnter New Visitor Name : ");
				gets(visitor[j].personalData.name);

				for (num = 0; num < strlen(visitor[j].personalData.name); num++) {
					if (isalpha(visitor[j].personalData.name[num]) == 0) {
						if (visitor[j].personalData.name[num] != ' ') {
							printf("\033[0;31m");
							printf("<ERROR>Please enter a valid visitor name<ERROR>\n");
							printf("\033[0m");
							break;
						}
					}
					else if (num == strlen(visitor[j].personalData.name) - 1) {
						break; //避免num跳回去加多一次value //to avoid num to be added one more time
					}

				}

			} while (isalpha(visitor[j].personalData.name[num]) == 0);


			for (int i = 0; i < strlen(visitor[j].personalData.name); i++) {
				visitor[j].personalData.name[i] = toupper(visitor[j].personalData.name[i]);
			}

			do {

				do {
					printf("\nEnter New Visitor IC NO (xxxxxx-xx-xxxx) : ");
					gets(visitor[j].personalData.ic);

					if (strlen(visitor[j].personalData.ic) != 14) {

						printf("\033[0;31m");
						printf("<ERROR>Invalid!!!Please enter full IC NO include with '-' character.<ERROR>\n");
						printf("\033[0m");
					}
					else {
						if (visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-') {
							printf("\033[0;31m");
							printf("<ERROR>Invalid!!!Please use only '-' character in seventh and tenth place to complete IC NO (eg. 111111-01-1111).<ERROR>\n");
							printf("\033[0m");
						}
					}


				} while (strlen(visitor[j].personalData.ic) != 14 || visitor[j].personalData.ic[6] != '-' || visitor[j].personalData.ic[9] != '-');


				for (num = 0; num < strlen(visitor[j].personalData.ic); num++) {
					if (num == 6 || num == 9) {
						continue;
					}
					else if (isdigit(visitor[j].personalData.ic[num]) == 0) {
						printf("\033[0;31m");
						printf("<ERROR>You have enter invalid character!!!Please enter IC NO with number only<ERROR>\n");
						printf("\033[0m");
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

				for (num = 0; num < strlen(visitor[j].category); num++) {
					if (isalpha(visitor[j].category[num]) == 0) {
						printf("\033[0;31m");
						printf("<ERROR>Please enter a valid visitor category by using alphabet only<ERROR>\n");
						printf("\033[0m");
						break;
					}
					else if (num == strlen(visitor[j].category) - 1) {
						break;
					}
				}

			} while (isalpha(visitor[j].category[num]) == 0);

			for (int i = 0; i < strlen(visitor[j].category); i++) {
				visitor[j].category[i] = toupper(visitor[j].category[i]);
			}

			printf("\nEnter New Lastest Venue Visit : ");
			rewind(stdin);
			gets(visitor[j].latestVisit);
			for (int i = 0; i < strlen(visitor[j].latestVisit); i++) {
				visitor[j].latestVisit[i] = toupper(visitor[j].latestVisit[i]);
			}

			do {
				printf("\nEnter New Date (dd/mm/yyyy): ");
				scanf("%d/%d/%d", &visitor[j].day, &visitor[j].month, &visitor[j].year);

				if (visitor[j].day <= 0 || visitor[j].day > 31 || visitor[j].month <= 0 || visitor[j].month > 12 || visitor[j].year < 2019 || visitor[j].year > 2021) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid date<ERROR>\n");
					printf("\033[0m");
				}

			} while (visitor[j].day <= 0 || visitor[j].day > 31 || visitor[j].month <= 0 || visitor[j].month > 12 || visitor[j].year < 2019 || visitor[j].year > 2021);

			do {
				printf("\nEnter New Time Visited (hh:mm) : ");
				scanf("%d:%d", &visitor[j].hrs, &visitor[j].min);

				if (visitor[j].hrs < 0 || visitor[j].hrs>23 || visitor[j].min < 0 || visitor[j].min >59) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid time visited (eg. 17:20)<ERROR>\n");
					printf("\033[0m");
				}

			} while (visitor[j].hrs < 0 || visitor[j].hrs > 23 || visitor[j].min < 0 || visitor[j].min > 59);

			do {
				do {
					printf("\nEnter New Visitor Contact Number (123-45678900) : ");
					rewind(stdin);
					gets(visitor[j].contactNum);

					if (!(strlen(visitor[j].contactNum) >= 11 && strlen(visitor[j].contactNum) <= 13)) {
						printf("\033[0;31m");
						printf("<ERROR>Please enter a valid/full contact number<ERROR>\n");
						printf("\033[0m");
					}
					else
						if (visitor[j].contactNum[3] != '-') {
							printf("\033[0;31m");
							printf("<ERROR>Please use only '-' character in fourth place!!!<ERROR>\n");
							printf("\033[0m");
						}

				} while (!(strlen(visitor[j].contactNum) >= 11 && strlen(visitor[j].contactNum) <= 13) || visitor[j].contactNum[3] != '-');

				for (num = 0; num < strlen(visitor[j].contactNum); num++) {
					if (num == 3) {
						continue;
					}
					else if (isdigit(visitor[j].contactNum[num]) == 0) {
						printf("\033[0;31m");
						printf("<ERROR>You have enter invalid character!!!Please enter contact number with number only<ERROR>\n");
						printf("\033[0m");
						break;
					}
					else if (num == strlen(visitor[j].contactNum) - 1)
						break;
				}

			} while (isdigit(visitor[j].contactNum[num]) == 0);

			do {
				printf("\nEnter New Temperature of Visitor : ");
				scanf("%lf", &visitor[j].temperature);

				if (!(visitor[j].temperature > 35 && visitor[j].temperature < 42)) {
					printf("\033[0;31m");
					printf("<ERROR>Please enter a valid visitor temperature ( > 35 and < 42 )<ERROR>\n");
					printf("\033[0m");
				}

			} while (!(visitor[j].temperature > 35 && visitor[j].temperature < 42));

			printf("\nNEW RECORD : \n");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].day, visitor[j].month, visitor[j].year, visitor[j].hrs, visitor[j].min, "", visitor[j].contactNum, visitor[j].temperature, "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n\n");
			record++;

			printf("Loading");
			for (int i = 0; i < 8; i++)
			{
				Sleep(200);
				printf(".");
				
			}

			fileFunction(&fptr, "Visitor Information.dat", "wb");
			fwrite(&visitor, sizeof(Details), count, fptr);
			fclose(fptr);

			printf("\n\nMODIFY SUCCESSFULLY\n");

		}


		do {
			printf("\ncontinue to modify more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

	printf("\n<%d record(s) modified>\n", record);

	
	
}




void displayVisitor() {
	Details visitor;
	FILE* fptr;
	SYSTEMTIME t;
	int no = 1,record = 0;

	fileFunction(&fptr, "Visitor Information.dat", "rb");

	GetLocalTime(&t);
	printf("\nVisitor Information - as until %d-%d-%d\n", t.wDay, t.wMonth, t.wYear);
	printf("\n+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
	printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
	printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");


	while (fread(&visitor, sizeof(Details), 1, fptr) != 0) {
		printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor.personalData.name, visitor.personalData.ic, visitor.personalData.gender, visitor.personalData.age, visitor.category, visitor.latestVisit, visitor.day, visitor.month, visitor.year, visitor.hrs, visitor.min, "", visitor.contactNum, visitor.temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		no++;
		record++;
	}

	printf("\n<%d records listed>\n", record);

	fclose(fptr);

}



void deleteVisitor() {
	Details readVisitor;
	Details visitor[100];
	int count = 0, deleted = 0, num, no, j;
	char decide, yesNo;
	FILE* fptr;

	fileFunction(&fptr, "Visitor Information.dat", "rb");

	while (fread(&readVisitor, sizeof(Details), 1, fptr) != 0) {
		visitor[count] = readVisitor;
		count++;
	}

	fclose(fptr);

	do {
		displayVisitor();
		no = 0;
		do {
			printf("\nEnter NO. of visitor to be deleted : >NO. ");
			rewind(stdin);
			scanf("%d", &no);

			if (!(no > 0 && no <= count)) {
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid number (1 to %d)!!<ERROR>\n", count);
				printf("\033[0m");
			}

		} while (!(no > 0 && no <= count));

		j = no - 1;

		printf("\nVisitor Information : \n");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
		printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[j].personalData.name, visitor[j].personalData.ic, visitor[j].personalData.gender, visitor[j].personalData.age, visitor[j].category, visitor[j].latestVisit, visitor[j].day, visitor[j].month, visitor[j].year, visitor[j].hrs, visitor[j].min, "", visitor[j].contactNum, visitor[j].temperature, "");
		printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

		do {
			printf("\nConfirm to delete the record(s) ? (Y/y = yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &decide);

			if (toupper(decide) != 'Y' && toupper(decide) != 'N') {
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
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
				Sleep(200);
				printf(".");

			}

			fileFunction(&fptr, "Visitor Information.dat", "wb");
			fwrite(&visitor, sizeof(Details), count, fptr);
			fclose(fptr);

			printf("\n\nDELETE SUCCESSFULLY\n");

			deleted++;
		}									
	
		do {
			printf("\ncontinue to delete more records?(Y/y = Yes, N/n = No) : ");
			rewind(stdin);
			scanf("%c", &yesNo);

			if (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

	printf("\n<%d records deletedd>\n", deleted);
}



void reportVisitor() {
	Details visitor[100];
	FILE* fptr;
	int no = 0, count = 0, choice;
	char yesNo;

	fileFunction(&fptr, "Visitor Information.dat", "rb");

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
				printf("\033[0;31m");
				printf("<ERROR>Please enter a valid number (1 to 3)!!!<ERROR>\n");
				printf("\033[0m");
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
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
					}
					else {
						no++;
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature);
						printf("\033[0;31m");
						printf("(HIGH)    ");
						printf("\033[0m");
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
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature);
						printf("\033[0;31m");
						printf("(HIGH)    ");
						printf("\033[0m");
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
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature);
						printf("\033[0;31m");
						printf("(HIGH)    ");
						printf("\033[0m");
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
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature, "");
						printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

					}
					else {
						no++;
						printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature);
						printf("\033[0;31m");
						printf("(HIGH)    ");
						printf("\033[0m");
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
			printf("\033[0;31m");
			printf("\n\n %70s Visitor with HIGH TEMPERATURE\n", "");
			printf("\033[0m");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");
			printf("|NO  |NAME %-24s|IC NO %-13s|GENDER  |AGE %-2s|CATEGORY %-12s|LASTEST VENUE VISIT %-5s|DATE %-9s|TIME VISITED  |CONTACT NUMBER %-5s|TEMPEREATURE  |\n", "", "", "", "", "", "", "");
			printf("+====+=============================+===================+========+======+=====================+=========================+==============+==============+====================+==============+\n");

			for (int i = 0; i < count; i++) {
				if (visitor[i].temperature >= 37.4) {
					no++;
					printf("|%d.%-2s|%-29s|%-19s|%-8c|%-6d|%-21s|%-25s|%02d/%02d/%-8d|%02d:%02d %-8s|%-20s|%.1lf %-9s|\n", no, "", visitor[i].personalData.name, visitor[i].personalData.ic, visitor[i].personalData.gender, visitor[i].personalData.age, visitor[i].category, visitor[i].latestVisit, visitor[i].day, visitor[i].month, visitor[i].year, visitor[i].hrs, visitor[i].min, "", visitor[i].contactNum, visitor[i].temperature, "");
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
				printf("\033[0;31m");
				printf("<ERROR>Please enter (Y/y = Yes, N/n = No) only!!!<ERROR>\n");
				printf("\033[0m");
			}
		} while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N');

	} while (toupper(yesNo) == 'Y');

}


