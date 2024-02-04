#include"basic.h"
#include"manu.h"

int main()
{
	setlocale(LC_ALL, "");
	FILE* stream = freopen("CON", "r", stdin);
	for(int n=0;;)
	{
		printf("1 to login\n2 to add\n3 to change\n4 to exit\n");
		scanf("%d", &n);
		if (n == 1)
			login_manu(stream);
		else if (n == 2)
			add_manu(stream);
		else if (n == 3)
			change_manu(stream);
		else if (n == 4)
			exit(0);
	}
	return 0;
}


//123556