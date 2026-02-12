#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "loginSignUp.c"
#include "sqlite3.c"
#include "sqlite3.h"
#include "db.c"
#include "db.h"
#include "SQLServiceLayer.c"
#include "SQLServiceLayer.h"
//declared functions for later use
void View_Equipment (void);
void View_Own_Bookings (void);
void Make_Bookings (void);
void Cancel_Bookings (void);
void student (void);
/*
 The student function is essentially the "main" part of this file
 It is the "controller", meaning the student can access all of his seperate actions through this function
 */
void student (void) {
    int i = 0;
    while (i == 0) {
        int choice;
        //prompts to ask what the user would like to do
        printf("\n\nWelcome Back Student!");
        printf("\nWhat would you like to do today?");
        printf("\n1. Browse Equipment: ");
        printf("\n2. View your Bookings ");
        printf("\n3. Make Bookings: ");
        printf("\n4. Cancel Bookings: ");
        printf("\n5. Close Program: ");
        scanf("%d", &choice);
        switch(choice){ // switch case for each option afforded to the user. Calls a function based on the answer
            case 1: // calls View_equipment
                View_Equipment();
                break;
            case 2: // calls View_Own_Bookings
                View_Own_Bookings();
                break;
            case 3: // calls Make_Bookings
                Make_Bookings();
                break;
            case 4: // calls Cancel_Bookings
                Cancel_Bookings();
                break;
            case 5: //Closes the program
                printf("NOW CLOSING THE PROGRAM...");
                i++;
                break;
            default:
                break;
        }
    }
}
/*
 The View_Equipment function lists all the items in the equipment database
 */
void View_Equipment (void) {
    //displays all equipment sql
    ListEquipment();
}

/*
 The View_Own_Bookings function, asks the user for their uni ID and outputs all bookings related to that ID
 */
void View_Own_Bookings (void) {
    int University_ID = 0;
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    //Output any bookings made with that Uni ID
}

/*
 The Make_Bookings function allows the user to book an item for the equipment database
 This happens through premade variables and inputs
 */
void Make_Bookings (void) {
    int University_ID = 0;
    int Item_Number = 0;
    int Booking_ID = rand() % 900000000 + 100000000; // a random number genarated between 999999999 and 100000000
    char Start_Date [] = "-1"; // placeholder; will be changed by the techinician in another file
    char Due_Date [] = "-1"; // placeholder; will be changed by the techinician in another file
    // the following gets the current date from the user and saves it as a string
    time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char Requested_Date[11];
        strftime(Requested_Date, sizeof(Requested_Date), "%d/%m/%Y", tm_info);
    printf("Please Enter your University ID: "); // to get the uni ID
    scanf("%d", &University_ID);
    printf("Please Enter the Item Number: "); // to get the item number
    scanf("%d", &Item_Number);
    //put into the database, new booking
}
/*
 the Cancel_Booking function removes a booking made by the student
 it can only remove this booking if the "-1" placeholder in start date has changed.
 */
void Cancel_Bookings (void) {
    // the following asks the user for uni id and booking number to cancel the students booking
    int University_ID = 0;
    int Booking_ID = 0;
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    printf("Please Enter the Booking Number: ");
    scanf("%d", &Booking_ID);
    // make sure the booking reference and uni ID add up. Get rid of the booking. can only cancel if there is "-1" in start date.
}
