#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int n, k;
int answer;
string inputData[8];

void ReadData()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    cin >> inputData[i];
  }
}

void f(int bitmask, int permutation)
{
  if(bitmask == (1 << k) - 1)
  {
    int *values = new int[n];
    memset(values, 0, sizeof(int) * n);
    for(int i = 0; i < k; i++)
    {
      int code = (permutation % 10) - 1;
      permutation /= 10;
      for(int j = 0; j < n; j++)
      {
        values[j] = values[j] * 10 + (inputData[j].at(code) - '0');
      }
    }
    int minimal = INT_MAX, maximal = INT_MIN;
    for(int i = 0; i < n; i++)
    {
      minimal = min(minimal, values[i]);
      maximal = max(maximal, values[i]);
    }
    answer = min(answer, maximal - minimal);
    return;
  }
  for(int i = 0; i < k; i++)
  {
    if((bitmask & (1 << i)) == 0)
    {
      f(bitmask | (1 << i), permutation * 10 + (i + 1));
    }
  }
}

void Solve()
{
  answer = INT_MAX;
  f(0, 0);
}

void WriteData()
{
  cout << answer << endl;
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
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