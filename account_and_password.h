#ifndef ACCOUNT_AND_PASSWORD_H
#define ACCOUNT_AND_PASSWORD_H

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic_header.h"

int check_access(char* input)
{
	struct user* temp = NULL;
	FILE* pf = fopen("users_list.txt", "r");
	if (!pf)
	{
		ferror(errno);
		return -1;
	}
	temp = (struct user*)malloc(sizeof(struct user));
	fread(temp, sizeof(struct user), 1, pf);
	fclose(pf);
	if (!strcmp(temp->account, input))
		return 1;
	else
		return 0;
}

char* return_password(char* input)
{
	struct user* temp= NULL;
	FILE* pf = fopen("users_list.txt", "r");
	if (!pf)
	{
		ferror(errno);
		return NULL;
	}
	for (size_t a = 1;;)
	{
		temp = (struct user*)malloc(sizeof(struct user));
		a=fread(temp, sizeof(struct user), 1, pf);
		if (!a)
		{
			fclose(pf);
			return NULL;
		}
		if (!strcmp(temp->account, input))
		{
			fclose(pf);
			return temp->password;
		}
	}
}


#endif
