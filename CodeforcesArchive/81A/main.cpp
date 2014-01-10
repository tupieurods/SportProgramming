#include <stdio.h>
#include <stack>

using namespace std;

char str[200005];

void ReadData()
{
  scanf("%s", &str);
}

stack<char> answer;

void Solve()
{
  answer = stack<char>();
  int index = 0;
  int strLen = strlen(str);
  for(int i = 0; i < strLen; i++)
  {
    if(!answer.empty() && answer.top() == str[i])
      answer.pop();
    else
      answer.push(str[i]);
  }
}

void WriteData()
{
  int cnt = 0;
  while(!answer.empty())
  {
    str[cnt] = answer.top();
    cnt++;
    answer.pop();
  }
  for(int i = cnt - 1; i >= 0; i--)
  {
    printf("%c", str[i]);
  }
  printf("\n");
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
  for(int i = 0; i < QWE; i++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}