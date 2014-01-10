#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

pair<__int64, int> arr[100009];
int n;
__int64 d;
int a, b;

void ReadData()
{
  scanf("%d %I64d", &n, &d);
  scanf("%d %d", &a, &b);
  for(int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    arr[i] = make_pair(x * 1LL * a  + y * 1LL * b, i + 1);
  }
}

vector<int> answer;

int compare(const void *v1, const void *v2)
{
  pair<__int64, int> val1 = *(pair<__int64, int>*)v1;
  pair<__int64, int> val2 = *(pair<__int64, int>*)v2;
  return val1.first - val2.first;
}

void Solve()
{
  answer.clear();
  qsort(arr, n, sizeof(pair<__int64, int>), compare);
  __int64 sum = 0;
  int index = 0;
  while(sum < d && index < n)
  { 
    if(sum + arr[index].first <= d)
    {
      sum += arr[index].first;
      answer.push_back(arr[index].second);
    }
    index++;
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d ", *it);
  }
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