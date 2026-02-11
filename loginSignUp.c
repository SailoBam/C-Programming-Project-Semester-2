#include "db.h"
#include "sqlite3.c"
#include "sqlite3.h"
#include "SQLServiceLayer.h"
#include "AdminFunctions.h"

void signup(void);


/*
 The login function asks the user for a username and password
 calls an sql function to make sure its in the database and returns a number based on their status.
 1 = student, 2 = technician and 3 = admin.
 if it returns a number other than the three mentioned, it means the username and password didnt appear in the database.
 In that case, it asks if the user would like to try logging in again.
 */
void login (void) {
    char username [100];
    char password [100];
    printf("\nPlease Login to access the Database");

    int i = 0;
    while (i == 0) {
        /* db squlite return a 1 if their status = 'student'
      return a 2 if their status = 'technician'
      return a 3 if their status = 'admin'
         int 'c' is what should be returned by the database
    */
        printf("\nEnter your Username: ");
        scanf("%s", username);
        printf("\nEnter your Password: ");
        scanf("%s", password);
        int c = SignIn(DB, username, password);
        
        switch (c) {
            case 1:
                printf("\n YOUR A student");
                //student();
                exit(0);
            case 2:
                printf("\nYOUR A tech");
                //technician();
                exit(0);
            case 3:
                printf("\nYOUR AN admin");
                admin();
                exit(0);
            default:
                printf("\nINVALID USERNAME OR PASSWORD... ")
                printf("\nWould you like to try again (Yes=0 or No=1): ");
                scanf("%f", i);
                break;
        }
    }
    
    //scan the sql database to makesure the username and password match with a user.
    // then gives access to neccessary user status; admin, tech or student.
    //"Giving Access" will call the respective file
    
}

/*
 This function lets the user sign up to the database.
 It asks them a series of questions to add to the database like; surname, uni ID.
 calls an sql function and inputs the information into the database (saves their info into the database).
 Once they have signed up into the database it automatically sets their status to that of a student.
 Finally it calls the startlogin function again
 */
void signup (void) {
    // The following are placeholder variables for the bottom questions (saves user answers into variables).
    char first_name [100];
    char last_name [100];
    char username [100];
    char password [100];
    int university_ID;
    // the following asks the user questions and saves their answers as predeclared variables.
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
    startlogin(); // calls the startlogin function
}
/*
 The startlogin function gives the user the option to either log in or sign up to the database.
 Depending on the answer of the user it will either call the log in function, sign up function or close the program.
 */
void startlogin(void) {
    int choice; //stores the choice of the user as an integer.
    printf("Please indicate wether you need to login, sign up or close the database:"); //prompt for user
    printf("\n1. Login:"); // entering 1 calls the login function
    printf("\n2. Sign up:"); //entering 2 calls the sign up function
    printf("\n3. Close the program:"); // entering 3 closes the progam --> stops running
    scanf("%d", &choice); //scans the entered number and saves it as the integer variable "choice"
    switch (choice) { // a switch case that goes through 3 different cases, can either stop the program or call a function
        case 1: // if choice == 1
            login (); // call login function
            break; //breaks out of the switch case
        case 2: // if choice == 2
            signup(); // call sign up function
            break; // breaks out of the switch case
        case 3: // if choice == 3
            printf("\nThe Program will now close..."); //tells the user that the programs closing
            exit(0); //stops the program from running.
        default: //if choice == any number other than 1, 2 or 3
            printf("\nInvalid choice detected..."); //tells the user that the choice they made was invalid
            printf("\nProgram now closing..."); //tells the user that the programs closing
            break; // breaks out of the switch case
    }
    
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
    startlogin();
}

