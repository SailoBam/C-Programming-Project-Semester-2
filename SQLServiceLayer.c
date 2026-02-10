#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"


// =============== Table Creation ===================

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
    
	if (rc != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
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



// =============== Accessing Functions =======================


void SignUpStudent(sqlite3 *DB, char first_name[], char last_name[], char username[], char password[], int university_ID){
	char status[] = "student";
    char command[1000];
    snprintf(command, sizeof command, "INSERT INTO USERS (USERNAME, NAME, SURNAME, PASSWORD, STATUS, UNIVERSITYID) VALUES('%s', '%s', '%s', '%s', '%s', '%d');", username, first_name, last_name, password, status, university_ID);
    //printf("%s\n", command);
    
    char *errMsg = 0;
    int addAccount = sqlite3_exec(DB, command, 0, 0, &errMsg);

    if (addAccount != SQLITE_OK) {
        printf("Users error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

int identifyStatus(void *data, int argc, char **argv, char **colName)
{
    int *status = (int *)data;

    if (argc < 1 || argv[0] == NULL)
        return 0;

    if (strcmp(argv[0], "student") == 0)
        *status = 1;
    else if (strcmp(argv[0], "technician") == 0)
        *status = 2;
    else if (strcmp(argv[0], "admin") == 0)
        *status = 3;

    return 0;
}

int SignIn(sqlite3 *DB, char username[], char password[])
{
    char sql[512];
    int status = 0;
    char *errMsg = NULL;

    snprintf(sql, sizeof sql,
        "SELECT STATUS FROM USERS WHERE USERNAME='%s' AND PASSWORD='%s';",
        username, password);

    int rc = sqlite3_exec(DB, sql, identifyStatus, &status, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQLite error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return -1;
    }

    return status;
}



int printUsers(void *NotUsed, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++) {
        printf("%-15s", argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void ListUsers(sqlite3 *DB){
    printf("----------------------------------------------------------------------------------------------\n");

    const char *sql = "SELECT * FROM USERS;";
	char *errMsg = NULL;
    int rc = sqlite3_exec(DB, sql, printUsers, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}


void OpenDB() {

    if (sqlite3_open("store.db", &DB)) {
        printf("Can't open database: %s\n", sqlite3_errmsg(DB));
    }

    CreateUsersTable(DB);
    CreateEquipmentTable(DB);
    CreateBookingTable(DB);
    //sqlite3_close(DB);
}
