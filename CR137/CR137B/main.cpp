#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int** table = new int*[n];
  int* colums = new int[m];
  for(int i = 0; i < n; i++)
    {
      table[i] = new int[m];
      for(int j = 0; j < m; j++)
        {
          if(i==0)
            colums[j] = j;
          scanf("%d ", &table[i][j]);
        }
    }
  for(int i = 0; i < k; i++)
    {
      char s;
      int x, y;
      scanf("%c %d %d", &s, &x, &y);
      getchar();
      //printf("-%c-",s);
      x--;
      y--;
      switch(s)
        {
          case 'c':
            {
              swap(colums[x], colums[y]);
            }
            break;
          case 'r':
            {
              swap(table[x], table[y]);
            }
            break;
          case 'g':
            {
              printf("%d ", table[x][colums[y]]);
            }
            break;
        }
    }
  return 0;
}
