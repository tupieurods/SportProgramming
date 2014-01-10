#include <stdio.h>
#include <stdlib.h>

int n;
int a[200009], b[200009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    b[val] = i;
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n - 1; i++)
  {
    if(b[a[i]] > b[a[i + 1]])
    {
      answer = n - i - 1;
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