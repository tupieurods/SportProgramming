#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct element
{
  int pos;
  int volume;
};

string toStr(int value)
{
  std::stringstream strStream;
  strStream << value;
  return strStream.str();
}

bool elementCompare(const element first, const element second)
{
  return(first.volume < second.volume);
}

vector<element> boats;
vector<element> katamarans;

void RemoveLastFromBoats(int &v, int &count, string &anwser)
{
  v--;
  count += boats[boats.size()-1].volume;
  anwser += toStr(boats[boats.size()-1].pos) + "\n";
  boats.pop_back();
}

int main()
{
  int n, v;
  scanf("%d %d", &n, &v);
  for(int i = 1; i <= n; i++)
    {
      int tmpT, tmpP;
      scanf("%d %d", &tmpT, &tmpP);
      if(tmpT == 1)
        boats.push_back( {i, tmpP});
      else
        katamarans.push_back( {i, tmpP});
    }
  sort(boats.begin(), boats.end(), elementCompare);
  sort(katamarans.begin(), katamarans.end(), elementCompare);
  int count = 0;
  string anwser = "";
  if(v % 2 != 0 && !boats.empty())
    RemoveLastFromBoats(v, count, anwser);
  while(true)
    {
      if(v == 0
          || (v == 1 && boats.empty())
          || (katamarans.empty() && boats.empty()))
        break;
      if(katamarans.empty() || v == 1)
        {
          RemoveLastFromBoats(v, count, anwser);
        }
      else
        {
          //v >= 2
          int boatsVolume = boats.empty() ? 0
                            : boats.size() > 1 ? boats[boats.size()-1].volume + boats[boats.size()-2].volume
                            : boats[boats.size()-1].volume;
          if(katamarans[katamarans.size()-1].volume > boatsVolume)
            {
              v -= 2;
              count += katamarans[katamarans.size()-1].volume;
              anwser += toStr(katamarans[katamarans.size()-1].pos) + "\n";
              katamarans.pop_back();
            }
          else
            {
              RemoveLastFromBoats(v, count, anwser);
              if(!boats.empty())
                RemoveLastFromBoats(v, count, anwser);
            }
        }
    }
  printf("%d\n%s", count, anwser.c_str());
  return 0;
}
