#include"basic_header.h"
#include"main_manu.h"

int main()
{
	setlocale(LC_ALL, "");
	FILE* stream = freopen("CON", "r", stdin);
	for(int n=0;;)
	{
		printf("1 to login\n4 to exit\n");
		scanf("%d", &n);
		if (n == 1)
			main_login_manu(stream);
		else if (n == 4)
			exit(0);
	}
	return 0;
}


//123556