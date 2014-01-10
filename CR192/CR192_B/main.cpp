#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool matrix[1009][1009];
int enem[1009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(matrix, 0, sizeof(matrix));
  memset(enem, 0, sizeof(enem));
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    enem[from]++;
    enem[to]++;
    matrix[from][to] = true;
    matrix[to][from] = true;
  }
}

vector<pair<int, int>> answer;
int used[1000];

int bfs(int vertex)
{
  queue<int> Q;
  Q.push(vertex);
  memset(used, 0xFF, sizeof(used));
  used[vertex] = 0;
  int result = 0;

  while(!Q.empty())
  {
    int current = Q.front();
    Q.pop();

    for(int i = 0; i < n; i++)
    {
      if(used[i] == -1 && !matrix[current][i])
      {
        Q.push(i);
        used[i] = used[current] + 1;
        matrix[current][i] = true;
        matrix[i][current] = true;
        answer.push_back(make_pair(current, i));
        result = max(result, used[i]);
      }
    }
  }
  return result;
}

void Solve()
{
  answer.clear();
  int prev = -1;
  int check = 3;
  for(int i = 0; i < 2; i++)
  {
    int current = 0;
    for(int j = 1; j < n; j++)
    {
      if(enem[current] > enem[j] && j != prev)
      {
        current = j;
      }
    }
    check = bfs(current);
    if(check <= 2)
      break;
    prev = current;
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(int i = 0; i < answer.size(); i++)
  {
    printf("%d %d\n", answer[i].first + 1, answer[i].second + 1);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}