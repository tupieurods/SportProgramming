#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct rule
{
  string p;
  int l, r;
};

string t;
int n;
rule *rules;
int z[5000];
set<string> bad, good;

void ReadData()
{
  cin >> t;
  cin >> n;
  rules = new rule[n];
  for(int i = 0; i < n; i++)
  {
    cin >> rules[i].p >> rules[i].l >> rules[i].r;
  }
}

int calc(string &str, string &pattern)
{
  memset(z, 0, sizeof(z));
  string working = str + "@" + pattern;
  int lenStr = str.length();
  int patternLen = pattern.length();
  for(int i = 1, l = 0, r = 0; i < lenStr + 1 + patternLen; i++)
  {
    if(i <= r)
    {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < lenStr + 1 + patternLen
       && working[z[i]] == working[z[i] + i])
    {
      z[i]++;
    }
    if(i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
  int result = 0;
  for(int i = lenStr + 1; i < lenStr + 1 + patternLen; i++)
  {
    if(z[i] == lenStr)
      result++;
  }
  return result;
}

bool validate(string &str)
{
  for(int i = 0; i < n; i++)
  {
    int current = calc(str, rules[i].p);
    if(current < rules[i].l || current > rules[i].r)
      return false;
  }
  return true;
}

set<int> djview;

int f(int l, int r)
{
  if(djview.find(l * 10000 + r) != djview.end())
    return 0;
  djview.insert(l * 10000 + r);
  if(l > r)
    return 0;
  //printf("%d %d\n", l, r);
  int result = 0;
  string subString = t.substr(l, r - l);
  if(bad.find(subString) == bad.end() 
    && good.find(subString) == good.end())
  {
    bool valid = validate(subString);
    if(valid)
      good.insert(subString);
    else
      bad.insert(subString);
    result = (int)valid;
  }
  if(l != r - 1)
    result += f(l + 1, r) + f(l, r - 1);
  return result;
}

int answer;
void Solve()
{
  bad.clear();
  good.clear();
  djview.clear();
  answer = f(0, t.length());
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