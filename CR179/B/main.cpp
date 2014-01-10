#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int mod = 1000000007;

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  string s1, s2;
  int n;
  cin >> n;
  cin >> s1;
  cin >> s2;
  int *last1 = new int[n], *last2 = new int[n];
  memset(last1, 0, sizeof(int) * n);
  memset(last2, 0, sizeof(int) * n);
  int sum1 = 0, sum2 = 0;
  for(int i = n - 1; i >= 0; i--)
  {
    last1[i] = sum1;
    if(s1[i] == '?')
      sum1++;
    last2[i] = sum2;
    if(s2[i] == '?')
      sum2++;
  }
  __int64 answer = 0;
  int flag = 3;
  //0 - <
  //1 - >
  //2 - uncomparable
  //3 - undefined
  for(int i = 0; i < n; i++)
  {
    if(s1[i] == '?' || s2[i] == '?')
    {
      __int64 minimal;
      if(s1[i] == '?' && s2[i] == '?')
      {
        minimal = 55;//Если два вопроса, то больше 55и вариантов только
        //в случае 3, он отдельно обрабатывается
      }
      else 
      {
        //Рассчитать сколько возможных вариантов если не два ?
      }
      if(answer == 0)//не будем на ноль множить
        answer = 1;
      switch(flag)
      {
        case 0:
        case 1:
        {
          int cnt = last1[i] + last2[i];
          for(int j = 0; j < cnt; j++)
          {
            minimal *= 10;
            minimal %= mod;
          }
          answer *= minimal;
          answer %= mod;
          break;
        }
        case 2:
        {
          minimal = 1;
          int cnt = last1[i] + last2[i];
          if(s1[i] == '?')
            cnt++;
          if(s2[i] == '?')
            cnt++;
          for(int j = 0; j < cnt; j++)
          {
            minimal *= 10;
            minimal %= mod;
          }
          answer *= minimal;
          answer %= mod;
          break;
        }
        case 3:
        {
          minimal = 362880;
          int cnt = last1[i] + last2[i];
          for(int j = 0; j < cnt; j++)
          {
            minimal *= 10;
            minimal %= mod;
          }
          answer *= minimal;
          answer %= mod;
          answer *= 2;
          answer %= mod;
          break;
        }
      }
      continue;
    }
    if(flag == 3)
    {
      flag = s1[i] - '0' < s2[i] - '0' ? 0 : 1;
      continue;
    }
    else if(flag != 2)
    {
      int current = s1[i] - '0' < s2[i] - '0' ? 0 : 1;
      if(current != flag)
        flag = 2;
    }
  }
  if(answer == 0 && flag == 2)
    answer++;
  cout << answer << endl;
  return 0;
}
