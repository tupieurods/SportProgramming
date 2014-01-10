#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int a[100009], b[100009];

void ReadData()
{
  scanf("%d", &n);
  memset(a, 0xFF, sizeof(a));
  memset(b, 0xFF, sizeof(b));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
}

int answer;

void Solve()
{
  answer = 0;
  bool flag = false;
  for(int i = 0; i < n; i++)
  {
    if(a[i] == i)
    {
      answer++;
      continue;
    }
    if(flag == true)
    {
      continue;
    }
    if(a[a[i]] == i)
    {
      flag = true;
      answer += 2;
    }
  }
  if(answer != n && flag == false)
  {
    answer++;
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