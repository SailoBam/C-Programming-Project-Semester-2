#include <stdlib.h>
#include <stdio.h>
#include "loginSignUp.c"
#include "sqlite3.c"
#include "sqlite3.h"
#include "db.c"
#include "db.h"
#include "SQLServiceLayer.c"
#include "SQLServiceLayer.h"

void View_Equipment (void);
void Update_Equipment_Status (void);
void View_Bookings (void);
void Update_Booking_For_Equipment (void);
void technician (void);
void technician (void) {
    int i = 0;
    while (i == 0) {
        int choice;
        printf("\n\nWelcome Back Technician!");
        printf("\nWhat would you like to do today?");
        printf("\n1. View Equipment: ");
        printf("\n2. Update Equipment Status: ");
        printf("\n3. View Bookings: ");
        printf("\n4. Update Bookings: ");
        printf("\n5. Close Program: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                View_Equipment();
                break;
            case 2:
                Update_Equipment_Status();
                break;
            case 3:
                View_Bookings();
                break;
            case 4:
                Update_Booking_For_Equipment();
                break;
            case 5:
                printf("\nNOW CLOSING THE PROGRAM...");
                i++;
                break;
            default:
                break;
        }
    }
}
void View_Equipment (void) {
    //displays all equipment sql
}
void Update_Equipment_Status (void) {
    int ID_ENUM;
    int choice;
    printf("\nEnter the Items ID number: ");
    scanf("%d", &ID_ENUM);
    printf("\nWould you like to change the Availibility (1) or Equipment Status (2): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            char available [100];
            printf("\nInput what you would like to change the availability to: ");
            scanf("%s", &available);
            //change the equipment availability, use id number to identify it
            break;
        case 2:
            char status [100];
            printf("\nInput what you would like to change the equipment status to: ");
            scanf("%s", &status);
            //change the equipment status, use id number to identify it
            break;
        default:
            printf("<invalid-choice>");
            break;
    }
    //the user will input the change they want for the piece of equipment
    // they will be asked the ID number of the equipment item
    //updates the status of the equipment (working, broken, being repaired)
}
void View_Bookings (void) {
    //displays all the booking made by students
}
void Update_Booking_For_Equipment (void) {
    int i = 0;
    while (i == 0) {
        int choice = 0;
        int Booking_ID = 0;
        printf("\nPlease enter the booking ID: ");
        scanf("%d", &Booking_ID);
        printf("\n\nWhat are you Updating about the Booking? ");
        printf("\n1. Start and End Date: ");
        printf("\n2. Process Returns: ");
        printf("\n3. Return to Technician Window: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                char Start [11];
                char End [11];
                printf("\nWhat is the Start Date (dd/mm/YYYY): ");
                scanf("%s", &Start);
                printf("\nWhat is the End Date (dd/mm/YYYY): ");
                scanf("%s", &End);
                //add it into the sql database
                break;
            case 2:
                // Get rid of the booking
                break;
            case 3:
                i++;
                break;
            default:
                break;
        }
    }
}
