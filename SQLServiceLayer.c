#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"


// =============== Table Creation ===================

// Creates the three database tables
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
    // Checks that the sql command is run correctly otherwise it returns an error message, This is repeated throughout the code where sql messages are run
	if (rc != SQLITE_OK) {
        printf("Users error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    printf("Users table created \n");
	}
	
void CreateEquipmentTable(sqlite3 *DB) {
    char *equip =
        "CREATE TABLE IF NOT EXISTS EQUIPMENT ("
        "ID INTEGER PRIMARY KEY NOT NULL, "
        "ITEMNUMBER INT NOT NULL, "
        "ITEMNAME TEXT NOT NULL,"
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
    printf("Equipment table created \n");
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
        "DUEDATE DATE NOT NULL); ";

    char *errMsg = 0;
    int rc = sqlite3_exec(DB, booking, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("Booking table created \n");
}



// =============== Accessing USERS Functions =======================


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

void SignUpAdmin(sqlite3 *DB, char first_name[], char last_name[], char username[], char password[], int university_ID, char status[]){
    char command[1000];
    snprintf(command, sizeof command, "INSERT INTO USERS (USERNAME, NAME, SURNAME, PASSWORD, STATUS, UNIVERSITYID, STATUS) VALUES('%s', '%s', '%s', '%s', '%s', '%d', '%s');", username, first_name, last_name, password, status, university_ID, status);
    //printf("%s\n", command);
    
    char *errMsg = 0;
    int addAccount = sqlite3_exec(DB, command, 0, 0, &errMsg);

    if (addAccount != SQLITE_OK) {
        printf("Users error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void EditUser(sqlite3 *DB, int idNumber, char attribute[], char value[]){
    char sql[512];
	char *errMsg = NULL;
	
	snprintf(sql, sizeof sql, "UPDATE USERS SET '%s' = '%s' WHERE ID = '%d' ;", attribute, value, idNumber );
        
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("\n Entry Edited");
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
        "SELECT STATUS FROM USERS WHERE USERNAME = '%s' AND PASSWORD ='%s';", username, password);

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

void RemoveUser(sqlite3 *DB, int idNumber){
	printf("\n INSIDE REMOVEUSER");
    char sql[512];
	char *errMsg = NULL;
	
	snprintf(sql, sizeof sql, "DELETE FROM USERS WHERE ID = %d;", idNumber );
    printf("\n message is %s", sql);
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("\n Entry Removed");
}

// ==================== Accessing EQUIPMENT Functions =======================

void AddEquipment(sqlite3 *DB, int itemNumber, char itemName[], char purchaseDate[], char description[], char workingStatus[], char availability[] ){
    char command[1000];
    snprintf(command, sizeof command, "INSERT INTO EQUIPMENT (ITEMNUMBER, ITEMNAME, PURCHASEDATE, DESCRIPTION, WORKINGSTATUS, AVAILABILITY) VALUES( %d, '%s', '%s', '%s', '%s', '%s');", itemNumber, itemName, purchaseDate, description, workingStatus, availability);
    printf("%s\n", command);
    
    char *errMsg = 0;
    int addEquipment = sqlite3_exec(DB, command, 0, 0, &errMsg);

    if (addEquipment != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void RemoveEquipment(sqlite3 *DB, int idNumber){
    char sql[512];
	char *errMsg = NULL;
	
	snprintf(sql, sizeof sql, "DELETE FROM EQUIPMENT WHERE ID = %d ;", idNumber );
        
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("\n Entry Removed");
}

void EditEquipment(sqlite3 *DB, int idNumber, char attribute[], char value[]){
    char sql[512];
	char *errMsg = NULL;
	
	snprintf(sql, sizeof sql, "UPDATE EQUIPMENT SET '%s' = '%s' WHERE ID = %d ", attribute, value, idNumber);
    printf("\n The SQL message is %s", sql);
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("\n Entry Edited");
}




int printEquipment(void *NotUsed, int argc, char **argv, char **colName)
{
    for (int i = 0; i < argc; i++) {
        printf("%-15s", argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void ListEquipment(sqlite3 *DB){
    printf("----------------------------------------------------------------------------------------------\n");

    const char *sql = "SELECT * FROM EQUIPMENT;";
	char *errMsg = NULL;
    int rc = sqlite3_exec(DB, sql, printEquipment, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

// ==================== Accessing BOOKING Functions =======================


void AddBooking(sqlite3 *DB, int bookingID, int studentID, int itemNumber, char requestedAt[], char startDate[], char dueDate[]){
	printf("INSIDE ADD BOOKINGS");
    char command[1000];
    snprintf(command, sizeof command, "INSERT INTO BOOKING (BOOKINGID, STUDENTID, ITEMNUMBER, REQUESTEDAT, STARTDATE, DUEDATE) VALUES( %d, %d, %d, '%s', '%s', '%s');", bookingID, studentID, itemNumber, requestedAt, startDate, dueDate);
    printf("%s\n", command);
    
    char *errMsg = 0;
    int addBooking = sqlite3_exec(DB, command, 0, 0, &errMsg);

    if (addBooking != SQLITE_OK) {
        printf("Equipment error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    //         Set the availabilty to booked
    
    char sql[512];
	snprintf(sql, sizeof sql, "UPDATE EQUIPMENT SET AVAILABILITY = 'booked' WHERE ITEMNUMBER = %d ", itemNumber);
    printf("\n The SQL message is %s", sql);
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
}

void ListBookings(sqlite3 *DB){
    printf("----------------------------------------------------------------------------------------------\n");

    const char *sql = "SELECT * FROM BOOKING;";
	char *errMsg = NULL;
    int rc = sqlite3_exec(DB, sql, printEquipment, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void ListPersonalBookings(sqlite3 *DB, int universityID){
    printf("----------------------------------------------------------------------------------------------\n");
	char command[1000];
    snprintf(command, sizeof command, "SELECT * FROM BOOKING WHERE STUDENTID = %d;", universityID);
    printf("Message is %s", command);
	char *errMsg = NULL;
    int rc = sqlite3_exec(DB, command, printEquipment, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void CancelBooking(sqlite3 *DB, int bookingID, int studentID){
	char find[512];
	char *errMsg = NULL;
 
    char update[512];
	snprintf(update, sizeof update, "UPDATE EQUIPMENT SET AVAILABILITY = 'available' WHERE ITEMNUMBER = (SELECT ITEMNUMBER FROM BOOKING WHERE BOOKINGID = %d AND STUDENTID = %d); ", bookingID, studentID);
    printf("\n The SQL message is %s", update);
    int rc = sqlite3_exec(DB, update, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    char sql[512];
	snprintf(sql, sizeof sql, "DELETE FROM BOOKING WHERE BOOKINGID = %d;", bookingID);
    printf("\n message is %s", sql);
    int exe = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (exe != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void FinishBooking(sqlite3 *DB, int bookingID){
	char find[512];
	char *errMsg = NULL;
 
    char update[512];
	snprintf(update, sizeof update, "UPDATE EQUIPMENT SET AVAILABILITY = 'available' WHERE ITEMNUMBER = (SELECT ITEMNUMBER FROM BOOKING WHERE BOOKINGID = %d); ", bookingID);
    printf("\n The SQL message is %s", update);
    int rc = sqlite3_exec(DB, update, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    
    char sql[512];
	snprintf(sql, sizeof sql, "DELETE FROM BOOKING WHERE BOOKINGID = %d;", bookingID);
    printf("\n message is %s", sql);
    int exe = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (exe != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void EditBookingDate(sqlite3 *DB, int idNumber, char startDate[], char dueDate[]){
    char sql[512];
	char *errMsg = NULL;
	
	snprintf(sql, sizeof sql, "UPDATE BOOKING SET STARTDATE = '%s', DUEDATE = '%s' WHERE BOOKINGID = %d ", startDate, dueDate, idNumber);
    printf("\n The SQL message is %s", sql);
    int rc = sqlite3_exec(DB, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    printf("\n Entry Edited");
}



void OpenDB(void) {

    if (sqlite3_open("store.db", &DB)) {
        printf("Can't open database: %s\n", sqlite3_errmsg(DB));
    }

    CreateUsersTable(DB);
    CreateEquipmentTable(DB);
    CreateBookingTable(DB);
    //sqlite3_close(DB);
}
