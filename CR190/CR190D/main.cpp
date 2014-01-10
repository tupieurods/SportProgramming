#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> ciel, jiroA, jiroD;

void ReadData()
{
  scanf("%d %d", &n, &m);
  ciel.clear();
  jiroA.clear();
  jiroD.clear();
  char str[10];
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%s %d%*c", &str, &val);
    if(str[0] == 'A')
      jiroA.push_back(val);
    else
      jiroD.push_back(val);
  }
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    ciel.push_back(val);
  }
  sort(ciel.begin(), ciel.end());
  sort(jiroA.begin(), jiroA.end());
  sort(jiroD.begin(), jiroD.end());
}

int answer;
int dp[101][101][101][2];

int f(int nextCiel, int nextJiroA, int nextJiroD, bool allDead)
{
  if(nextCiel == m)
  {
    if(!allDead || (nextJiroD == jiroD.size() && nextJiroA == jiroA.size()))
      return 0;
    return -1000000000;
  }
  if(dp[nextCiel][nextJiroA][nextJiroD][allDead] != -1)
  {
    return dp[nextCiel][nextJiroA][nextJiroD][allDead];
  }
  //skip
  int result = f(nextCiel + 1, nextJiroA, nextJiroD, allDead);
  //Attack ATK
  if(nextJiroA != jiroA.size() && ciel[nextCiel] >= jiroA[nextJiroA])
  {
    result = max(ciel[nextCiel] - jiroA[nextJiroA]
    + f(nextCiel + 1, nextJiroA + 1, nextJiroD, allDead), result);
  }
  //Attack DEF
  if(nextJiroD != jiroD.size() && ciel[nextCiel] > jiroD[nextJiroD])
  {
    result = max(f(nextCiel + 1, nextJiroA, nextJiroD + 1, allDead), result);
  }
  //directAttack
  //if(nextJiroD == jiroD.size() && nextJiroA == jiroA.size())
  {
    result = max(ciel[nextCiel] + f(nextCiel + 1, nextJiroA, nextJiroD, true), result);
  }
  dp[nextCiel][nextJiroA][nextJiroD][allDead] = result;
  return result;
}

void Solve()
{
  answer = 0;
  memset(dp, 0xFF, sizeof(dp));
  answer = f(0, 0, 0, false);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
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