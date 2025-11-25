 /*
    This project is done by adhish v as a part of emertxe embedded system course
 */

#include "file.h"


int main()
{
    int choice;
    //printf("ok");
    AddressBook addr;
    Initialise(&addr);

    
    while(1)
    {
        printf("\n=====Address Book (By Adhish)=====\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Print All Contact\n");
        printf("6. Exit\n");
        printf("7. Save and Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            Add_Contact(&addr);
            break;
            case 2:
            Search(&addr);
            break;
            case 3:
            Edit(&addr);
            break;
            case 4:
            Delete(&addr);
            break;
            case 5:
            Print_Contact(&addr);
            break;
            case 6:
            return 0;
            case 7:
            Save(&addr);
            return 0;
            break;
            default:
            printf("\nEnter valid choice!\n");
        }
    }
}



