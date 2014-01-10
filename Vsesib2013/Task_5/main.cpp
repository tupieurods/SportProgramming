#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>

int w, h, n, d;
__int64 data[59][59];

void ReadData()
{
  scanf("%d %d %d %d", &w, &h, &n, &d);
  char str[59];
  memset(data, 0, sizeof(data));
  for(int i = 0; i < n; i++)
  {
    int useless;
    scanf("%d%*c", &useless);
    for(int j = 0; j < h; j++)
    {
      scanf("%s%*c", str);
      for(int k = 0; k < w; k++)
      {
        data[i][j] <<= 1;
        if(str[k] == '1')
        {
          data[i][j] |= 1;
        }
      }
    }
  }
}

bool canMoveYPositive(int page, int dy)
{
  for(int i = 0; i < dy; i++)
  {
    if(data[page][h - 1 - i] != 0)
    {
      return false;
    }
  }
  return true;
}

bool canMoveYNegative(int page, int dy)
{
  for(int i = 0; i < dy; i++)
  {
    if(data[page][i] != 0)
    {
      return false;
    }
  }
  return true;
}

bool canMoveXPositive(int page, int dx)
{
  for(int i = 0; i < h; i++)
  {
    if((((1LL << dx) - 1LL) & data[page][i]) != 0)
    {
      return false;
    }
  }
  return true;
}

bool canMoveXNegative(int page, int dx)
{
  for(int i = 0; i < h; i++)
  {
    if((data[page][i] << dx) >= (1LL << w))
    {
      return false;
    }
  }
  return true;
}

bool canMove(int page, int dx, int dy)
{
  if((dy > 0 && !canMoveYPositive(page, dy))
    || (dy < 0 && !canMoveYNegative(page, -dy)))
  {
    return false;
  }
  if((dx > 0 && !canMoveXPositive(page, dx))
    || (dx < 0 && !canMoveXNegative(page, -dx)))
  {
    return false;
  }
  return true;
}

__int64 Arr[50], Brr[50];

int cntBits(__int64 val)
{
  int result = 0;
  while(val != 0)
  {
    if(val & 1 != 0)
    {
      result++;
    }
    val >>= 1;
  }
  return result;
}

__int64 dp2[51][50][50];

__int64 calcSwapped(int page, int dx, int dy, int prevDx, int prevDy)
{
  int ind1 = dx - prevDx,
    ind2 = dy - prevDy;
  if(ind1 < 0)
  {
    ind1 = -ind1 + 20;
  }
  if(ind2 < 0)
  {
    ind2 = -ind2 + 20;
  }
  if(dp2[page][ind1][ind2] != -1)
  {
    return dp2[page][ind1][ind2];
  }
  memset(Arr, 0, sizeof(Arr));
  memset(Brr, 0, sizeof(Brr));
  for(int i = 0; i < h; i++)
  {
    int index1, index2;
    if(prevDy >= 0)
    {
      index1 = i + prevDy;
      index2 = i;
    }
    else
    {
      index1 = i;
      index2 = i - prevDy;
    }
    if(index1 >= h || index2 >= h)
    {
      break;
    }
    Arr[index1] = prevDx >= 0 ? data[page - 1][index2] >> prevDx : data[page - 1][index2] << -prevDx;
  }
  for(int i = 0; i < h; i++)
  {
    int index1, index2;
    if(dy >= 0)
    {
      index1 = i + dy;
      index2 = i;
    }
    else
    {
      index1 = i;
      index2 = i - dy;
    }
    if(index1 >= h || index2 >= h)
    {
      break;
    }
    Brr[index1] = dx >= 0 ? data[page][index2] >> dx : data[page][index2] << -dx;
  }
  __int64 result = 0LL;
  for(int i = 0; i < h; i++)
  {
    result += cntBits(Arr[i] ^ Brr[i]);
  }
  dp2[page][ind1][ind2] = result;
  return result;
}

__int64 answer;
__int64 dp[59][25][25];

__int64 f(int page, int prevDx, int prevDy)
{
  if(page == n)
  {
    return 0LL;
  }
  int ind1 = prevDx >= 0 ? prevDx : -prevDx + 10,
    ind2 = prevDy >= 0 ? prevDy : -prevDy + 10;
  if(dp[page][ind1][ind2] != -1)
  {
    return dp[page][ind1][ind2];
  }
  //printf("%d %d %d\n", page, prevDx, prevDy);
  __int64 result = 1LL << 50;
  for(int dx = -d; dx <= d; dx++)
  {
    for(int dy = -d; dy <= d; dy++)
    {
      if(canMove(page, dx, dy))
      {
        __int64 currentResult = calcSwapped(page, dx, dy, prevDx, prevDy);
        currentResult += f(page + 1, dx, dy);
        result = std::min(currentResult, result);
      }
    }
  }
  dp[page][ind1][ind2] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  memset(dp2, 0xFF, sizeof(dp2));
  answer = f(1, 0, 0);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

//#define LOCAL

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n50 50 50 10\n");
    for(int i=0; i<50; i++)
    {
      printf("%d\n", i+1);
      for(int y=0; y<50;y++)
      {
        for(int x=0;x<50;x++)
          printf( (i%2 == 0 ? (x<40 && y<40) : (x>=10 && y >=10)) ? "1" : "0");
        //printf( (i%2 == 0 ? (x==49 && y==0) : (x==0 && y == 49)) ? "1" : "0");
        //printf( rand() %2==0 ? "1" : "0");
        printf("\n");
      }
    }
    fflush(stdout);
    return 0;
  }
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    int cnt = 20;
    printf("%d\n", cnt);
    srand(time(NULL));
    for(int i = 0; i < cnt; i++)
    {
      w = rand() % 50 + 1;
      h = rand() % 50 + 1;
      n = rand() % 50 + 1;
      d = std::min(11, std::min(w, h));
      d = rand() % d;
      if(w < 1 || w > 50 || h < 1 || h > 50 || n < 1 || n > 50
        || d < 0 || d > 10 || d >= h || d >= w)
      {
        throw;
      }
      printf("%d %d %d %d\n", w, h, n, d);
      for(int T = 0; T < n; T++)
      {
        printf("%d\n", T + 1);
        for(int j = 0; j < h; j++)
        {
          for(int k = 0; k < w; k++)
          {
            printf("%d", rand() % 2);
          }
          printf("\n");
        }
      }
      //printf("\n");
    }
    return 0;
  }
  freopen("input.txt", "r", stdin);
  int QWE = 1;
#ifdef LOCAL
  scanf("%d", &QWE);
#endif
  freopen("output.txt", "w", stdout);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}