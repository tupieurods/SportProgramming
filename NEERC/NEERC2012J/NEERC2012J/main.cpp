#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define LOCALTEST

int main()
{
  int QWE;
  #ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  #else
  freopen("jumping.in", "r", stdin);
  freopen("jumping.out", "w", stdout);
  #endif
  scanf("%d\n", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    int a, b, c;
    scanf("%d %d %d\n", &a, &b, &c);
    int n = a + b + c + 1;
    int* anwser = new int[n];
    memset(anwser, 0, sizeof(int) * n);
    int current = 0;
    int pos = 1;
    //Избавляемся от с
    int k = c / 3;
    int excess = c % 3;
    if(excess == 0)
    {
      for(int i = 0; i < k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      current++;
      anwser[pos++] = current;
      for(int i = 0; i < k; i++)
      {
        current -= 3;
        anwser[pos++] = current;
      }
      current++;
      anwser[pos++] = current;
      for(int i = 0; i < k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      a -= 2;
    }
    else if(excess == 1)
    {
      for(int i = 0; i <= k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      current -= 2;
      anwser[pos++] = current;
      for(int i = 0; i < k; i++)
      {
        current -= 3;
        anwser[pos++] = current;
      }
      current++;
      anwser[pos++] = current;
      for(int i = 0; i < k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      current += 2;
      anwser[pos++] = current;
      b -= 2;
      a--;
    }
    else//if(excess == 2)
    {
      for(int i = 0; i <= k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      current--;
      anwser[pos++] = current;
      for(int i = 0; i < k; i++)
      {
        current -= 3;
        anwser[pos++] = current;
      }
      current--;
      anwser[pos++] = current;
      for(int i = 0; i <= k; i++)
      {
        current += 3;
        anwser[pos++] = current;
      }
      a -= 2;
    }
    c = 0;
    //Добиваем ответ
    while(a != 1)
    {
      current++;
      anwser[pos++] = current;
      a--;
    }
    while(current + 2 < n)
    {
      current += 2;
      anwser[pos++] = current;
      b--;
    }
    if(current == (n - 1))
    {
      current--;
    }
    else
    {
      current++;
    }
    a--;
    anwser[pos++] = current;
    while(b != 0)
    {
      current -= 2;
      anwser[pos++] = current;
      b--;
    }
    //Выводим ответ
    for(int i = 0; i < n; i++)
    {
      printf("%d ", anwser[i]);
    }
    printf("\n");
  }
  return 0;
}