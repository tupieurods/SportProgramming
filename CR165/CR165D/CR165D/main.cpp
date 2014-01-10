#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//#define LOCALTEST

using namespace std;

inline int max(int a, int b)
{
  return a > b ? a : b;
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
    int* data = new int[n];
    int* d = new int[n];
    for(int i = 0; i < n; i++)
    {
      double tmp;
      cin >> data[i] >> tmp;
      //scanf("%d %lf", &data[i], &tmp);
      d[i] = 0;
    }
    d[0] = 1;
    int anwser = d[0];
    for(int i = 1; i < n; i++)
    {
      int maximum = 0;
      for(int j = 0; j < i; j++)
      {
        if(data[i] >= data[j])
          maximum = max(maximum, d[j]);
      }
      d[i] = maximum + 1;
      anwser = max(anwser, maximum + 1);
    }
    printf("%d\n", n - anwser);
  }
  return 0;
}