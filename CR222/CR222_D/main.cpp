#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, s;
pair<int, int> a[100009];
pair<int, pair<int, int>> st[100009];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &s);
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &st[i].first);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &st[i].second.first);
    st[i].second.second = i;
  }
}

bool answer;
int answerArr[100009];

bool check(int steps)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int studentID = n - 1;
  int taskID = m - 1;
  int cost = 0;
  while(taskID >= 0)
  {
    while(studentID >= 0 && st[studentID].first >= a[taskID].first)
    {
      pq.push(st[studentID].second);
      studentID--;
    }
    if(pq.size() == 0 || pq.top().first + cost > s)
    {
      return false;
    }
    pair<int, int> current = pq.top();
    pq.pop();
    cost += current.first;
    for(int i = 0; i < steps && taskID >= 0; i++)
    {
      answerArr[a[taskID].second] = current.second;
      taskID--;
    }
  }
  return true;
}

void Solve()
{
  answer = false;
  sort(a, a + m);
  sort(st, st + n);
  int l = 1, r = m;
  while(r - l > 5)
  {
    int mid = (l + r) / 2;
    if(check(mid))
    {
      r = mid;
    }
    else
    {
      l = mid;
    }
  }
  for(int mid = l; mid <= r; mid++)
  {
    if(check(mid))
    {
      answer = true;
      return;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < m; i++)
    {
      printf("%d ", answerArr[i] + 1);
    }
    printf("\n");
  }
  else
  {
    printf("NO\n");
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