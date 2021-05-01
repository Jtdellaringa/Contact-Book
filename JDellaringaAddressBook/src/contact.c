/*
 * contact.c
 *
 *  Created on: Apr 28, 2021
 *      Author: jtdellaringa
 */
#include "contact.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//Define variables
char uInput = ' ';
struct contact contacts[100];
int contactsSortedCount = 0;
char userString[1000];
char tempString[1000];
int contactCount = 0;
int currIndex = 0;
int indexToChange = 0;

int sortedIndexSave = 0;
//Implement modifiers
void addContact() {
	scanf("%d", &indexToChange);
	fgets(userString, BUFSIZ, stdin); // get \n
	fgets(userString, BUFSIZ, stdin); // get actual string?
	//scanf("%d", &indexToChange);
	//struct contact contactTemp; // @suppress("Type cannot be resolved")
	if (indexToChange < currIndex) {
		for (int i = currIndex; i > indexToChange; i--) {
			contacts[i] = contacts[i - 1];
		}
		char *token = strtok(userString, ",");
		//contacts[0].lastName = &token;
		strcpy(contacts[indexToChange].lastName, token);
		//&contacts[currIndex].lastName=  &token;

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].firstName, token);

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].email, token);

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].phoneNumber, token);

	} else {

		char *token = strtok(userString, ",");
		//contacts[0].lastName = &token;
		strcpy(contacts[indexToChange].lastName, token);
		//&contacts[currIndex].lastName=  &token;

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].firstName, token);

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].email, token);

		token = strtok(NULL, ",");
		strcpy(contacts[indexToChange].phoneNumber, token);
	}
	//Parse string into its seperate parts then add them to the contact
	//setfirstName(contactTemp, tempString);
	//Parse string into its seperate parts then add them to the contact
	//setlastName(contactTemp, tempString);
	//Parse string into its seperate parts then add them to the contact
	//setEmail(contactTemp, tempString);
	//Parse string into its seperate parts then add them to the contact
	//setphoneNumber(contactTemp, tempString);

	//Add the contact pointer to the array then add to the contact count;

	//contacts[currIndex] = contactTemp;

	contactCount++;
	currIndex++;

}

void printCount() {
	printf("%d\n", contactCount);
}

void printField() {
	scanf("%d", &indexToChange);
	gets(tempString, BUFSIZ, stdin);
	gets(tempString, BUFSIZ, stdin);
	int len;
	len = strlen(contacts[indexToChange].phoneNumber);
	if (strstr(tempString, "firstName") != NULL) {
		printf("%s\n", contacts[indexToChange].firstName);
	} else if (strstr(tempString, "lastName") != NULL) {
		printf("%s\n", contacts[indexToChange].lastName);
	} else if (strstr(tempString, "email") != NULL) {
		printf("%s\n", contacts[indexToChange].email);
	} else if (strstr(tempString, "phoneNumber") != NULL) {
		if (contacts[indexToChange].phoneNumber[len - 1] == '\n') {
			printf("%s", contacts[indexToChange].phoneNumber);
		} else {
			printf("%s\n", contacts[indexToChange].phoneNumber);
		}
	}
}

void printContact() {
	scanf("%d", &indexToChange);
	int len;
	len = strlen(contacts[indexToChange].phoneNumber);
	if (contacts[indexToChange].phoneNumber[len - 1] != '\n') {
		printf("%s,%s,%s,%s", contacts[indexToChange].lastName,
				contacts[indexToChange].firstName,
				contacts[indexToChange].email,
				contacts[indexToChange].phoneNumber);
		printf("\n");
	} else {
		printf("%s,%s,%s,%s", contacts[indexToChange].lastName,
				contacts[indexToChange].firstName,
				contacts[indexToChange].email,
				contacts[indexToChange].phoneNumber);
	}

}

void loadContacts() {
	//load file and store contacts
	FILE *fp;
	int len;

	//struct contact *temp;
	fgets(tempString, BUFSIZ, stdin); //gets /n?
	fgets(tempString, sizeof(tempString), stdin);
	len = strlen(tempString);

	if (tempString[len - 1] == '\n') {
		tempString[len - 1] = 0;
	}
	fp = fopen(tempString, "r");
	//char bufferString[1000];
	//fgets(tempString, BUFSIZ, fp);
	//fgets(tempString, BUFSIZ, fp);
	fgets(tempString, BUFSIZ, fp);
	while (fgets(tempString, BUFSIZ, fp) != NULL) {

		//fgets(tempString, BUFSIZ, fp);
		//fgets(tempString, BUFSIZ, fp);
		//while (fgets(tempString, BUFSIZ, fp) != NULL) {
		//lastName,firstName,email,phoneNumber

		char *token = strtok(tempString, ",");
		//printf("%s", token);
		//contacts[0].lastName = &token;
		strcpy(contacts[currIndex].lastName, token);
		//&contacts[currIndex].lastName=  &token;

		token = strtok(NULL, ",");
		//printf("%s\n", token);
		strcpy(contacts[currIndex].firstName, token);

		token = strtok(NULL, ",");
		//printf("%s\n", token);
		strcpy(contacts[currIndex].email, token);

		token = strtok(NULL, ",");
		len = strlen(token);

		if (token[len - 2] == '\r') {
			token[len - 2] = 0;
		}

		if (token[len - 1] == '\n') {
			token[len - 1] = 0;
		}

		strcpy(contacts[currIndex].phoneNumber, token);

		contactCount++;
		currIndex++;
	}
	pclose(fp);
}

