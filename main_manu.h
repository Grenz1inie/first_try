#ifndef MAIN_MANU_H
#define MAIN_MANU_H

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic_header.h"
#include"sub_manu.h"

void main_login_manu(FILE* stream)
{
	char account[12] = { 0 }, password[7] = {0};
	gets(account);
	gets(password);



				admin(stream);
}



#endif 
