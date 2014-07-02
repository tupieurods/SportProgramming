#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

__int64 n, xpos, ypos, dx, dy, t;

template<typename T>
class Matrix
{
public:
  T **data;
  int rows, cols;
  Matrix<T>(const Matrix<T> &m);
  Matrix<T>(int rows, int columns);
  Matrix<T>& operator = (const Matrix<T> &m);

  template<typename T>
  friend Matrix<T> operator*(const Matrix<T> &m1, const Matrix<T> &m2);

  ~Matrix<T>();
};

template<typename T>
Matrix<T>::Matrix<T>(int rows, int columns) : rows(rows), cols(columns)
{
  data = new T*[rows];
  for(int i = 0; i < rows; i++)
  {
    data[i] = new T[cols];
    memset(data[i], 0, sizeof(__int64) * cols);
  }
}

template<typename T>
Matrix<T>::Matrix<T>(const Matrix<T> &m) : rows(m.rows), cols(m.cols)
{
  data = new T*[rows];
  for(int i = 0; i < rows; i++)
  {
    data[i] = new T[cols];
    memset(data[i], 0, sizeof(data[i]));
  }
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      data[i][j] = m.data[i][j];
    }
  }
}

template<typename T>
Matrix<T>::~Matrix<T>()
{
  for(int i = 0; i < rows; i++)
  {
    delete[] data[i];
  }
  delete[] data;
}

template<typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m)
{
  if(rows != m.rows || cols != m.cols)
  {
    throw;
  }
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      data[i][j] = m.data[i][j];
    }
  }
  return *this;
}

template<typename T>
Matrix<T> operator*(const Matrix<T> &m1, const Matrix<T> &m2)
{
  if(m1.cols != m2.rows)
  {
    throw;
  }
  Matrix<T> result(m1.rows, m2.cols);
  for(int i = 0; i < result.rows; i++)
  {
    for(int j = 0; j < result.cols; j++)
    {
      __int64 tmp = 0;
      for(int k = 0; k < m1.cols; k++)
      {
        tmp += m1.data[i][k] * m2.data[k][j];
      }
      result.data[i][j] = (tmp - 1) % n + 1;
    }
  }
  return result;
}

Matrix<__int64> identityM(6, 6);

template<typename T>
Matrix<T> binPow(Matrix<T> m, __int64 power)
{
  if(power == 0)
  {
    return identityM;
  }
  Matrix<T> tmp = binPow(m, power / 2);
  return power % 2 == 0 ? tmp * tmp : (tmp * tmp) * m;
}

void ReadData()
{
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &n, &xpos, &ypos, &dx, &dy, &t);
}

int xposA, yposA;
__int64 base[6][6] =
{
  {2, 1, 1, 1, 0, 0},
  {1, 2, 1, 1, 0, 0},
  {1, 0, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 0},
  {0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 1, 1},
};

void Solve()
{
  if(t == 0)
  {
    xposA = xpos;
    yposA = ypos;
    return;
  }
  Matrix<__int64> A(6, 6), B(6, 6);
  for(int i = 0; i < 6; i++)
  {
    identityM.data[i][i] = 1;
    for(int j = 0; j < 6; j++)
    {
      A.data[i][j] = B.data[i][j] = base[i][j];
    }
  }
  B = binPow(A, t);
  /*for(int i = 1; i < t; i++)
  {
    B = B * A;
  }*/
  /*for(int row = 0; row < 6; row++)
  {
    for(int column = 0; column < 6; column++)
    {
      printf("%I64d ", B.data[row][column]);
    }
    printf("\n");
  }*/
  xposA = (xpos * B.data[0][0] + ypos * B.data[1][0] + dx * B.data[2][0] + dy * B.data[3][0] + B.data[4][0] + B.data[5][0]) % n;
  yposA = (xpos * B.data[0][1] + ypos * B.data[1][1] + dx * B.data[2][1] + dy * B.data[3][1] + B.data[4][1] + B.data[5][1]) % n;
  if(xposA <= 0)
  {
    xposA += n;
  }
  if(yposA <= 0)
  {
    yposA += n;
  }
  /*xposA = xpos;
  yposA = ypos;
  for(int i = 1; i <= t; i++)
  {
  xposA = (2 * xpos + ypos + dx) % n;
  yposA = (xpos + 2 * ypos + dy) % n;
  dx = (dx + xpos + ypos + i) % n;
  dy = (dy + xpos + ypos + i) % n;
  if(xposA == 0)
  {
  xposA = n;
  }
  if(yposA == 0)
  {
  yposA = n;
  }
  xpos = xposA;
  ypos = yposA;
  }*/
}

void WriteData()
{
  printf("%d %d\n", xposA, yposA);
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
}