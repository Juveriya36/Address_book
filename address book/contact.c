#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    int i,j;
    Contact temp;
    for(i=0;i<addressBook->contactCount-1;i++)
    {
        for(j=0;j<addressBook->contactCount-1-i;j++)
        {
            if((strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0))
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
                
            }
        }
    }
    for(i=0;i<addressBook->contactCount;i++)
    {
       printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       
    }
    
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
     saveContactsToFile(addressBook);
}

int validate_name(char *name)
{
    for(int i=0;name[i]!='\0';i++)
    {
        if(!((name[i]>='A' && name[i]<='Z')||(name[i]>='a' && name[i]<='z')||(name[i]==' ')||(name[i]=='.'))) //check if the name contains only letters, space,and dot.
               {
            return 0;
        }

    }
    return 1;
}
    
int validate_phone(char *phone,AddressBook *addressBook)
{
     if(strlen(phone)!=10)
    {
        printf("Phone number must contain 10 digits\n");
        return 0;
    }
    for(int i=0;phone[i]!='\0';i++)
    {
        if(phone[i]<'0' || phone[i]>'9') //check if the phone number ontains only digits.

        {

            return 0;
        }
    }
    for(int j=0;j<addressBook->contactCount;j++)
    {
        if(strcmp(addressBook->contacts[j].phone,phone)==0)
        {
            return 0;
        }
    }
    return 1;
}

int validate_email(char *email,AddressBook *addressBook)
{
    for(int i=0;email[i]!=0;i++)
    {
        if(!((email[i]>='a' && email[i]<='z') ||(email[i] == '.')||(email[i] == '@'))) //hek if the email ontains only Lowerase letters,

        {
            return 0;
        }
    }
    if(strlen(email)<4||strcmp(email+strlen(email)-4,".com")!=0) //check if the email ends with  ".com"
       {
        return 0;
    }
    return 1;
    
}


void createContact(AddressBook *addressBook)
{
	char name[50];
    char phone[20];
    char email[50];
    int valid1,valid2,valid3;
    while(1)
{
    
    printf("\nEnter the name:\n");
    scanf(" %[^\n]",name);
    valid1 = validate_name(name);
    if(valid1 == 1)
    {
        printf("It is a valid name:\n");
        break;
    }
    
    else
    {
        printf("It is not valid,enter the name again\n");
    }
}
    
    while(1)
    {
    printf("Enter the number:");
    scanf(" %[^\n]",phone);

    valid2 = validate_phone(phone,addressBook); //check if number is valid or not

    if(valid2 == 1)
    {
        printf("It is a valid number:\n");
        break;
    }
    else
    {
        printf("It is not a valid number,try again:\n");
    }
}

    while(1)
    {
        printf("Enter the email:");
        scanf(" %[^\n]",email);

        valid3 = validate_email(email,addressBook); //check if email is valid or not

        if(valid3 == 1)
        {
            printf("It is valid mail:\n");
            break;
        }
        else
        {
            printf("It is not valid mail,try again:\n");
        }
    }

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);

    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);

    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    addressBook->contactCount++;

    printf("Contacts Added Successfully\n");
    
}
int search_by_phone(AddressBook *addressBook) //search the contact by phone number 

{
    int i;
    char str[11];
    printf("Enter the phone1");
    scanf(" %[^\n]",str);

    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str, addressBook->contacts[i].phone) == 0) //camparing the phone number with contact list
        {
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            return i;
        }
    }

    printf("Contact not found");
    return -1;
}

int search_by_name(AddressBook *addressBook) //search the contact by name
{
    int count=0;
    int i,ind;
    char str[50];
    printf("Enter the name:");
    scanf(" %[^\n]",str);

    for( i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str, addressBook->contacts[i].name) == 0) //comparing the name with ccontact list
        {
            //print the contact with a s.no
            printf("%d\t%s\t%s\t%s\n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            ind = i;
            count++;
        }
    }

    
    if(count == 0)
    {
        return -1;
    }

    
    if(count == 1)
    {
        return ind;
    }

    
    if(count > 1)
    {
         search_by_phone(addressBook);
    }

}


int search_by_email(AddressBook *addressBook) //search the contact by email
{
    int i;
    char str[20];
    printf("Enter the email1");
    scanf(" %[^\n]",str);

    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str, addressBook->contacts[i].email) == 0)
        {
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            return i;
        }
    }

    printf("Contact not found");
    return -1;
}

