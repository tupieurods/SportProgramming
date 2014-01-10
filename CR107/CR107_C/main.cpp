#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

bool table[3200009];
vector<int> primes;

void calcTable()
{
  memset(table, true, sizeof(table));
  table[0] = false;
  table[1] = false;
  for(int i = 2; i < 3200009; i++)
  {
    if(table[i])
    {
      primes.push_back(i);
      if(i * 1LL * i <= 3200009)
      {
        for(int j = i * i; j < 3200009; j += i)
        {
          table[j] = false;
        }
      }
    }
  }
}

__int64 q;

void ReadData()
{
  scanf("%I64d", &q);
}

bool answer;
int a1, a2;

void Solve()
{
  __int64 copy = q;
  answer = false;
  int cnt = 0;
  a1 = -1, a2 = -1;
  for(vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
  {
    while(copy % *it == 0)
    {
      //printf("\t%d\n", *it);
      copy /= *it;
      cnt++;
      if(a1 == -1)
      {
        a1 = *it;
        continue;
      }
      if(a2 == -1)
      {
        a2 = *it;
      }
    }
  }
  if(copy != 1)
    cnt++;
  if(cnt == 0 || cnt == 1)
  {
    answer = true;
    a1 = 0;
    return;
  }
  if(cnt > 2)
  {
    answer = true;
  }
}

void WriteData()
{
  if(answer)
  {
    if(a1 == 0)
    {
      printf("1\n0\n");
    }
    else
    {
      printf("1\n%d\n", a1 * a2);
    }
  }
  else
  {
    printf("2\n");
  }
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  calcTable();
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}