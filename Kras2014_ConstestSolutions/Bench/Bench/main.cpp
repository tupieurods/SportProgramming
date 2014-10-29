#include <stdlib.h>
#include <stdio.h>

int main()
{
	__int64 t = 0;
	int n = 1000000000;
	for(int i = 0; i < 1000000000 / 2; i++)
	{
		t = (t + (n - i) * 1LL * (n - i - 1)) % 2017;
	}
	printf("%I64d\n");
	return 0;
}