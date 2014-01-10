#include <map>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>

using namespace std;

string ToStr(int value)
{
  stringstream StrStream;
  StrStream << value;
  return StrStream.str();
}

int main()
{
  int n;
  scanf("%d", &n);
  map<string, int> db;
  //string *anwser=new string[n+1];
  string tmp;
  for(int i = 0; i <= n; i++)
    {
      tmp="";
      getline(std::cin, tmp);
      if(i==0)
        continue;
      if(!db.count(tmp))
        {
          db.insert(make_pair(tmp, 1));
          //anwser[i]="OK";
          printf("OK\n");
        }
      else
        {
          //anwser[i]=tmp+ToStr(db[tmp]);
          printf("%s%d\n", tmp.c_str(), db[tmp]);
          db[tmp]++;
        }
    }
  /*for(int i = 1; i <= n; i++)
  {
    printf("%s\n",anwser[i].c_str());
  } */
  return 0;
}
