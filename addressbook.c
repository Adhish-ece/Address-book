#include "utilis.h"

int main()
{
    int choice;
    File_exist();
    while(1)
    {
        printf("\n=====Address Book (By Adhish)=====\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Print All Contact\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            Add_contact();
            break;
            case 2:
            Search();
            break;
            case 3:
            Edit();
            break;
            case 4:
            Delete();
            break;
            case 5:
            Print();
            break;
            case 6:
            return 0;
            break;
            default:
            printf("\nEnter valid choice!\n");
        }
    }
}
