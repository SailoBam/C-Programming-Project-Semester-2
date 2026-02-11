#ifndef ADMINFUNCTIONS_H
#define ADMINFUNCTIONS_H
#include "sqlite3.h"

/* Main admin menu */
void admin(void);

/* Equipment functions */
void Equipment_Functions(void);
void Add_Equipment(void);
void Change_Equipment(void);
void Remove_Equipment(void);
void View_Equipment(void);

/* User functions */
void User_Functions(void);
void Add_User(void);
void Change_User(void);
void Remove_User(void);
void View_Users(void);

#endif
