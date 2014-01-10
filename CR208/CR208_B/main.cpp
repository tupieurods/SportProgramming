#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

string a[100009];
string str;
int n;
int check;

void ReadData()
{
  scanf("%d%*c", &n);
  check = 2 + 2 * n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    check += a[i].length();
    scanf("%*c");
  }
  cin >> str;
  scanf("%*c");
}

int answer;

void Solve()
{
  answer = 0;
  int len = str.length();
  int shit = 2;
  int current = -1;
  int pos = 0;
  for(int i = 0; i < len; i++)
  {
    if(shit != 0)
    {
      if(shit == 2 && str[i] == '<')
      {
        shit--;
        answer++;
      }
      else if(shit == 1 && str[i] == '3')
      {
        shit--;
        answer++;
      }
      if(shit == 0)
      {
        pos = 0;
        current++;
      }
      continue;
    }
    if(current < n && a[current][pos] == str[i])
    {
      pos++;
      answer++;
      if(pos == a[current].length())
      {
        shit = 2;
      }
    }
  }
}

void WriteData()
{
  if(answer == check)
  {
    printf("yes\n");
  }
  else
  {
    printf("no\n");
  }
}


int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
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