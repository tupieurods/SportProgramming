#include <stdio.h>

int n;
int arr[105];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int answer;

void Solve()
{
  answer = 0;
  //n^3, Сам дурак
  for(int l = 0; l < n; l++)
  {
    for(int r = l; r < n; r++)
    {
      int currentSum = 0;
      for(int i = 0; i < n; i++)
      {
        if(i < l || i > r)
        {
          currentSum += arr[i];
        }
        else
        {
          currentSum += 1 - arr[i];
        }
      }
      answer = max(answer, currentSum);
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