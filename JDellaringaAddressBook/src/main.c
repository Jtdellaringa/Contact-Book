/*
 ============================================================================
 Name        : JDellaringaAddressBook.c
 Author      : Joseph Dell'Aringa
 Version     :
 Copyright   : 2021
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	puts("Ready");
	char uInput = ' ';
	uInput = getc(stdin);
	struct contact contacts[100];
	//struct contact *contactsSorted[1000];
	int contactsSortedCount = 0;
	char userString[1000];
	char tempString[1000];
	int contactCount = 0;
	int currIndex = 0;
	int indexToChange = 0;

	int sortedIndexSave = 0;
	struct contact *ptr;
	//setfirstName(ptr, "test");
	//getfirstName(ptr);
	//setEmail(ptr,"test");
	//getemailAddress(ptr);
	//getphoneNumber(ptr);
	//etlastName(ptr, "test");

	while (uInput != 'q') {
		//puts("Ready\n");
		if (uInput == 'a') {
			addContact();
			/*scanf("%d", &indexToChange);
			 fgets(userString, BUFSIZ, stdin); // get \n
			 fgets(userString, BUFSIZ, stdin); // get actual string?
			 //scanf("%d", &indexToChange);
			 //struct contact contactTemp; // @suppress("Type cannot be resolved")
			 if(indexToChange < currIndex){
			 for(int i = currIndex; i > indexToChange; i--){
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

			 }else{

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
			 currIndex++;*/

		} else if (uInput == 'd') {
			deleteContact();
			/*scanf("%d", &indexToChange); //get \n?
			 if (indexToChange <= currIndex && indexToChange >= 0) {
			 //strcpy(contacts[indexToChange].firstName, NULL); //'Erases' contact
			 //strcpy(contacts[indexToChange].lastName, NULL);
			 //strcpy(contacts[indexToChange].email, NULL);
			 //strcpy(contacts[indexToChange].phoneNumber, NULL);
			 for (int i = indexToChange; i < currIndex; i++) {
			 contacts[i] = contacts[i + 1]; //Sets all contacts minus 1 index in the list to ensure no null contacts throughout the array
			 }
			 }
			 currIndex--;
			 contactCount--;*/
		} else if (uInput == 'e') {
			editField();

		} else if (uInput == 'g') {
			printContact();
		} else if (uInput == 'f') {
			printField();
			//printf("\n");
		} else if (uInput == 'n') {
			printCount();
		} else if (uInput == 'l') {
			loadContacts();
		} else if (uInput == 's') {
			saveContacts();
		} else if (uInput == 'o') {
			sortContacts();
		}
		/*else if (uInput == 'o') { // change back to s

		 //finding the first contact in alphabetical order, lexicographically
		 //struct contact *startingContact = contacts[0];
		 int startingIndex = 0;
		 for (int i = 1; i <= currIndex; i++) {
		 if (contacts[startingIndex].lastName > contacts[i].lastName) {
		 startingIndex = i;
		 }
		 }


		 //call delete function of the contact.
		 //delete contacts[i]; // Will this delete from contacts original?

		 //Assuming it doesn't...hopefully

		 //contactsSorted[0] = ;


		 while (contactsSortedCount < contactCount) {
		 startingContact = NULL;
		 int i = 0;
		 while (startingContact == NULL) {
		 startingContact = contacts[i];
		 i++;
		 }
		 for (int i = 1; i <= currIndex; i++) {
		 if (getfirstName(startingContact) > getfirstName(contacts[i])) {
		 startingContact = contacts[i];
		 }
		 sortedIndexSave = i;
		 }
		 contactsSorted[contactsSortedCount++] = startingContact;
		 contacts[sortedIndexSave] = NULL;
		 }
		 for (int i = 0; i < contactCount; i++) {
		 contacts[i] = contactsSorted[i]; // putting contacts sorted back in the contacts array.
		 }

		 //ContactsSorted should be contain all elements of contacts but sorted/
		 //Add all contacts back to original list?
		 //Or just set contacts = contactsSorted?

		 //Want to put all these functions in the contact.h file to call them in main.
		 //return EXIT_SUCCESS;

		 //return EXIT_SUCCESS;


		 //break;}*/
		else if (uInput == 'q') {
			break;
		} else if (uInput == 's') {
			saveContacts();
		}
		//puts("Ready");
		/*uInput = getc(stdin);
		 if (uInput == '\n') {
		 uInput = getc(stdin);
		 }*/

		uInput = getc(stdin);
		if (uInput == '\n') {
			uInput = getc(stdin);
		}
	}

	puts("Complete");
	return EXIT_SUCCESS;
}

