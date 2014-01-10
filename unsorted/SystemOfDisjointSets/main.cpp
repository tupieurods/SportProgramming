#include <stdio.h>
#include <vector>
#include <set>
//Используется только для вывода

using namespace std;

struct setElem
{
  setElem* next;
  setElem* rep;
  int size;
  int num;
};

struct edge
{
  int u, v;
};

vector<setElem> sets;
vector<edge> edges;
int n;

void MakeSet(int n)
{
  setElem tmp = {NULL, NULL, 1, n};
  tmp.rep = &tmp;
  sets.push_back(tmp);
}

setElem FindSet(int x)
{
  setElem tmp = sets[x - 1];
  return *tmp.rep;
}

void Union(int x, int y)
{
  setElem first = FindSet(x);
  setElem second = FindSet(y);
  if(first.size < second.size)
  {
    swap(first, second);
  }
  setElem tmp = first;
  while(tmp.next != NULL)
  {
    tmp = *tmp.next;
  }
  tmp.next = &second;
  tmp = second;
  while(tmp.next != NULL)
  {
    tmp.rep = &first;
    tmp = *tmp.next;
  }
  first.size += second.size;
}

void ConnectedComponents()
{
  for(int i = 0; i < n; i++)
  {
    MakeSet(i);
  }
  for(vector<edge>::iterator i = edges.begin(); i != edges.end(); i++)
  {
    setElem first = FindSet(i->u);
    setElem second = FindSet(i->v);
    if(&first != &second)
      Union(i->u, i->v);
  }
}

void printSets()
{
  set< setElem* > differentSets;
  for(int i = 0; i < n; i++)
  {
    differentSets.insert(&sets[i]);
  }
  for(set< setElem* >::iterator i = differentSets.begin(); i != differentSets.end(); i++)
  {
    setElem* tmp = (*i)->rep;
    while(tmp != NULL)
    {
      printf("%d ", tmp->num);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    edge tmp = {from, to};
    edges.push_back(tmp);
  }
  ConnectedComponents();
  return 0;
}
