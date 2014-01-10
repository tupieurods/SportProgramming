#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>;

using namespace std;

int n, m, k;
bool rotated;

struct point2i
{
  int x, y;

  int goodness()
  {
    return rotated ? x * 65536 + y : y * 65536 + x;
  }
};

template <bool direction>
class FindNext
{
  private:
    int _arr[2009];
  public:
    FindNext();
    int NextFree( int column);
    void Mark(int column);
    void Reset();
};

template <bool direction>
FindNext<direction>::FindNext()
{
}

template <bool direction>
void FindNext<direction>::Reset()
{
  for(int i = 0; i < 2009; i++)
  {
    _arr[i] = i;
  }
}

template <bool direction>
int FindNext<direction>::NextFree(int column)
{
  int result = column;
  while(result != -1 && _arr[result] != result)
  {
    result = _arr[result];
  }
  while(column != result)
  {
    int copy = _arr[column];
    _arr[column] = result;
    column = copy;
  }
  return result;
}

template <bool direction>
void FindNext<direction>::Mark(int column)
{
  if((direction && column == m) || (!direction && column == 1))
  {
    _arr[column] = -1;
  }
  else if(_arr[column] == column)
  {
    _arr[column] += direction ? 1 : -1;
  } 
}

FindNext<true> Right[2009];
FindNext<false> Left[2009];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  rotated = false;
  if(n > m)
  {
    swap(n, m);
    rotated = true;
  }
}

void Init()
{
  for(int i = 0; i < 2009; i++)
  {
    Right[i].Reset();
    Left[i].Reset();
  }
}

void SolveRotated();

void Solve()
{
  Init();
  for(int T = 0; T < k; T++)
  {
    point2i p;
    scanf("%d %d", &p.y, &p.x);
    if(rotated)
    {
      swap(p.x, p.y);
    }
    int bestResult = 5000;
    point2i answer, currentAnswer;
    answer.x = 3000;
    answer.y = 3000;
    for(int dy = 0; dy <= bestResult; dy++)
    {
      int left = -1, right = -1,
        dleft = 5000, dright = 5000,
        currentBestResult = 5000;
      currentAnswer.y = 3000;
      currentAnswer.x = 3000;
      if(p.y - dy >= 1)
      {
        left = Left[p.y - dy].NextFree(p.x);
        right = Right[p.y - dy].NextFree(p.x);
        if(left != -1)
        {
          dleft = p.x - left;
        }
        if(right != -1)
        {
          dright = right - p.x;
        }
        int r = dy + min(dleft, dright);
        point2i toCheck;
        toCheck.x = dleft <= dright ? left : right;
        toCheck.y = p.y - dy;
        if((r < currentBestResult) 
          || (r == currentBestResult 
              && toCheck.goodness() < currentAnswer.goodness()))
        {
          currentAnswer = toCheck;
          currentBestResult = r;
        }
      }
      if(p.y + dy <= n)
      {
        left = Left[p.y + dy].NextFree(p.x);
        right = Right[p.y + dy].NextFree(p.x);
        dleft = 5000;
        dright = 5000;
        if(left != -1)
        {
          dleft = p.x - left;
        }
        if(right != -1)
        {
          dright = right - p.x;
        }
        int r = dy + min(dleft, dright);
        point2i toCheck;
        toCheck.x = dleft <= dright ? left : right;
        toCheck.y = p.y + dy;
        if((r < currentBestResult) 
          || (r == currentBestResult 
              && toCheck.goodness() < currentAnswer.goodness()))
        {
          currentAnswer = toCheck;
          currentBestResult = r;
        }
      }
      if(currentBestResult < bestResult 
        || (currentBestResult == bestResult 
            && currentAnswer.goodness() < answer.goodness()))
      {
        answer = currentAnswer;
        bestResult = currentBestResult;
      }
    }
    Left[answer.y].Mark(answer.x);
    Right[answer.y].Mark(answer.x);
    if(rotated)
    {
      swap(answer.x, answer.y);
    }
    printf("%d %d\n", answer.y, answer.x);
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