/*
 * contact.h
 *
 *  Created on: Apr 28, 2021
 *      Author: jtdellaringa
 */

#ifndef CONTACT_H_
#define CONTACT_H_


struct contact {
	char firstName[255];
	char lastName[255];
	char email[255];
	char phoneNumber[255];
};
//Define modifiers
void addContact();
void printCount();
void printField();
void printContact();
void loadContacts();
void editField();
void deleteContact();
void saveContacts();
void sortContacts();

#endif /* CONTACT_H_ */