void editField() {
	scanf("%d", &indexToChange);
	gets(tempString, BUFSIZ, stdin); // gets nothing?
	gets(tempString, BUFSIZ, stdin); //gets field to modify
	//scanf("%d", &indexToChange);
	if (strstr(tempString, "firstName") != NULL) {
		gets(tempString, BUFSIZ, stdin);
		strcpy(contacts[indexToChange].firstName, tempString);
	} else if (strstr(tempString, "lastName") != NULL) {
		gets(tempString, BUFSIZ, stdin);

		strcpy(contacts[indexToChange].lastName, tempString);
	} else if (strstr(tempString, "email") != NULL) {
		gets(tempString, BUFSIZ, stdin);
		strcpy(contacts[indexToChange].email, tempString);
	} else if (strstr(tempString, "phoneNumber") != NULL) {
		gets(tempString, BUFSIZ, stdin);
		strcpy(contacts[indexToChange].phoneNumber, tempString);
	}
}

void deleteContact() {
	scanf("%d", &indexToChange); //get \n?
	if (indexToChange < currIndex && indexToChange >= 0) {
		//strcpy(contacts[indexToChange].firstName, NULL); //'Erases' contact
		//strcpy(contacts[indexToChange].lastName, NULL);
		//strcpy(contacts[indexToChange].email, NULL);
		//strcpy(contacts[indexToChange].phoneNumber, NULL);
		for (int i = indexToChange; i < currIndex; i++) {
			contacts[i] = contacts[i + 1]; //Sets all contacts minus 1 index in the list to ensure no null contacts throughout the array
		}
	}
	currIndex--;
	contactCount--;

}

void saveContacts() {
	FILE *fp;
	int len;
	gets(tempString, BUFSIZ, stdin); // gets nothing?
	//gets(tempString, BUFSIZ, stdin);
	fgets(tempString, sizeof(tempString), stdin);
	len = strlen(tempString);

	if (tempString[len - 1] == '\n') {
		tempString[len - 1] = 0;
	}
	fp = fopen(tempString, "w+");
	fprintf(fp, "lastName,firstName,email,phoneNumber\n");
	for (int i = 0; i < contactCount; i++) {
		len = strlen(contacts[i].phoneNumber);
		if (contacts[i].phoneNumber[len - 1] == '\n') {
			fprintf(fp, "%s,%s,%s,%s", contacts[i].lastName,
					contacts[i].firstName, contacts[i].email,
					contacts[i].phoneNumber);
		} else {
			fprintf(fp, "%s,%s,%s,%s\n", contacts[i].lastName,
					contacts[i].firstName, contacts[i].email,
					contacts[i].phoneNumber);
		}
	}
	fclose(fp);

}

void sortContacts() {
		int i;
		int j;
		char tempfirstName[255];
		char templastName[255];
		char tempEmail[255];
		char tempNumber[255];
		for (i = 0; i < contactCount; i++) {
			for (j = i + 1; j < contactCount; j++) {
				if (strcmp(contacts[i].lastName, contacts[j].lastName) > 0) {

					//Copy over contact info for contacts[i]
					strcpy(tempfirstName, contacts[i].firstName);
					strcpy(templastName, contacts[i].lastName);
					strcpy(tempEmail, contacts[i].email);
					strcpy(tempNumber, contacts[i].phoneNumber);

					//copy contact info from contacts[j] into contacts[i]
					strcpy(contacts[i].firstName, contacts[j].firstName);
					strcpy(contacts[i].lastName, contacts[j].lastName);
					strcpy(contacts[i].email, contacts[j].email);
					strcpy(contacts[i].phoneNumber, contacts[j].phoneNumber);

					//Copy contact info for i into contact info for j
					strcpy(contacts[j].firstName, tempfirstName);
					strcpy(contacts[j].lastName, templastName);
					strcpy(contacts[j].email, tempEmail);
					strcpy(contacts[j].phoneNumber, tempNumber);
				}
			}
		}
}


