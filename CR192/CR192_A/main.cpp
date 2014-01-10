#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int r, c;
    scanf("%d %d", &r, &c);
    int matrix[10][10];
    bool a[10], b[10];
    memset(matrix, 0, sizeof(matrix));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    char str[15];
    for(int i = 0; i < r; i++)
    {
      scanf("%s%*c", str);
      for(int j = 0; j < c; j++)
      {
        if(str[j] == 'S')
        {
          a[i] = true;
          b[j] = true;
          matrix[i][j] = 1;
        }
      }
    }
    int answer = 0;
    for(int i = 0; i < c; i++)
    {
      if(b[i] == false)
      {
        answer += r;
        for(int j = 0; j < r; j++)
        {
          matrix[j][i] = 2;
        }
      }
    }
    for(int i = 0; i < r; i++)
    {
      if(a[i] == false)
      {
        for(int j = 0; j < c; j++)
        {
          if(matrix[i][j] != 2)
            answer++;
          matrix[i][j] = 2;
        }
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}