#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  string *PwdCommandResults = new string[n+1];
  string CurrentDirectory = "";
  for (int i = 0; i <= n; i++)
    {
      PwdCommandResults[i] = "";
      string Line;
      getline(std::cin,Line);
      size_t result = Line.find("pwd");
      if (result != string::npos)//pwd
        {
          PwdCommandResults[i] = CurrentDirectory + "/";
        }
      else//cd
        {
          //Line.erase(0,Line.find(" ")+1);
          string path = Line.substr(Line.find(" ") + 1);
          if (path[0] == '/')
            {
              CurrentDirectory = "";
              path = path.substr(1);
            }
          if(path.empty())
            continue;
          path = path + "/";
          string Tmp;
          while (!path.empty())
            {
              Tmp = path.substr(0, path.find("/"));
              if (Tmp == "..")
                {
                  CurrentDirectory = CurrentDirectory.substr(0, CurrentDirectory.find_last_of("/"));
                }
              else
                {
                  CurrentDirectory = CurrentDirectory + "/" + Tmp;
                }
              path = path.substr(path.find("/") + 1);
            }
        }
    }
  for (int i = 0; i <= n; i++)
    {
      if (PwdCommandResults[i] != "")
        printf("%s\n", PwdCommandResults[i].c_str());
    }
}
