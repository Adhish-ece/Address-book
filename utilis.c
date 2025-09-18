
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
    int count,newcount=0;
    int deleted =0;
    fscanf(fp,"%d\n",&count);
    char ph[20];
    printf("Enter the phone number of the user to delete: ");
    scanf(" %[^\n]",ph);
    while(fgets(line,sizeof(line),fp))
    {
        Contact c;
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]",c.name, c.phone, c.email, c.loc);
        if(strcmp(c.phone,ph)==0)
        {
            printf("\ndeleting contact: %s | %s | %s | %s\n",c.name,c.phone,c.email,c.loc);
            deleted =1;
        }
        else
        {
            fprintf(temp,"%s,%s,%s,%s\n",c.name, c.phone, c.email, c.loc);
            newcount++;
        }
        
    }
    rewind(temp);
    fprintf(temp,"%d\n",newcount);
    fclose(temp);
    fclose(fp);
    remove(file);
    rename("temp.csv",file);
    if(deleted)
    printf("contact deleted succefully");
    else
    printf("sorry user not found!\n");
}

//edit contact fun
void Edit() {
 char query[50];
    printf("Enter phone number of contact to edit: ");
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

    while (fgets(line, sizeof(line), fp)) {
        Contact c;
        sscanf(line, "%49[^,],%19[^,],%49[^,],%49[^\n]",c.name, c.phone, c.email, c.loc);
        strcpy(oldPh,c.phone);
        strcpy(oldGm,c.email);
        if (strcmp(c.phone, query) == 0) {
            printf("Editing contact: %s | %s | %s | %s\n", c.name, c.phone, c.email, c.loc);

            do
            {
                printf("Enter new name: ");
                scanf(" %[^\n]",c.name);
                if(!validate_name(c.name))
                printf("Name should be alphabets!\n");
            } while(!validate_name(c.name));

            do {
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

            updated = 1;
        }
        fprintf(temp, "%s,%s,%s,%s\n",c.name, c.phone, c.email, c.loc);
    }
    fclose(fp);
    fclose(temp);

    remove(file);
    rename("temp.csv", file);

    if (updated)
        printf("\nContact updated!\n");
    else
        printf("\nContact not found!\n");
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
    int count = Get_Count();
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
    int found = 0;
    printf("Enter phone number/gmail: ");
    scanf(" %[^\n]",s);
    FILE *fp=fopen(file,"r");
    if(!fp)
        printf("No contact are present");
    fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)) {
        sscanf(line,"%49[^,],%19[^,],%49[^,],%49[^,]",c.name,c.phone,c.email,c.loc);
        if((strcmp(s,c.phone)==0 || strcmp(s,c.email)==0)) {
            found=1;
            printf("\n%s | %s | %s | %s \n",c.name,c.phone,c.email,c.loc);
            fclose(fp);
            return;
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
