#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <deque>

using namespace std;

#define LOCALTEST

deque<int> number;
deque<__int64> powers;

void transfer(__int64 n, int k)
{
  number.clear();
  while(n != 0)
  {
    number.push_front(n % k);
    n /= k;
  }
}

__int64 getPower(__int64 k, int power)
{
  if(powers.size() == 0)
  {
    __int64 result = 1;
    powers.push_back(1);
    for(int i = 1; i <= power; ++i)
    {
      result *= k;
      powers.push_back(result);
    }
  }
  return powers[power];
}

int main()
{
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
#endif
  //freopen("output.txt", "w", stdout);
  int QWE;
#ifdef LOCALTEST
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    __int64 n;
    int k;
    cin >> n >> k;
    if(n < k)
    {
      cout << n + 1<< endl;
      continue;
    }
    transfer(n, k);
    if(number.size() % 2 == 0)
      number.push_front(0);
    __int64 sum = 0;
    unsigned int len = number.size();
    int power = len / 2;
    getPower(k, power);
    for(unsigned int i = 0; i < len; ++i)
    {
      if((i + 1) % 2 == 0)
      {
        if(number[i] != 0)
        {
          for(int j = i; j < len; ++j)
          {
            if((j + 1) % 2 == 0)
              number[j] = 0;
            else
              number[j] = k - 1;
          }
        }
        continue;
      }
      if(i == len - 1)
      {
        sum += number[i] + 1;
        continue;
      }
      sum += (__int64)number[i] * getPower(k, power);
      --power;
    }
    cout << sum << endl;
    powers.clear();
    /*cout << "transfered " << endl;
    for(int i = 0; i < number.size(); ++i)
      cout << number[i];
    cout << endl;*/
  }
  return 0;
}