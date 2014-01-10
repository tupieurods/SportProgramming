#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
  for(int T = 1; T <= 31; T++)
  {
    char str[7];
    sprintf(str,"%.2d",T);
    //cout << str << endl;
    ifstream strm(str);
    //fstream strm("input.txt");
    int QWE = 1;
    /*for(int T = 0; T < QWE; T++)
    {*/
    int w, h;
    strm >> h >> w;
    double result = 0;
    for(int i = 0; i < h; i++)
    {
      bool inPloygon = false;
      for(int j = 0; j < w; j++)
      {
        char symb;
        strm >> symb;
        switch(symb)
        {
        case '/':
          {
            inPloygon = !inPloygon;
            //inPloygon++;
            result += 0.5;
            break;
          }
        case '\\':
          {
            inPloygon = !inPloygon;
            //inPloygon--;
            result += 0.5;
            break;
          }
        case '.':
          {
            if(inPloygon)
              result++;
            break;
          }
        }
      }
    }
    strm.close();
    sprintf(str,"%.2d.a",T);
    ofstream cout(str);
    cout << (int)ceil(result) << endl;
    cout.close();
    //}
  }
  return 0;
}