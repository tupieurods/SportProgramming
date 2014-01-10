#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
map<string, int> cnt;
bool used[5051];

void ReadData()
{
  memset(used, 0, sizeof(used));
  cin >> str;
}

void f(int l, int r)
{
  if(l > r)
    return;
  if(used[100 * l + r])
    return;
  used[100 * l + r] = true;
  string sub = str.substr(l, r - l + 1);
  map<string, int>::iterator it = cnt.find(sub);
  if(it == cnt.end())
    cnt.insert(make_pair(sub, 1));
  else
    it->second++;
  f(l + 1, r);
  f(l, r - 1);
}

void Solve()
{
  f(0, str.length() - 1);
}

void WriteData()
{
  string answer;
  int answerCnt = 0;
  for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
  {
    if(answerCnt < it->second)
    {
      answerCnt = it->second;
      answer = it->first;
    }
  }
  cout << answer << endl;
}

int main()
{
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