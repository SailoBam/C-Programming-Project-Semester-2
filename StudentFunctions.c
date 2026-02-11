//
//  main.c
//  TechnicianAbilities
//
//  Created by Dexton Grant on 2026-02-01.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void View_Equipment (void);
void View_Own_Bookings (void);
void Make_Bookings (void);
void Cancel_Bookings (void);

void main (void) {
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
    printf("Please Enter your University ID: ");
    scanf("%d", &University_ID);
    printf("Please Enter the Item Number: ");
    scanf("%d", &Item_Number);
    time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char Requested_Date[11];   // "YYYY-MM-DD" + null terminator
        strftime(Requested_Date, sizeof(Requested_Date), "%d/%m/%Y", tm_info);
    //
    
}
void Cancel_Bookings (void) {
    // able to update the book status (if its with the student or if they've returned it
}
