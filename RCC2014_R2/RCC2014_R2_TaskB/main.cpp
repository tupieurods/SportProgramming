#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int n, m, k;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
}

bool field[15][15];
pair<int, int> p1, p2, p3;

//set<int> s;

bool check()
{
  int result = 0;
  memset(field, 0, sizeof(field));
  field[p1.second][p1.first] = true;
  field[p2.second][p2.first] = true;
  field[p3.second][p3.first] = true;
  for(int i = 1; i <= n; i++)
  {
    if(field[p1.second][i] == false)
    {
      field[p1.second][i] = true;
      result++;
    }
    if(field[p2.second][i] == false)
    {
      field[p2.second][i] = true;
      result++;
    }
    if(field[p3.second][i] == false)
    {
      field[p3.second][i] = true;
      result++;
    }
  }
  for(int i = 1; i <= m; i++)
  {
    if(field[i][p1.first] == false)
    {
      field[i][p1.first] = true;
      result++;
    }
    if(field[i][p2.first] == false)
    {
      field[i][p2.first] = true;
      result++;
    }
    if(field[i][p3.first] == false)
    {
      field[i][p3.first] = true;
      result++;
    }
  }
  /*if(s.find(result) == s.end())
  {
    printf("%d: %d %d %d %d %d %d\n", result, p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
    s.insert(result);
  } */
  return result == k;
}

void solveEasy()
{
  for(int x1 = 1; x1 <= n; x1++)
  {
    for(int x2 = 1; x2 <= n; x2++)
    {
      for(int x3 = 1; x3 <= n; x3++)
      {
        for(int y1 = 1; y1 <= m; y1++)
        {
          for(int y2 = 1; y2 <= m; y2++)
          {
            for(int y3 = 1; y3 <= m; y3++)
            {
              p1 = make_pair(x1, y1);
              p2 = make_pair(x2, y2);
              p3 = make_pair(x3, y3);
              if(p1 != p2 && p2 != p3 && p1 != p3)
              {
                if(check())
                {
                  printf("%d %d %d %d %d %d\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
  printf("IMPOSSIBLE\n");
}

void Solve()
{
  if(n <= 4 && m <= 4)
  {
    solveEasy();
    return;
  }
  if(n >= 3 && m >= 3)
  {
    __int64 counter = 0;
    for(int i = 1; i <= 3; i++)
    {
      counter += m - i;
    }
    for(int i = 1; i <= 3; i++)
    {
      counter += n - i;
    }
    if(counter == k)
    {
      printf("1 1 2 2 3 3\n");
      return;
    }
    counter = (n - 4 + m) * 2LL + 1;
    if(counter == k)
    {
      printf("1 1 1 2 2 1\n");
      return;
    }
    counter = m - 3 + (n - 1) * 3LL;
    if(counter == k)
    {
      printf("1 1 1 2 1 3\n");
      return;
    }
    counter = 3LL * (n - 1) + 2LL * (m - 3);
    if(counter == k)
    {
      printf("1 1 1 2 2 3\n");
      return;
    }
    counter = 3LL * (m - 1) + 2LL * (n - 3);
    if(counter == k)
    {
      printf("1 1 2 1 3 2\n");
      return;
    }
    counter = 3LL * (m - 1) + (n - 3);
    if(counter == k)
    {
      printf("1 1 2 1 3 1\n");
      return;
    }
    printf("IMPOSSIBLE\n");
    return;
  }
  if(n < 3)
  {
    if(n == 1)
    {
      if(k == m - 3)
      {
        printf("1 1 1 2 1 3\n");
        return;
      }
    }
    else//n == 2
    {
      if(k == m)
      {
        printf("1 1 1 2 1 3\n");
        return;
      }
      else if(k == (m - 2) + (m - 1))
      {
        printf("1 1 1 2 2 1\n");
        return;
      }
    }
    printf("IMPOSSIBLE\n");
    return;
  }
  if(m < 3)
  {
    if(m == 1)
    {
      if(k == n - 3)
      {
        printf("1 1 2 1 3 1\n");
        return;
      }
    }
    else//m == 2
    {
      if(k == n)
      {
        printf("1 1 2 1 3 1\n");
        return;
      }
      else if(k == (n - 2) + (n - 1))
      {
        printf("1 1 1 2 2 1\n");
        return;
      }
    }
    printf("IMPOSSIBLE\n");
    return;
  }
}

void WriteData()
{
}

//#define LOCAL

int main()
{
  /*n = 5;
  m = 7;
  solveEasy();
  return 0;*/
  int QWE = 1;
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    //WriteData();
  }
  return 0;
}