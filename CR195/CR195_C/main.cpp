#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int n;
int a[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

vector<int> answer;

bool isBitOn(int value, int bitNumber)
{
  return ((1 << bitNumber) & value) != 0;
}

void Solve()
{
  for(int i = 29; i >= 0; i--)
  {
    int current = 0;
    bool flag = true;
    answer.clear();
    for(int j = 0; j < n; j++)
    {
      if(isBitOn(a[j], i))
      {
        if(flag)
        {
          flag = false;
          current = a[j];
        }
        else
        {
          current &= a[j];
        }
        answer.push_back(a[j]);
      }
    }
    if(flag == false && (current % (1 << i)) == 0)
    {
      return;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n");
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