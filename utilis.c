
//adhish v
#include "utilis.h"

void Print()
{
    FILE *fp =fopen(file,"r");
    if(!fp)
    {
        printf("\nNo Record Found!\n");
        return;
    }
    int count;
    fscanf(fp,"%d\n",&count);
    printf("\n%-20s %-15s %-35s %-20s(total %d contact)\n","Name","Phone","Gmail","Location",count);
    printf("\n--------------------------------------------------------------------------------------------------------------\n");
    char line[256];
    Contact c;
    while(fgets(line,sizeof(line),fp))
    {
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]",c.name, c.phone, c.email, c.loc);
        printf("\n%-20s %-15s %-35s %-20s\n",c.name,c.phone,c.email,c.loc);
    }

}

void Delete()
{
    FILE *fp = fopen(file,"r");
    FILE *temp = fopen("temp.csv","w");
    fprintf(temp,"0\n");
    char line[256];
    int count;
    fscanf(fp,"%d\n",&count);
    char query[20];
    printf("Enter the phone number/email/name of the user to delete: ");
    scanf(" %[^\n]",query);
    Contact contact_list[MAX];
    int contact_count =0;

    while(fgets(line,sizeof(line),fp))
    {
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]",contact_list[contact_count].name, contact_list[contact_count].phone, contact_list[contact_count].email, contact_list[contact_count].loc);
        contact_count++;
    }
    fclose(fp);
    int match[MAX];
    int match_count =0;
    for(int i=0;i<contact_count;i++)
    {
        if(strcmp(contact_list[i].email,query)==0 || strcmp(contact_list[i].phone,query)==0)
        {
            match[match_count++]=i;
            break;
        }
        else if(strcmp(contact_list[i].name,query)==0)
        {
            match[match_count++]=i;
        }
    }
    
    if(match_count==0)
    {
        printf("No contact found with %s\n",query);
        fclose(temp);
        remove("temp.csv");
        return;
    }

    int choice=0;
    if(match_count>1)
    {
        printf("Multiple contact detected with name: %s",query);
        for(int i=0;i<match_count;i++)
        {
            printf("\n%d. %-20s %-15s %-35s %-20s\n",i+1,contact_list[match[i]].name,contact_list[match[i]].phone,contact_list[match[i]].email,contact_list[match[i]].loc);
        }
        do
        {
            printf("Enter the choice: ");
            scanf("%d",&choice);
            choice--;
            if(!(choice>=0 && choice <match_count))
            printf("Invalid choice !\n");
        }while(!(choice>=0 && choice <match_count));
    }
    int idx = match[choice];
    printf("Deleting contact: %-20s %-15s %-35s %-20s\n",contact_list[idx].name,contact_list[idx].phone,contact_list[idx].email,contact_list[idx].loc);
    for(int i=idx;i<contact_count-1;i++)
    {
        contact_list[i]=contact_list[i+1];
    }
    contact_count--;
    count--;
    rewind(temp);
    fprintf(temp,"%d\n",count);
    for(int i=0;i<contact_count;i++)
    {
        fprintf(temp, "%s,%s,%s,%s\n",contact_list[i].name, contact_list[i].phone, contact_list[i].email, contact_list[i].loc);
    }
    fclose(temp);
    rename("temp.csv",file);
    printf("Deleted successfully\n");

}   


