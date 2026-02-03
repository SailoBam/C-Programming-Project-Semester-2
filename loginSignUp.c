#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void login (void) {
    char username [100];
    char password [100];
    printf("\nPlease Login to access the Database");
    printf("\nEnter your Username: ");
    scanf("%s", username);
    printf("\nEnter your Password: ");
    scanf("%s", password);
    //scan the sql database to makesure the username and password match with a user.
    // then gives access to neccessary user status; admin, tech or student.
    
}

void signup (void) {
    char first_name [100];
    char last_name [100];
    char username [100];
    char password [100];
    char university_ID [100];
    
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
    scanf("%s", university_ID);
    
    //enter the info into an temperary sql database for users.
    
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


