#ifndef MAIN_MANU_H
#define MAIN_MANU_H

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic_header.h"
#include"sub_manu.h"
#include"account_and_password.h"

void main_login_manu(FILE* stream)
{
	char account[12] = { 0 }, password[7] = { 0 }, * temp = NULL;
	gets(account);
	if (check_access(account))
		for (char* temp = return_password(account);;)
		{
			gets(password);
			if (!strcmp(password, "0"))
				return;
			else
				if (!strcmp(password, temp))
					admin(stream);
				else
				{
					continue;
				}
		}
	else
		return;
}


#endif 
