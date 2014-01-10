#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#pragma comment(linker, "/STACK:1000000")

struct node
{
  int k, a, index;
};

struct ansStruct
{
  int parent, left, right;
};

int n;
node *inputData;
ansStruct answer[50005];

void ReadData()
{
  scanf("%d", &n);
  inputData = new node[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &inputData[i].k, &inputData[i].a);
    inputData[i].index = i + 1;
    answer[i].parent = 0;
    answer[i].left = 0;
    answer[i].right = 0;
  }
}

int compare(const void *val1, const void *val2)
{
  node *v1 = (node*)val1;
  node *v2 = (node*)val2;
  return (v1->k - v2->k);
}

int **ST;

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

void CalcRMQArray()
{
  ST = new int*[n];
  for(int i = 0; i < n; i++)
  {
    ST[i] = new int[16];
    ST[i][0] = i;
  }
  for(int j = 1; 1 << j <= n; j++)
  {
    for(int i = 0; i + (1 << j) - 1 < n; i++)
    {
      int index = i + (1 << (j - 1));
      if(inputData[ST[i][j - 1]].a < inputData[ST[index][j - 1]].a)
        ST[i][j] = ST[i][j - 1];
      else
        ST[i][j] = ST[index][j - 1];
    }
  }
}

int findMinAIndex(int l, int r)
{
  int result = l;
  for(int i = l + 1; i <= r; i++)
  {
    if(inputData[i].a < inputData[result].a)
      result = i;
  }
  return result;
}

int getLog2(int val)
{
  if(val < 2)
    return 0;
  if(val < 4)
    return 1;
  if(val < 8)
    return 2;
  if(val < 16)
    return 3;
  if(val < 32)
    return 4;
  if(val < 64)
    return 5;
  if(val < 128)
    return 6;
  if(val < 256)
    return 7;
  if(val < 512)
    return 8;
  if(val < 1024)
    return 9;
  if(val < 2048)
    return 10;
  if(val < 4096)
    return 11;
  if(val < 8192)
    return 12;
  if(val < 16384)
    return 13;
  if(val < 32768)
    return 14;
  if(val < 65536)
    return 15;
}

int findMinAIndex2(int l, int r)
{
  int k = getLog2(r - l + 1);
  if(inputData[ST[l][k]].a < inputData[ST[r + 1 - (1 << k)][k]].a)
    return ST[l][k];
  else
    return ST[r + 1 - (1 << k)][k];
}

void f(int l, int r, int parent, bool left)
{
  if(l > r)
    return;
  int minimalInd = findMinAIndex2(l, r);
  if(parent != 0)
  {
    answer[inputData[minimalInd].index - 1].parent = parent;
    if(left)
      answer[parent - 1].left = inputData[minimalInd].index;
    else
      answer[parent - 1].right = inputData[minimalInd].index;
  }
  f(l, minimalInd - 1, inputData[minimalInd].index, true);
  f(minimalInd + 1, r, inputData[minimalInd].index, false);
}

void Solve()
{
  qsort(inputData, n, sizeof(node), compare);
  CalcRMQArray();
  f(0, n - 1, 0, true);
}

void WriteData()
{
  printf("YES\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d %d %d\n", answer[i].parent, answer[i].left, answer[i].right);
  }
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  //cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}