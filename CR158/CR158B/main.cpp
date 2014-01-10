#include <iostream>
#include <string>
#include <map>

using namespace std;

int getDaysInMonth(int month)
{
  month--;
  if(month == 1)
    return 28;
  return 31 - (month % 7) % 2;
}

bool check(string &value, int start)
{
  int day = 0, month = 0, year = 0;
  for(int i = 0; i < 10; i++)
  {
    if((i == 2) || (i == 5))
    {
      if(value[start + i] != '-')
        return false;
    }
    else if(value[start + i] == '-')
        return false;
  }
  year = (value[start + 6] - '0') * 1000 + (value[start + 7] - '0') * 100
    + (value[start + 8] - '0') * 10 + (value[start + 9] - '0');
  if(!((year >= 2013) && (year <= 2015)))
    return false;
  month = (value[start + 3] - '0') * 10 + (value[start + 4] - '0');
  if(!((month >=1) && (month <= 12)))
    return false;
  day = (value[start] - '0') * 10 + (value[start + 1] - '0');
  if(!((day >= 1) && (day <= getDaysInMonth(month))))
    return false;
  return true;
}

int main()
{
  string in;
  cin >> in;
  int biggest = 0;
  string anwser;
  map<string, int> dict;
  int len = in.size() - 9;
  map<string, int>::iterator it;
  for(int i = 0; i < len; i++)
  {
    if(check(in, i))
    {
      string tmp(in, i, 10);
      //cout << tmp << endl;
      it = dict.find(tmp);
      int count = 1;
      if(it != dict.end())
      {
        count = ++(it->second);
      }
      else
      {
        dict.insert(make_pair(tmp, 1));
      }
      if(count > biggest)
      {
        biggest = count;
        anwser = tmp;
      }
    }
  }
  cout << anwser;
  return 0;
}
