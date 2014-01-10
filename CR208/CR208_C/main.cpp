#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
//int a[100009];

void ReadData()
{
  scanf("%d", &n);
}

void Solve()
{
  int cnt = 0;
  int a[3];
  int b[3];
  memset(a, 0xFF, sizeof(a));
  memset(b, 0xFF, sizeof(b));
  bool cleared = false;
  for(int T = 0; T < n; T++)
  {
    int val;
    scanf("%d", &val);
    if(val == 0)
    {
      int current = 0;
      for(int i = 0; i < cnt; i++)
      {
        bool flag = true;
        for(int j = 0; j < 3; j++)
        {
          if(b[j] == i)
          {
            b[j] = -1;
            flag = false;
            break;
          }
        }
        if(flag)
        {
          printf("pushFront\n");
        }
        else
        {
          switch(current)
          {
            case 0: 
            {
              printf("pushStack\n");
              break;
            }
            case 1: 
            {
              printf("pushQueue\n");
              break;
            }
            case 2:
            {
              printf("pushBack\n");
              break;
            }
          }
          current++;
        }
      }
      int answer = std::min(3, cnt);
      //printf("%d ", answer);
      switch(answer)
      {
        case 0:
        {
          printf("0\n");
          break;
        }
        case 1:
        {
          printf("1 popStack\n");
          break;
        }
        case 2:
        {
          printf("2 popStack popQueue\n");
          break;
        }
        case 3:
        {
          printf("3 popStack popQueue popBack\n");
          break;
        }
      }
      memset(a, 0xFF, sizeof(a));
      memset(b, 0xFF, sizeof(b));
      cnt = 0;
      cleared = true;
      continue;
    }
    cleared = false;
    if(val > a[2])
    {
      a[0] = a[1];
      a[1] = a[2];
      b[0] = b[1];
      b[1] = b[2];
      a[2] = val;
      b[2] = cnt;
    }
    else if(val > a[1])
    {
      a[0] = a[1];
      b[0] = b[1];
      a[1] = val;
      b[1] = cnt;
    }
    else if(val > a[0])
    {
      a[0] = val;
      b[0] = cnt;
    }
    cnt++;
  }
  if(!cleared)
  {
    for(int i = 0; i < cnt; i++)
    {
      printf("pushFront\n");
    }
    /*int current = 0;
      for(int i = 0; i < cnt; i++)
      {
        bool flag = true;
        for(int j = 0; j < 3; j++)
        {
          if(b[j] == i)
          {
            b[j] = -1;
            flag = false;
            break;
          }
        }
        if(flag)
        {
          printf("pushFront\n");
        }
        else
        {
          switch(current)
          {
            case 0: 
            {
              printf("pushStack\n");
              break;
            }
            case 1: 
            {
              printf("pushQueue\n");
              break;
            }
            case 2:
            {
              printf("pushBack\n");
              break;
            }
          }
          current++;
        }
      } */
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
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