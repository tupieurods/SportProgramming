#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string p, s;
int k, lenp, lens;

void ReadData()
{
  /*cin >> p;
  cin >> s;*/
  getline(std::cin, p);
  getline(std::cin, s);
  lenp = p.length();
  lens = s.length();
  scanf("%d%*c", &k);
  //cin >> k;
}

int currentCnt;
int dp[2009][209];
string pSubStrs[2000], sSubStrs[200];
__int64 pHashes[2000], sHashes[200];

bool f(int pPos, int sPos)
{
  if(sPos == currentCnt)
  {
    return true;
  }
  if(pPos == k)
  {
    return false;
  }
  if(dp[pPos][sPos] != -1)
  {
    return dp[pPos][sPos] != 0;
  }
  bool result = f(pPos + 1, sPos);
  if(result)
  {
    dp[pPos][sPos] = 1;
    return result;
  }
  if((pHashes[pPos] == sHashes[sPos])
    && (pSubStrs[pPos] == sSubStrs[sPos]))
  {
    result = f(pPos + 1, sPos + 1);
    if(result)
    {
      dp[pPos][sPos] = 2;
      return result;
    }
  }
  dp[pPos][sPos] = 0;
  return false;
}

string gBuild;

void g(int pPos, int sPos)
{
  if(sPos == currentCnt)
  {
    return;
  }
  gBuild += dp[pPos][sPos] == 1 ? "0" : "1";
  if(dp[pPos][sPos] == 1)
  {
    g(pPos + 1, sPos);
  }
  else
  {
    g(pPos + 1, sPos + 1);
  }
}

bool answer;
string answerStr;

void Solve()
{
  answer = false;
  if(lens > lenp)
  {
    return;
  }
  int maxCnt = min(k, lens);
  for(int i = 0; i < k; i++)
  {
    pSubStrs[i] = "";
    pHashes[i] = 0;
    int pos = i;
    while(pos < lenp)
    {
      pSubStrs[i] += p[pos];
      pHashes[i] = pHashes[i] * 443LL + p[pos];
      pos += k;
    }
  }
  answerStr = "";
  for(int i = 1; i <= maxCnt; i++)
  {
    for(int j = 0; j < i; j++)
    {
      sSubStrs[j] = "";
      sHashes[j] = 0;
      int pos = j;
      while(pos < lens)
      {
        sSubStrs[j] += s[pos];
        sHashes[j] = sHashes[j] * 443LL + s[pos];
        pos += i;
      }
    }
    memset(dp, 0xFF, sizeof(dp));
    currentCnt = i;
    if(f(0, 0))
    {
      answer = true;
      gBuild = "";
      g(0, 0);
      int toAdd = k - gBuild.length();
      for(int i = 0; i < toAdd; i++)
      {
        gBuild += "0";
      }
      if(answerStr == "" || gBuild < answerStr)
      {
        answerStr = gBuild;
      }
    }
  }
}

void WriteData()
{
  if(answer == false)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << answerStr << endl;
  }
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //cin >> QWE;
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}