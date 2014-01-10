#include <stdio.h>
#include <algorithm>
#include <set>

int answer, n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

void Solve()
{
  scanf("%d", &answer);
  for(int i = 1; i < k; i++)
  {
    int val;
    scanf("%d", &val);
    val -= n - answer;
    answer = val;
    if(answer <= 0)
    {
      answer = 0;
      break;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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