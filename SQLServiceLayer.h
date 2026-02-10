// SQLServiceLayer.h
#ifndef SQLSERVICE_LAYER_H
#define SQLSERVICE_LAYER_H
#include "sqlite3.c"
#include "sqlite3.h"

// Functions to create tables
void CreateUsersTable(sqlite3 *DB);
void CreateEquipmentTable(sqlite3 *DB);
void CreateBookingTable(sqlite3 *DB);

// Function to open the database and create tables
void OpenDB(void);

#endif // SQLSERVICE_LAYER_H
