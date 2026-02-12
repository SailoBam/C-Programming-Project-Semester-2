#ifndef STUDENT_H
#define STUDENT_H

#include "sqlite3.h"

/* Main student menu */
void student(void);

/* Menu options */
void View_Equipment(void);
void View_Own_Bookings(void);
void Make_Bookings(void);
void Cancel_Bookings(void);

#endif
