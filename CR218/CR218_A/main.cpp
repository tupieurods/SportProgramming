#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k, a[109];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < k; i++)
  {
    int index = i;
    int one = 0, two = 0;
    while(index < n)
    {
      if(a[index] == 1)
      {
        one++;
      }
      else
      {
        two++;
      }
      index += k;
    }
    answer += std::min(one, two);
  }
}

void WriteData()
{
  printf("%d\n", answer);
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