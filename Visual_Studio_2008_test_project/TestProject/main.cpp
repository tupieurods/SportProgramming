#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

int n, k;
int c[100009];
vector<int> tree[4 * 100009];
map<int, vector<int>> numbersPos;

void ReadData()
{
  for(int i = 0; i < 4 * 100009; i++)
  {
    tree[i].clear();
  }
  numbersPos.clear();
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
    if(numbersPos.find(c[i]) == numbersPos.end())
    {
      numbersPos.insert(make_pair(c[i], vector<int>()));
    }
    numbersPos[c[i]].push_back(i);
  }
}

vector<int>::iterator it1, it2;

void addElem(int l, int r, int pos, int index, int value)
{
  if(l == r && pos == l)
  {
    tree[index].push_back(value);
    return;
  }
  int center = l + (r - l) / 2;
  if(pos <= center)
  {
    addElem(l, center, pos, index * 2 + 1, value);
  }
  else
  {
    addElem(center + 1, r, pos, index * 2 + 2, value);
  }
  it1 = tree[index * 2 + 1].begin();
  it2 = tree[index * 2 + 2].begin();
  tree[index].clear();
  while(it1 != tree[index * 2 + 1].end() || it2 != tree[index * 2 + 2].end())
  {
    if(it1 != tree[index * 2 + 1].end() && it2 != tree[index * 2 + 2].end())
    {
      if(*it1 < *it2)
      {
        tree[index].push_back(*it1);
        it1++;
      }
      else
      {
        tree[index].push_back(*it2);
        it2++;
      }
    }
    else if(it1 != tree[index * 2 + 1].end())
    {
      tree[index].push_back(*it1);
      it1++;
    }
    else
    {
      tree[index].push_back(*it2);
      it2++;
    }
  }
}

int findElem(int tl, int tr, int l, int r, int index, int val)
{
  if(l > r)
  {
    return INT_MAX;
  }
  if(tl == l && tr == r)
  {
    it1 = upper_bound(tree[index].begin(), tree[index].end(), val);
    return it1 == tree[index].end() ? INT_MAX : *it1;
  }
  int center = tl + (tr - tl) / 2;
  return min(findElem(tl, center, l, min(center, r), index * 2 + 1, val),
    findElem(center + 1, tr, max(center + 1, l), r, index * 2 + 2, val));
}

int dp[100009];

int f(int level)
{
  if(dp[level] != -1)
  {
    return dp[level];
  }
  if(level == n - 1)
  {
    return n - 1;
  }
  int result = level;
  int t = findElem(0, n - 1, level + 1, min(level + k, n - 1), 0, c[level]);
  int ind = -1;
  if(numbersPos.find(t) != numbersPos.end())
  {
    it1 = upper_bound(numbersPos[t].begin(), numbersPos[t].end(), min(level + k, n - 1));
    //if(*it1 != min(level + k, n - 1))
    //{
      it1--;
    //}
    ind = *it1;
  }
  /*int ind = -1;
  for(int i = 0; i < k; i++)
  {
    if(c[i + level + 1] == t)
    {
      ind = i + level + 1;
    }
  }*/
  /*int t = INT_MAX;
  int ind = -1;
  for(int i = 0; i < k; i++)
  {
    if(i + level + 1 < n && c[i + level + 1] > c[level] && c[i + level + 1] < t)
    {
      t = c[i + level + 1];
      ind = i + level + 1;
    }
    else if(i + level + 1 < n && c[i + level + 1] == t)
    {
      ind = i + level + 1;
    }
  }*/
  if(ind != -1)
  {
    result = max(result, f(ind));
  }
  dp[level] = result;
  return result;
}

int answer;

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    addElem(0, n - 1, i, 0, c[i]);
  }
  answer = -1;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < k; i++)
  {
    answer = max(f(i), answer);
  }
}

void WriteData()
{
  printf("%d\n", answer + 1);
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
    //time_t timeTotal = clock();
    ReadData();
    Solve();
    WriteData();
    //printf("working time: %f\n", (float)timeTotal / CLOCKS_PER_SEC);
  }
  return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//int m;
