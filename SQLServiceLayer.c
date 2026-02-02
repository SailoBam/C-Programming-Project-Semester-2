#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.c"

void CreateUsersTable(sqlite3 *DB) {
    char *sql =
        "CREATE TABLE IF NOT EXISTS USERS ("
        "ID INTEGER PRIMARY KEY NOT NULL, "
        "USERNAME TEXT NOT NULL, "
        "NAME TEXT NOT NULL, "
        "SURNAME TEXT NOT NULL, "
        "PASSWORD TEXT NOT NULL, "
        "STATUS TEXT, "
        "UNIVERSITYID INTEGER);";
	
	char *errMsg = 0;
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);
    
    printf("Users table created successfully\n");
	}
	
void CreateEquipmentTable(sqlite3 *DB) {
    char *equip =
        "CREATE TABLE IF NOT EXISTS EQUIPMENT ("
        "ID INTEGER PRIMARY KEY NOT NULL, "
        "ITEMNUMBER INT NOT NULL, "
        "PURCHASEDATE DATE NOT NULL, "
        "DESCRIPTION TEXT NOT NULL, "
        "WORKINGSTATUS TEXT NOT NULL, "
        "AVAILABILITY TEXT);";

    char *errMsg = 0;
    int rc = sqlite3_exec(DB, equip, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("Equipment table created successfully\n");
}

void CreateBookingTable(sqlite3 *DB) {
    char *booking =
        "CREATE TABLE IF NOT EXISTS BOOKING ("
        "ID INTEGER PRIMARY KEY NOT NULL, "
        "BOOKINGID INT NOT NULL, "
        "STUDENTID INT NOT NULL, "
        "ITEMNUMBER INT NOT NULL, "
        "REQUESTEDAT TEXT NOT NULL, "
        "STARTDATE DATE NOT NULL, "
        "DUEDATE DATE NOT NULL, "
        "COLLECTEDAT TEXT NOT NULL, "
        "RETURNEDAT TEXT);";

    char *errMsg = 0;
    int rc = sqlite3_exec(DB, booking, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("Booking table created successfully\n");
}


void OpenDB(void) {
    sqlite3 *DB;

    if (sqlite3_open("store.db", &DB)) {
        printf("Can't open database: %s\n", sqlite3_errmsg(DB));
    }

    CreateUsersTable(DB);
    CreateEquipmentTable(DB);
    CreateBookingTable(DB);

    sqlite3_close(DB);
}
