#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int m;
vector<int> avaible;

void ReadData()
{
  avaible.clear();
  char str[19];
  scanf("%s%*c", str);
  for(int i = 0; i < 10; i++)
  {
    if(str[i] == '1')
    {
      avaible.push_back(i + 1);
    }
  }
  scanf("%d%*c", &m);
}

bool answer;
vector<int> answerVector;
vector<int>::iterator it;

void Solve()
{
  answer = false;
  answerVector.clear();
  int l = 0, r = 0, prev = -1;
  for(int T = 0; T < avaible.size(); T++)
  {
    r = 0;
    l = avaible[T];
    prev = l;
    answerVector.push_back(prev);
    for(int i = 1; i < m; i++)
    {
      bool flag = false;
      if(i % 2 == 0)
      {
        for(it = avaible.begin(); it != avaible.end(); it++)
        {
          if(*it != prev && l + *it > r)
          {
            prev = *it;
            l += *it;
            flag = true;
            answerVector.push_back(*it);
            break;
          }
        }
      }
      else
      {
        for(it = avaible.begin(); it != avaible.end(); it++)
        {
          if(*it != prev && r + *it > l)
          {
            prev = *it;
            r += *it;
            flag = true;
            answerVector.push_back(*it);
            break;
          }
        }
      }
      if(flag == false)
      {
        answerVector.clear();
        break;
      }
    }
    if(answerVector.size() == m)
    {
      answer = true;
      return;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(it = answerVector.begin(); it != answerVector.end(); it++)
    {
      printf("%d ", *it);
    }
  }
  else
  {
    printf("NO");
  }
  printf("\n");
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