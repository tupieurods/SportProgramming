#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits.h>
#include <queue>
#include <stack>

#define LOCALTEST

using namespace std;

int m, n;//число строк, число столбцов
string** cells;
double** answerCells;
int** colorCells;

/*
for(int i = 0; i < m; i++)
{
for(int j = 0; j < n; j++)
{

}
}
*/

void dfsVisit(int, int);

int getPrior(char elem)
{
  switch(elem)
  {
  case '+': return 2;
  case '-': return 2;
  case '*': return 3;
  case '/': return 3;
  case '!': return 9000;
  case '(': return 0;
  case ')': return 1;
  default: return -1;
  }
}

double calc(string& expr)//Высчитывает значение в ячейке
{
  int len = expr.length();
  deque<double> numbers;
  stack<double> operators;
  string calcOperators = "";
  for(int i = 0; i < len;)
  {
    int prior = getPrior(expr[i]);
    switch(prior)
    {
    case 0:
      {
        operators.push(expr[i]);
        i++;
        break;
      }
    case 2:
      {
        while((!operators.empty()) && (getPrior(operators.top()) >= prior))
        {
          calcOperators += operators.top();
          operators.pop();
        }
        if(i == 0 || abs(getPrior(expr[i - 1])) != 1)
        {
          if(expr[i] == '-')
          {
            operators.push('!');
          }
          else
          {
            //По идее ничего
          }
        }
        else
        {
          operators.push(expr[i]);
        }
        i++;
        break;
      }
    case 3:
      {
        while((!operators.empty()) && (getPrior(operators.top()) >= prior))
        {
          calcOperators += operators.top();
          operators.pop();
        }
        operators.push(expr[i]);
        i++;
        break;
      }
    case 1:
      {
        while(operators.top() != '(')
        {
          calcOperators += operators.top();
          operators.pop();
        }
        operators.pop();
        i++;
        break;
      }
    default:
      {
        double toAdd = 0;
        if(expr[i] == '{')
        {
          i++;
          int row = 0;
          while(expr[i] != ',')
          {
            row = row * 10 + (double)(expr[i] - '0');
            i++;
          }

          i++;
          int column = 0;
          while(expr[i] != '}')
          {
            column = column * 10 + (double)(expr[i] - '0');
            i++;
          }
          i++;
          if(colorCells[row - 1][column - 1] == 1)
            return 1e100;
          dfsVisit(row - 1, column - 1);
          if(colorCells[row - 1][column - 1] == 2)
          {
            return 1e100;
          }
          toAdd = answerCells[row - 1][column - 1];
        }
        else
        {
          while(i < len && expr[i] >= '0' && expr[i] <= '9')
          {
            toAdd = toAdd * 10 + (double)(expr[i] - '0');
            i++;
          }
        }
        numbers.push_back(toAdd);
        calcOperators += '|';
        if(toAdd == 1e100)
        {
          return 1e100;
        }
        break;
      }
    }
  }
  while(!operators.empty())
  {
    calcOperators += operators.top();
    operators.pop();
  }
  len = calcOperators.length();
  stack<double> calcNumbers;
  int currentNumber = 0;
  for(int i = 0; i < len; i++)
  {
    double left = 1e50;
    double right = 1e50;
    if(calcOperators[i] == '|')
    {
      calcNumbers.push(numbers[currentNumber++]);
      continue;
    }
    else if(calcOperators[i] == '!')
    {
      right = -calcNumbers.top();
      calcNumbers.pop();
    }
    else
    {
      right = calcNumbers.top();
      calcNumbers.pop();
      if(!calcNumbers.empty())
      {
        left = calcNumbers.top();
        calcNumbers.pop();
      }
    }
    switch(calcOperators[i])
    {
    case '+':
      {
        right = right + left;
        break;
      }
    case '*':
      {
        right = right * left;
        break;
      }
    case '/':
      {
        if(right == 0)
        {
          return 1e100;
        }
        right = left / right;
        break;
      }
    case '-':
      {
        right = -right + left;
        break;
      }
    }
    calcNumbers.push(right);
  }
  //printf("%s\n", calcOperators.c_str());
  return calcNumbers.top();
}

void dfs()
{
  answerCells = new double*[m];
  colorCells = new int*[m];
  for(int i = 0; i < m; i++)
  {
    answerCells[i] = new double[n];
    colorCells[i] = new int[n];
    memset(colorCells[i], 0, sizeof(int) * n);
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(colorCells[i][j] == 0)
        dfsVisit(i, j);
    }
  }
}

void dfsVisit(int row, int column)
{
  if(colorCells[row][column] != 0)
  {
    return;
  }
  colorCells[row][column] = 1;
  double result = calc(cells[row][column]);
  colorCells[row][column] = result == 1e100 ? 2 : 3;
  answerCells[row][column] = result;
}

void removeSpaces(string& current, int row)
{
  int pos = 0;
  string elem = "";
  int len = current.length();
  for(int i = 0; i < len; i++)
  {
    if(current[i] == ' ')
      continue;
    if(current[i] == '|')
    {
      cells[row][pos++] = elem;
      elem = "";
    }
    else
    {
      elem += current[i];
    }
  }
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d\n", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d %d\n", &m, &n);
    string current;
    cells = new string*[m];
    for(int i = 0; i < m; i++)
    {
      cells[i] = new string[n];
      getline(std::cin, current);
      current += "|";
      removeSpaces(current, i);
      //printf("%s\n", current.c_str());
    }
    //Тест обр польской записи
    //current = "1+3*4-7*(0-123*(-1))+4";
    //current = "(31+5)/(4-2/(-1))-7";
    //current = "7";
    //printf("%f\n", calc(current));
    /*for(int i = 0; i < m; i++)
    {
    for(int j = 0; j < n; j++)
    {
    printf("%s\t", cells[i][j].c_str());
    }
    printf("\n");
    }*/
    dfs();
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(answerCells[i][j] == 1e100)
        {
          printf(" - ");
        }
        else
        {
          printf("%f ", answerCells[i][j]);
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}