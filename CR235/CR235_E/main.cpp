#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
int l, r, p;

void ReadData()
{
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &l, &r, &p);
}

__int64 addWithModulo(__int64 v1, __int64 v2, __int64 modulo)
{
  __int64 result = (v1 + v2) % p;
  if(result < 0)
  {
    result += modulo;
  }
  return result;
}

__int64 answer;
int factors[10];

void Solve()
{
  answer = 0;
  if(l == 1)
  {
    answer = addWithModulo(answer, ((m * 2LL * n) % p + n + m) % p, p);
  }
  for(int dx = 1; dx <= n; dx++)
  {
    double nl_f = l * 1.0 * l - dx * 1.0 * dx;
    double nr_f = r * 1.0 * r - dx * 1.0 * dx;
    if(nr_f < 0)
    {
      break;
    }
    int nl = nl_f > 0.0 ? (int)ceil(sqrt(nl_f)) : 1;
    int nr = min((int)floor(sqrt(nr_f)), m);
    if(nl == 0)
    {
      nl = 1;
    }
    if(nl > nr) 
    {
      continue;
    }
    int factorsCnt = 0;
    int copy_dx = dx;
    for(int divider = 2; divider * divider <= dx; divider++)
    {
      if(dx % divider == 0)
      {
        while(dx % divider == 0)
        {
          dx /= divider;
        }
        factors[factorsCnt++] = divider;
      }
    }
    if(dx > 1)
    {
      factors[factorsCnt++] = dx;
    }
    dx = copy_dx;
    /*__int64 sum = 0;
    int counter = 0;
    for(int i = nl; i <= nr; i++)
    {
      for(int j = 0; j < factorsCnt; j++)
      {
        if(i % factors[j] == 0)
        {
          sum += i;
          sum %= p;
          counter++;
          break;
        }
      }
    }
    __int64 tmp = nr - nl + 1 - counter;*/
    __int64 badCounter = 0;
    __int64 badSum = 0;
    for(int mask = 1; mask < (1 << factorsCnt); mask++)
    {
      int copyMask = mask;
      int power = 1;
      __int64 mul = 1;
      int idx = 0;
      while(mask != 0)
      {
        if((mask & 1) != 0)
        {
          power++;
          mul *= factors[idx];
        }
        mask >>= 1;
        idx++;
      }
      __int64 currentBadCounter = nr / mul - (nl - 1) / mul;
      __int64 shitCorrecter = (nl - 1) / mul;
      __int64 firstBad = (mul * shitCorrecter) % p;
      while(firstBad < nl)
      {
        firstBad += mul;
      }
      //__int64 currentbadSum = ((firstBad * 1LL * currentBadCounter) % p + mul * 1LL * ((currentBadCounter - 1LL) * currentBadCounter) / 2LL) % p;
      __int64 currentBadSum = addWithModulo((firstBad * 1LL * currentBadCounter) % p, ((((mul * (currentBadCounter - 1)) * currentBadCounter)) / 2 ) %p, p);
      if(power % 2 == 0)
      {
        badCounter = addWithModulo(badCounter, currentBadCounter, p);
        badSum = addWithModulo(badSum, currentBadSum, p);
      }
      else
      {
        badCounter = addWithModulo(badCounter, -currentBadCounter, p);
        badSum = addWithModulo(badSum, -currentBadSum, p);
      }
      mask = copyMask;
    }
    __int64 goodCounter = nr - nl + 1 - badCounter;
    //__int64 goodSum = ((goodCounter * (m + 1) * 2LL) % p - (((nl + nr) * 1LL * (nr - nl + 1)) - badSum * 2LL)) % p;
    __int64 goodSum = addWithModulo((goodCounter * (m + 1) * 2LL) % p, -((((nl + nr) * 1LL * (nr - nl + 1)) % p - badSum * 2LL) % p), p);
    //answer = (answer + ((n - dx + 1) * goodSum) % p) % p;
    answer = addWithModulo(answer, ((n - dx + 1) * goodSum) % p, p);
  }
}

void WriteData()
{
  printf("%I64d\n\n", answer);
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
}