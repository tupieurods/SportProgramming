#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#pragma warning(disable: 4996)

int n;
__int64 v;

void ReadData()
{
  scanf("%d %I64d", &n, &v);
}

std::vector<int> answer;

void Solve()
{
  answer.clear();
  for(int i = 0; i < n; i++)
  {
    int k;
    scanf("%d", &k);
    bool flag = false;
    for(int j = 0; j < k; j++)
    {
      __int64 val;
      scanf("%I64d", &val);
      if(val < v)
      {
        flag = true;
      }
    }
    if(flag)
    {
      answer.push_back(i + 1);
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(std::vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
  {
    printf("%d ", *it);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}