#include <stdio.h>
#include <vector>

using namespace std;

int n;
int *pcToPlay;//Комп на котором играется i-ая игра
int *prevCount;//Число игр которые надо сыграть перед i-ой
vector<int> dependedGames[200];//Список игр, которые зависят от i-ой игры
int answer;

void ReadData()
{
  scanf("%d", &n);
  pcToPlay = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &pcToPlay[i]);
    pcToPlay[i]--;
    dependedGames[i].clear();
  }
  prevCount = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &prevCount[i]);
    for(int j = 0; j < prevCount[i]; j++)
    {
      int curr;
      scanf("%d", &curr);
      dependedGames[curr - 1].push_back(i);
    }
  }
}

void Solve()
{
  answer = INT_MAX;
  //Перебираем стартовый компьютер
  vector<int> pc[3];//Список игр, которые можно сыграть на i-м компьютере
  pc[0].reserve(250);
  pc[1].reserve(250);
  pc[2].reserve(250);
  for(int i = 0; i < 3; i++)
  {
    pc[0].clear();
    pc[1].clear();
    pc[2].clear();
    int *currentPrevCount = new int[n];
    memcpy(currentPrevCount, prevCount, sizeof(int) * n);
    for(int j = 0; j < n; j++)
    {
      if(currentPrevCount[j] == 0)
      {
        pc[pcToPlay[j]].push_back(j);
        currentPrevCount[j]--;
      }
    }
    int played = 0;
    int currentPc = i;
    int currentAnswer = -1;
    while(played < n)
    {
      currentAnswer++;
      for(vector<int>::iterator it = pc[currentPc].begin(); it != pc[currentPc].end(); it++)
      {
        played++;
        for(vector<int>::iterator dependIt = dependedGames[*it].begin(); dependIt != dependedGames[*it].end(); dependIt++)
        {
          currentPrevCount[*dependIt]--;
          if(currentPrevCount[*dependIt] == 0)
          {
            pc[pcToPlay[*dependIt]].push_back(*dependIt);
            currentPrevCount[*dependIt]--;
          }
        }
      }
      pc[currentPc].clear();
      currentPc++;
      if(currentPc == 3)
        currentPc = 0;
    }
    answer = min(answer, currentAnswer);
  }
}

void WriteData()
{
  if(answer == INT_MAX)
    throw;
  printf("%d\n", answer + n);
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