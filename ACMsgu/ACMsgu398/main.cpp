#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string toStr(int value)
{
  ostringstream s;
  s << value;
  return s.str();
}

int* bfs(vector<int>* data, int number_of_vertex , int x)
{
  int* result = new int[number_of_vertex+1];
  queue<int> q;
  int* vertex_color = new int[number_of_vertex+1];
  memset(vertex_color, 0, (number_of_vertex + 1)*sizeof(int));
  memset(result, 0x7F7F7F, (number_of_vertex + 1)*sizeof(int));
  q.push(x);
  vertex_color[x] = 1;
  result[x] = 0;
  while(!q.empty())
  {
    int pos = q.front();
    q.pop();
    for(vector<int>::iterator i = data[pos].begin(); i != data[pos].end(); i++)
    {
      if(vertex_color[*i] == 0)
      {
        q.push(*i);
        result[*i] = result[pos] + 1;
        vertex_color[*i] = 1;
      }
    }
    vertex_color[pos] = 2;
  }
  return result;
}

int main()
{
  int n, x;
  scanf("%d %d", &n, &x);
  vector<int>* data = new vector<int>[n+1];
  for(int i = 1; i <= n; i++)
  {
    int d;
    scanf("%d", &d);
    int tmp;
    for(int j = 0; j < d; j++)
    {
      scanf("%d", &tmp);
      data[i].push_back(tmp);
    }
  }
  int* result = bfs(data, n, x);
  string outRes = "";
  int count = 0;
  for(int i = 1; i <= n; i++)
  {
    if(result[i] == 2)
    {
      count++;
      outRes += toStr(i) + " ";
    }
  }
  printf("%d\n", count);
  if(count != 0)
    printf("%s", outRes.c_str());
  return 0;
}
