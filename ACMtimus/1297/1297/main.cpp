#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int *d1, *d2, n;

void ReadData()
{
  cin >> str;
  n = str.length();
  d1 = new int[n];
  d2 = new int[n];
}

int d1Max, d2Max;

void Solve()
{
  int l1 = 0, r1 = -1, l2 = 0, r2 = -1;
  for(int i = 0; i < n; i++)
  {
    int k1 = (i > r1 ? 0 : min(d1[l1 + r1 - i], r1 - i));
    while(i + k1 < n && i - k1 >= 0 && str[i + k1] == str[i - k1])
      k1++;
    d1[i] = k1;
    k1--;
    if(i + k1 > r1)
    {
      l1 = i - k1;
      r1 = i + k1;
    }

    int k2 = (i > r2 ? 0 : min(d2[l2 + r2 - i + 1], r2 - i + 1)) + 1;
    while(i + k2 - 1 < n && i - k2 >= 0 && str[i + k2 - 1] == str[i - k2])
      k2++;
    k2--;
    d2[i] = k2;
    if(i + k2 - 1 > r2)
    {
      l2 = i - k2;
      r2 = i + k2 - 1;
    }
  }
  d1Max = 0, d2Max = 0;
  for(int i = 0; i < n; i++)
  {
    //printf("%d ", d1[i]);
    if(d1[i] > d1[d1Max])
      d1Max = i;
    if(d2[i] > d2[d2Max])
      d2Max = i;
  }
  //printf("\n");
}

void WriteData()
{
  //printf("%d %d", d1[d1Max], d2[d2Max]);
  int len1 = d1[d1Max] * 2 - 1;
  int len2 = d2[d2Max] * 2;
  if(len1 > len2)
  {
    cout << str.substr(d1Max - d1[d1Max] + 1, len1) << endl;
  }
  else if(len2 > len1)
  {
    cout << str.substr(d2Max - d2[d2Max], len2) << endl;
  }
  else
  {
    throw;
  }
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