#include <stdlib.h>
#include <stdio.h>
#include "loginSignUp.c"
#include "sqlite3.c"
#include "sqlite3.h"
#include "db.c"
#include "db.h"
#include "SQLServiceLayer.c"
#include "SQLServiceLayer.h"
// the following are to declare functions
void View_Equipment (void);
void Update_Equipment_Status (void);
void View_Bookings (void);
void Update_Booking_For_Equipment (void);
void technician (void);
/*
 the technician function is esentially the main interface of the program.
 it asks the user what they would like to do with the authorities available to the technician
 */
void technician (void) {
    int i = 0;
    while (i == 0) {
        int choice;
        //the following prompts the user to choose what they would like to do as a technician and calls the subsequent function
        printf("\n\nWelcome Back Technician!");
        printf("\nWhat would you like to do today?");
        printf("\n1. View Equipment: ");
        printf("\n2. Update Equipment Status: ");
        printf("\n3. View Bookings: ");
        printf("\n4. Update Bookings: ");
        printf("\n5. Close Program: ");
        scanf("%d", &choice);
        switch(choice){ // switch case for the input of the user. either calls a function or closes the program
            case 1: //to view the equipment
                View_Equipment();
                break;
            case 2: //to update the status or availability of equipment
                Update_Equipment_Status();
                break;
            case 3: // to view the users own bookings
                View_Bookings();
                break;
            case 4: // to update booking information for the students
                Update_Booking_For_Equipment();
                break;
            case 5: // to close the program
                printf("\nNOW CLOSING THE PROGRAM...");
                i++;
                break;
            default:
                break;
        }
    }
}
/*
 the View_Equipment function outputs the entire equipment database, for the user to see
 */
void View_Equipment (void) {
    //displays all equipment sql
}
/*
 The Update_Equipment_Status function allows the user to change either the availability or status of an item
 Normally this function would be for after a return is processed
 */
void Update_Equipment_Status (void) {
   // the following variables are placeholders for inputs that will be asked of the user
    int ID_ENUM;
    int choice;
    // the printf statements prompt the user for an input
    printf("\nEnter the Items ID number: ");
    scanf("%d", &ID_ENUM);
    printf("\nWould you like to change the Availibility (1) or Equipment Status (2): ");
    scanf("%d", &choice);
    switch(choice) { // switch case for either availability (= 1) or status (= 2)
        case 1: // to change an items availability
            char available [100];
            printf("\nInput what you would like to change the availability to: ");
            scanf("%s", &available);
            //change the equipment availability, use id number to identify it
            break;
        case 2: // to change an items status
            char status [100];
            printf("\nInput what you would like to change the equipment status to: ");
            scanf("%s", &status);
            //change the equipment status, use id number to identify it
            break;
        default: // any other number outputs the following
            printf("<invalid-choice>");
            break;
    }
    //the user will input the change they want for the piece of equipment
    // they will be asked the ID number of the equipment item
    //updates the status of the equipment (working, broken, being repaired)
}

/*
 The View_Bookings function outputs all the entries in the booking database
 */

void View_Bookings (void) {
    //displays all the booking made by students
}

/*
 The Update_Booking_For_Equipment function focuses on two areas; start and end data as well as process returns
 The start and end date area is important for setting a timeline for the student
 The process returns area deletes the return entry for that booking (should only be done when an item is collected from a student)
 */
void Update_Booking_For_Equipment (void) {
    int i = 0;
    while (i == 0) {
        // variable placeholders
        int choice = 0;
        int Booking_ID = 0;
        //asks for booking ID and what they want to change about the booking entry. saves inputs in various variables
        printf("\nPlease enter the booking ID: ");
        scanf("%d", &Booking_ID);
        printf("\n\nWhat are you Updating about the Booking? ");
        printf("\n1. Start and End Date: ");
        printf("\n2. Process Returns: ");
        printf("\n3. Return to Technician Window: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // to set the start and end date of a booking entry
                char Start [11];
                char End [11];
                printf("\nWhat is the Start Date (dd/mm/YYYY): ");
                scanf("%s", &Start);
                printf("\nWhat is the End Date (dd/mm/YYYY): ");
                scanf("%s", &End);
                //add it into the sql database
                break;
            case 2: // to process a return (delete a booking entry; due to being completed)
                // Get rid of the booking
                break;
            case 3: // to return to the technician entry
                i++;
                break;
            default:
                break;
        }
    }
}
