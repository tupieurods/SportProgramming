#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

struct command
{
  string name;
  int ourGoals, gotGoals, points, played;
};

command teams[4];

void UpdateTeamInfo(string teamName, int aPoint, int bPoints)
{
  for(int j = 0; j < 4; j++)
  {
    if(teams[j].name == "")
    {
      teams[j].name = teamName;
    }
    if(teams[j].name == teamName)
    {
      if(aPoint > bPoints)
      {
        teams[j].points += 3;
      }
      else if(aPoint == bPoints)
      {
        teams[j].points += 1;
      }
      teams[j].ourGoals += aPoint;
      teams[j].gotGoals += bPoints;
      teams[j].played++;
      break;
    }
  }
}

string firstTeam, secondTeam;

void ReadData()
{
  string points;
  for(int i = 0; i < 4; i++)
  {
    teams[i].name = "";
    teams[i].ourGoals = 0;
    teams[i].gotGoals = 0;
    teams[i].points = 0;
    teams[i].played = 0;
  }
  for(int i = 0; i < 5; i++)
  {
    int a, b;
    cin >> firstTeam >> secondTeam >> points;
    a = points[0] - '0';
    b = points[2] - '0';
    UpdateTeamInfo(firstTeam, a, b);
    UpdateTeamInfo(secondTeam, b, a);
    /*cout << firstTeam << endl
    << secondTeam << endl
    << a << endl
    << b << endl;*/
  }
}

pair<int, int> answer;

int compare(const void *v1, const void *v2)
{
  command val1 = *(command*)v1;
  command val2 = *(command*)v2;
  if(val1.points == val2.points)
  {
    if(val1.ourGoals - val1.gotGoals == val2.ourGoals - val2.gotGoals)
    {
      if(val1.ourGoals == val2.ourGoals)
      {
        if(val1.name < val2.name)
          return -1;
        return 1;
        /*if(val1.name.length() != val2.name.length())
        return val1.name.length() - val2.name.length();
        int len = val1.name.length();
        for(int i = 0; i < len; i++)
        {
        if(val1.name[i] != val2.name[i])
        {
        return val1.name[i] - val2.name[i];
        }
        }*/
      }
      return val2.ourGoals - val1.ourGoals;
    }
    return val2.ourGoals - val2.gotGoals - (val1.ourGoals - val1.gotGoals);
  }
  return val2.points - val1.points;
}

void Solve()
{
  firstTeam = "BERLAND";
  command copyFirst, copySecond;
  for(int i = 0; i < 4; i++)
  {
    if(teams[i].name == firstTeam)
    {
      copyFirst = teams[i];
    }
    if(teams[i].played == 2
      && teams[i].name != firstTeam)
    {
      secondTeam = teams[i].name;
      copySecond = teams[i];
      //break;
    }
  }
  qsort(teams, 4, sizeof(command), compare);
  answer = make_pair(-1, -1);
  if(teams[0].name == firstTeam
    || teams[1].name == firstTeam)
  {
    answer.first = 1;
    answer.second = 0;
    return;
  }

  for(int i = 60; i >= 1; i--)
  {
    for(int j = i - 1; j >= 0; j--)
    {
      for(int k = 0; k < 4; k++)
      {
        if(teams[k].name == firstTeam)
        {
          teams[k] = copyFirst;
        }
        if(teams[k].name == secondTeam)
        {
          teams[k] = copySecond;
        }
      }
      UpdateTeamInfo(firstTeam, i, j);
      UpdateTeamInfo(secondTeam, j, i);
      qsort(teams, 4, sizeof(command), compare);
      if(teams[0].name == firstTeam
        || teams[1].name == firstTeam)
      {
        if(answer.first == -1)
        {
          answer.first = i;
          answer.second = j;
        }
        else
        {
          if(i - j < answer.first - answer.second)
          {
            answer.first = i;
            answer.second = j;
          }
          else if(i - j == answer.first - answer.second)
          {
            if(j < answer.second)
            {
              answer.first = i;
              answer.second = j;
            }
          }
        }
      }
    }
  }
}

void WriteData()
{
  if(answer.first == -1)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << answer.first << ":" << answer.second << endl;
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}