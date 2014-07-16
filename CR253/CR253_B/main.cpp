#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[209];
int len, k;

void ReadData()
{
  scanf("%s%*c", str);
  scanf("%d", &k);
  len = strlen(str);
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < len; i++)
  {
    int maximal = (len + k - i) / 2;
    if(maximal <= answer)
    {
      break;
    }
    int current = 0;
    for(int j = answer; j <= maximal; j++)
    {
      bool flag = true;
      for(int m = 0; m < j; m++)
      {
        int nxt = i + m + j;
        if(!((nxt < len && str[i + m] == str[nxt]) || (nxt >= len && nxt < len + k)))
        {
          flag = false;
          break;
        }
      }
      if(flag)
      {
        current = j;
      }
    }
    answer = std::max(current, answer);
  }
}

void WriteData()
{
  printf("%d\n", answer * 2);
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