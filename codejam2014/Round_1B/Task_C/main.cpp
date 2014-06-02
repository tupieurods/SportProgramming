#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, m;
int codes[59];
bool matrix[59][59];
int used[59];
int firstIdx;

void ReadData()
{
  scanf("%d %d", &n, &m);
  firstIdx = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &codes[i]);
    if(codes[i] < codes[firstIdx])
    {
      firstIdx = i;
    }
  }
  memset(matrix, 0, sizeof(matrix));
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    matrix[from][to] = true;
    matrix[to][from] = true;
  }
}

int answer[59];

void insertClosest(set<int> &s, int idx)
{
  for(int i = 0; i < n; i++)
  {
    if(i != idx && matrix[idx][i] && used[i] == -1)
    {
      s.insert(codes[i] * 100 + i);
    }
  }
}

int dfsUsed[59], dfsCnt;
vector<int> st;

void dfsVisit(int currentV)
{
  if(dfsUsed[currentV] == dfsCnt)
  {
    throw;
  }
  dfsUsed[currentV] = dfsCnt;
  for(int i = 0; i < n; i++)
  {
    if(i != currentV && matrix[currentV][i] && used[i] == -1 && dfsUsed[i] != dfsCnt)
    {
      dfsVisit(i);
    }
  }
}

bool check(int maxPos)
{
  int prev = dfsCnt;
  for(int i = 0; i <= maxPos; i++)
  {
    dfsCnt++;
    dfsVisit(st[i]);
  }
  for(int i = 0; i < n; i++)
  {
    if(dfsUsed[i] <= prev && used[i] == -1)
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  dfsCnt = 0;
  memset(dfsUsed, 0, sizeof(dfsUsed));
  memset(answer, 0, sizeof(answer));
  memset(used, 0xFF, sizeof(used));
  used[firstIdx] = 0;
  answer[0] = codes[firstIdx] * 100 + firstIdx;
  set<int> s;
  insertClosest(s, firstIdx);
  int current = 0;
  st.clear();
  st.push_back(firstIdx);
  while(!s.empty())
  {
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
      bool flag = false;
      for(int i = st.size() - 1; i >= 0; i--)
      {
        if(matrix[st[i]][*it % 100])
        {
          if(check(i))
          {
            for(int j = st.size() - 1; j > i; j--)
            {
              st.pop_back();
            }
            current++;
            answer[current] = *it;
            used[*it % 100] = current;
            insertClosest(s, *it % 100);
            flag = true;
            break;
          }
        }
      }
      if(flag)
      {
        st.push_back(*it % 100);
        s.erase(it);
        break;
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d", answer[i] / 100);
  }
  printf("\n");
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}