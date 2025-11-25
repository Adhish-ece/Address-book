//#include "contact.h"
#include "contact.h"


void Edit(AddressBook *addr)
{
    
    int match[MAX_CONTACT] = {0};
    int match_count = 0;
    char query[50];
    printf("Enter the Name/Phone/Gmail: ");
    scanf(" %[^\n]",query);

    for(int i = 0; i < addr->contact_count; i++)
    {
        if(strcmp(addr->contact[i].name, query) == 0 ||
        strcmp(addr->contact[i].ph, query) == 0 ||
        strcmp(addr->contact[i].gmail, query) == 0)
        {
            match[match_count++] = i;
        }
    }

    if(match_count ==0)
    {
        printf("No contact found!\n");
        return;
    }

    if(match_count==1)
    {
        int i = match[0];
        printf("Contact Found:\n");
        printf("\n %-5d %-20s %-15s %-35s\n",1,addr->contact[i].name,addr->contact[i].ph,addr->contact[i].gmail);
        do
        { 
            printf("Enter the name: ");
            scanf(" %[^\n]",addr->contact[i].name);
            if(!Validate_Name(addr->contact[i].name))
            printf("Please Enter a Valid Name\n");
        }while(!Validate_Name(addr->contact[i].name));
        do
        {
            printf("Enter your Phone number: ");
            scanf(" %[^\n]",addr->contact[i].ph);
            
            if(!Validate_Ph(addr->contact[i].ph))
            printf("Error: Enter valid phone number\n");
            
            if(Duplicate_Ph(addr,addr->contact[i].ph))
            printf("Error: Phone number already exists\n");
            

        }while(!Validate_Ph(addr->contact[i].ph) || Duplicate_Ph(addr,addr->contact[i].ph));

        do
        {
            printf("Enter your Gmail: ");
            scanf(" %[^\n]",addr->contact[i].gmail);
            if(!ValidateGm(addr->contact[i].gmail))
            printf("Enter valid gmail\n");
            if(Duplicate_Gm(addr,addr->contact[i].gmail))
            printf("Email Address already exist!\n");

        }while(!ValidateGm(addr->contact[i].gmail) || Duplicate_Gm(addr,addr->contact[i].gmail));
        printf("Contact edited successfully\n");
        return;
    }
    if(match_count>1)
    {
        printf("\n %-5s %-20s %-15s %-35s\n","SL","Name","Phone","Gmail");
        printf("\n-------------------------------------------------------------------------\n");
        for(int i=0;i<match_count;i++)
        {
            int idx = match[i];
            printf("\n %-5d %-20s %-15s %-35s\n",i+1,addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
        }
    }
    int choise,edit_idx;
    char ph[20];
    char gmail[50];
    printf("\nEnter the SL Number you want to edit : ");
    scanf("%d",&choise);
    choise--;
    edit_idx=match[choise];
    printf("\nSelected");
    printf("\n %-5d %-20s %-15s %-35s\n",choise+1,addr->contact[edit_idx].name,addr->contact[edit_idx].ph,addr->contact[edit_idx].gmail);
    do
    { 
        printf("Enter the name: ");
        scanf(" %[^\n]",addr->contact[edit_idx].name);
        if(!Validate_Name(addr->contact[edit_idx].name))
        printf("Please Enter a Valid Name\n");
    }while(!Validate_Name(addr->contact[edit_idx].name));
    do
    {
        printf("Enter your Phone number: ");
        scanf(" %[^\n]",ph);
        
        if(!Validate_Ph(ph))
        printf("Error: Enter valid phone number\n");
        
        if(Duplicate_Ph(addr,ph) && strcmp(ph,addr->contact[edit_idx].ph)!=0)
        printf("Error: Phone number already exists\n");
        

    }while(!Validate_Ph(ph) || (Duplicate_Ph(addr,ph) && strcmp(ph,addr->contact[edit_idx].ph)!=0));
    strcpy(addr->contact[edit_idx].ph,ph);

    do
    {
        printf("Enter your Gmail: ");
        scanf(" %[^\n]",gmail);
        if(!ValidateGm(gmail))
        printf("Enter valid gmail\n");
        if(Duplicate_Gm(addr,gmail) && strcmp(gmail,addr->contact[edit_idx].gmail)!=0)
        printf("Email Address already exist!\n");

    }while(!ValidateGm(gmail) || (Duplicate_Gm(addr,gmail) && strcmp(gmail,addr->contact[edit_idx].gmail)!=0));
    strcpy(addr->contact[edit_idx].gmail,gmail);
}


void Search(AddressBook *addr)
{
    int match[MAX_CONTACT] = {0};
    int match_count = 0;
    char query[50];
    printf("Enter the Name/Phone/Gmail: ");
    scanf(" %[^\n]",query);

    for(int i = 0; i < addr->contact_count; i++)
    {
        if(strcmp(addr->contact[i].name, query) == 0 ||
        strcmp(addr->contact[i].ph, query) == 0 ||
        strcmp(addr->contact[i].gmail, query) == 0)
        {
            match[match_count++] = i;
        }
    }

    if(match_count ==0)
    {
        printf("No contact found!\n");
        return;
    }


    if(match_count==1)
    {
        int idx = match[0];
        printf("Contact Found:\n");
        printf("\n %-5d %-20s %-15s %-35s\n",1,addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
    }
    if(match_count>1)
    {
        printf("\n %-5s %-20s %-15s %-35s\n","SL","Name","Phone","Gmail");
        printf("\n-------------------------------------------------------------------------\n");
        for(int i=0;i<match_count;i++)
        {
            int idx = match[i];
            printf("\n %-5d %-20s %-15s %-35s\n",i+1,addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
        }
    }

}

void Delete(AddressBook *addr)
{
    int match[MAX_CONTACT] = {0};
    int match_count = 0;
    char query[50];
    printf("Enter the Name/Phone/Gmail: ");
    scanf(" %[^\n]",query);
    for(int i = 0; i < addr->contact_count; i++)
    {
        if(strcmp(addr->contact[i].name, query) == 0 ||
        strcmp(addr->contact[i].ph, query) == 0 ||
        strcmp(addr->contact[i].gmail, query) == 0)
        {
            match[match_count++] = i;
        }
    }

    if(match_count ==0)
    {
        printf("No contact found!\n");
        return;
    }
   if(match_count==1)
   {
        int idx = match[0];
        printf("Contact Found:\n");
        printf("Name: %s\nPhone: %s\nGmail: %s\n",addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
        char choice;
        printf("Are you sure you want to delete this contact? (y/n): ");
        scanf(" %c",&choice);
        if(choice=='y' || choice=='Y')
        {
            for(int i=idx;i<addr->contact_count-1;i++)
            {
                addr->contact[i] = addr->contact[i+1];
            }
            addr->contact_count--;
            printf("Contact deleted successfully!\n");
        }
        else
        {
            printf("Deletion cancelled.\n");
        }
        return;
   }
   if(match_count>1)
   {
    printf("Multiple contacts found:\n");
    printf("\n %-5s %-20s %-15s %-35s\n","SL","Name","Phone","Gmail");
    printf("\n-------------------------------------------------------------------------\n");
    for(int i=0;i<match_count;i++)
    {
        int idx = match[i];
        printf("\n %-5d %-20s %-15s %-35s\n",i+1,addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
    }
    int del_idx;
    printf("Enter the SL number of the contact to delete (1-%d): ",match_count);
    scanf("%d",&del_idx);
    if(del_idx<1 || del_idx>match_count)
    {
        printf("Invalid SL number. Deletion cancelled.\n");
        return;
    }
    int idx = match[del_idx-1];
    printf("Contact Found:\n");
    printf("Name: %s\nPhone: %s\nGmail: %s\n",addr->contact[idx].name,addr->contact[idx].ph,addr->contact[idx].gmail);
    char choice;
    printf("Are you sure you want to delete this contact? (y/n): ");
    scanf(" %c",&choice);
    if(choice=='y' || choice=='Y')
    {
        for(int i=idx;i<addr->contact_count-1;i++)
        {
            addr->contact[i] = addr->contact[i+1];
        }
        addr->contact_count--;
        printf("Contact deleted successfully!\n");
    }
    else
    {
        printf("Deletion cancelled.\n");
    }
    return;
    }
}


void Print_Contact(AddressBook *addr)
{
    printf("\n %-5s %-20s %-15s %-35s\n","SL","Name","Phone","Gmail");
    printf("\n-------------------------------------------------------------------------\n");
   
    for(int i = 0;i<addr->contact_count;i++)
    {
        printf("\n %-5d %-20s %-15s %-35s\n",i+1,addr->contact[i].name,addr->contact[i].ph,addr->contact[i].gmail);
    }
    return;
}

void Add_Contact(AddressBook *addr)
{
    if(addr->contact_count==MAX_CONTACT)
    {
        printf("Maximum Contact Limit Reached!\n");
        return;
    }

    int i = addr->contact_count;
    do
    { 
        printf("Enter the name: ");
        scanf(" %[^\n]",addr->contact[i].name);
        if(!Validate_Name(addr->contact[i].name))
        printf("Please Enter a Valid Name\n");
    }while(!Validate_Name(addr->contact[i].name));
    do
    {
        printf("Enter your Phone number: ");
        scanf(" %[^\n]",addr->contact[i].ph);
        
        if(!Validate_Ph(addr->contact[i].ph))
        printf("Error: Enter valid phone number\n");
        
        if(Duplicate_Ph(addr,addr->contact[i].ph))
        printf("Error: Phone number already exists\n");
        

    }while(!Validate_Ph(addr->contact[i].ph) || Duplicate_Ph(addr,addr->contact[i].ph));

    do
    {
        printf("Enter your Gmail: ");
        scanf(" %[^\n]",addr->contact[i].gmail);
        if(!ValidateGm(addr->contact[i].gmail))
        printf("Enter valid gmail\n");
        if(Duplicate_Gm(addr,addr->contact[i].gmail))
        printf("Email Address already exist!\n");

    }while(!ValidateGm(addr->contact[i].gmail) || Duplicate_Gm(addr,addr->contact[i].gmail));
    addr->contact_count++;
}

int ValidateGm(char gm[])
{
    return (strstr(gm,"@") && strstr(gm,".com"));
}

int Duplicate_Gm(AddressBook *addr,char gm[])
{
    for(int i=0;i<addr->contact_count;i++)
    {
        if(strcmp(addr->contact[i].gmail,gm)==0)
        return 1;   
    }
    return 0;
}

int Duplicate_Ph(AddressBook *addr,char ph[])
{
    
    for(int i=0;i<addr->contact_count;i++)
    {
        if(strcmp(addr->contact[i].ph,ph)==0)
        return 1;   
    }
    return 0;
}


int Validate_Ph(char ph[])
{
    if(strlen(ph)==10 && digit(ph))
        return 1;
    else
        return 0;
}

int digit(char ph[]) 
{
    int flag =1;
    int len = strlen(ph);
    for(int i=0;i<len;i++) {
        if(!(ph[i]>='0' && ph[i]<='9')) {
            flag = 0;
            return flag;
        }
    }
    return flag;
}

int Validate_Name(char name[])
{
    int flag =1;
    for(int i=0;name[i]!='\0';i++)
    {
        if(!((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]== ' '))
        {
            flag =0;
            break;
        }
    }
    return flag;
}

