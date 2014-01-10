#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct order
{
  int day;
  int cost;
};

bool compare(order a, order b)
{
  if(a.day == b.day)
    return a.cost > b.cost;
  return a.day < b.day;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int QWE;
  scanf("%d\n", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    vector<order> data;
    int n;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
    {
      int lastDay, cost;
      scanf("%d %d\n", &lastDay, &cost);
      order tmp;
      tmp.day = lastDay;
      tmp.cost = cost;
      data.push_back(tmp);
    }
    sort(data.begin(), data.end(), compare);
    /*for(vector<order>::iterator i = data.begin(); i != data.end(); ++i)
    {
      printf("%d %d\n", i->day, i->cost);
    }*/
    int day = 1;
    int result = 0;
    for(vector<order>::iterator i = data.begin(); i != data.end(); ++i)
    {
      if(day > i->day)
        continue;
      result += i->cost;
      day++;
    }
    printf("%d\n", result);
  }
  return 0;
}
