#include <stdio.h>
#include <stdlib.h>

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  //freopen("B-small-attempt0.out", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    int **a = new int*[n];
    int** fails = new int*[n];
    for(int i = 0; i < n; i++)
    {
      a[i] = new int[m];
      fails[i] = new int[m];
      for(int j = 0; j < m; j++)
      {
        scanf("%d", &a[i][j]);
        fails[i][j] = 0;
      }
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(!((a[i][j] < a[i][0] && a[i][0] == a[i][m - 1])
            || (a[i][j] < a[0][j] && a[i][0] == a[n - 1][j])))
          fails[i][j]++;
      }
    }
    /*for(int j = 0; j < m; j++)
    {
      for(int i = 0; i < n; i++)
      {
        if(a[i][j] < a[0][j])
          fails[i][j]++;
      }
    }*/
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(fails[i][j] > 0)
          flag = false;
        printf("%d ", fails[i][j]);
      }
      printf("\n");
    }
    if(flag)
      printf("Case #%d: YES\n", T + 1);
    else
      printf("Case #%d: NO\n", T + 1);
  }
  return 0;
}