#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.c"
#include "sqlite3.h"
#include "SQLServiceLayer.c"
#include "loginSignUp.c"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	OpenDB();
	startlogin();
	return 0;
}