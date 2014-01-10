#include <vector>
#include <stdio.h>
#include <queue>
#include <strings.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct edge
{
  //f=first; s=second;
  int f, s;
};

vector<int>* data;
edge* edges;
int n;

string toStr(int value)
{
  ostringstream s;
  s << value;
  return s.str();
}

int* bfs(int start)
{
  int* result = new int[n+1];
  int* color = new int[n+1];
  queue<int> q;
  q.push(start);
  memset(result, 0x7F, sizeof(int)*(n + 1));
  memset(color, 0, sizeof(int)*(n + 1));
  result[start] = 0;
  color[start] = 1;
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    for(vector<int>::iterator i = data[current].begin(); i != data[current].end(); i++ )
    {
      if(color[*i] == 0)
      {
        q.push(*i);
        color[*i] = 1;
        result[*i] = result[current] + 1;
      }
    }
    color[current] = 2;
  }
  return result;
}

int main()
{
  int m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  data = new vector<int>[n+1];
  edges = new edge[m+1];
  for(int i = 1; i <= m; i++)
  {
    int f, s;
    scanf("%d %d", &f, &s);
    edges[i] = {f, s};
    data[f].push_back(s);
    data[s].push_back(f);
  }
  int* result = bfs(s);
  printf("%d\n", result[t]);
  int* count = new int[result[t]];
  memset(count, 0, sizeof(int)*result[t]);
  string* outStr = new string[result[t]];
  for(int i = 1; i <= m; i++)
  {
    int current =0;
    if(result[edges[i].f] < result[t] && result[edges[i].s] < result[t]
        || (result[edges[i].f] == result[t] && result[edges[i].s] < result[t])
        || (result[edges[i].s] == result[t] && result[edges[i].f] < result[t]))
    {
      current=min(result[edges[i].f],result[edges[i].s]);
    }
    count[current]++;
    outStr[current] += toStr(i) + " ";
  }
  for(int i = 0; i < result[t]; i++)
  {
    printf("%d %s\n", count[i], outStr[i].c_str());
  }
  return 0;
}
