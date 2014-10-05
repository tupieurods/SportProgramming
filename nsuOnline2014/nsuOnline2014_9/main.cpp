//Unsolved
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M, T, A, B;
bool light[109];
vector<pair<int, int>> edges[10009];
int edgesL[10009];

void ReadData()
{
  scanf("%d %d %d %d %d", &N, &M, &T, &A, &B);
  memset(light, false, sizeof(light));
  for(int i = 0; i < M; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    int k;
    scanf("%d", &k);
    bool add = true;
    int total = 0;
    for(int j = 0; j < k; j++)
    {
      int ll, tt;
      scanf("%d %d", &ll, &tt);
      total += ll;
      edges[i].push_back(make_pair(ll, tt));
      if(tt == 1 && ll > T)
      {
        add = false;
      }
    }
    
  }
}

//Должно и так зайти
int answer;

void Solve()
{
  
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  return 0;
}