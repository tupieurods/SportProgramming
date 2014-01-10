#include <stdio.h>
#include <vector>
#include <limits.h>
#include <string.h>

using namespace std;

int n, d;
int station[105];
vector<pair<int, int> > v;

inline int abs(int val)
{
  return val < 0 ? -val : val;
}

int getDistance(int station1, int station2)
{
  return abs(v[station1 - 1].first - v[station2 - 1].first)
    + abs(v[station1 - 1].second - v[station2 - 1].second);
}

int deikstra()
{
  int lengths[105];
  bool used[105];
  memset(used, 0, sizeof(used));
  memset(lengths, 0xFF, sizeof(lengths));
  int current = 1;
  lengths[current] = 0;
  while(current != -1)
  {
    used[current] = true;
    for(int i = 1; i <= n; i++)
    {
      if(used[i])
        continue;
      int weight = d * getDistance(current, i) - station[current];
      if(lengths[i] == -1 || lengths[i] > weight + lengths[current])
        lengths[i] = weight + lengths[current];
    }
    current = -1;
    for(int i = 1; i <= n; i++)
    {
      if(lengths[i] == -1 || used[i])
        continue;
      if(current == -1 || lengths[i] < lengths[current])
        current = i;
    }
  }
  return lengths[n];
}

int main()
{
  scanf("%d %d", &n, &d);
  memset(station, 0, sizeof(station));
  for(int i = 0; i < n - 2; i++)
  {
    scanf("%d", &station[i + 2]);
  }
  for(int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    v.push_back(make_pair(x, y));
  }
  int answer = deikstra();
  printf("%d", answer);
  return 0;
}
