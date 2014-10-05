#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#define MOD 1000000007LL;

string s, comm[100009];
int n;

void ReadData()
{
  cin >> s;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> comm[i];
  }
}

__int64 answer;
__int64 trans[10], powers[10];

void Solve()
{
  for(int i = 0; i < 10; i++)
  {
    trans[i] = i;
    powers[i] = 10;
  }

  for(int i = n - 1; i >= 0; i--)
  {
    __int64 conv = 0;
    __int64 newPow = 1;
    int l = comm[i].length();
    if(l > 3)
    {
      for(int j = 3; j < l; j++)
      {
        conv = (conv * powers[comm[i][j] - '0'] + trans[comm[i][j] - '0']) % MOD;
        newPow = (powers[comm[i][j] - '0'] * newPow) % MOD;
      }
    }
    trans[comm[i][0] - '0'] = conv;
    powers[comm[i][0] - '0'] = newPow;
  }

  answer = 0;
  __int64 nxtPow = 1;
  int l = s.length();
  for(int i = 0; i < l; i++)
  {
    answer = (answer * nxtPow + trans[s[i] - '0']) % MOD;
    if(i != l - 1)
    {
      nxtPow = powers[s[i + 1] - '0'];
    }
  }
}

void WriteData()
{
  cout << answer << endl;
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //scanf("%d", &QWE);
  cin >> QWE;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}