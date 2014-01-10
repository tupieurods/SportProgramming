#include <stdio.h>
#include <math.h>

using namespace std;

__int64 n;
int answer;

void check(__int64 value)
{
  __int64 t = n / value;
  for(__int64 a = 1; a < value; a++)
  {
    __int64 b = value - a;
    if(b < a)//Отсекаем перестановки
      break;
    __int64 BminusA = b - a;
    __int64 D = BminusA * BminusA + 4 * t;
    if(D >= 0.0)
    {
      __int64 sqrtD = (__int64)sqrt((double)D);
      if(sqrtD * sqrtD != D)
        continue;
      __int64 x = (-BminusA + sqrtD) / 2;
      __int64 c = x - a;
      if(c >= b && x * x + BminusA * x - t == 0)
      {
        if(a != b && b != c)
        {
          answer += 6;
        }
        else if(a != b || b != c)
        {
          answer += 3;
        }
        else
        {
          answer++;
        }
      }
      if(D != 0)
      {
        x = (-BminusA - sqrtD) / 2;
        c = x - a;
        if(c >= b && x * x + BminusA * x - t == 0)
        {
          if(a != b && b != c)
          {
            answer += 6;
          }
          else if(a != b || b != c)
          {
            answer += 3;
          }
          else
          {
            answer++;
          }
        }
      }
    }
  }
}

int main()
{
  scanf("%I64d", &n);
  if(n % 3 != 0)
  {
    printf("0");
    return 0;
  }
  n /= 3LL;
  answer = 0;
  for(__int64 i = 1; i * i * i <= n; i++)
  {
    if(n % i == 0)
    {
      check(i);
    }
  }
  printf("%d\n", answer);
  return 0;
}
