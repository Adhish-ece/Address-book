#ifndef UTILIS_H
#define UTILIS_H
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define file "address.csv"
#define MAX 100


typedef struct 
{
    char name[50];
    char phone[20];
    char email[50];
    char loc[50];
}Contact;

void Print();
void Delete();
void Edit();
int Get_Count();
void update_count(int count);
void Add_contact();
int ValidatePh(char ph[]);
int ValidateGm(char gm[]);
int DuplicateGm(char gm[]);
int DuplicatePh(char ph[]);
int digit(char ph[]);
void File_exist();
void Search();
int validate_name(char *name);
#endif
                
