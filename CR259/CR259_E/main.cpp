#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, root;
vector<int> v[100009];
bool odd[100009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 100009; i++)
  {
    v[i].clear();
  }
  #endif
  root = -1;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    odd[i] = val == 1;
    if(val == 1)
    {
      root = i;
    }
  }
}

vector<int> answer;
bool answerFound;
bool used[100009];

void pushToAnswer(int vertex)
{
  answer.push_back(vertex);
  odd[vertex] = !odd[vertex];
}

void dfs(int vertex, int parent)
{
  used[vertex] = true;
  pushToAnswer(vertex);

  for(vector<int>::iterator it = v[vertex].begin(); it != v[vertex].end(); ++it)
  {
    if(!used[*it])
    {
      dfs(*it, vertex);
      pushToAnswer(vertex);
    }
  }

  if(odd[vertex] && parent != -1)
  {
    pushToAnswer(parent);
    pushToAnswer(vertex);
  }
}

void Solve()
{
  answer.clear();
  answerFound = true;
  if(root == -1)
  {
    return;
  }
  memset(used, 0, sizeof(used));
  dfs(root, -1);
  for(int i = 0; i < n; i++)
  {
    if(used[i] == false && odd[i] == true)
    {
      answerFound = false;
      return;
    }
  }
}

void WriteData()
{
  if(answerFound == false)
  {
    printf("-1\n");
    return;
  }
  int start;
  if(answer.size() == 0)
  {
    printf("0\n");
    return;
  }
  else if(odd[root])
  {
    start = 1;
    printf("%d\n", answer.size() - 1);
  }
  else
  {
    start = 0;
    printf("%d\n", answer.size());
  }
  for(; start < answer.size(); start++)
  {
    printf("%d ", answer[start] + 1);
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