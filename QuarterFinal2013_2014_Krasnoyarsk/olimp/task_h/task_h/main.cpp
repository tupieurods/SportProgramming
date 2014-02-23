#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

__int64 x_1, x_2, y_1, y_2;

void ReadData()
{
	scanf("%I64d %I64d %I64d %I64d", &x_1, &y_1, &x_2, &y_2);
	if(x_1 > x_2)
	{
		std::swap(x_1, x_2);
		std::swap(y_1, y_2);
	}
}

__int64 answer;

void Solve()
{
	answer = 0;
	if(x_1 == y_1 && x_2 == y_2)
	{
		answer = abs(x_1 - x_2) + 1;
		return;
	}
	if(x_1 == x_2)
	{
		answer = 1 + abs(y_1 - y_2);
		return;
	}
	else if(y_1 == y_2)
	{
		answer = 1 + abs(x_1 - x_2);
		return;
	}
	for(int i = x_1; i <= x_2; i++)
	{
		__int64 y_test = i * (y_2 - y_1) - x_1 * (y_2 - y_1) + y_1 * (x_2 - x_1);
		__int64 y_test2 = y_test / (x_2 - x_1);
		if(y_test2 * (x_2 - x_1) == y_test)
		{
			answer++;
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
	freopen("SEGMENT.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}