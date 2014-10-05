#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[2][109];

void ReadData()
{
  scanf("%s%*c", str[0]);
  scanf("%s%*c", str[1]);
}

double _x, _y;
char wstr[109];
int wstrL;

//result.first - free
//result.second.first - x
//result.second.second - y
pair<double, pair<double, double>> parse(int l, int r)
{
  pair<double, pair<double, double>> result = make_pair(0, make_pair(0, 0));
  int shit = 0;
  int mul = 0;
  int _sign = 1;
  for(int i = l; i < r; i++)
  {
    if(wstr[i] == '(')
    {
      int idx = i;
      int shit = 0;
      while(true)
      {
        if(wstr[idx] == '(')
        {
          shit++;
        }
        else if(wstr[idx] == ')')
        {
          shit--;
          if(shit == 0)
          {
            if(i == l || !(wstr[i - 1] >= '0' && wstr[i - 1] <= '9'))
            {
              mul = 1;
            }
            pair<double, pair<double, double>> current = parse(i + 1, idx);
            result.first += _sign * mul * current.first;
            result.second.first += _sign * mul * current.second.first;
            result.second.second += _sign * mul * current.second.second;
            mul = 0;
            i = idx;
            _sign = 1;
            break;
          }
        }
        idx++;
      }
    }
    else if(shit == 0)
    {
      //fuck switch and case
      if(wstr[i] == 'x')
      {
        if(i == l || !(wstr[i - 1] >= '0' && wstr[i - 1] <= '9'))
        {
          result.second.first += _sign;
        }
        else
        {
          result.second.first += _sign * mul;
        }
        mul = 0;
        _sign = 1;
      }
      else if(wstr[i] == 'y')
      {
        if(i == l || !(wstr[i - 1] >= '0' && wstr[i - 1] <= '9'))
        {
          result.second.second += _sign;
        }
        else
        {
          result.second.second += _sign * mul;
        }
        mul = 0;
        _sign = 1;
      }
      else if(wstr[i] == '+')
      {
        if(mul != 0)
        {
          result.first += _sign * mul;
          mul = 0;
        }
        _sign = 1;
      }
      else if(wstr[i] == '-')
      {
        if(mul != 0)
        {
          result.first += _sign * mul;
          mul = 0;
        }
        _sign = -1;
      }
      else//number
      {
        mul = mul * 10 + (wstr[i] - '0');
      }
    }
  }
  if(mul != 0)
  {
    result.first += _sign * mul;
  }
  return result;
}

void Solve()
{
  _x = _y = 0;
  //first
  int l1 = strlen(str[0]);
  int zpos = 0;
  for(; zpos < l1; zpos++)
  {
    if(str[0][zpos] == '=')
    {
      break;
    }
  }
  memset(wstr, 0, sizeof(wstr));
  memcpy(wstr, str[0], sizeof(char) * zpos);
  wstrL = strlen(wstr);
  //printf("!");
  pair<double, pair<double, double>> p1 = parse(0, wstrL);
  //printf("p1: %lf %lf %lf\n", p1.first, p1.second.first, p1.second.second);
  memset(wstr, 0, sizeof(wstr));
  memcpy(wstr, str[0] + zpos + 1, sizeof(char) * (l1 - zpos - 1));
  wstrL = strlen(wstr);
  pair<double, pair<double, double>> p2 = parse(0, wstrL);
  //printf("p2: %lf %lf %lf\n", p2.first, p2.second.first, p2.second.second);

  //second
  int l2 = strlen(str[1]);
  zpos = 0;
  for(; zpos < l2; zpos++)
  {
    if(str[1][zpos] == '=')
    {
      break;
    }
  }
  memset(wstr, 0, sizeof(wstr));
  memcpy(wstr, str[1], sizeof(char) * zpos);
  wstrL = strlen(wstr);
  //printf("!");
  pair<double, pair<double, double>> p3 = parse(0, wstrL);
  //printf("p3: %lf %lf %lf\n", p3.first, p3.second.first, p3.second.second);
  memset(wstr, 0, sizeof(wstr));
  memcpy(wstr, str[1] + zpos + 1, sizeof(char) * (l2 - zpos - 1));
  wstrL = strlen(wstr);
  pair<double, pair<double, double>> p4 = parse(0, wstrL);
  //printf("p4: %lf %lf %lf\n", p4.first, p4.second.first, p4.second.second);

  //first
  p1.first -= p2.first;
  p1.second.first -= p2.second.first;
  p1.second.second -= p2.second.second;

  //second
  p3.first -= p4.first;
  p3.second.first -= p4.second.first;
  p3.second.second -= p4.second.second;
  /*printf("p1: %lf %lf %lf\n", p1.first, p1.second.first, p1.second.second);
  printf("p3: %lf %lf %lf\n", p3.first, p3.second.first, p3.second.second);*/

  p1.first *= -1;
  p3.first *= -1;
  double a1 = p1.second.first;
  double a2 = p3.second.first;
  double b1 = p1.second.second;
  double b2 = p3.second.second;
  double d = a1 * b2 - a2 * b1;
  double c1 = p1.first;
  double c2 = p3.first;
  double d1 = c1 * b2 - c2 * b1;
  _x = d1 / d;
  double d2 = a1 * c2 - a2 * c1;
  _y = d2 / d;
}

void WriteData()
{
  printf("%lf\n%lf\n", _x, _y);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}