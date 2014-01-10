#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int primes[100009];
  int cnt = 0;
  bool *table = new bool[1000005];
  memset(table, true, sizeof(bool) * 1000005);
  table[0] = table[1] = false;
  for(int i = 2; i <= 1000000; i++)
  {
    if(table[i])
    {
      primes[cnt] = i;
      cnt++;
      if((__int64)i * i <= 1000000)
      {
        for(int j = i * i; j <= 1000000; j += i)
        {
          table[j] = false;
        }
      }
    }
  }
  int n;
  scanf("%d", &n);
  int answer = 0;
  int answerA[10000];
  int answerB[10000];
  //for(int i = 0; i < cnt; i++)
  {
    /*if(primes[i] > n)
    {
      break;
    }*/
    for(int j = 0; j < cnt; j++)
    {
      if(primes[0] + primes[j] > n)
      {
        break;
      }
      if(table[primes[0] + primes[j]])
      {
        answerA[answer] = primes[0];
        answerB[answer] = primes[j];
        answer++;
      }
    }
  }
  printf("%d\n", answer);
  for(int i = 0; i < answer; i++)
  {
    printf("%d %d\n", answerA[i], answerB[i]);
  }
  return 0;
}