//int inputPattern, target;
//
//void ReadData()
//{
//  scanf("%d", &m);
//  inputPattern = 0;
//  target = 0;
//  for(int i = 0; i < m; i++)
//  {
//    int val;
//    scanf("%d", &val);
//    inputPattern = inputPattern * 10 + (val - 1);
//    target = target * 10 + i;
//  }
//}
//
//int permutation;
//bool used[5];
//map<int, int> permutationNumbers;
//vector<int> permutations;
//
//void genPermutations(int cnt)
//{
//  if(cnt == 0)
//  {
//    if(permutationNumbers.find(permutation) != permutationNumbers.end())
//    {
//      throw;
//    }
//    permutationNumbers.insert(make_pair(permutation, permutations.size()));
//    permutations.push_back(permutation);
//    return;
//  }
//  for(int i = 0; i < m; i++)
//  {
//    if(!used[i])
//    {
//      used[i] = true;
//      permutation = permutation * 10 + i;
//      genPermutations(cnt - 1);
//      permutation /= 10;
//      used[i] = false;
//    }
//  }
//}
//
//int powersOf10[6] = {1, 10, 100, 1000, 10000, 100000};
//
////Индексы отсчитываются справа
//int swapNumbers(int value, int j, int k)
//{
//  int valj = (value / powersOf10[j]) % 10;
//  int valk = (value / powersOf10[k]) % 10;
//  int result = value - valj * powersOf10[j] - valk * powersOf10[k];
//  result = result + valk * powersOf10[j] + valj * powersOf10[k];
//  return result;
//}
//
//double matrix[120][121];
//int ind[120];
//double solution[120];
//double const eps = 1e-6;
//
//void showMatrix(int cnt)
//{
//  for(int i = 0; i < cnt; i++)
//  {
//    for(int j = 0; j <= cnt; j++)
//    {
//      printf("%.2f ", matrix[i][j]);
//    }
//    printf("\n");
//  }
//}
//
//void gauss(int cnt)
//{
//  for(int i = 0; i < cnt; i++)
//  {
//    ind[i] = i;
//  }
//  //Прямой ход
//  for(int i = 0; i < cnt; i++)
//  {
//    if(fabs(matrix[ind[i]][i]) < eps)//Если диагональный элемент равен нулю
//    {
//      for(int j = i + 1; j < cnt; j++)
//      {
//        if(fabs(matrix[ind[j]][i]) > eps)
//        {
//          swap(ind[i], ind[j]);
//          break;
//        }
//      }
//    }
//    if(fabs(1.0 - matrix[ind[i]][i]) > eps)//Если диагональный элемент 1.0
//    {
//      double val = matrix[ind[i]][i];
//      for(int j = i; j <= cnt; j++)
//      {
//        matrix[ind[i]][j] /= val;
//      }
//    }
//    for(int j = i + 1; j < cnt; j++)
//    {
//      if(fabs(matrix[ind[j]][i]) > eps)
//      {
//        double val = matrix[ind[j]][i];
//        for(int k = i; k <= cnt; k++)
//        {
//          matrix[ind[j]][k] -= matrix[ind[i]][k] * val;
//        }
//      }
//    }
//    /*printf("next:\n");
//    showMatrix(cnt);*/
//  }
//  //Обратный ход
//  for(int i = cnt - 1; i >= 0; i--)
//  {
//    solution[ind[i]] = 0;
//    for(int j = i + 1; j < cnt; j++)
//    {
//      solution[ind[i]] += matrix[ind[i]][j] * solution[ind[j]];
//    }
//    solution[ind[i]] = (matrix[ind[i]][cnt] - solution[ind[i]]) / matrix[ind[i]][i];
//  }
//}
//
//void Solve()
//{
//  permutationNumbers.clear();
//  permutations.clear();
//  genPermutations(m);
//  int intP = (m * (m - 1)) / 2;
//  memset(matrix, 0, sizeof(matrix));
//  int permCnt = permutations.size();
//  for(int i = 0; i < permCnt; i++)
//  {
//    matrix[i][i] = -intP;
//    if(permutations[i] == target)
//    {
//      matrix[i][permCnt] = 0;
//      continue;
//    }
//    matrix[i][permCnt] = -intP;
//    int current = permutations[i];
//    for(int j = 0; j < m; j++)
//    {
//      for(int k = j + 1; k < m; k++)
//      {
//        int swapped = swapNumbers(current, j, k);
//        //printf("good\n");
//        if(swapped != target)
//        {
//          matrix[i][permutationNumbers[swapped]] = 1;
//        }
//      }
//    }
//  }
//  gauss(permCnt);
//  /*for(int i = 0; i < permCnt; i++)
//  {
//    for(int j = 0; j <= permCnt; j++)
//    {
//      printf("%.2f ", matrix[i][j]);
//    }
//    printf("\n");
//  }*/
//}
//
//void WriteData()
//{
//  printf("%.25f\n", abs(solution[ind[permutationNumbers[inputPattern]]]));
//}
//
//int main()
//{
//  int QWE;
//  #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  //freopen("output.txt", "w", stdout);
//  scanf("%d", &QWE);
//  #else
//  QWE = 1;
//  #endif
//  for(int T = 0; T < QWE; T++)
//  {
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  return 0;
//}