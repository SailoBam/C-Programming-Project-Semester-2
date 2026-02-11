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

void View_Equipment (void);
void View_Own_Bookings (void);
void Make_Bookings (void);
void Cancel_Bookings (void);
void student (void);
void student (void) {
    int i = 0;
    while (i == 0) {
        int choice;
        printf("\n\nWelcome Back Student!");
        printf("\nWhat would you like to do today?");
        printf("\n1. Browse Equipment: ");
        printf("\n2. View your Bookings ");
        printf("\n3. Make Bookings: ");
        printf("\n4. Cancel Bookings: ");
        printf("\n5. Close Program: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                View_Equipment();
                break;
            case 2:
                View_Own_Bookings();
                break;
            case 3:
                Make_Bookings();
                break;
            case 4:
                Cancel_Bookings();
                break;
            case 5:
                printf("NOW CLOSING THE PROGRAM...");
                i++;
                break;
            default:
                break;
        }
    }
}

void View_Equipment (void) {
    //displays all equipment sql
    ListEquipment();
}
void View_Own_Bookings (void) {
    int University_ID = 0;
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    //Output any bookings made with that Uni ID
}
void Make_Bookings (void) {
    int University_ID = 0;
    int Item_Number = 0;
    int Booking_ID = rand() % 900000000 + 100000000;
    char Start_Date [] = "-1";
    char Due_Date [] = "-1";
    time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char Requested_Date[11];   // "YYYY-MM-DD" + null terminator
        strftime(Requested_Date, sizeof(Requested_Date), "%d/%m/%Y", tm_info);
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    printf("Please Enter the Item Number: ");
    scanf("%d", &Item_Number);
    //put into the database, new booking
}
void Cancel_Bookings (void) {
    int University_ID = 0;
    int Booking_ID = 0;
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    printf("Please Enter the Booking Number: ");
    scanf("%d", &Booking_ID);
    // make sure the booking reference and uni ID add up. Get rid of the booking. can only cancel if there is "-1" in start date.
}
