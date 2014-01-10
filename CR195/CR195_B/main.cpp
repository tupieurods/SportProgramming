#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int m, r;

void ReadData()
{
  scanf("%d %d", &m, &r);
}

double answer;

void Solve()
{
  double toAdd = sqrt(2.0) * r;
  answer = r * 2.0 * m;//’одим во все верхние
  answer += (m - 1) * 2.0 * (2.0 * r + toAdd);//—ходили в правую соседнюю
  //и в левую соседнюю, если можем
  double p = 2.0 * (r + toAdd);
  for(int i = 0; i < m; i++)
  {
    //printf("v: %d u: %d\n", i / m + 1, m + 1 + i % m);
    int left = i - 1;
    if(left > 0)
    {
      answer += p * left;
      answer += (r * 2.0 * left * (left - 1)) / 2.0;
    }
    int right = m - i - 2;
    if(right > 0)
    {
      answer += p * right;
      answer += (r * 2.0 * right * (right - 1)) / 2.0;
    }
  }
  answer /= m * 1.0 * m;
}

void WriteData()
{
  printf("%.10lf\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("10000\n");
    for(int i = 0; i < 1000; i++)
    {
      for(int j = 0; j < 10; j++)
      {
        printf("%d %d\n", i + 1, j + 1);
      }
    }
    return 0;
  }
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