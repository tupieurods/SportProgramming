#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str1[1009], str2[1009];
int m1[30], m2[30];

bool ReadData()
{
  if(gets(str1) == NULL)
  {
    return false;
  }
  gets(str2);
  return true;
}

//vector<char> answer;

void Solve()
{
  memset(m1, 0, sizeof(m1));
  int str1l = strlen(str1);
  for(int i = 0; i < str1l; i++)
  {
    /*if(str1[i] < 'a' || str1[i] > 'z')
      throw;*/
    m1[(int)(str1[i] - 'a')]++;
  }
  memset(m2, 0, sizeof(m2));
  int str2l = strlen(str2);
  for(int i = 0; i < str2l; i++)
  {
    /*if(str2[i] < 'a' || str2[i] > 'z')
      throw;*/
    m2[(int)(str2[i] - 'a')]++;
  }
  int printed = 0;
  for(int i = 0; i < 30; i++)
  {
    int cnt = min(m1[i], m2[i]);
    for(int j = 0; j < cnt; j++)
    {
      printed++;
      printf("%c", 'a' + i);
    }
  }
  /*if(printed == 0)
  {
    throw;
  } */
  /*answer.clear();
  sort(answer.begin(), answer.end());*/
}

void WriteData()
{
  /*for(vector<char>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%c", *it);
  }*/
  printf("\n");
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