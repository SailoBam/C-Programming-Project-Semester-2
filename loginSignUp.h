#ifndef LOGINSIGNUP_H
#define LOGINSIGNUP_H

#include "sqlite3.h"

/* Main entry point for authentication */
void startlogin(void);

/* Login and signup functions */
void login(void);
void signup(void);

#endif
