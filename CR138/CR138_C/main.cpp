#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
char str[100009];
int globBlocks[100009];
int sum[100009];

void ReadData()
{
  scanf("%s%*c", str);
  n = strlen(str);
  memset(sum, 0, sizeof(sum));
  memset(globBlocks, 0xFF, sizeof(sum));
  int cSum = 0;
  for(int i = 0; i < n; i++)
  {
    if(str[i] == '[')
    {
      cSum++;
    }
    sum[i + 1] = cSum;
  }
}

int getSum(int l, int r)
{
  return sum[r + 1] - sum[l];
}

int answer;
int left, right;

void Solve()
{
  answer = 0;
  stack<int> st;
  vector<pair<int, int>> blocks;
  for(int i = 0; i < n; i++)
  {
    if(str[i] == '(' || str[i] == '[')
    {
      st.push(i);
      continue;
    }
    if(st.size() != 0 && ((str[st.top()] == '(' && str[i] == ')')
      || (str[st.top()] == '[' && str[i] == ']')))
    {
      left = st.top();
      right = i;
      st.pop();
      globBlocks[left] = right;
      globBlocks[right] = left;
      /*if(blocks.size() != 0)
      {
        if(blocks[blocks.size() - 1].second + 1 == left)
        {
          blocks[blocks.size() - 1].second = right;
        }
        else
        {
          blocks.push_back(make_pair(left, right));
        }
      }
      else
      {
        blocks.push_back(make_pair(left, right));
      }*/
    }
    else
    {
      while(!st.empty())
        st.pop();
    }
  }
  int i = 0;
  int cl = 0, cr = 0;
  while(cr < n)
  {
    if(globBlocks[cr] != -1)
    {
      cr = globBlocks[cr] + 1;
    }
    else
    {
      cr++;
      cl = cr;
    }
    if(getSum(cl, cr - 1) > answer)
    {
      answer = getSum(cl, cr - 1);
      left = cl;
      right = cr - 1;
    }
  }
  /*sort(blocks.begin(), blocks.end());
  for(int i = 0; i < blocks.size(); i++)
  {
    if(getSum(blocks[i].first, blocks[i].second) > answer)
    {
      answer = getSum(blocks[i].first, blocks[i].second);
      left = blocks[i].first;
      right = blocks[i].second;
    }
  }*/
}

void WriteData()
{
  printf("%d\n", answer);
  if(answer == 0)
    return;
  for(int i = left; i <= right; i++)
  {
    printf("%c", str[i]);
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