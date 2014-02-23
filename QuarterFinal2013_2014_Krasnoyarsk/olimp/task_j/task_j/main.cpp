#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int h, l;
pair<int, int> cars[2509];
int current[59];
int carsCnt;

void ReadData()
{
	scanf("%d %d", &h, &l);
	carsCnt = -1;
	for(int i = 0; i < h; i++)
	{
		current[i] = 1;
		for(int j = 0; j < l; j++)
		{
			int val;
			scanf("%d", &val);
			if(val != -1)
			{
				carsCnt = max(carsCnt, val);
				cars[val - 1] = make_pair(i, j + 1);
			}
		}
	}
}

__int64 answer;

void Solve()
{
	answer = 0;
	for(int i = 0; i < carsCnt; i++)
	{
		answer += cars[i].first * 20;
		int v1 = max(current[cars[i].first], cars[i].second) - min(current[cars[i].first], cars[i].second);
		int v2 = (l - max(current[cars[i].first], cars[i].second)) + min(current[cars[i].first], cars[i].second);
		answer += min(v1, v2) * 5;
		current[cars[i].first] = cars[i].second;
	}
}

void WriteData()
{
	printf("%I64d\n", answer);
}

int main()
{
	int QWE = 1;
	freopen("TOWER.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}