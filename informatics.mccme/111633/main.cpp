#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

//#define LOCAL

int n, k;
int v[100005][2];
int colors[100005];

void ReadData()
{
  scanf("%d", &n);
  memset(v, 0, sizeof(v));
  int round = 0;
  for(int i = 0; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    if(i == n / 2)
      round++;
    v[from][round] = to;
    v[to][round] = from;
  }
  scanf("%d", &k);
}

vector<int> answer;

void bfs(int vertex)
{
  queue<int> q;
  q.push(vertex);
  colors[vertex] = 0;

  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    if(colors[v[current][0]] == -1)
    {
      colors[v[current][0]] = (colors[current] + 1) % 2;
      q.push(v[current][0]);
    }
    if(colors[v[current][1]] == -1)
    {
      colors[v[current][1]] = (colors[current] + 1) % 2;
      q.push(v[current][1]);
    }
  }
}

void Solve()
{
  answer.clear();
  memset(colors, 0xFF, sizeof(colors));
  for(int i = 1; i <= n; i++)
  {
    if(colors[i] == -1)
      bfs(i);
    if(colors[i] == 0)
      answer.push_back(i);
  }
}

void WriteData()
{
  if(answer.size() < k)
  {
    printf("0\n");
    return;
  }
  for(int i = 0; i < k; i++)
  {
    printf("%d ", answer[i]);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("input.txt", "r", stdin);
#ifdef LOCAL
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}