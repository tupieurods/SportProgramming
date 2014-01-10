#include <stdio.h>

using namespace std;

int main()
{
  int n;
  __int64 modul = 1000000007LL;
  scanf("%d", &n);
  if(n == 1 || n == 2)
  {
    printf("0");
    return 0;
  }
  __int64 answer = 1;
  int countTwo = n - 2;
  for(int T = 0; T < 2; T++)
  {
    for(int i = 2; i <= n; i++)
    {
      __int64 current = i;
      /*while((countTwo > 0) && (current % 2 == 0))
      {
        current /= 2;
        countTwo--;
      }*/
      answer *= current % modul;
      answer %= modul;
    }
  }
  while((countTwo > 0))
  {
    answer /= 2;
    answer %= modul;
    countTwo--;
  }
  printf("%I64d", answer);
  /*int** matrix = new int*[n];
  for(int i = 0; i < n; i++)
  {
    matrix[i] = new int[n];
    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = ((i + j) % n) + 1;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }*/
  return 0;
}
