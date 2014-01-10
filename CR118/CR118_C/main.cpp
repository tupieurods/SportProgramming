//#include <stdio.h>
//#include <stdlib.h>
//
//__int64 n;
//const __int64 mod = 1000000007;
//
//struct mat2x2
//{
//  __int64 value[2][2];
//};
//
//void ReadData()
//{
//  scanf("%I64d", &n);
//}
//
//__int64 answer;
//
//mat2x2 mul(mat2x2 m1, mat2x2 m2)
//{
//  mat2x2 result;
//  result.value[0][0] = 0;
//  result.value[0][1] = 0;
//  result.value[1][0] = 0;
//  result.value[1][1] = 0;
//  for(int i = 0; i < 2; i++)
//  {
//    for(int j = 0; j < 2; j++)
//    {
//      for(int k = 0; k < 2; k++)
//      {
//        result.value[i][j] += m1.value[i][k] * m2.value[k][j];
//        result.value[i][j] %= mod;
//      }
//    }
//  }
//  /*for(int i = 0; i < 2; i++)
//  {
//    for(int j = 0; j < 2; j++)
//    {
//      printf("%I64d ", result[i][j]);
//    }
//    printf("\n");
//  }*/
//  return result;
//}
//
//mat2x2 binPow(mat2x2 mat, __int64 power)
//{
//  if(power == 1)
//  {
//    return mat;
//  }
//  mat2x2 tmpMat = binPow(mat, power / 2);
//  tmpMat = mul(tmpMat, tmpMat);
//  if(power % 2 == 1)
//  {
//    tmpMat = mul(tmpMat, mat);
//  }
//  return tmpMat;
//}
//
//void Solve()
//{
//  if(n == 0)
//  {
//    answer = 1;
//    return;
//  }
//  mat2x2 result;;
//  result.value[0][0] = 3;
//  result.value[0][1] = 1;
//  result.value[1][0] = 1;
//  result.value[1][1] = 3;
//  result = binPow(result, n);
//  answer = result.value[1][1];
//}
//
//void WriteData()
//{
//  printf("%I64d\n", answer);
//}
//
//int main()
//{
//  int QWE = 1;
//#ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  scanf("%d", &QWE);
//#endif
//  for(int T = 0; T < QWE; T++)
//  {
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  return 0;
//}

#include <stdio.h>
#include <stdlib.h>

__int64 n;
const __int64 mod = 1000000007;

void ReadData()
{
  scanf("%I64d", &n);
}

__int64 answer;

__int64** mul(__int64 **m1, __int64 **m2)
{
  __int64 **result = new __int64*[2];
  result[0] = new __int64[2];
  result[0][0] = 0;
  result[0][1] = 0;
  result[1] = new __int64[2];
  result[1][0] = 0;
  result[1][1] = 0;
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      for(int k = 0; k < 2; k++)
      {
        result[i][j] += m1[i][k] * m2[k][j];
        result[i][j] %= mod;
      }
    }
  }
  /*for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      printf("%I64d ", result[i][j]);
    }
    printf("\n");
  }*/
  return result;
}

__int64** binPow(__int64 **mat, __int64 power)
{
  if(power == 1)
  {
    __int64 **result = new __int64*[2];
    result[0] = new __int64[2];
    result[1] = new __int64[2];
    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 2; j++)
      {
        result[i][j] = mat[i][j];
      }
    }
    return result;
  }
  __int64** tmpMat = binPow(mat, power / 2);
  tmpMat = mul(tmpMat, tmpMat);
  if(power % 2 == 1)
  {
    tmpMat = mul(tmpMat, mat);
  }
  return tmpMat;
}

void Solve()
{
  if(n == 0)
  {
    answer = 1;
    return;
  }
  __int64 **result = new __int64*[2];
  result[0] = new __int64[2];
  result[1] = new __int64[2];
  result[0][0] = 3;
  result[0][1] = 1;
  result[1][0] = 1;
  result[1][1] = 3;
  result = binPow(result, n);
  answer = result[1][1];
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}