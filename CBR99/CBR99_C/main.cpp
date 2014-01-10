#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;

void ReadData()
{
  scanf("%d %d%*c", &n, &k);
}

int answer;
char gChars[9] = "aeiou";
char strings[4][10009];
int ind[4];
int lens[4];
bool rifm[4][4];

bool check(int v1, int v2)
{
  if(lens[v1] - ind[v1] != lens[v2] - ind[v2])
  {
    return false;
  }
  for(int i = 0; i < lens[v1] - ind[v1]; i++)
  {
    if(strings[v1][ind[v1] + i] != strings[v2][ind[v2] + i])
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  answer = 3;
  for(int i = 0; i < n; i++)
  {
    memset(rifm, false, sizeof(rifm));
    for(int j = 0; j < 4; j++)
    {
      scanf("%s%*c", strings[j]);
      if(answer == 4)
      {
        continue;
      }
      int cnt = k;
      ind[j] = strlen(strings[j]) - 1;
      lens[j] = ind[j] + 1;
      while(ind[j] != -1)
      {
        if(strchr(gChars, strings[j][ind[j]]) != NULL)
        {
          cnt--;
        }
        if(cnt == 0)
        {
          break;
        }
        ind[j]--;
      }
      if(cnt != 0)
      {
        answer = 4;
        //return;
      }
    }
    for(int j = 0; j < 4; j++)
    {
      for(int t = j + 1; t < 4; t++)
      {
        bool res = check(j, t);
        rifm[j][t] = res;
        rifm[t][j] = res;
      }
    }
    if(answer != 4)
    {
      int current = 4;
      if(rifm[0][1] && rifm[0][2] && rifm[0][3])
      {
        current = 3;
      }
      else if(rifm[0][1] && rifm[2][3])
      {
        current = 0;
      }
      else if(rifm[0][2] && rifm[1][3])
      {
        current = 1;
      }
      else if(rifm[0][3] && rifm[1][2])
      {
        current = 2;
      }
      if(answer == 3 && current != 3)
      {
        answer = current;
      }
      if((current == 4)
        || (current != 3 && current != answer))
      {
        answer = 4;
      }
    }
  }
}

char str[5][9] = 
{
  "aabb",
  "abab",
  "abba",
  "aaaa",
  "NO"
};

void WriteData()
{
  printf("%s\n", str[answer]);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}