#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n;
vector<pair<__int64, __int64>> prec;

void ReadData()
{
	scanf("%d", &n);
}

bool answer;
map<pair<__int64, int>, bool> m;

bool f(__int64 v, int step)
{
	if(v >= n)
	{
		return true;
	}
	if(m.find(make_pair(v, step)) != m.end())
	{
		return m[make_pair(v, step)];
	}
	bool result = true;
	for(int i = 2; i <= 9; i++)
	{
		result = result && !f(v * i, (step + 1) % 2);
	}
	m[make_pair(v, step)] = result;
	return result;
}


/*
4
9
10
1149729
999999999
*/
void Solve()
{
	int sz = prec.size();
	answer = true;
	for(int i = 0; i < sz; i++)
	{
		if(n >= prec[i].first && n <= prec[i].second)
		{
			break;
		}
		answer = !answer;
	}
	//tl or wa, but i can try...
	/*m.clear();
	answer = !f(1, 0);*/
	/*__int64 t1 = 1;
	__int64 t2 = 1;
	bool step = true;
	while(true)
	{
		if(step)
		{
			t1 *= 9;
			if(t1 >= n)
			{
				answer = true;
				break;
			}
		}
		else
		{
			t1 *= 2;
			if(t1 >= n)
			{
				answer = false;
				break;
			}
		}
	}
	bool step = true;
	bool a2;
	while(true)
	{
		if(step)
		{
			t2 *= 2;
			if(t2 >= n)
			{
				a2 = true;
				break;
			}
		}
		else
		{
			t2 *= 9;
			if(t2 >= n)
			{
				a2 = false;
				break;
			}
		}
	}*/
}

void WriteData()
{
	if(answer)
	{
		printf("1\n");
	}
	else
	{
		printf("2\n");
	}
}

void precalc()
{
	prec.clear();
	prec.push_back(make_pair(2, 9));
	prec.push_back(make_pair(10, 18));
	__int64 mul[2] = {2, 9};
	int idx = 1;
	while(prec[prec.size() - 1].second < 1000000000)
	{
		pair<__int64, __int64> prev = prec[prec.size() - 1];
		prec.push_back(make_pair(prev.second + 1, prev.second * mul[idx]));
		idx = (idx + 1) % 2;
	}
	//printf("QQ");
}

int main()
{
	precalc();
	/*if(!true)
	{
		freopen("GAME.IN", "w", stdout);
		printf("5000\n");
		
		for(int i = 0; i < 5000; i++)
		{
			printf("%d\n", i + 1);
		}
		return 0;
	}*/
	int QWE = 1;
	freopen("GAME.IN", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}