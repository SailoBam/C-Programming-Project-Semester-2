//
//  main.c
//  TechnicianAbilities
//
//  Created by Dexton Grant on 2026-02-01.
//

#include <stdlib.h>
#include <stdio.h>

void View_Equipment (void);
void Update_Equipment_Status (void);
void View_Bookings (void);
void Update_Booking_For_Equipment (void);
int main(int argc, const char * argv[]) {
    int choice;
    printf("Welcome Back Technician!");
    printf("\nWhat would you like to do today?");
    printf("1. View Equipment: ");
    printf("2. Update Equipment Status: ");
    printf("3. View Bookings: ");
    printf("4. Update Bookings: ");
    printf("5. Close Program: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            View_Equipment;
            break;
        case 2:
            Update_Equipment_Status;
            break;
        case 3:
            View_Bookings;
            break;
        case 4:
            Update_Booking_For_Equipment;
            break;
        case 5:
            printf("NOW CLOSING THE PROGRAM...");
            exit(0);
        default:
            printf("<INVALID OPTION CHOSEN>");
            printf("<ERROR RESULTING IN PROGRAM SHUTTING DOWN>");
            exit(0);
    }
}

void View_Equipment (void) {
    //displays the equipment sql
}
void Update_Equipment_Status (void) {
    //updates the status of the equipment (working, broken, being repaired)
}
void View_Bookings (void) {
    //displays all the booking made by students
}
void Update_Booking_For_Equipment (void) {
    // able to update the book status (if its with the student or if they've returned it
}
