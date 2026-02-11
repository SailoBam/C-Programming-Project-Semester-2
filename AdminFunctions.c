

#include <stdlib.h>
#include <stdio.h>
#include "loginSignUp.c"

void User_Functions (void);
void Add_User (void);
void Change_User (void);
void Remove_User (void);
void View_User (void);
void Equipment_Functions (void);
void Add_Equipment (void);
void Change_Equipment (void);
void Remove_Equipment (void);
void View_Equipment (void);


void admin (void) {
    int i =0;
    while (i == 0){
        int choice;
        printf("Welcome Back Admin!");
        printf("\nWhat would you like to do:");
        printf("\n1. User Functions: ");
        printf("\n2. Equipment Functions ");
        printf("\n3. Close Program: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                User_Functions();
                break;
            case 2:
                Equipment_Functions();
                break;
            case 3:
                printf("NOW CLOSING THE PROGRAM...");
                int i = 1;
                break;
            default:
                break;
        }
    }
}

void Equipment_Functions (void) {
    int i =0;
    while (i == 0){
        int choice = 0;
        printf("\n\nWhat Are you doing: ")
        printf("\n1. Add New Equipment: ");
        printf("\n2. Change Equipment Details: ");
        printf("\n3. Remove Equipment: ");
        printf("\n4. View Equipment: ")
        printf("\n5. Return to Admin screen : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Add_Equipment();
                break;
            case 2:
                Change_Equipment();
                break;
            case 3:
                Remove_Equipment ();
                break;
            case 4:
                View_Equipment ();
                break;
            case 5:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
    }
}

void Add_Equipment (void) {
    int Item_Number = 0;
    char Item_Name [100];
    char Purchase_Date [20];
    char Description [100];
    char Status [100];
    char Availability [] = "Open";
    printf("\nEnter the Item Number for the Equipment: ");
    scanf("%d", &Item_Number);
    printf("\nEnter the Item's Name for the Equipment: ");
    scanf("%s", &Item_Name);
    printf("\nEnter the Purchase Date for the Equipment (day/month/year): ");
    scanf("%s", &Purchase_Date);
    printf("\nEnter the Item's Description (word limit is 100): ");
    scanf("%s", &Description);
    printf("\nEnter the Status of the Equipment (ei: working, broken...): ");
    scanf("%s", &Status);
   //call the sql and add. include the variable that only appears in the variable section
    
}

void Change_Equipment (void) {
    int i = 0;
    while (i == 0){
        int choice = 0;
        int ID_Number = 0;
        printf("\nPlease enter the ID Number for the sql database:  ");
        scanf("%d", &ID_Number);
        printf("\n\nWhat are you changing? ")
        printf("\n1. Item Number: ");
        printf("\n2. Item Name: ");
        printf("\n3. Purchase Date: ");
        printf("\n4. Description: ");
        printf("\n5. Status: ");
        printf("\n6. Availability: ");
        printf("\n7. Return to Equipment Window: ")
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("What do you want to change the item number too: ");
                scanf("%d", int item_number);
                //changes the item number. call sql and change it.
                break;
            case 2:
                char item_name [100];
                printf("What do you want to change the item name too: ");
                scanf("%s", item_name);
                //changes the item name.  call sql and change it.
                break;
            case 3:
                char purchase_date [100];
                printf("What do you want to change the Purchase Date too: ");
                scanf("%s", purchase_date);
                //changes the purchase date.  call sql and change it.
                break;
            case 4:
                char description [100];
                printf("What do you want to change the description too: ");
                scanf("%s", description);
                //changes the description.  call sql and change it.                break;
            case 5:
                char status [100];
                printf("What do you want to change the status too: ");
                scanf("%s", status);
                //changes the status.  call sql and change it.
                break;
            case 6:
                char available [100];
                printf("What do you want to change the status too: ");
                scanf("%s", available);
                //changes the available status.  call sql and change it.
                break;
            case 7:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
    }
    
}
void Remove_Equipment (void) {
    printf("\nPlease enter the ID Number for the equipment that you want to remove:  ");
    scanf("%d", &ID_Number);
    //remove the equipment Item
}

void View_Equipment (void) {
    // outputs the sql for equipment
}

void User_Functions (void) {
    int i =0;
    while (i == 0){
        int choice = 0;
        printf("\n\nWhat Are you doing: ")
        printf("\n1. Add New User: ");
        printf("\n2. Change User Details: ");
        printf("\n3. Remove User: ");
        printf("\n4. View User Database: ")
        printf("\n5. Return to Admin screen : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Add_User();
                break;
            case 2:
                Change_User();
                break;
            case 3:
                Remove_User ();
                break;
            case 4:
                View_User ();
                break;
            case 5:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
    }
}


void Add_User (void) {
    int University_ID = 0;
    char Username [100];
    char First_Name [20];
    char Surname [100];
    char Password [100];
    char Status [20];
    printf("\nEnter the Username: ");
    scanf("%s", &Username);
    printf("\nEnter the First Name: ");
    scanf("%s", &First_Name);
    printf("\nEnter the Surname: ");
    scanf("%s", &Surname);
    printf("\nEnter the Password: ");
    scanf("%s", &Password);
    printf("\nEnter the Status of the User: ");
    scanf("%s", &Status);
    printf("\nEnter the University ID of the User: ");
    scanf("%d", &University_ID);
   //call the sql and add. include the variable that only appears in the variable section
}

void Change_User (void) {
    int i = 0;
    while (i == 0){
        int choice = 0;
        int ID_Number = 0;
        printf("\nPlease enter the ID Number for the sql database:  ");
        scanf("%d", &ID_Number);
        printf("\n\nWhat are you changing? ")
        printf("\n1. Username: ");
        printf("\n2. First Name: ");
        printf("\n3. Surname: ");
        printf("\n4. Password: ");
        printf("\n5. Status: ");
        printf("\n6. University ID: ");
        printf("\n7. Return to Equipment Window: ")
        scanf("%d", &choice);
        switch(choice){
            case 1:
                char username [100];
                printf("What do you want to change the Username too: ");
                scanf("%s", username);
                //changes the username. call sql and change it.
                break;
            case 2:
                char first_name [100];
                printf("What do you want to change the first name too: ");
                scanf("%s", first_name);
                //changes the first name.  call sql and change it.
                break;
            case 3:
                char surname [100];
                printf("What do you want to change the surname too: ");
                scanf("%s", surname);
                //changes the surname.  call sql and change it.
                break;
            case 4:
                char password [100];
                printf("What do you want to change the password too: ");
                scanf("%s", password);
                //changes the password.  call sql and change it.                break;
            case 5:
                char status [100];
                printf("What do you want to change the status too: ");
                scanf("%s", status);
                //changes the status.  call sql and change it.
                break;
            case 6:
                printf("What do you want to change the university ID too: ");
                scanf("%d", int university_ID);
                //changes the uni Id.  call sql and change it.
                break;
            case 7:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
    }
    
}
void Remove_User (void) {
    printf("\nPlease enter the ID Number for the User that you want to remove:  ");
    scanf("%d", &ID_Number);
    //remove the equipment Item
}

void View_User (void) {
    // outputs the user sql
}