//edit contact fun
void Edit() 
{
 char query[50];
    printf("Enter phone number/Email/Name of contact to edit: ");
    scanf("%s", query);

    FILE *fp = fopen(file, "r");
    FILE *temp = fopen("temp.csv", "w");

    int count;
    fscanf(fp, "%d\n", &count);
    fprintf(temp, "%d\n", count); // write same count for now

    char line[256];
    int updated = 0;
    char oldPh[20];
    char oldGm[50];

    Contact contact_list[MAX];
    int contact_count = 0;
    Contact c;
    while (fgets(line, sizeof(line), fp))
    {
        
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]",contact_list[contact_count].name, contact_list[contact_count].phone, contact_list[contact_count].email, contact_list[contact_count].loc);
        contact_count++;
    }

    fclose(fp);

    int match[100];
    int match_count = 0;
    for (int i = 0; i < contact_count; i++) 
    {
        if(strcmp(contact_list[i].phone, query) == 0 || strcmp(contact_list[i].email, query) == 0) 
        {
            match[match_count++] = i;
            break;       
        }
        else if(strcmp(contact_list[i].name, query) == 0) 
        {
            match[match_count++] = i;
        }
    }
    

    if (match_count == 0)
    {
        printf("\nContact not found!\n");
        fclose(temp);
        remove("temp.csv");
        return;
    } 

    int choice=0;
    if(match_count >1)
    {
        printf("Multiple contact is detected with name : %s",query);
        for(int i=0;i<match_count;i++)
        {
            printf("\n%d. %-20s %-15s %-35s %-20s\n",i+1,contact_list[match[i]].name,contact_list[match[i]].phone,contact_list[match[i]].email,contact_list[match[i]].loc);
        }
        do
        {
            printf("Enter the choice : ");
            scanf("%d",&choice);
            choice--;
            if(!(choice>=0 && choice<match_count))
            printf("Invalid choice\n");
        }while(!(choice>=0 && choice<match_count));
       
    }
    
    int idx = choice;
    strcpy(c.name,contact_list[match[choice]].name);
    strcpy(c.phone,contact_list[match[choice]].phone);
    strcpy(c.email,contact_list[match[choice]].email);
    strcpy(c.loc,contact_list[match[choice]].loc);
    strcpy(oldPh,c.phone);
    strcpy(oldGm,c.email);
    printf("Editing contact: %-20s %-15s %-35s %-20s\n",c.name,c.phone,c.email,c.loc);

    do
    {
        printf("Enter new name: ");
        scanf(" %[^\n]",c.name);
        if(!validate_name(c.name))
        printf("Name should be alphabets!\n");
    } while(!validate_name(c.name));

    do 
    {
        printf("Enter new phone (10 digits): ");
        scanf("%s", c.phone);
        if(!ValidatePh(c.phone))
        printf("Phone number should 10 digit!(or not a charecter)\n");
        else if(DuplicatePh(c.phone) && strcmp(oldPh,c.phone)!=0)
        printf("Phone number is already exist!\n");
    } while (!ValidatePh(c.phone) || (DuplicatePh(c.phone) && strcmp(oldPh,c.phone)!=0));

    do {
        printf("Enter new email: ");
        scanf("%s", c.email);
        if(!ValidateGm(c.email))
        printf("Enter Valid Gmail\n");
        else if(DuplicateGm(c.email) && strcmp(oldGm,c.email)!=0)
        printf("Gmail already exist!\n");
    } while (!ValidateGm(c.email) || (DuplicateGm(c.email) && strcmp(oldGm,c.email)!=0));

    printf("Enter new location: ");
    scanf(" %[^\n]", c.loc);

    strcpy(contact_list[match[idx]].name,c.name);
    strcpy(contact_list[match[idx]].phone,c.phone);
    strcpy(contact_list[match[idx]].email,c.email);
    strcpy(contact_list[match[idx]].loc,c.loc);

    for(int i = 0;i<contact_count;i++)
    {
        fprintf(temp, "%s,%s,%s,%s\n",contact_list[i].name, contact_list[i].phone, contact_list[i].email, contact_list[i].loc);
    }
    fclose(temp);
    remove(file);
    rename("temp.csv", file);
    
    
}

//get count fun
int Get_Count() {
    int count=0;
    FILE *fp = fopen(file,"r");
    if(fp) {
        fscanf(fp,"%d\n",&count);
        fclose(fp);
    }
    return count;
}

//update count fun
void update_count(int count) {
    FILE *fp =fopen(file,"r+");
    if(fp) {
        rewind(fp);
        fprintf(fp,"%d\n",count);
        fclose(fp);
    }
}

