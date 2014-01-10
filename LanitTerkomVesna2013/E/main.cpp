#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int w, h, n;
vector<pair<int, int>> a[1000];
int answer[2005];
int heap[2005], heapPos[2005];
int heapSize;

bool comparer(pair<int, int> firstPair, pair<int, int> secondPair)
{
  if(firstPair.first == secondPair.first)
    return firstPair.second > secondPair.second;
  return firstPair.first < secondPair.first;
}

void ReadData()
{
  scanf("%d %d %d", &w, &h, &n);
  memset(answer, 0, sizeof(answer));
}

int dx;
void FindDx(int r, int dy)
{
  dx = (int)sqrt((double)r * r - dy * dy) + 1;
  while((dx * dx + dy * dy) >= (r * r))
    dx--;
}

void Heapify(int pos)
{
  int l = pos << 1;
  int r = (pos << 1) + 1;
  int largest = pos;
  if(l <= heapSize && heap[l] > heap[pos])
    largest = l;
  if(r <= heapSize && heap[r] > heap[largest])
    largest = r;
  if(largest != pos)
  {
    swap(heapPos[heap[pos]], heapPos[heap[largest]]);
    swap(heap[pos], heap[largest]);
    Heapify(largest);
  }
}

void HeapAdd(int val)
{
  heapSize++;
  int pos = heapSize;
  heapPos[val] = heapSize;
  while(pos > 1 && heap[pos >> 1] < val)
  {
    heap[pos] = heap[pos >> 1];
    heapPos[heap[pos >> 1]] = pos;
    pos >>= 1;
  }
  heap[pos] = val;
  heapPos[val] = pos;
}

void HeapDelete(int val)
{
  int deletePos = heapPos[val];
  if(deletePos == heapSize)
  {
    heapPos[val] = 0;//Позиция удаляемого неопределена
    heap[deletePos] = 0;//Элемент равен нулю
    heapSize--;
    return;
  }
  //Ставим последний элемент кучи на место удаляемого
  heap[deletePos] = heap[heapSize];
  //Позиция последнего элемента кучи теперь позиция удаляемого
  heapPos[heap[heapSize]] = deletePos;
  //Последний элемент кучи обращается в ноль
  heap[heapSize] = 0;
  //Позиция удаляемого неопределена
  heapPos[val] = 0;
  heapSize--;
  if(val > heap[deletePos])
  {
    Heapify(deletePos);
  }
  else
  {
    val = heap[deletePos];
    while(deletePos > 1 && heap[deletePos >> 1] < val)
    {
      heap[deletePos] = heap[deletePos >> 1];
      heapPos[heap[deletePos >> 1]] = deletePos;
      deletePos >>= 1;
    }
    heap[deletePos] = val;
    heapPos[val] = deletePos;
  }
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    int x0, y0, r;
    scanf("%d %d %d", &x0, &y0, &r);
    x0--;
    y0--;
    int from = y0 - (r - 1) > 0 ? y0 - (r - 1) : 0;
    int to = y0 + r - 1 < h ? y0 + r - 1 : h - 1;
    for(int y = from; y <= to; y++)
    {
      FindDx(r, abs(y - y0));
      int left = max(x0 - dx, 0),
          right = min(x0 + dx, w - 1);
      a[y].push_back(make_pair(left, i + 1));
      if(right != w - 1)
        a[y].push_back(make_pair(right + 1, -(i + 1)));
    }
  }
  set<int, greater<int>> v;
  for(int i = 0; i < h; i++)
  {
    sort(a[i].begin(), a[i].end(), comparer);
    int pos = 0;
    int color = 0;
    int right_bound;
    v.clear();
    /*heapSize = 0;
    memset(heap, 0, sizeof(heap));
    memset(heapPos, 0, sizeof(heapPos));*/
    printf("\n%d: ", i);
    for(int j = 0; j < w; j++)
    {
      right_bound = pos < a[i].size() ? a[i][pos].first : w;
      printf("%d ", right_bound);
      if(j < right_bound - 1)
      {
        answer[color] += right_bound - 1 - j;
        j = right_bound - 1;
      }
      while(pos < a[i].size() && a[i][pos].first == j)
      {
        int value = a[i][pos].second;
        /*if(value < 0)
          HeapDelete(-value);
        else
          HeapAdd(value);*/
        if(value < 0)
          v.erase(-value);
        else
          v.insert(value);
        pos++;
      }
      /*if(heapSize != 0)
        color = heap[1];
      else
        color = 0;
      answer[color]++;*/
      if(v.size() != 0)
        color = *v.begin();
      else
        color = 0;
      answer[color]++;
    }
  }
  printf("\n");
}

void WriteData()
{
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", answer[i]);
  }
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  heapSize = 0;
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}