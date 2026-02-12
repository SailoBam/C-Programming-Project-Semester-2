#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "sqlite3.h"

/* Main technician menu */
void technician(void);

/* Menu options */
void View_Equipment(void);
void Update_Equipment_Status(void);
void View_Bookings(void);
void Update_Booking_For_Equipment(void);

#endif
