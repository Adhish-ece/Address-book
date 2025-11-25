#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>
#define MAX_CONTACT 100

typedef struct
{
    char name[50];
    char ph[20];
    char gmail[50];
}Contact;

typedef struct
{
    Contact contact[MAX_CONTACT];
    int contact_count;
}AddressBook;


void Print_Contact(AddressBook *addr);
void Add_Contact(AddressBook *addr);
int Validate_Name(char name[]);
int Validate_Ph(char ph[]);
int digit(char ph[]);
int Duplicate_Ph(AddressBook *addr,char ph[]);
int ValidateGm(char gm[]);
int Duplicate_Gm(AddressBook *addr,char gm[]);
void Delete(AddressBook *addr);
void Search(AddressBook *addr);
void Edit(AddressBook *addr);


#endif