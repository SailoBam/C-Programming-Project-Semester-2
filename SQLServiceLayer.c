#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

void CreateUsersTable(sqlite3 *DB) {
    const char *sql =
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
	
void CreateItemsTable(sqlite3 *DB) {
	
}

void OpenDB(void) {
    sqlite3 *DB;

    if (sqlite3_open("store.db", &DB)) {
        printf("Can't open database: %s\n", sqlite3_errmsg(DB));
    }

    CreateUsersTable(DB);

    sqlite3_close(DB);
}