void searchContact(AddressBook *addressBook) 
{

    int choice;
    do
    {
        printf("Search contact by:\n");
        printf("1.Search by name\n");
        printf("1.Search by phone\n");
        printf("1.Search by email\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice)
    {
        case 1:
            search_by_name(addressBook);
            break;
        case 2: 
            search_by_phone(addressBook);
            break;
        case 3: 
            search_by_email(addressBook);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}while(choice!=3);

}

void edit_name(AddressBook *addressBook, int res) //edit the name of contact
{
    

    int valid1;
    char name[20];
    while(1)
    {
        printf("Enter the name : ");
        scanf(" %[^\n]", name);

        valid1 = validate_name(name);
        if(valid1 == 1)// valid
            break;
        
    }

    strcpy(addressBook->contacts[res].name, name);

}
void edit_phone(AddressBook *addressBook, int res) //edit the phone number of contact
{
    int valid2;
    char phone[20];
    while(1)
    {
    printf("Enter the number:");
    scanf(" %[^\n]",phone);

    valid2 = validate_phone(phone,addressBook);
    if(valid2 == 1)
    break;
    else
    printf("It is not a valid number,try again:\n");
    }
     strcpy(addressBook->contacts[res].phone, phone);
}

void edit_email(AddressBook *addressBook, int res) //edit the email of contact
{
    int valid3;
    char email[50];
    while(1)
    {
        printf("Enter the email:");
        scanf(" %[^\n]",email);

        valid3 = validate_email(email,addressBook);
        if(valid3 == 1)
        break;
        else
        printf("It is not valid mail,try again:\n");
    }
     strcpy(addressBook->contacts[res].email, email);
}

void editContact(AddressBook *addressBook) //edit the contact details.
{
	
     int choice;
     int res;
    
    do
    {
        printf("Edit contact by\n");
        printf("1.search by name\n");
        printf("2.search by phone\n");
        printf("3.search by email\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
           res = search_by_name(addressBook);
           break;
        case 2: 
            res = search_by_phone(addressBook);
            break;
        case 3: 
           res = search_by_email(addressBook);
           break;
        default:
            printf("Invalid input\n");
            break;
    }
    if(res != -1)
    {
        break;
    }
    printf("Contact not found:\n");
}while(choice!=3);


    if(res != -1)
    {
        printf("Edit contact by:\n");
        printf("1.Edit the name:\n");
        printf("2.Edit the phone:\n");
        printf("3.Edit the email:\n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            edit_name(addressBook, res);
            break;
        case 2: 
            edit_phone(addressBook, res);
            break;
        case 3: 
            edit_email(addressBook, res);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}
    
}
void delete_name(AddressBook *addressBook,int res) //delete the name of contact
{
	
    int valid1;
    char name[20];
    while(1)
    {
        printf("Enter the name : ");
        scanf(" %[^\n]", name);

        valid1 = validate_name(name);
        if(valid1 == 1)// valid
            break;
        
    }

}

    

void delete_phone(AddressBook *addressBook,int res) //delete the phone number
{
	
    int valid2;
    char phone[20];
    while(1)
    {
        printf("Enter the number : ");
        scanf(" %[^\n]", phone);

        valid2 = validate_phone(phone,addressBook);
        if(valid2 == 1)// valid
            break;
        else
        printf("It is not valid number,try again:\n");
    }

}

void delete_email(AddressBook *addressBook, int res) //delete the email of contact
{
    

    int valid3;
    char email[50];
    while(1)
    {
        printf("Enter the email : ");
        scanf(" %[^\n]", email);

        valid3 = validate_email(email,addressBook);
        if(valid3 == 1)// valid
            break;
        else
        printf("It is not valid mail,try again:\n");
    }
}

void deleteContact(AddressBook *addressBook) // delete the contact
{
    int choice;
     int res;
    
    do
    {
        printf("\nSearch contact by\n");
        printf("1.search by name\n");
        printf("2.search by phone\n");
        printf("3.search by email\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
           res = search_by_name(addressBook);
           break;
        case 2: 
            res = search_by_phone(addressBook);
            break;
        case 3: 
           res = search_by_email(addressBook);
           break;
        default:
            printf("Invalid input\n");
            break;
    }
    if(res != -1)
    {
        break;
    }
    printf("Contact not found\n");
}while(choice!=3);
        
 if(res != -1)
 {   
        printf("Delete contact by\n");
        printf("1.delete the name:\n");
        printf("2.delete the phone:\n");
        printf("3.delete the email:\n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            delete_name(addressBook, res);
            break;
        case 2: 
            delete_phone(addressBook, res);
            break;
        case 3: 
            delete_email(addressBook, res);
            break;
        default:
            printf("Invalid input\n");
           
            break;
    }

    }

    int i;
    for(i=res;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i+1];
    }
    addressBook->contactCount--;

    printf("Contact deleted successfully\n");
    
}
   

