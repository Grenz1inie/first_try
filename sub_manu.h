#ifndef SUB_MANU_H
#define SUB_MANU_H

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic_header.h"
#include"struct_and_functions.h"

void admin(FILE* stream)
{
	struct customer* phead = create();
	memcpy(phead->access, "admin", sizeof("admin"));
	int n = 0;
	while (1)
	{
		system("cls");
		printf("��ǰ���ݿ⣺\n");


		print(phead);
		printf("\n>>>��ѡ�����Ĳ���<<<\n1.����û�\n2.ɾ��ָ���û�\n3.search\n4.���\n5.��������\n6.��������\n0.�˳�\n\n");

		scanf("%d", &n); getchar(stream);

		if (n == 0)
		{
			system("cls");
			exit(0);
		}
		else if (n == 1)
		{
			system("cls");
			add(phead);
		}
		else if (n == 2)
		{
			system("cls");
			delet(phead, stream);
		}
		else if (n == 3)
		{
			system("cls");

		}
		else if (n == 4)
		{
			system("cls");
			cleardata(phead->next);
			phead->next = NULL;
		}
		else if (n == 5)
		{
			system("cls");
			SaveToFile(phead,stream);
		}
		else if (n == 6)
		{
			system("cls");
			LoadFromFile(phead, stream);
		}

	}
}




#endif 
