#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int n, m;
bool sieve[35009];
vector<int> primes;

void ReadData()
{
	scanf("%d %d", &n, &m);
}

//c __int64 спокойней
__int64 gcd(__int64 a, __int64 b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool used_2[35009];
int nok[35009];
__int64 answer1, answer2;

void Solve()
{
	set<int> usedOver;
	vector<int>::iterator it;
	memset(used_2, 0, sizeof(used_2));
	memset(nok, 0xFF, sizeof(nok));
	answer2 = 1LL;
	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		if(i == 0)
		{
			answer1 = val;
		}
		else
		{
			answer1 = gcd(answer1, val);
		}
		for(it = primes.begin(); it != primes.end(); it++)
		{
			int counter = -1;
			if(val % *it == 0)
			{
				counter = 0;
				while(val % *it == 0)
				{
					val /= *it;
					counter++;
				}
			}
			if(counter != -1)
			{
				nok[*it] = max(nok[*it], counter);
				used_2[*it] = true;
			}
		}
		if(val != 1)
		{
			if(val >= 35009)
			{
				if(usedOver.find(val) == usedOver.end())
				{
					answer2 *= val;
					answer2 %= m;
					usedOver.insert(val);
				}
			}
			else
			{
				nok[val] = max(nok[val], 1);
				used_2[val] = true;
			}
		}
	}
}

void WriteData()
{
	for(int i = 2; i < 35009; i++)
	{
		if(used_2[i])
		{
			for(int j = 0; j < nok[i]; j++)
			{
				answer2 *= i;
				answer2 %= m;
			}
		}
	}
	printf("%I64d %I64d\n", answer1, answer2);
}

int main()
{
	memset(sieve, true, sizeof(sieve));
	sieve[0] = false;
	sieve[1] = false;
	for(int i = 2; i < 35009; i++)
	{
		if(sieve[i] && i * 1LL * i < 1000000000)
		{
			primes.push_back(i);
			for(int j = i * i; j < 35009; j += i)
			{
				sieve[j] = false;
			}
		}
	}
	/*for(int i = 2; i < 1009; i++)
	{
	if(sieve[i])
	{
	printf("%d ", i);
	}
	}
	return 0;*/
	int QWE = 1;
	freopen("NUMBERS.IN", "r", stdin);
	scanf("%d", &QWE);
	for(int T = 0; T < QWE; T++)
	{
		ReadData();
		Solve();
		WriteData();
	}
	return 0;
}