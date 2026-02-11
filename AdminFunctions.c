#include <stdlib.h>
#include <stdio.h>
#include "db.h"
#include "SQLServiceLayer.h"


void Change_Equipment (void);
void Add_Equipment (void);
void Change_Equipment (void);
void Remove_Equipment (void);
void View_Equipment (void);
void User_Functions (void);
void Add_User (void);	
void Change_User (void);	
void Remove_User (void);
void View_Users (void);
void Equipment_Functions(void);
void User_Functions (void);
	
void admin (void) {
    int i =0;
    while (i == 0){
        int choice;
        printf("\n\n Welcome Back Admin!");
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
                printf("\n\n NOW CLOSING THE PROGRAM...");
                exit(0);
            default:
                break;
        }
    }
}

void Equipment_Functions (void) {
    int i =0;
    while (i == 0){
        int choice = 0;
        printf("\n\nWhat Are you doing: ");
        printf("\n1. Add New Equipment: ");
        printf("\n2. Change Equipment Details: ");
        printf("\n3. Remove Equipment: ");
        printf("\n4. View Equipment: ");
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
                admin();
                break;
            default:
                break;
        }
    }
}



void Add_Equipment(void) {
    int Item_Number = 0;
    char Item_Name[50];
    char Purchase_Date[20];
    char Description[100];
    char Status[25];
    char Availability[] = "Open";

    printf("\nEnter the Item Number for the Equipment: ");
    scanf("%d", &Item_Number);
    while(getchar() != '\n'); // flush newline after number

    printf("\nEnter the Item's Name for the Equipment: ");
    fgets(Item_Name, sizeof(Item_Name), stdin);
    Item_Name[strcspn(Item_Name, "\n")] = 0; // remove newline

    printf("\nEnter the Purchase Date (day/month/year): ");
    fgets(Purchase_Date, sizeof(Purchase_Date), stdin);
    Purchase_Date[strcspn(Purchase_Date, "\n")] = 0;

    printf("\nEnter the Item's Description (word limit 100): ");
    fgets(Description, sizeof(Description), stdin);
    Description[strcspn(Description, "\n")] = 0;

    printf("\nEnter the Status of the Equipment (ie: working, broken...): ");
    fgets(Status, sizeof(Status), stdin);
    Status[strcspn(Status, "\n")] = 0;

    // SQL function to add equipment
    AddEquipment(DB, Item_Number, Item_Name, Purchase_Date, Description, Status, Availability);
    
}

void Change_Equipment (void) {
    int i = 0;
    while (i == 0){
        int choice = 0;
        int ID_Number = 0;
        char item_number[100];
        char item_name[100];
        char purchase_date[100];
        char description[100];
        char status[100];
        char available[100];
        ListEquipment(DB);
        printf("\nPlease enter the ID Number for the sql database:  ");
        scanf("%d", &ID_Number);
        printf("\n\nWhat are you changing? ");
        printf("\n1. Item Number: ");
        printf("\n2. Item Name: ");
        printf("\n3. Purchase Date: ");
        printf("\n4. Description: ");
        printf("\n5. Status: ");
        printf("\n6. Availability: ");
        printf("\n7. Return to Equipment Window: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("What do you want to change the item number too: ");
                scanf("%s", item_number);
                EditEquipment(DB, ID_Number, "ITEMNUMBER", item_number);
                break;
            case 2:

                printf("What do you want to change the item name too: ");
                scanf("%s", item_name);
                EditEquipment(DB, ID_Number, "ITEMNAME", item_name);
                break;
            case 3:
                
                printf("What do you want to change the Purchase Date too: ");
                scanf("%s", purchase_date);
                EditEquipment(DB, ID_Number, "PURCHASEDATE", purchase_date);
                break;
            case 4:
                
                printf("What do you want to change the description too: ");
                scanf("%s", description);
                EditEquipment(DB, ID_Number, "DESCRIPTION", description);               
				break;
            case 5:
                
                printf("What do you want to change the status too: ");
                scanf("%s", status);
                EditEquipment(DB, ID_Number, "STATUS", status);   
                break;
            case 6:
                
                printf("What do you want to change the status too: ");
                scanf("%s", available);
                EditEquipment(DB, ID_Number, "AVAILABILITY", available);   
                break;
            case 7:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
        
        Equipment_Functions();
    }
    
}
void Remove_Equipment (void) {
	int ID_Number;
    printf("\nPlease enter the ID Number for the equipment that you want to remove:  ");
    scanf("%d", &ID_Number);
    
    //SQL function to remove entry
    RemoveEquipment(DB, ID_Number);
    Equipment_Functions();
}

void View_Equipment (void) {
    ListEquipment(DB);
}


void User_Functions (void) {
    int i =0;
    while (i == 0){
        int choice = 0;
        printf("\n\nWhat Are you doing: ");
        printf("\n1. Add New User: ");
        printf("\n2. Change User Details: ");
        printf("\n3. Remove User: ");
        printf("\n4. View User Database: ");
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
                Remove_User();
                break;
            case 4:
                View_Users();
                break;
            case 5:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                admin();
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
   SignUpAdmin(DB, First_Name, Surname, Username, Password, University_ID, Status);
}

void Change_User (void) {
    int i = 0;
    while (i == 0){
        int choice = 0;
        int ID_Number = 0;
        char username[100];
        char first_name[100];
        char surname[100];
        char password[100];
        char status[100];
        char university_ID[100];
        printf("\nPlease enter the ID Number for the sql database:  ");
        scanf("%d", &ID_Number);
        printf("\n\nWhat are you changing? ");
        printf("\n1. Username: ");
        printf("\n2. First Name: ");
        printf("\n3. Surname: ");
        printf("\n4. Password: ");
        printf("\n5. Status: ");
        printf("\n6. University ID: ");
        printf("\n7. Return to Equipment Window: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                
                printf("What do you want to change the Username too: ");
                scanf("%s", username);
                EditUser(DB, ID_Number, "USERNAME", username);
                break;
            case 2:
                
                printf("What do you want to change the first name too: ");
                scanf("%s", first_name);
                EditUser(DB, ID_Number, "NAME", first_name);
                break;
            case 3:
                
                printf("What do you want to change the surname too: ");
                scanf("%s", surname);
                EditUser(DB, ID_Number, "SURNAME", surname);
                break;
            case 4:
                
                printf("What do you want to change the password too: ");
                scanf("%s", password);
                EditUser(DB, ID_Number, "PASSWORD", password);               
				break;
            case 5:
                
                printf("What do you want to change the status too: ");
                scanf("%s", status);
                EditUser(DB, ID_Number, "STATUS", status);  
                break;
            case 6:
                printf("What do you want to change the university ID too: ");
                scanf("%d", university_ID);
                EditUser(DB, ID_Number, "UNIVERSITYID", university_ID);  
                break;
            case 7:
                printf("\n\n...Returning you to the ADMIN SCREEN...\n");
                int i = 1;
                break;
            default:
                break;
        }
        admin();
    }
    
}
void Remove_User (void) {
	int ID_Number;
    printf("\nPlease enter the ID Number for the User that you want to remove:  ");
    scanf("%d", &ID_Number);
    RemoveUser(DB, ID_Number);
}

void View_Users (void) {
    ListUsers(DB);
}