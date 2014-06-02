#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int r, c, m;

void ReadData()
{
  scanf("%d %d %d", &r, &c, &m);
  //printf("%d %d %d\n", r, c, m);
}

bool table[60][60];

void WriteData()
{
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      if((i == r - 1) && (j == c - 1))
      {
        printf("c");
      }
      else if(table[i][j])
      {
        printf("*");
      }
      else
      {
        printf(".");
      }
    }
    printf("\n");
  }
}

void Solve()
{
  int area = r * c;
  if(r == 1 && c == 1)
  {
    if(m != 0)
    {
      printf("Impossible\n");
    }
    else
    {
      printf("c\n");
    }
    return;
  }
  if(r == 1)
  {
    for(int i = 0; i < c; i++)
    {
      if(i == c - 1)
      {
        printf("c\n");
      }
      else if(m != 0)
      {
        printf("*");
        m--;
      }
      else
      {
        printf(".");
      }
    }
    return;
  }
  if(c == 1)
  {
    for(int i = 0; i < r; i++)
    {
      if(i == r - 1)
      {
        printf("c\n");
      }
      else if(m != 0)
      {
        printf("*\n");
        m--;
      }
      else
      {
        printf(".\n");
      }
    }
    return;
  }
  if(area - m == 1)
  {
    for(int i = 0; i < r; i++)
    {
      for(int j = 0; j < c; j++)
      {
        if((i == r - 1) && (j == c - 1))
        {
          printf("c");
        }
        else
        {
          printf("*");
        }
      }
      printf("\n");
    }
    return;
  }
  memset(table, 0, sizeof(table));
  int sr = r - 2, sc = c - 2;
  for(int i = 0; i < sr; i++)
  {
    if(m == 0)
    {
      break;
    }
    for(int j = 0; j < sc; j++)
    {
      if(m == 0)
      {
        break;
      }
      if((i == sr - 1) && (j == sc - 1))
      {
        if(m % 2 != 0)
        {
          m--;
          table[i][j] = true;
        }
      }
      else
      {
        table[i][j] = true;
        m--;
      }
    }
  }
  if(m % 2 != 0)
  {
    printf("Impossible\n");
    return;
    //throw;
  }
  for(int i = 0; i < sr - 1; i++)
  {
    if(m == 0)
    {
      break;
    }
    m -= 2;
    table[i][c - 1] = true;
    table[i][c - 2] = true;
  }
  for(int j = 0; j < sc - 1; j++)
  {
    if(m == 0)
    {
      break;
    }
    m -= 2;
    table[r - 1][j] = true;
    table[r - 2][j] = true;
  }
  if(sr + sc != 0 && m >= 2 && ((sr * sc == 0 && sr != 0) || table[sr - 1][sc - 1]))
  {
    table[sr - 1][c - 1] = true;
    table[sr - 1][c - 2] = true;
    m -= 2;
  }
  if(sr + sc != 0 && m >= 2 && ((sr * sc == 0 && sc != 0) || table[sr - 1][sc - 1]))
  {
    table[r - 1][sc - 1] = true;
    table[r - 2][sc - 1] = true;
    m -= 2;
  }
  if(m == 0)
  {
    WriteData();
  }
  else
  {
    printf("Impossible\n");
  }
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    //printf("1623076\n");
    for(int i = 6; i < 31; i++)
    {
      for(int j = 6; j < 31; j++)
      {
        int cnt = i * j;
        for(int k = 0; k < cnt; k++)
        {
          printf("%d %d %d\n", i, j, k);
        }
      }
    }
    return 0;
  }
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d:\n", T + 1);
    ReadData();
    Solve();
  }
  return 0;
}