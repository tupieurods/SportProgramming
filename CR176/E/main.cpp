#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int n, t;
int *p, /**q,*/ *y;
stack<int> st;
set<int> s;

void ReadData()
{
  scanf("%d", &n);
  p = new int[n];
  y = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &p[n - i - 1]);
  }
  scanf("%d", &t);
  //q = new int[t];
  s.clear();
  for(int i = 0; i < t; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    s.insert(n - tmp + 1);
    //q[i] = n - q[i] + 1;
  }
  //sort(q, q + t);
}

void Solve()
{
  st = stack<int>();
  for(int i = 0; i < n; i++)
  {
    if(st.empty() || st.top() != p[i])
    {
      st.push(p[i]);
      y[i] = p[i];
      continue;
    }
    if(s.find(i + 1) != s.end())
    {
      st.push(p[i]);
      y[i] = p[i];
    }
    else
    {
      y[i] = -st.top();
      st.pop();
    }
  }
}

void WriteData()
{
  if(!st.empty())
  {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for(int i = n - 1; i >= 0; i--)
  {
    printf("%d ", -y[i]);
  }
  printf("\n");
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
