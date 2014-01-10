#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool answer;
int n, **m;
vector<pair<int, int>> v;

void ReadData()
{
  scanf("%d", &n);
  char str[30];
  m =  new int*[n];
  v.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%s", &str);
    m[i] = new int[n];
    for(int j = 0; j < n; j++)
    {
      m[i][j] = str[j] == '0' ? 0 : v.size() + 1;
      if(m[i][j] != 0)
        v.push_back(make_pair(i, j));
    }
  }
}

vector<pair<int, int>> rotatedV;

void rotateV(int angle)
{
  rotatedV.clear();
  for(vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++)
  {
    switch(angle)
    {
    case 0:
      rotatedV.push_back(make_pair(it->first, it->second));
      break;
    case 1:
      rotatedV.push_back(make_pair(it->second, -it->first));
      break;
    case 2:
      rotatedV.push_back(make_pair(-it->first, -it->second));
      break;
    case 3:
      rotatedV.push_back(make_pair(-it->second, it->first));
      break;
    }
  }
}

int rAngle;
void rotate(int &x, int &y)
{
  switch(rAngle)
  {
  case 0:
    break;
  case 1:
    x = -x;
    swap(x, y);
    break;
  case 2:
    x = -x;
    y = -y;
    break;
  case 3:
    y = -y;
    swap(x, y);
    break;
  }
}

int dx, dy;
bool *part1, *part2;
bool f(int);
__forceinline bool ifInside(bool flag, int newX, int newY, int index)
{
  if(newX >= 0 && newX < n 
      && newY >= 0 && newY < n
      && m[newY][newX] != 0
      && m[newY][newX] != index + 1
      && !part1[m[newY][newX] - 1]
      && !part2[m[newY][newX] - 1])
  {
    int p1 = index,
      p2 = m[newY][newX] - 1;

    if(!flag) swap(p1, p2);

    part1[p1] = true;
    part2[p2] = true;

    if(f(index + 1)) return true;

    part1[p1] = false;
    part2[p2] = false;
  }
  return false;
}

bool f(int index)
{
  if(index == v.size())
    return true;
  if(part1[index] || part2[index])
    return f(index + 1);
  
  int newY = rotatedV[index].first + dy;
  int newX = rotatedV[index].second + dx;
  
  bool result = ifInside(true, newX, newY, index);
  if(!result)
  {
    newY = v[index].first - dy;
    newX = v[index].second - dx;
    rotate(newX, newY);
    result = ifInside(false, newX, newY, index);
  }

  return result;
}

void Solve()
{
  answer = false;
  if(v.size() == 0)
  {
    answer = true;
    return;
  }
  if(v.size() % 2 == 0)
  {
    part1 = new bool[v.size()];
    part2 = new bool[v.size()];
    for(int i = 0; i < 4; i++)
    {
      rotateV(i);
      rAngle = i;
      //printf("Testing Angle: %d\n", i * 90);
      for(int secondCell = 1; secondCell < v.size(); secondCell++)
      {
        //if(i == 2)
          //printf("NextSecondCell: %d\n", secondCell);
        /*if(secondCell == 46)
        {
          printf("test\n");
        }*/
        memset(part1, 0, sizeof(bool) * v.size());
        memset(part2, 0, sizeof(bool) * v.size());
        part1[0] = true;
        part2[secondCell] = true;
        dy = v[secondCell].first - rotatedV[0].first;
        dx = v[secondCell].second - rotatedV[0].second;
        answer = f(1);
        if(answer)
        {
          //printf("angle: %d\n", i);
          goto GTFO;
        }
      }
    }
  }
GTFO:;
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(m[i][j] == 0 || !part1[m[i][j] - 1])
          printf("0");
        else
          printf("1");
      }
      printf("\n");
    }
  }
  else
  {
    printf("NO\n");
  }
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
}