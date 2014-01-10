#include <stdio.h>
#include <string.h>
#include <deque>
#include <set>

using namespace std;

deque<int> anwser;
int data[100001][4];
set<int> bullshit;
int n;

void calcAnwser()
{
  int last = 2;
  for(int i = 0; i < n - 3; i++)
  {
    bool flag2 = false;
    for(int j = 0; j < 4; j++)
    {
      for(int k = 0; k < 4; k++)
      {
        if((data[anwser[last]][j] == data[anwser[last - 1]][k])
            && (bullshit.count(data[anwser[last]][j]) == 0))
        {
          flag2 = true;
          bullshit.insert(data[anwser[last]][j]);
          anwser.push_back(data[anwser[last]][j]);
          last++;
          break;
        }
      }
      if(flag2)
        break;
    }
  }
}

int main()
{
  scanf("%d", &n);
  int* countIn = new int[n + 1];
  memset(countIn, 0, sizeof(int) * (n + 1));
  for(int i = 0; i < 2 * n; i++)
  {
    int left, right;
    scanf("%d %d", &left, &right);
    if(countIn[right] >=4 || countIn[left]>= 4)
    {
      printf("-1\n");
      return 0;
    }
    data[left][countIn[left]] = right;
    data[right][countIn[right]] = left;
    countIn[right]++;
    countIn[left]++;
  }
  for(int i = 1; i <= n; i++)
  {
    if(countIn[i] != 4)
    {
      printf("-1\n");
      return 0;
    }
  }
  for(int i = 0; i < 3; i++)
  {
    bool flag = false;
    for(int j = i + 1; j < 4; j++)
    {
      for(int k = 0; k < 4; k++)
      {
        if(data[data[1][i]][k] == data[1][j])
        {
          anwser.clear();
          bullshit.clear();
          anwser.push_back(1);
          bullshit.insert(1);
          anwser.push_back(data[1][i]);
          anwser.push_back(data[1][j]);
          bullshit.insert(data[1][i]);
          bullshit.insert(data[1][j]);
          calcAnwser();
          if(anwser.size() != n)
          {
            bullshit.clear();
            bullshit.insert(1);
            anwser.clear();
            anwser.push_back(1);
            anwser.push_back(data[1][j]);
            anwser.push_back(data[1][i]);
            bullshit.insert(data[1][j]);
            bullshit.insert(data[1][i]);
            calcAnwser();
          }
          if(anwser.size() == n)
          {
            flag = true;
            break;
          }
        }
      }
      if(flag)
        break;
    }
    if(flag)
      break;
  }
  if(anwser.size() == n)
  {
    for(int i = 0; i < n; i++)
    {
      printf("%d ", anwser[i]);
    }
  }
  else
  {
    printf("-1\n");
  }
  return 0;
}
