#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct copyAction
{
  __int64 start, finish; //[start; finish)
  int len;

  copyAction(__int64 start, __int64 finish, int len): start(start), finish(finish), len(len)
  {
  }
};

map<__int64, int> newElems;
int m;
__int64 cnt;
int elems[100009];
vector<int> copyInd;
vector<copyAction> copyActions;

void ReadData()
{
  scanf("%d", &m);
  newElems.clear();
  cnt = 0;
  for(int i = 0; i < m; i++)
  {
    int type;
    scanf("%d", &type);
    if(type == 1)
    {
      int toAdd;
      scanf("%d", &toAdd);
      newElems.insert(make_pair(cnt, toAdd));
      if(cnt < 100000)
      {
        elems[cnt] = toAdd;
      }
      cnt++;
    }
    else if(type == 2)
    {
      int len, cntCopies;
      scanf("%d %d", &len, &cntCopies);
      __int64 newCnt = cnt + len * 1LL * cntCopies;
      if(newCnt > 100000)
      {
        copyActions.push_back(copyAction(cnt, newCnt, len));
      }
      int pos = 0;
      while(cnt < 100000 && cnt < newCnt)
      {
        elems[cnt] = elems[pos];
        pos = (pos + 1) % len;
        cnt++;
      }
      cnt = newCnt;
    }
  }
}

void Solve()
{
  int n;
  scanf("%d", &n);
  int copyActionsSize = copyActions.size();
  for(int i = 0; i < n; i++)
  {
    __int64 pos;
    scanf("%I64d", &pos);
    pos--;
    if(pos < 100000)
    {
      printf("%d ", elems[pos]);
    }
    else
    {
      if(newElems.find(pos) != newElems.end())
      {
        printf("%d ", newElems[pos]);
        continue;
      }
      int l = 0, r = copyActionsSize;
      int mid;
      while(l < r)
      {
        mid = (l + r) / 2;
        if(pos >= copyActions[mid].start && pos < copyActions[mid].finish)
        {
          break;
        }
        if(pos >= copyActions[mid].finish)
        {
          l = mid + 1;
        }
        else
        {
          r = mid;
        }
      }
      printf("%d ", elems[(pos - copyActions[mid].start) % copyActions[mid].len]);
    }
  }
}

void WriteData()
{
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