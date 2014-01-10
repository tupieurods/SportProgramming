#include <stdio.h>
#include <string.h>

int numbers[10];
int n, sum;

void ReadData()
{
  scanf("%d", &n);
  memset(numbers, 0, sizeof(numbers));
  sum = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    numbers[val]++;
    sum += val;
  }
}

bool flag = false;
void Solve()
{
  switch(sum % 3)
  {
  case 1:
    //Пробуем удалить одну цифру
    for(int i = 1; i < 10; i++)
    {
      if(i % 3 == 1)
      {
        if(numbers[i] != 0)
        {
          numbers[i]--;
          flag = true;
          break;
        }
      }
    }
    //Пробуем удалить две цифры
    if(!flag)
    {
      int cnt = 2;
      for(int i = 1; i < 10; i++)
      {
        if(cnt == 0)
        {
          flag = true;
          break;
        }
        if(i % 3 == 2)
        {
          if(numbers[i] >= 2)
          {
            numbers[i] -= cnt;
            cnt = 0;
          }
          else if(numbers[i] == 1)
          {
            numbers[i]--;
            cnt--;
          }
        }
      }
    }
    break;
  case 2:
    //Пробуем удалить одну цифру
    for(int i = 1; i < 10; i++)
    {
      if(i % 3 == 2)
      {
        if(numbers[i] != 0)
        {
          numbers[i]--;
          flag = true;
          break;
        }
      }
    }
    //Пробуем удалить две цифры
    if(!flag)
    {
      int cnt = 2;
      for(int i = 1; i < 10; i++)
      {
        if(cnt == 0)
        {
          flag = true;
          break;
        }
        if(i % 3 == 1)
        {
          if(numbers[i] >= 2)
          {
            numbers[i] -= cnt;
            cnt = 0;
          }
          else if(numbers[i] == 1)
          {
            numbers[i]--;
            cnt--;
          }
        }
      }
    }
    break;
  default:
    flag = true;
    break;
  }
}

void WriteData()
{
  if(numbers[0] == 0)
  {
    printf("-1\n");
    return;
  }
  if(!flag)
  {
    printf("0\n");
    return;
  }
  int printed = 0;
  for(int i = 9; i >= 0; i--)
  {
    if(i == 0 && printed == 0)
    {
      printf("0\n");
      return;
    }
    for(int j = 0; j < numbers[i]; j++)
    {
      printed++;
      printf("%d", i);
    }
  }
  printf("\n");
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
  return 0;
}