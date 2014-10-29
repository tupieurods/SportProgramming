#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int p[109];
int zero;

void ReadData()
{
	scanf("%d", &n);
	zero = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		if(p[i] == 0)
		{
			zero++;
		}
	}
}

int answer;

void Solve()
{
	answer = 0;
	while(zero != n)
	{
		bool boooo = false;
		for(int i = 0; i < n; i++)
		{
			if(p[i] <= 18 && p[i] >= 11)
			{
				boooo = true;
				p[i] -= 9;
				answer++;
				//continue;
			}
			if((p[i] % 10) != 0)
			{
				p[i] -= p[i] % 10;
				if(p[i] == 0)
				{
					zero++;
				}
				answer++;
			}
		}
		if(zero == n)
		{
			break;
		}
		if(boooo)
		{
			continue;
		}
		answer++;
		for(int i = 0; i < n; i++)
		{
			p[i] /= 10;
		}
	}
}

void WriteData()
{
	printf("%d\n", answer);
}

int main()
{
	int QWE = 1;
	freopen("HOLIDAY.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}