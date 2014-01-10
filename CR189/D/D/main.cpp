#include <stdio.h>
#include <vector>

using namespace std;

int n, *a, *nextElem;
int answer;
bool *ate;
vector<int> killers;

void ReadData()
{
  scanf("%d", &n);
  a = new int[n];
  nextElem = new int[n];
  ate = new bool[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    nextElem[i] = i + 1;
    killers.push_back(i);
    ate[i] = false;
  }
}

void Solve()
{
  answer = 0;
  while(true)
  {
    vector<int> newKillers;
    bool flag = false;
    for(vector<int>::iterator it = killers.begin(); it != killers.end(); it++)
    {
      int current = *it;
      while(/*!ate[current] && */current != n && nextElem[current] != n
        && a[current] > a[nextElem[current]])
      {
        current = nextElem[current];
        ate[current] = true;
      }
      if(*it != current && !ate[*it])
      {
        newKillers.push_back(*it);
        nextElem[*it] = nextElem[current];
        flag = true;
      }
    }
    /*for(int i = 0; i < n; i++)
      printf("%d ", nextElem[i]);
    printf("\n");*/
    if(flag)
      answer++;
    if(newKillers.size() == 0)
      break;
    killers = newKillers;
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}