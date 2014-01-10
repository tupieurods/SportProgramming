#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

//#define LOCALTEST

using namespace std;

deque<pair<int, pair<double, double>>>* lists;
double** answer;
int** previous;
deque<int> cycle;

void FloydWarshall(int n, double z)
{
  answer = new double*[n];
  previous = new int*[n];
  for(int i = 0; i < n; i++)
  {
    answer[i] = new double[n];
    previous[i] = new int[n];
    memset(previous[i], 0xFF, sizeof(int) * n);
    for(int j = 0; j < n; j++)
    {
      answer[i][j] = 100000;
    }
    for(int j = 0; j < lists[i].size(); j++)
    {
      answer[i][lists[i][j].first] = -(lists[i][j].second.first - z * lists[i][j].second.second);
      previous[i][lists[i][j].first] = i;
    }
  }
  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(answer[i][k] + answer[k][j] < answer[i][j])
        {
          answer[i][j] = answer[i][k] + answer[k][j];
          previous[i][j] = previous[k][j];
        }
      }
    }
  }
  //Тестовый вывод:
  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%f ", answer[i][j]);
    }
    printf("\n");
  } */
  /*printf("diag start\n");
  for(int i = 0; i < n; i++)
  {
    printf("%f ", answer[i][i]);
  }
  printf("diag end\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%d ", previous[i][j] + 1);
    }
    printf("\n");
  }*/
}

void calcAnswer(int current, int finish, bool start)
{
  if(current != finish || start)
  {
    calcAnswer(previous[finish][current], finish, false);
  }
  cycle.push_back(current + 1);
  //printf("%d ", current + 1);
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    lists = new deque<pair<int, pair<double, double>>>[n];
    for(int i = 0; i < m; i++)
    {
      int from, to;
      double b, c;
      scanf("%d %d %lf %lf", &from, &to, &b, &c);
      lists[from - 1].push_back(make_pair(to - 1, make_pair(b, c)));
    }
    double zDown = 0;
    double zTop = 100000;
    double z;
    while(zTop - zDown > 0.00000000001)
    {
      //printf("%f %f\n", zDown, zTop);
      z = zDown + (zTop - zDown) / 2.0;
      FloydWarshall(n, z);
      bool flag = false;
      for(int i = 0; i < n; i++)
      {
        if(answer[i][i] <= 0.0)
          flag = true;
      }
      if(flag)
      {
        zDown = z;
      }
      else
      {
        zTop = z;
      }
    }
    //printf("%f\n", z);
    int c = -1;
    for(int i = 0; i < n; i++)
    {
      if((answer[i][i] <= 1e-5) && (answer[i][i] >= -1e-5))
      {
        c = i;
      }
    }
    if(c == -1)
    {
      printf("0");
      return 0;
    }
    calcAnswer(c, c, true);
    printf("%d\n", cycle.size() - 1);
    n = cycle.size() - 1;
    for(int i = 0; i < n; i++)
    {
      printf("%d ", cycle[i]);
    }
  }
  return 0;
}