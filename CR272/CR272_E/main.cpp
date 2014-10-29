#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[2009], p[509];
int ls, lp;

void ReadData()
{
  scanf("%s%*c", s);
  scanf("%s%*c", p);
  ls = strlen(s);
  lp = strlen(p);
}

int dp[2009][2009];
int a[2009];
//int level;

int f(int idx, int toDel)
{
  /*level++;
  for(int i = 0; i < level; i++)
  {
    printf("_");
  }
  printf("%d %d\n", idx, toDel);  */
  if(idx == ls)
  {
    //level--;
    return toDel == 0 ? 0 : INT_MIN;
  }
  if(dp[idx][toDel] != -1)
  {
    //level--;
    return dp[idx][toDel];
  }
  dp[idx][toDel] = INT_MIN;
  dp[idx][toDel] = max(dp[idx][toDel], f(idx + 1, toDel));
  //printf("%d %d: %d\n", idx, toDel, dp[idx][toDel]);
  if(toDel != 0)
  {
    dp[idx][toDel] = max(dp[idx][toDel], f(idx + 1, toDel - 1));
//    printf("%d %d: %d\n", idx, toDel, dp[idx][toDel]);
  }
  if(a[idx] != -1)
  {
    if(a[idx] - idx + 1 - lp <= toDel)
    {
      dp[idx][toDel] = max(dp[idx][toDel], f(a[idx] + 1, toDel - (a[idx] - idx + 1 - lp)) + 1);
      //printf("%d %d: %d\n", idx, toDel, dp[idx][toDel]);
    }
  }
  //printf("%d %d: %d\n", idx, toDel, dp[idx][toDel]);
  //level--;
  return dp[idx][toDel];
}

void Solve()
{
  //level = 0;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < ls; i++)
  {
    int ppos = 0;
    int lpos = i;
    while(lpos < ls && ppos < lp)
    {
      if(s[lpos] == p[ppos])
      {
        ppos++;
      }
      if(ppos == lp)
      {
        break;
      }
      lpos++;
    }
    if(ppos != lp)
    {
      a[i] = -1;
    }
    else
    {
      a[i] = lpos;
    }
  }
  /*printf("%d \n", f(2, 2));
  for(int i = 0; i <= ls; i++)
  {
    for(int j = 0; j <= ls; j++)
    {
      printf("%d\t", dp[i][j]);
    }
    printf("\n");
  }*/
  for(int i = 0; i <= ls; i++)
  {
    //printf("level %d:\n", i);
    printf("%d ", f(0, i));
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
  //freopen("out.txt", "w", stdout);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}