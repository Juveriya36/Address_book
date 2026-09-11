/*
Name : Juveriya Bepari
Institute : Emertxe
Date of submission : 19/06/2026

Description :-

* This project is a simple address book system made using C language.
* It helps to store contact details like name, phone number and email.
* The user can add new contacts and view all saved contacts easily.
* It allows searching contacts using name, phone number or email.
* The user can update contact details whenever needed.
* It also allows deleting unwanted contacts from the list.
* The data is saved in a file so it is not lost after closing the program.
* The program checks the input to make sure correct data is entered.
* It avoids duplicate phone numbers and email addresses.
* The project uses functions to make the code simple and organized.
* It is menu-driven, so the user can choose options easily.
* This project helps in understanding basic concepts of C programming.

*/



#include <stdio.h>
#include "contact.h"
#include "file.h"



int main() 
{
    int choice;
    AddressBook addressBook;
    //initialize(&addressBook); // Initialize the address book

    addressBook.contactCount = 0;
    loadContactsFromFile(&addressBook);


    do 
    {
        printf("\n-------------Address Book Menu--------------\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save and Exit\n");		
         printf("7. Load and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
             case 3:
                 editContact(&addressBook);
                 break;
             case 4:
                 deleteContact(&addressBook);
                 break;
             case 5:          
                 listContacts(&addressBook);
                 break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("Existing...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
