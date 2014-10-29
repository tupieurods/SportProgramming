#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[50];
bool a[19];

int main()
{
	int QWE = 1;
	scanf("%d%*c", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		scanf("%s%*c", str);
		int l= strlen(str);
		memset(a, 0, sizeof(a));
		for(int i = 0; i < l; i++)
		{
			a[str[i] - '0'] = true;
		}
		int cnt = 0;
		for(int i = 0; i < 10; i++)
		{
			if(a[i] == false)
			{
				printf("%d", i);
				cnt++;
			}
		}
		if(cnt == 0)
		{
			printf("allo\n");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}