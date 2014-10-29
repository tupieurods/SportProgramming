#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
//sharing submition
using namespace std;

struct node
{
  pair<int, int> maximal;
  node *l, *r;
};

int n, d;
int h[100009];
node *mainNode;
pair<int, int> lastNode = make_pair(-1, -1);

void ReadData()
{
  scanf("%d %d", &n, &d);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &h[i]);
  }
}

int answerID;
pair<int, int> answer[100009];

pair<int, int> getMax(node *p, __int64 tl, __int64 tr, __int64 l, __int64 r)
{
  if(l > r || p == NULL)
  {
    return lastNode;
  }
  if((tl == l && tr == r) || (p->l == NULL && p->r == NULL))
  {
    return p->maximal;
  }
  __int64 center = tl + (tr - tl) / 2LL;
  return max(getMax(p->l, tl, center, l, min(center, r)),
    getMax(p->r, center + 1, tr, max(center + 1, l), r));
}

pair<int, int> getBest(__int64 l, __int64 r)
{
  return getMax(mainNode, 1, 1100000000000000LL, l, r);
}

void upd(node *p, __int64 pos, __int64 l, __int64 r, int _f, int _s)
{
  if(l == r && l == pos)
  {
    p->maximal = make_pair(_f, _s);
    return;
  }
  __int64 center = l + (r - l) / 2LL;
  if(center >= pos)
  {
    if(p->l == NULL)
    {
      p->l = new node();
      p->l->maximal = lastNode;
      p->l->l = p->l->r = NULL;
    }
    upd(p->l, pos, l, center, _f, _s);
  }
  else
  {
    if(p->r == NULL)
    {
      p->r = new node();
      p->r->maximal = lastNode;
      p->r->l = p->r->r = NULL;
    }
    upd(p->r, pos, center + 1, r, _f, _s);
  }
  p->maximal = max(p->l != NULL ? p->l->maximal : lastNode, p->r != NULL ? p->r->maximal : lastNode);
}

void Solve()
{
  //No clear for mainNode, because i don't have big multitest
  mainNode = new node();
  mainNode->maximal = make_pair(-1 ,-1);
  mainNode->l = mainNode->r = NULL;
  memset(answer, 0xFF, sizeof(answer));
  answer[0] = make_pair(1, 0);
  upd(mainNode, h[0], 1, 1100000000000000LL, 1, 0);
  for(int i = 1; i < n; i++)
  {
    pair<int, int> l = getBest(1, h[i] - d);
    pair<int, int> r = getBest(h[i] + d, 1100000000000000LL);
    //printf("step %d. l.f:%d l.s:%d r.f:%d r.s:%d\n", i, l.first, l.second, r.first, r.second);
    if(l.first != -1)
    {
      answer[i].first = l.first + 1;
      answer[i].second = l.second;
    }
    if(r.first != -1 && r.first + 1 > answer[i].first)
    {
      answer[i].first = r.first + 1;
      answer[i].second = r.second;
    }
    if(answer[i].first == -1)
    {
      answer[i].first = 1;
      answer[i].second = i;
    }
    upd(mainNode, h[i], 1, 1100000000000000LL, answer[i].first, i);
  }
  answerID = 0;
  for(int i = 1; i < n; i++)
  {
    if(answer[i].first > answer[answerID].first)
    {
      answerID = i;
    }
  }
}

void show(int id)
{
  if(answer[id].second != id)
  {
    show(answer[id].second);
  }
  printf("%d ", id + 1);
}

void WriteData()
{
  printf("%d\n", answer[answerID].first);
  show(answerID);
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