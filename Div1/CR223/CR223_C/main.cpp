#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct node
{
  int answer, outOpen, outClose;
};

int len, m;
char str[1000009];
node tree[(1 << 21) + 9];
node empty;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
  scanf("%d", &m);
}

node update(node &n1, node &n2)
{
  node result;
  int tmp = min(n1.outOpen, n2.outClose);
  result.answer = n1.answer + n2.answer + tmp;
  result.outOpen = n1.outOpen + n2.outOpen - tmp;
  result.outClose = n1.outClose + n2.outClose - tmp;
  return result;
}

void treeAdd(int l, int r, int pos, int ind)
{
  if(l == r)
  {
    if(l != pos)
    {
      throw;
    }
    tree[ind].answer = 0;
    tree[ind].outOpen = str[pos] == '(' ? 1 : 0;
    tree[ind].outClose = 1 - tree[ind].outOpen;
    return;
  }
  int mid = (l + r) / 2;
  if(pos <= mid)
  {
    treeAdd(l, mid, pos, ind * 2 + 1);
  }
  else
  {
    treeAdd(mid + 1, r, pos, ind * 2 + 2);
  }
  tree[ind] = update(tree[ind * 2 + 1], tree[ind * 2 + 2]);
}

node treeGet(int l, int r, int ql, int qr, int ind)
{
  if(l == ql && r == qr)
  {
    return tree[ind];
  }
  if(l > r || ql > qr)
  {
    return empty;
  }
  int mid = (l + r) / 2;
  return update(treeGet(l, mid, ql, min(qr, mid), ind * 2 + 1), 
    treeGet(mid + 1, r, max(ql, mid + 1), qr, ind * 2 + 2));
}

void Solve()
{
  memset(tree, 0, sizeof(tree));
  for(int i = 0; i < len; i++)
  {
    treeAdd(0, len - 1, i, 0);
  }
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", treeGet(0, len - 1, l - 1, r - 1, 0).answer * 2);
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  empty.answer = 0;
  empty.outOpen = 0;
  empty.outClose = 0;
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
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
