#include <stdio.h>
#include <string.h>

int n, m;
int field[505][505];
char answerChars[1000005];
int answerX[1000005];
int answerY[1000005];
int answer;

void ReadData()
{
  scanf("%d %d%*c", &n, &m);
  memset(field, 0, sizeof(field));
  char str[505];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", &str);
    for(int j = 0; j < m; j++)
    {
      if(str[j] == '#')
      {
        field[i][j] = -1;
      }
    }
  }
}

void dfsVisit(int x, int y, bool notRoot);
void dfs()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(field[i][j] == 0)
      {
        dfsVisit(j, i, false);
      }
    }
  }
}

int delta[4][2] =
{
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0}
};

bool validate(int x, int y)
{
  if(x >= 0 && x < m && y >= 0 && y < n && field[y][x] == 0)
    return true;
  return false;
}

void dfsVisit(int x, int y, bool notRoot)
{
  //printf("B %d %d\n", y + 1, x + 1);
  answerChars[answer] = 'B';
  answerX[answer] = x;
  answerY[answer] = y;
  answer++;
  field[y][x] = 1;
  for(int i = 0; i < 4; i++)
  {
    if(validate(x + delta[i][0], y + delta[i][1]))
      dfsVisit(x + delta[i][0], y + delta[i][1], true);
  }
  if(notRoot)
  {
    //printf("D %d %d\n", y + 1, x + 1);
    //printf("R %d %d\n", y + 1, x + 1);
    answerChars[answer] = 'D';
    answerX[answer] = x;
    answerY[answer] = y;
    answer++;
    answerChars[answer] = 'R';
    answerX[answer] = x;
    answerY[answer] = y;
    answer++;
    field[y][x] = 2;
  }
}

void Solve()
{
  answer = 0;
  dfs();
}

void WriteData()
{
  printf("%d\n", answer);
  for(int i = 0; i < answer; i++)
  {
    printf("%c %d %d\n", answerChars[i], answerY[i] + 1, answerX[i] + 1);
  }
  printf("\n");
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%*c", &QWE);
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