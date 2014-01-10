#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
  int n;
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    string str;
    getline(std::cin, str);
    int currAnswer;
    bool Rflag = false;
    bool Fflag = false;
    if(str.length() < 5)
      currAnswer = 2;
    else
    {
      if(str.substr(0, 5) == "miao.")
        Rflag = true;
      if(str.substr(str.size() - 5, 5) == "lala.")
        Fflag = true;
      if((Rflag && Fflag) || (!Rflag && !Fflag))
        currAnswer = 2;
      else if(Rflag)
        currAnswer = 1;
      else if(Fflag)
        currAnswer = 0;
      else
        throw;
    }
    switch(currAnswer)
    {
      case 0:
        cout << "Freda's" << endl;
        break;
      case 1:
        cout << "Rainbow's" << endl;
        break;
      case 2:
        cout << "OMG>.< I don't know!" << endl;
        break;
    }
  }
  return 0;
}
