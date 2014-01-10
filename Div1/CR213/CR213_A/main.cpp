#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

char str[4009];
int n;
__int64 a;

void ReadData()
{
  scanf("%I64d%*c", &a);
  scanf("%s%*c", str);
  n = strlen(str);
}

__int64 answer;
int sums[4009];
int m[5009 * 9];

int getSum(int l, int r)
{
  return sums[r] - sums[l - 1];
}

void Solve()
{
  answer = 0;
  memset(sums, 0, sizeof(sums));
  for(int i = 0; i < n; i++)
  {
    sums[i + 1] = sums[i] + (int)(str[i] - '0');
  }
  map<int, int> m;
  map<int, int>::iterator it;
  for(int i = 0; i < n; i++)
  {
    for(int j = i; j < n; j++)
    {
      int val = getSum(i + 1, j + 1);
      it = m.find(val);
      if(it == m.end())
      {
        m.insert(make_pair(val, 1));
      }
      else
      {
        it->second++;
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = i; j < n; j++)
    {
      int val = getSum(i + 1, j + 1);
      if(val != 0 && a >= val && a % val == 0)
      {
        val = a / val;
        it = m.find(val);
        if(it != m.end())
        {
          answer += it->second;
        }
      }
      else if(val == 0 && a == 0)
      {
        //Число различных прямоугольников для столбца будет (1+n)*(n)/2
        //Но у нас есть ещё и строка. Поэтому, умножим на два и получим (1+n)*n
        //Но тогда мы дважды возьмём каждый ноль в матрице b. Вычтем их нахер.
        //Получаем формулу n * (n + 1) - m[0]
        answer += n * 1LL * (n + 1) - m[0];
      }
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n81\n");
    for(int i = 0; i < 4000; i++)
    {
      printf("9");
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