#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

const int mod = 1000000007;
bool a[26];
int n, m;
__int64 answer;
string inputData[100];

void ReadData()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    cin >> inputData[i];
  }
}

void Solve()
{
  answer = 1LL;
  for(int i = 0; i < m; i++)
  {
    __int64 cnt = 0LL;
    memset(a, 0, sizeof(a));
    for(int j = 0; j < n; j++)
    {
      int code = inputData[j].at(i) - 'A';
      if(!a[code])
        cnt++;
      a[code] = true;
    }
    answer *= cnt;
    answer %= mod;
  }
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
}