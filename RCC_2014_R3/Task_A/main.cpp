#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int l[4];
void ReadData()
{
  for(int i = 0; i < 4; i++)
  {
    scanf("%d", &l[i]);
  }
}

int answer[3];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  for(int i = 0; i < 4; i++)
  {
    for(int j = i + 1; j < 4; j++)
    {
      for(int k = j + 1; k < 4; k++)
      {
        if((l[k] >= l[i] + l[j])
          || (l[i] >= l[k] + l[j])
          || (l[j] >= l[i] + l[k]))
        {
          continue;
        }
        int sum = l[i] + l[j] + l[k];
        int a = max(l[i], max(l[j], l[k]));
        sum -= a;
        int b = min(l[i], min(l[j], l[k]));
        int c = sum - b;
        if(b * b + c * c == a * a)
        {
          answer[0]++;
        }
        else if(b * b + c * c > a * a)
        {
          answer[1]++;
        }
        else
        {
          answer[2]++;
        }
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < 3; i++)
  {
    printf("%d ", answer[i]);
  }
  printf("\n");
}

//#define LOCAL

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}