#include <iostream>
#include <fstream>
#include <limits.h>
#include <math.h>

using namespace std;

int n, m;
int*** data;
int cube[7][4] = {
  {0, 0, 0, 0},
  {2, 3, 4, 5},
  {1, 3, 4, 6},
  {1, 2, 5, 6},
  {1, 2, 5, 6},
  {1, 3, 4, 6},
  {2, 3, 4, 5}
};

/*int f(int x, int y, int t)
{
  //Чтобы цикл не гонять
  if( (y == n - 1) && (x == m - 1))
    return data[y][x][0] * t;
  if(data[y][x][t] == INT_MIN)
  {
    int result = data[y][x][0] * t;
    int maximal = INT_MIN;
    for(int i = 0; i < 4; i++)
    {
      if(x < m - 1)
      {
        maximal = max(f(x + 1, y, cube[t][i]), maximal);
      }
      if(y < n - 1)
      {
        maximal = max(f(x, y + 1, cube[t][i]), maximal);
      }
    }
    if(maximal != INT_MIN)
      result += maximal;
    data[y][x][t] = result;
  }
  return data[y][x][t];
}*/

int main()
{
  fstream strm("input.txt");
  int QWE;
  strm >> QWE;
  for(int T = 0; T < QWE; T++)
  {
    strm >> n >> m;
    data = new int**[n];
    for(int i = 0; i < n; i++)
    {
      data[i] = new int*[m];
      for(int j = 0; j < m; j++)
      {
        data[i][j] = new int[7];
        strm >> data[i][j][0];
        for(int k = 1; k < 7; k++)
          data[i][j][k] = INT_MIN;
      }
    }

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        for(int k = 1; k < 7; k++)
        {
          if( (i == 0) && (j == 0))
          {
            data[i][j][k] = data[i][j][0] * k;
          }
          else
          {
            data[i][j][k] = data[i][j][0] * k;
            int maximal = INT_MIN;
            for(int p = 0; p < 4; p++)
            {
              if(i != 0)
              {
                maximal = max(data[i-1][j][cube[k][p]], maximal);
              }
              if(j != 0)
              {
                maximal =  max(data[i][j-1][cube[k][p]], maximal);
              }
            }
            if(maximal != INT_MIN)
              data[i][j][k] += maximal;
          }
        }
      }
    }

    int result = INT_MIN;

    for(int i = 1; i <= 6; i++)
      result = max(result, data[n-1][m-1][i]);

    cout << result << endl;

    /*for(int i = 1; i <= 6; i++)
      result = max(result, f(0, 0, i));

    cout << result << endl;*/

    delete data;
  }
  return 0;
}
