#ifndef STRUCT_AND_FUNCTIONS_H   
#define STRUCT_AND_FUNCTIONS_H  

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic_header.h"

struct customer* create(void);

void add(struct customer* phead1);

void print(struct customer* phead);

void delet(struct customer* phead, FILE* stream);

void cleardata(struct customer* phead);

void saveToFile(struct customer* phead, const wchar_t* filename);

void loadFromFile(struct customer* phead, const wchar_t* filename);

struct expense_record
{
	int time[10];					//����ʱ��
	wchar_t commodity_name[100];	//��Ʒ����
	float value[3];					//���������ۣ��ܼ�
};

struct customer
{
	char access[10];		//�û�Ȩ��
	wchar_t name[100];		//�û�����
	int phone_number[20];	//�û���ϵ��ʽ
	struct expense_record;	//�û����Ѽ�¼
	struct customer* next;	//��һ�ڵ�
};

struct customer* create(void)
{
	struct customer* phead;
	phead = (struct customer*)malloc(sizeof(struct customer));
	phead->next = NULL;
	return phead;
}

void add(struct customer* phead)
{
	printf("����������û����ƣ�\n");
	while (phead->next != NULL)
		phead = phead->next;
	phead->next = (struct customer*)malloc(sizeof(struct customer));
	phead = phead->next;
	fgetws(phead->name, 100, stdin);
	phead->next = NULL;
}

void delet(struct customer* phead, FILE* stream)
{
	struct customer* phead0 = phead;
	print(phead0);
	printf("\n������Ŀ����ţ�\n");
	int n = 0;
	scanf("%d", &n);
	if (n <= 0)
	{
		system("cls");
		printf("ɾ��ʧ�ܣ������²���\n���س�����");
		getchar(stream); getchar(stream);
		return;
	}
	for (n--; n > 0; phead = phead->next, n--)
	{
		if (phead->next == NULL)
		{
			system("cls");
			printf("ɾ��ʧ�ܣ������²���\n���س�����");
			getchar(stream); getchar(stream);
			return;
		}
	}
	if (phead->next == NULL)
	{
		system("cls");
		printf("ɾ��ʧ�ܣ������²���\n���س�����");
		getchar(stream); getchar(stream);
		return;
	}
	struct customer* ptemp = phead->next;
	if (ptemp->next == NULL)
	{
		phead->next = NULL;
		free(ptemp);
	}
	else
	{
		phead->next = ptemp->next;
		free(ptemp);
	}
	system("cls");
	printf("ɾ���ɹ�\n���س�����");
	getchar(stream); getchar(stream);
}

void print(struct customer* phead)
{
	int i = 1;
	if (phead->next == NULL)
		printf("No data\n");
	else
		for (phead = phead->next; phead != NULL; phead = phead->next)
			if (phead->name != L"\n")
				wprintf(L"%d.%ls", i++, phead->name);
}

void cleardata(struct customer* phead)
{
	if (phead->next != NULL) cleardata(phead->next);
	phead->next = NULL;
	free(phead);
}

void check(struct customer* phead, int num, FILE* stream)
{
	if (phead->next == NULL)
		printf("No data\n");
	else
		for (; num > 0; num--)
			phead = phead->next;
}

void SaveToFile(struct customer* phead, FILE* stream)
{
	FILE* pf = fopen("admin.txt", "wb");
	for (struct customer* ptemp = phead->next; ptemp != NULL; ptemp = ptemp->next)
		fwrite(ptemp, sizeof(struct customer), 1, pf);
	fclose(pf);
	printf("����ɹ�\n���س�����");
	getchar(stream);
}

void LoadFromFile(struct customer* phead, FILE* stream)
{
	size_t a=0;
	struct customer* ptemp1 = NULL;
	struct customer* ptemp2 = (struct customer*)malloc(sizeof(struct customer));
	FILE* pf = fopen("admin.txt", "rb");
	if (!pf)
	{
		ferror(errno);
		return;
	}
	if (a=fread(ptemp2, sizeof(struct customer), 1, pf) > 0)
		for (ptemp1 = phead; a > 0; ptemp1 = ptemp1->next)
		{
			ptemp1->next = ptemp2;
			ptemp2 = (struct customer*)malloc(sizeof(struct customer));
			a=fread(ptemp2, sizeof(struct customer), 1, pf);
		}
	else
		phead->next = NULL;
	fclose(pf);
	printf("����ɹ�\n���س�����");
	getchar(stream);
}


#endif // FUNCTIONS_H