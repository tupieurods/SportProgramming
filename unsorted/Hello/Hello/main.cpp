#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  cout<<"Hello World!\n"<<cos(1.0)<<"\n";
  cout<<min(5,6)<<"\n";
  system("PAUSE");
  return 0;
}

int min(int val1, int val2)
{
  return val1>val2 ? val2 : val1;
}