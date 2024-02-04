#ifndef MANU_H
#define MANU_H

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic.h"
#include"user.h"

void login_manu(FILE* stream)
{
	char account[9] = { 0 }, passwords[9] = { 0 }, correctpass[9] = { '6','6','6',0 };
	printf("plz enter account and passwords\n");
	scanf("%s", account); getchar(stream);
	while (1)
	{
		scanf("%s", passwords); getchar(stream);
		if (!strcmp(account, correctpass))
		{
			char temp[9] = { 0 };
			FILE* fp = fopen("admin.txt", "r");
			fgets(temp, 9, fp);
			fclose(fp);
			if (!strcmp(passwords, temp))
				admin(stream);
			else
			{
				system("cls");
				printf("error\nplz try again\n");
			}
		}
	}
}

void add_manu(FILE* stream)
{

}

void change_manu(FILE* stream)
{
	char temp[9] = { 0 };
	FILE* fp = fopen("admin.txt", "w");
	if (!fp)
	{
		printf("无法打开文件\n");
		return;
	}
	printf("plz");
	fgets(temp, 8, stdin);
	fprintf(fp, "%s", temp);
	fclose(fp);
}




#endif 
