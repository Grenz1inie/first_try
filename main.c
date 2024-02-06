#include"basic_header.h"
#include"main_manu.h"

int main()
{
	setlocale(LC_ALL, "");
	FILE* stream = freopen("CON", "r", stdin);
	for(int n=0;;)
	{
		system("cls");
		printf("1 to login\n4 to exit\n");
		scanf("%d", &n); getchar();
		if (n == 1)
		{
			system("cls");
			main_login_manu(stream);
		}
		else if (n == 4)
			exit(0);
	}
	return 0;
}