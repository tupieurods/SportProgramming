#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

char key[19], str[200];

bool ReadData()
{
  memset(key, 0, sizeof(key));
  scanf("%s%*c", key);
  if(strcmp(key, "THEEND") == 0)
  {
    return false;
  }
  scanf("%s%*c", str);
  return true;
}

vector<pair<char, int>> v;
char answer[200];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  int keyl = strlen(key);
  int strl = strlen(str);
  while(strl % keyl != 0)
  {
    str[strl] = 'Q';
    strl++;
  }
  int cnt = strl / keyl;
  v.clear();
  for(int i = 0; i < keyl; i++)
  {
    v.push_back(make_pair(key[i], i));
  }
  sort(v.begin(), v.end());
  int index1 = 0;
  for(int i = 0; i < keyl; i++)
  {
    int index2 = v[i].second;
    for(int j = 0; j < cnt; j++)
    {
      answer[index2] = str[index1];
      index1++;
      index2 += keyl;
    }
  }
}

void WriteData()
{
  printf("%s\n", answer);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  while(ReadData())
  {
    Solve();
    WriteData();
  }
  return 0;
}