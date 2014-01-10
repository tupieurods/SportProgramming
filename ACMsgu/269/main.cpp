#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

struct BigInt
{
  char digits[550];
  int len;
  //bool sign;
};

BigInt* createBigInt(int value)
{
  BigInt *result = new BigInt;
  memset(result->digits, 0, sizeof(result->digits));
  result->len = 0;
  //result->sign = false;
  while(value != 0)
  {
    result->digits[result->len] = value % 10;
    result->len++;
    value /= 10;
  }
  if(result->len == 0)
    result->len = 1;
  return result;
}

BigInt* Multiply(BigInt *first, BigInt *second)
{
  BigInt *result = new BigInt;
  memset(result->digits, 0, sizeof(result->digits));
  for(int i = 0; i < second->len; i++)
  {
    int r = 0;
    for(int j = 0; j < first->len || r > 0; j++)
    {
      result->digits[i + j] += r + first->digits[j] * second->digits[i];
      r = result->digits[i + j] / 10;
      result->digits[i + j] -= r * 10;
    }
  }
  int maximal = first->len + second->len;
  while(maximal > 0 && result->digits[maximal] == 0)
    maximal--;
  result->len = maximal + 1;
  //result->sign = false;
  //delete first;
  return result;
}

BigInt* Sum(BigInt *first, BigInt *second)
{
  BigInt *result = new BigInt;
  if(first->len < second->len)
  {
    std::swap(first, second);
  }
  memcpy(result->digits, first->digits, sizeof(first->digits));
  int r = 0;
  result->len = first->len;
  for(int i = 0; i < second->len || r > 0; i++)
  {
    result->digits[i] += second->digits[i] + r;
    if(result->digits[i] >= 10)
    {
      r = 1;
      //r = result->digits[i] / 10;
      result->digits[i] -= 10;
    }
    else
    {
      r = 0;
    }
  }
  /*int maximal = first->len + second->len;
  while(maximal > 0 && result->digits[maximal] == 0)
    maximal--;
  result->len = maximal + 1;*/
  if(result->digits[result->len] != 0)
    result->len++;
  return result;
}

void ShowBigInt(BigInt *value)
{
  /*if(value->sign)
  {
    printf("-");
  }*/
  for(int i = value->len - 1; i >= 0; i--)
  {
    printf("%d", value->digits[i]);
  }
}

int lines[255], n, k;
//__int64 cache[255][255], answer;
typedef BigInt* BigIntP;
BigIntP cache[255][255], answer;
BigIntP small[255];

int compare(const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

void ReadData()
{
  scanf("%d %d", &n, &k);
  memset(lines, 0x7F, sizeof(lines));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &lines[i]);
  }
  qsort(lines, n, sizeof(int), compare);
}

BigIntP f(int line, int t)
{
  if(cache[line][t] != NULL)
  {
    return cache[line][t];
  }
  __int64 mul = lines[line] - t >= 0 ? lines[line] - t : 0;
  if(line == n - 1 && t != k - 1)
  {
    if(t == k)
      return small[1];
    return small[0];
  }
  else if(line == n - 1)
  {
    return small[mul];
  }
  BigIntP result = small[0];
  result = f(line + 1, t);
  if(mul != 0)
  {
    result = Sum(result, Multiply(f(line + 1, t + 1), small[mul]));
    //result += f(line + 1, t + 1) * mul;
  }
  cache[line][t] = result;
  return result;
}

void Solve()
{
  //answer = 0LL;
  memset(cache, 0, sizeof(cache));
  answer = f(0, 0);
}

void WriteData()
{
  ShowBigInt(answer);
  printf("\n");
  //printf("%I64d\n", answer);
}

int main()
{
  /*if(true)
  {
    ShowBigInt(Sum(createBigInt(134), createBigInt(49)));
    return 0;
  }*/
  /*if(true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n250 250\n");
    for(int i = 0; i < 250; i++)
    {
      printf("%d ", 250);
    }
    printf("\n");
    return 0;
  }*/
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int i = 0; i < 251; i++)
  {
    small[i] = createBigInt(i);
  }
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
/*
3 2
3 3 3
2 2
2 3
3 3
2 1 2
*/