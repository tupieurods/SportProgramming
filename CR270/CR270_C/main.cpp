#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
char a[100009][59], b[100009][59];
int idx[100009];

void ReadData()
{
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s %s%*c", a[i], b[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &idx[i]);
    idx[i]--;
  }
}

bool answer;

void Solve()
{
  answer = true;
  int prev = strcmp(a[idx[n - 1]], b[idx[n - 1]]) < 0 ? 1 : 0;
  for(int i = n - 2; i >= 0; i--)
  {
    int cnt = 0;
    int compRes = strcmp(a[idx[i]], b[idx[i]]);
    int c1 = -1, c2 = -1;
    if(prev == 0)
    {
      c1 = strcmp(a[idx[i]], a[idx[i + 1]]);
      c2 = strcmp(b[idx[i]], a[idx[i + 1]]);
    }
    else
    {
      c1 = strcmp(a[idx[i]], b[idx[i + 1]]);
      c2 = strcmp(b[idx[i]], b[idx[i + 1]]);
    }
    if(c1 > 0 && c2 > 0)
    {
      answer = false;
      return;
    }
    if(c1 < 0 && c2 < 0)
    {
      prev = compRes < 0 ? 1 : 0;
    }
    else
    {
      prev = c1 < 0 ? 0 : 1;
    }
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
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}