#include <stdio.h>
//Т.к. это не рабочий проект, то тут много копипасты
//Ну и вообще можно покороче написать
//В общем это говнокодерское решение. Лучше посмотреть у других
struct point
{
  int x, y;
};

point dots[8];

void ReadData()
{
  for(int i = 0; i < 8; i++)
  {
    scanf("%d %d", &dots[i].x, &dots[i].y);
  }
}

int current[4] = {-1, -1, -1, -1};

int angle(int p1, int p2, int p3, int *curr)
{
  p1 = curr[p1];
  p2 = curr[p2];
  p3 = curr[p3];
  return (dots[p1].x - dots[p2].x) * (dots[p3].x - dots[p2].x)
        + (dots[p1].y - dots[p2].y) * (dots[p3].y - dots[p2].y);
}

int distance(int p1, int p2, int *curr)
{
  p1 = curr[p1];
  p2 = curr[p2];
  return (dots[p1].x - dots[p2].x) * (dots[p1].x - dots[p2].x)
        + (dots[p1].y - dots[p2].y) * (dots[p1].y - dots[p2].y);
}

bool Check()
{
  bool used[4] = {false, false, false, false};
  for(int p1 = 0; p1 < 4; p1++)
  {
    used[p1] = true;
    for(int p2 = 0; p2 < 4; p2++)
    {
      if(used[p2]) continue;
      used[p2] = true;
      for(int p3 = 0; p3 < 4; p3++)
      {
        if(used[p3]) continue;
        used[p3] = true;
        for(int p4 = 0; p4 < 4; p4++)
        {
          if(used[p4]) continue;
          used[p4] = true;
          int d12 = distance(p1, p2, current);
          int d23 = distance(p2, p3, current);
          int d34 = distance(p3, p4, current);
          int d41 = distance(p4, p1, current);
          if(d12 == d23 && d23 == d34 && d34 == d41 && d41 == d12)
          {
            if(angle(p1, p2, p3, current) == 0
                && angle(p2, p3, p4, current) == 0
                && angle(p3, p4, p1, current) == 0
                && angle(p4, p1, p2, current) == 0)
                return true;
          }
          used[p4] = false;
        }
        used[p3] = false;
      }
      used[p2] = false;
    }
    used[p1] = false;
  }
  return false;
}

int current2[4] = {-1, -1, -1, -1};

bool Check2()
{
  bool used[4] = {false, false, false, false};
  for(int p1 = 0; p1 < 4; p1++)
  {
    used[p1] = true;
    for(int p2 = 0; p2 < 4; p2++)
    {
      if(used[p2]) continue;
      used[p2] = true;
      for(int p3 = 0; p3 < 4; p3++)
      {
        if(used[p3]) continue;
        used[p3] = true;
        for(int p4 = 0; p4 < 4; p4++)
        {
          if(used[p4]) continue;
          used[p4] = true;
          int d12 = distance(p1, p2, current2);
          int d23 = distance(p2, p3, current2);
          int d34 = distance(p3, p4, current2);
          int d41 = distance(p4, p1, current2);
          if(d12 == d34 && d23 == d41)
          {
            if(angle(p1, p2, p3, current2) == 0
                && angle(p2, p3, p4, current2) == 0
                && angle(p3, p4, p1, current2) == 0
                && angle(p4, p1, p2, current2) == 0)
                return true;
          }
          used[p4] = false;
        }
        used[p3] = false;
      }
      used[p2] = false;
    }
    used[p1] = false;
  }
  return false;
}

bool answer;
bool used1[4] = {false, false, false, false};
void Solve()
{
  answer = false;
  for(int i = 0; i < 8; i++)
  {
    current[0] = i;
    used1[i] = true;
    for(int j = i + 1; j < 8; j++)
    {
      current[1] = j;
      used1[j] = true;
      for(int k = j + 1; k < 8; k++)
      {
        current[2] = k;
        used1[k] = true;
        for(int m = k + 1; m < 8; m++)
        {
          current[3] = m;
          used1[m] = true;
          if(Check())
          {
            int next = 0;
            for(int tt = 0; tt < 8; tt++)
            {
              if(!used1[tt])
              {
                current2[next] = tt;
                next++;
                if(next == 4)
                  break;
              }
            }
            if(Check2())
            {
              answer = true;
              return;
            }
          }
          current[3] = -1;
          used1[m] = false;
        }
        current[2] = -1;
        used1[k] = false;
      }
      current[1] = -1;
      used1[j] = false;
    }
    current[0] = -1;
    used1[i] = false;
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < 4; i++)
    {
      printf("%d ", current[i] + 1);
    }
    printf("\n");
    for(int i = 0; i < 4; i++)
    {
      printf("%d ", current2[i] + 1);
    }
    printf("\n");
    return;
  }
  printf("NO\n");
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