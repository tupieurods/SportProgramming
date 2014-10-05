#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

struct node
{
  map<char, int> edges;
  bool leaf;
};

int n, k;
int nodesCnt;
node nodes[100009];
bool win[100009], lose[100009];

void ReadData()
{
  scanf("%d %d%*c", &n, &k);
}

bool answer;

int nextNode()
{
  nodes[nodesCnt].edges.clear();
  nodes[nodesCnt].leaf = false;
  nodesCnt++;
  return nodesCnt - 1;
}

void add(char str[])
{
  map<char, int>::iterator it;
  int len = strlen(str);
  int nodeId = 0;
  for(int i = 0; i < len; i++)
  {
    it = nodes[nodeId].edges.find(str[i]);
    if(it != nodes[nodeId].edges.end())
    {
      nodeId = it->second;
    }
    else
    {
      int nextNodeId = nextNode();
      nodes[nodeId].edges.insert(make_pair(str[i], nextNodeId));
      nodeId = nextNodeId;
    }
  }
  nodes[nodeId].leaf = true;
}

void dfs(int nodeId)
{
  win[nodeId] = false;
  lose[nodeId] = nodes[nodeId].edges.empty();
  for(map<char, int>::iterator it = nodes[nodeId].edges.begin(); it != nodes[nodeId].edges.end(); ++it)
  {
    dfs(it->second);
    win[nodeId] |= !win[it->second];
    lose[nodeId] |= !lose[it->second];
  }
}

void Solve()
{
  char str[100009];
  nodesCnt = 0;
  nextNode();
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    add(str);
  }
  dfs(0);
  if(k == 1)
  {
    answer = win[0];
  }
  else if(!win[0])
  {
    answer = false;
  }
  else if(lose[0])
  {
    answer = true;
  }
  else
  {
    answer = (k % 2) == 1;
  }
}

void WriteData()
{
  if(answer)
  {
    printf("First\n");
  }
  else
  {
    printf("Second\n");
  }
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