#include <cstdlib>
#include <iostream>
#include "stdio.h"
#include <map>
#include <set>;
#include <vector>


using namespace std;

struct tree_vertex
{
  int Result1;//Сколько денег полученно если можно взять деньги себе
  int Result0;//Сколько денег получено, если себе взять деньги нельзя
  int Action;//Действие
  vector<int> Slaves;//Список с подчинёнными
};

tree_vertex *chiefs;
bool *prime;

int Brut(int c, bool flag)
{
  if(flag)
    {
      if(chiefs[c].Result1 != 0)
        return chiefs[c].Result1;
    }
  else
    {
      if(chiefs[c].Result0 != 0)
        return chiefs[c].Result0;
    }
  int sum = 0;
  for(vector<int>::iterator j = chiefs[c].Slaves.begin(); j != chiefs[c].Slaves.end(); j++)
    {
      sum += Brut(*j, false);
    }
  int max = 0;
  if(flag)
    {
      max = sum + 1;
      chiefs[c].Result1 = max;
      if(max > chiefs[c].Result0)
        chiefs[c].Action = -1;
    }
  else
    {
      max = sum;
      int best = 0;
      for(vector<int>::iterator j = chiefs[c].Slaves.begin(); j != chiefs[c].Slaves.end(); j++)
        {
          int tmp = sum - Brut(*j, false) + Brut(*j, true);
          if(tmp >= max)
            {
              max = tmp;
              best = *j;
            }
        }
      chiefs[c].Result0 = max;
      if(max > chiefs[c].Result1)
        chiefs[c].Action = best;
    }
  return max;
}

void Show(int c, bool flag)
{
  if(c == -1)
    return;
  if(flag)
    {
      //printf("%d ", c);
      prime[c]=true;
      for(vector<int>::iterator j = chiefs[c].Slaves.begin(); j != chiefs[c].Slaves.end(); j++)
        Show(*j, false);
    }
  else
    {
      Show(chiefs[c].Action, true);
      for(vector<int>::iterator j = chiefs[c].Slaves.begin(); j != chiefs[c].Slaves.end(); j++)
        if(*j != chiefs[c].Action)
          Show(*j, false);
    }
}

int main()
{
  int N;
  scanf("%d", &N);
  chiefs = new tree_vertex[N+1];
  prime=new bool[N+1];
  prime[0]=false;
  prime[1]=false;
  vector<int> first;
  chiefs[1] = {0, 0, 0, first};
  for(int i = 2; i <= N; i++)
    {
      prime[i]=false;
      vector<int> tmpVector;
      chiefs[i] = {0, 0, 0, tmpVector};
      int tmp;
      scanf("%d", &tmp);
      chiefs[tmp].Slaves.push_back(i);
    }
  //Проверка правильно ли заполняется массив
  /*for(int i=1; i<=N; i++)
  {
    printf("i=%d\tResult=%d\tAction=%d\n%d:\t",i,chiefs[i].Result,chiefs[i].Action,i);
    for(vector<int>::iterator j=chiefs[i].Slaves.begin(); j!=chiefs[i].Slaves.end(); j++)
      printf("%d ",*j);
    printf("\n");
  } */
  printf("%d\n", 1000 * Brut(1, false));
  Show(1, false);
  for(int i=2; i<=N; i++)
    if(prime[i])
      printf("%d ",i);
  return 0;
}

