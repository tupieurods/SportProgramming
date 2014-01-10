#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string str;

void ReadData()
{
  cin >> str;
}

int z[1000099];
vector<int> metal;

void calcZ()
{
  string wStr = "metal@" + str;
  int cnt = wStr.length();
  int left = 0;
  int right = 0;
  for(int i = 1; i < cnt; i++)
  {
    if(i <= right)
    {
      z[i] = min(right - i + 1, z[i - left]);
    }
    while(z[i] + i < cnt && wStr[z[i]] == wStr[z[i] + i])
    {
      z[i]++;
    }
    if(z[i] + i - 1 > right)
    {
      left = i;
      right = z[i] + i - 1;
    }
  }
  metal.clear();
  for(int i = 6; i < cnt; i++)
  {
    if(z[i] == 5)
      metal.push_back(i - 6);
  }
}

__int64 answer;

void Solve()
{
  memset(z, 0, sizeof(z));
  calcZ();
  answer = 0LL;
  /*for(int i = 0; i < metal.size(); i++)
  {
    printf("%d ", metal[i]);
  }
  printf("\n");*/
  __int64 mul = metal.size();
  if(mul == 0)
    return;
  int pos = 0;
  int nextPos;
  int index = 0;
  while((nextPos = str.find("heavy", pos)) != str.npos)
  {
    while(index < metal.size() 
      && metal[index] < nextPos - 1)
    {
      mul--;
      index++;
    }
    answer += mul;
    pos = nextPos + 5;
    if(pos >= str.length())
      break;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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