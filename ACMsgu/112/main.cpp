#include <stdio.h>
#include <string.h>
#include <algorithm>

struct BigInt
{
  int digits[200009];
  int len;
  bool sign;
};

BigInt* createBigInt(int value)
{
  BigInt *result = new BigInt;
  memset(result->digits, 0, sizeof(result->digits));
  result->len = 0;
  result->sign = false;
  while(value != 0)
  {
    result->digits[result->len] = value % 10;
    result->len++;
    value /= 10;
  }
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
  result->sign = false;
  delete first;
  return result;
}

int Compare(BigInt *first, BigInt *second)
{
  if(first->len != second->len)
  {
    return first->len - second->len;
  }
  for(int i = first->len - 1; i >= 0; i--)
  {
    if(first->digits[i] != second->digits[i])
      return first->digits[i] - second->digits[i];
  }
  return 0;
}

BigInt* Minus(BigInt *first, BigInt *second)
{
  BigInt* result = new BigInt;
  int compareResult = Compare(first, second);
  result->sign = false;
  if(compareResult == 0)
  {
    result->digits[0] = 0;
    result->len = 1;
    return result;
  }
  if(compareResult < 0)
  {
    result->sign = true;
    std::swap(first, second);
  }
  memcpy(result->digits, first->digits, sizeof(result->digits));
  for(int i = 0; i < first->len; i++)
  {
    result->digits[i] -= second->digits[i];
    if(result->digits[i] < 0)
    {
      result->digits[i] += 10;
      result->digits[i + 1]--;
    }
  }
  int maximal = first->len;
  while(maximal > 0 && result->digits[maximal] == 0)
    maximal--;
  result->len = maximal + 1;
  return result;
}

int main()
{
  BigInt *test = createBigInt(1);
  BigInt *N100 = createBigInt(100);
  for(int i = 0; i < 100000; i++)
  {
    test = Multiply(test, N100);
  }
  printf("%d\n", test->len);
  /*int a, b;
  scanf("%d %d", &a, &b);
  BigInt *A = createBigInt(a),
    *B = createBigInt(b),
    *resultA = createBigInt(a),
    *resultB = createBigInt(b);
  for(int i = 1; i < b; i++)
  {
    resultA = Multiply(resultA, A);
  }
  for(int i = 1; i < a; i++)
  {
    resultB = Multiply(resultB, B);
  }
  BigInt *result = Minus(resultA, resultB);
  if(result->sign)
  {
    printf("-");
  }
  for(int i = result->len - 1; i >= 0; i--)
  {
    printf("%d", result->digits[i]);
  }*/
  return 0;
}