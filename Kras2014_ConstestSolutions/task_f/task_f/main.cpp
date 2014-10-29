#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int t[100009];

void ReadData()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}
}

__int64 answer;

bool check(__int64 target)
{
	__int64 result = k;
	for(int i = 0; i < n; i++)
	{
		result -= target /t[i];
		if(result <= 0)
		{
			return true;
		}
	}
	return result <= 0;
}

void Solve()
{
	sort(t, t + n);
	//printf("stage 1 done!\n");
	__int64 l = 1;
	__int64 r = _I64_MAX - 1000;
	//printf("stage 2 done!\n");
	while(r - l > 10)
	{
		__int64 center = l + (r - l) / 2;
		if(check(center))
		{
			r = center;
		}
		else
		{
			l = center + 1;
		}
	}
	for(; l <= r; l++)
	{
		if(check(l))
		{
			answer = l;
			break;
		}
	}
}

void WriteData()
{
	printf("%I64d\n", answer);
}

int main()
{
	int QWE = 1;
	freopen("FORD.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}