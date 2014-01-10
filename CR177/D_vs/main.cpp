#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int n, k;
__int64 answer;
const __int64 mod = 1000000007;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

int* arr;
bool* s;
void CalcFirstPart(int current)
{
  if(current == k)//ѕровер€ем, будет ли така€ перестановка ответом
  {
    int counter = 0;
    for(int i = 0; i < k; i++)
    {
      memset(s, 0, sizeof(bool) * (k));
      int pos = i;
      //bool flag = false;
      while(true)
      {
        if(s[pos])
        {
          //flag = true;
          break;
        }
        //s.insert(pos);
        s[pos] = true;
        pos = arr[pos];
      }
      if(!s[0]/*s.find(1) == s.end()*/)
        break;
      counter++;
    }
    if(counter == k)
    {
      answer++;
      answer %= mod;
    }
    return;
  }
  for(int i = 0; i < k; i++)
  {
    arr[current] = i;
    CalcFirstPart(current + 1);
  }
}

void Solve()
{
  answer = 0;
  arr = new int[k];
  s = new bool[k];
  CalcFirstPart(0);
  //(n - k)^(n - k)
  __int64 cnt = n - k;
  for(int i = 0; i < cnt; i++)
  {
    answer *= (n - k);
    answer %= mod;
  }
}

void WriteData()
{
#ifndef ONLINE_JUDGE
  printf("%d: %I64d\n", k, answer);
#else
  printf("%I64d\n", answer);
#endif
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}