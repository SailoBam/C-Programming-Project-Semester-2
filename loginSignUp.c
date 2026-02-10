#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "technicianFunctions.c"
#include "AdminFunctions.c"
#include "StudentFunctions.c"
#include "db.h"
#include "SQLServiceLayer.h"


void login (void) {
    char username [100];
    char password [100];
    printf("\nPlease Login to access the Database");

    int i = 0;
    while (i == 0) {
        int c = 0;
        /* db squlite return a 1 if their status = 'student'
      return a 2 if their status = 'technician'
      return a 3 if their status = 'admin'
         int 'c' is what should be returned by the database
    */
        printf("\nEnter your Username: ");
        scanf("%s", username);
        printf("\nEnter your Password: ");
        scanf("%s", password);
        
        switch (c) {
            case 1:
                student();
                exit(0);
            case 2:
                technician();
                exit(0);
            case 3:
                admin();
                exit(0);
        default:
                printf("Would you like to try again (Yes=0 or No=1): ");
                scanf("%f", i);
                break;
        }
    }
    
    //scan the sql database to makesure the username and password match with a user.
    // then gives access to neccessary user status; admin, tech or student.
    //"Giving Access" will call the respective file
    
}

void signup (void) {
    char first_name [100];
    char last_name [100];
    char username [100];
    char password [100];
    int university_ID;
    
    printf("\nThe following questions are necessary to signup to the database.");
    printf("\nA sign up is only available for students - otherwise a username and pasword will be provided.");
    printf("\nThe account sign up will take 3-5 business days to be verified.");
    printf("\nEnter your first name: ");
    scanf("%s", first_name);
    printf("\nEnter your last name: ");
    scanf("%s", last_name);
    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("\nEnter your password: ");
    scanf("%s", password);
    printf("\nEnter your university_ID: ");
    scanf("%d", &university_ID);
    
    //enter the info into the sql database for users.
    SignUpStudent(DB, first_name, last_name, username, password, university_ID);
    login();
}

void startlogin(void) {
    int choice;
    printf("Please indicate wether you need to login, sign up or close the database:");
    printf("\n1. Login:");
    printf("\n2. Sign up:");
    printf("\n3. Close the program:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            login ();
            break;
        case 2:
            signup();
            break;
        case 3:
            printf("\nThe Program will now close...");
            exit(0);
    default:
            printf("\nInvalid choice detected...");
            printf("\nProgram now closing...");
            break;
    }
    
}


