#include <stdio.h>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

struct planet
{
  //Список планет на которые можно переместиться
  vector< pair<int, int> > friends;
  int k;//Число
  int* tourists;
};

int n;
planet* planets;
int* distances;

bool compare(int a, int b)
{
  if(distances[a] == distances[b])
    return a < b;
  else
    return distances[a] < distances[b];
}

int getTimePenalty(int planetID, int x)
{
  if(planets[planetID].k == 0
      || planets[planetID].tourists[planets[planetID].k - 1] < x
      || planets[planetID].tourists[0] > x)
    return 0;
  int result = -1;
  for(int i = 0; i < planets[planetID].k; i++)
    if(planets[planetID].tourists[i] == x)
    {
      result = i;
      break;
    }
  if(result == -1)
    return 0;//Если в этот момент никто не приезжает

  for(int i = result + 1; i < planets[planetID].k; i++)
  {
    if(planets[planetID].tourists[i]
        != planets[planetID].tourists[i-1] + 1)
      return planets[planetID].tourists[i-1] + 1 - x;
  }
  return planets[planetID].tourists[planets[planetID].k - 1] + 1 - x;
}

int main()
{
  int m;
  scanf("%d %d", &n, &m);
  planets = new planet[n];
  for(int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    planets[a-1].friends.push_back(make_pair(b - 1, c));
    planets[b-1].friends.push_back(make_pair(a - 1, c));
  }

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &planets[i].k);
    if(planets[i].k == 0)
      continue;
    planets[i].tourists = new int[planets[i].k];
    for(int j = 0; j < planets[i].k; j++)
      scanf("%d", &planets[i].tourists[j]);
  }

  distances = new int[n];
  distances[0] = 0;
  for(int i = 1; i < n; i++)
    distances[i] = INT_MAX;

  set<int, bool(*)(int, int)> q(compare);
  for(int i = 0; i < n; i++)
    q.insert(i);

  while(!q.empty())
  {
    int minimal = *q.begin();
    if((minimal == n - 1) || (distances[minimal] == INT_MAX))
      break;
    q.erase(q.begin());
    vector<pair<int, int> >::iterator i = planets[minimal].friends.begin();
    int penalty=getTimePenalty(minimal, distances[minimal]);
    for(; i != planets[minimal].friends.end(); i++)
    {
      const pair<int, int>& tmp = *i;
      if(q.find(tmp.first) != q.end())//Если не обошли эту вершину
      {
        int len = distances[minimal] + tmp.second + penalty;
        if(distances[tmp.first] > len)
        {
          q.erase(q.find(tmp.first));
          distances[tmp.first] = len;
          q.insert(tmp.first);
        }
      }
    }
  }
  printf("%d", distances[n-1] == INT_MAX ? -1 : distances[n-1]);
  return 0;
}
