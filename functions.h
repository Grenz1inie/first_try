#ifndef FUNCTIONS_H   // 防止头文件被重复包含  
#define FUNCTIONS_H  

#define _CRT_SECURE_NO_WARNINGS 1

#include"basic.h"

struct customer* create(void);

void add(struct customer* phead1);

void print(struct customer* phead);

void delet(struct customer* phead, FILE* stream);

void cleardata(struct customer* phead);

void saveToFile(struct customer* phead, const wchar_t* filename);

void loadFromFile(struct customer* phead, const wchar_t* filename);

struct expense_record
{
	int time[10];
	wchar_t commodity_name[100];
	float value[3];
};

struct customer
{
	wchar_t name[100];
	int phone_number[20];
	struct expense_record;
	struct customer* next;
};

struct customer* create(void)
{
	struct customer* phead;
	phead = (struct customer*)malloc(sizeof(struct customer));
	memcpy(phead->name, L"admin", sizeof(wchar_t) * (wcslen(L"admin") + 1));
	phead->next = NULL;
	return phead;
}

void add(struct customer* phead)
{
	printf("请输入添加用户名称：\n");
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
	printf("\n请输入目标序号：\n");
	int n = 0;
	scanf("%d", &n);
	if (n <= 0)
	{
		system("cls");
		printf("删除失败，请重新操作\n按回车继续");
		getchar(stream); getchar(stream);
		return;
	}
	for (n--; n > 0; phead = phead->next, n--)
	{
		if (phead->next == NULL)
		{
			system("cls");
			printf("删除失败，请重新操作\n按回车继续");
			getchar(stream); getchar(stream);
			return;
		}
	}
	if (phead->next == NULL)
	{
		system("cls");
		printf("删除失败，请重新操作\n按回车继续");
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
	printf("删除成功\n按回车继续");
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

void saveToFile(struct customer* phead, const wchar_t* filename, FILE* stream)
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("无法打开文件\n");
		return;
	}
	for (struct customer* temp = phead->next; temp != NULL; temp = temp->next)
	{
		fwprintf(fp, L"%ls", temp->name);
	}
	fclose(fp);
	printf("保存成功\n按回车继续");
	getchar(stream);
}

void loadFromFile(struct customer* phead, const wchar_t* filename)
{
	if (phead->next != NULL)
		cleardata(phead->next);
	FILE* fp = fopen("data.txt", "r");
	if (!fp) {
		wprintf(L"无法打开文件\n");
		return;
	}
	wchar_t name[100];
	while (fgetws(name, 100, fp))
	{
		if (name != '\n')
		{
			phead->next = (struct customer*)malloc(sizeof(struct customer));
			phead = phead->next;
		}
		swprintf(phead->name, 100, L"%ls", name); // 将读取的名字设置到最后一个节点  
	}
	phead->next = NULL;
	fclose(fp);
}


#endif // FUNCTIONS_H