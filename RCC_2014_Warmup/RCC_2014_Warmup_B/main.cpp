#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int a[100009];

void ReadData()
{
  scanf("%d", &n);
}

bool answer;

void Solve()
{
  memset(a, 0xFF, sizeof(a));
  answer = true;
  for(int i = 0; i < n; i++)
  {
    int x_val, k_val;
    scanf("%d %d", &x_val, &k_val);
    if(x_val > a[k_val] && x_val - a[k_val] > 1)
    {
      answer = false;
      return;
    }
    a[k_val] = std::max(a[k_val], x_val);
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
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