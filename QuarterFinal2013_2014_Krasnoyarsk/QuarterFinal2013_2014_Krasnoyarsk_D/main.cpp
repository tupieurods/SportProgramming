#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int m;
int inputPattern, target;

void ReadData()
{
  scanf("%d", &m);
  inputPattern = 0;
  target = 0;
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    inputPattern = inputPattern * 10 + (val - 1);
    target = target * 10 + i;
  }
}

int permutation;
bool used[5];
map<int, int> permutationNumbers;
vector<int> permutations;

void genPermutations(int cnt)
{
  if(cnt == 0)
  {
    if(permutationNumbers.find(permutation) != permutationNumbers.end())
    {
      throw;
    }
    permutationNumbers.insert(make_pair(permutation, permutations.size()));
    permutations.push_back(permutation);
    return;
  }
  for(int i = 0; i < m; i++)
  {
    if(!used[i])
    {
      used[i] = true;
      permutation = permutation * 10 + i;
      genPermutations(cnt - 1);
      permutation /= 10;
      used[i] = false;
    }
  }
}

int powersOf10[6] = {1, 10, 100, 1000, 10000, 100000};

//Индексы отсчитываются справа
int swapNumbers(int value, int j, int k)
{
  int valj = (value / powersOf10[j]) % 10;
  int valk = (value / powersOf10[k]) % 10;
  int result = value - valj * powersOf10[j] - valk * powersOf10[k];
  result = result + valk * powersOf10[j] + valj * powersOf10[k];
  return result;
}

double matrix[120][121];
int ind[120];
double solution[120];
double const eps = 1e-6;

void showMatrix(int cnt)
{
  for(int i = 0; i < cnt; i++)
  {
    for(int j = 0; j <= cnt; j++)
    {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}

void gauss(int cnt)
{
  for(int i = 0; i < cnt; i++)
  {
    ind[i] = i;
  }
  //Прямой ход
  for(int i = 0; i < cnt; i++)
  {
    if(fabs(matrix[ind[i]][i]) < eps)//Если диагональный элемент равен нулю
    {
      for(int j = i + 1; j < cnt; j++)
      {
        if(fabs(matrix[ind[j]][i]) > eps)
        {
          swap(ind[i], ind[j]);
          break;
        }
      }
    }
    if(fabs(1.0 - matrix[ind[i]][i]) > eps)//Если диагональный элемент 1.0
    {
      double val = matrix[ind[i]][i];
      for(int j = i; j <= cnt; j++)
      {
        matrix[ind[i]][j] /= val;
      }
    }
    for(int j = i + 1; j < cnt; j++)
    {
      if(fabs(matrix[ind[j]][i]) > eps)
      {
        double val = matrix[ind[j]][i];
        for(int k = i; k <= cnt; k++)
        {
          matrix[ind[j]][k] -= matrix[ind[i]][k] * val;
        }
      }
    }
    /*printf("next:\n");
    showMatrix(cnt);*/
  }
  //Обратный ход
  for(int i = cnt - 1; i >= 0; i--)
  {
    solution[ind[i]] = 0;
    for(int j = i + 1; j < cnt; j++)
    {
      solution[ind[i]] += matrix[ind[i]][j] * solution[ind[j]];
    }
    solution[ind[i]] = (matrix[ind[i]][cnt] - solution[ind[i]]) / matrix[ind[i]][i];
  }
}

void Solve()
{
  permutationNumbers.clear();
  permutations.clear();
  genPermutations(m);
  int intP = (m * (m - 1)) / 2;
  memset(matrix, 0, sizeof(matrix));
  int permCnt = permutations.size();
  for(int i = 0; i < permCnt; i++)
  {
    matrix[i][i] = -intP;
    if(permutations[i] == target)
    {
      matrix[i][permCnt] = 0;
      continue;
    }
    matrix[i][permCnt] = -intP;
    int current = permutations[i];
    for(int j = 0; j < m; j++)
    {
      for(int k = j + 1; k < m; k++)
      {
        int swapped = swapNumbers(current, j, k);
        //printf("good\n");
        if(swapped != target)
        {
          matrix[i][permutationNumbers[swapped]] = 1;
        }
      }
    }
  }
  gauss(permCnt);
  /*for(int i = 0; i < permCnt; i++)
  {
    for(int j = 0; j <= permCnt; j++)
    {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }*/
}

void WriteData()
{
  printf("%.4f\n", abs(solution[ind[permutationNumbers[inputPattern]]]));
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
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