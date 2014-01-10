#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

//#define DEBUG
//#define MULTITEST

int getPrior(char symb)
{
  switch(symb)
  {
  case '(':
    return 0;
  case ')':
    return  1;
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 3;
  default:
    return 1000;
  }
}

string exprToPolskNotation(string expr)
{
  string result = "";
  result.reserve(expr.length());
  stack<char> Q;
  for(string::iterator i = expr.begin(); i != expr.end(); i++)
  {
    int prior = getPrior(*i);
    switch(prior)
    {
    case 0:
      {
        Q.push('(');
        break;
      }
    case 1:
      {
        while((!Q.empty()) && (0 != getPrior(Q.top())))
        {
          result += Q.top();
          Q.pop();
        }
        Q.pop();
        break;
      }
    case 2:
    case 3:
      {
        while((!Q.empty()) && (prior <= getPrior(Q.top())))
        {
          result += Q.top();
          Q.pop();
        }
        Q.push(*i);
        break;
      }
    default:
      {
        result += *i;
        break;
      }
    }
  }
  while(!Q.empty())
  {
    result += Q.top();
    Q.pop();
  }
  return result;
}

bool checkForOutBracketsPlusMinus(string expr)
{
  int flag = 0;
  for(string::iterator i = expr.begin(); i != expr.end(); i++)
  {
    switch( *i )
    {
    case '(':
      {
        flag++;
        break;
      }
    case ')':
      {
        flag--;
        break;
      }
    case '+':
    case '-':
      {
        if(flag == 0)
          return true;
        else
          break;
      }
    }
  }
  return false;
}

void swapOperationsWhenBracketsOpen(string* expr)
{
  int flag = 0;
  for(int i = 0; i < expr->length(); i++)
  {
    switch( expr->at(i) )
    {
    case '(':
      {
        flag++;
        break;
      }
    case ')':
      {
        flag--;
        break;
      }
    case '*':
      {
        if(flag == 0)
          (*expr)[i] = '/';
        break;
      }
    case '/':
      {
        if(flag == 0)
          (*expr)[i] = '*';
        break;
      }
    }
  }
}

void swapOperationsWhenBracketsOpen2(string* expr)
{
  int flag = 0;
  for(int i = 0; i < expr->length(); i++)
  {
    switch( expr->at(i) )
    {
    case '(':
      {
        flag++;
        break;
      }
    case ')':
      {
        flag--;
        break;
      }
    case '+':
      {
        if(flag == 0)
          (*expr)[i] = '-';
        break;
      }
    case '-':
      {
        if(flag == 0)
          (*expr)[i] = '+';
        break;
      }
    }
  }
}

int main()
{
  ifstream strm("input.txt");
  int QWE;
#ifdef MULTITEST
  strm >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    string InStr;
    strm >> InStr;
    string polsk = exprToPolskNotation(InStr);
    stack<string> Q;
    char prev = polsk[0];
    for(string::iterator i = polsk.begin(); i != polsk.end(); i++)
    {
      int prior = getPrior(*i);
      string tmp(i, i + 1);
      if(prior == 1000)
      {
        Q.push(tmp);
      }
      else
      {
        string first = Q.top();
        Q.pop();
        string second = Q.top();
        Q.pop();
        switch(prior)
        {
        case 2:
          {
            if(tmp == "-")
            {
              swapOperationsWhenBracketsOpen2(&first);
            }
            second = second + tmp + first;
            break;
          }
        case 3:
          {
            bool flag = true;
            if((first.length() > 1) && (checkForOutBracketsPlusMinus(first)))
            {
              first = "(" + first + ")";
              flag = false;
            }
            if((second.length() > 1) && (checkForOutBracketsPlusMinus(second)))
            {
              second = "(" + second + ")";
            }
            if(tmp == "/" && flag)
            {
              swapOperationsWhenBracketsOpen(&first);
            }
            second = second + tmp + first;
            break;
          }
        }
        Q.push(second);
        prev = *i;
      }
    }
    cout << Q.top() <<endl;
#ifdef DEBUG
    cout << "Polskaia notacia: " << polsk << endl << endl;
#endif
  }
  return 0;
}