//Add contact fun
void Add_contact() {
    Contact c;
    int count =Get_Count();
    if(count>=MAX) {
        printf("Address book is full! Cannot add more contacts.\n");
        return;
    }
    do
    {
        printf("Enter name: ");
        scanf(" %[^\n]",c.name);
        if(!validate_name(c.name))
        printf("Name should be alphabets!\n");
    } while(!validate_name(c.name));
    
    do {
        printf("Enter Phone (10 digit): ");
        scanf("%s",c.phone);
        if(!ValidatePh(c.phone))
            printf("Phone number should be 10 digit\n");
        else if(DuplicatePh(c.phone))
            printf("Phone number is already exist\n");
    } while(!ValidatePh(c.phone) || DuplicatePh(c.phone));
    do {
        printf("Enter Gmail ID: ");
        scanf("%s",c.email);
        if(!ValidateGm(c.email))
            printf("Invaild Gmail ID\n");
        else if(DuplicateGm(c.email))
            printf("Gmail is already exist\n");
    } while(!ValidateGm(c.email) || DuplicateGm(c.email));
    printf("Enter location: ");
    scanf(" %[^\n]",c.loc);
    FILE *fp = fopen(file,"a");
    fprintf(fp,"%s,%s,%s,%s\n",c.name, c.phone, c.email, c.loc);
    fclose(fp);
    update_count(count+1);
    printf("Contact added successfully\n");
}

//phone number validation fun
int ValidatePh(char ph[]) {
    if(strlen(ph)==10 && digit(ph))
        return 1;
    else
        return 0;
}

//validate gmail
int ValidateGm(char gm[]) {
    return (strstr(gm,"@") && strstr(gm,".com"));
}

//duplicate gmail check fun
int DuplicateGm(char gm[]) {
    int flag = 0;
    Contact c;
    FILE *fp = fopen(file,"r");
    if(!fp)
        printf("error opening the file!\n");
    char line[256];
    fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)) {
        sscanf(line,"%49[^,],%19[^,],%49[^,],%49[^,]",c.name,c.phone,c.email,c.loc);
        if(strcmp(gm,c.email)==0) {
            flag=1;
            fclose(fp);
            return flag;
        }
    }
    fclose(fp);
    return flag;
}

//duplicate phone check fun
int DuplicatePh(char ph[]) {
    int flag = 0;
    Contact c;
    FILE *fp = fopen(file,"r");
    if(!fp)
        printf("error opening the file!\n");
    char line[256];
    fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)) {
        sscanf(line,"%49[^,],%19[^,],%49[^,],%49[^,]",c.name,c.phone,c.email,c.loc);
        if(strcmp(ph,c.phone)==0) {
            flag=1;
            fclose(fp);
            return flag;
        }
    }
    fclose(fp);
    return flag;
}

//digit or not fun
int digit(char ph[]) {
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

//check the cvs file exist or not
void File_exist() {
    FILE *fp=fopen(file,"r");
    if(!fp) {
        fp=fopen(file,"w");
        fprintf(fp,"0\n");
        fclose(fp);
    }
}

//search fun
void Search() {
    Contact c;
    char s[50],line[256];
    int found = 0,sl=1;
    printf("Enter phone number/gmail/name: ");
    scanf(" %[^\n]",s);
    FILE *fp=fopen(file,"r");
    if(!fp)
        printf("No contact are present");
    fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)) 
    {
        sscanf(line,"%49[^,],%19[^,],%49[^,],%49[^\n]",c.name,c.phone,c.email,c.loc);
        if((strcmp(s,c.phone)==0 || strcmp(s,c.email)==0 || strcmp(s,c.name)==0)) {
            found=1;
            printf("\n%d. %-20s %-15s %-35s %-20s\n",sl++,c.name,c.phone,c.email,c.loc);
        }
    }
    if(!found)
        printf("\nNo Data found!\n");
    fclose(fp);
}

int validate_name(char *name)
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
