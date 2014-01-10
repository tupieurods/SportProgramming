#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string input;
int n;
string arr[100009];

void ReadData()
{
  cin >> n;
  int i = 0;
  while(cin >> arr[i])
    i++;
  n = i;
}

string answer;
int position;
bool fail;

void f()
{
  if(position >= n)
  {
    fail = true;
    return;
  }
  if(arr[position] == "int")
  {
    position++;
    answer += "int";
  }
  else
  {
    position++;
    answer += "pair<";
    f();
    answer += ",";
    f();
    answer += ">";
  }
}

void Solve()
{
  position = 0;
  answer = "";
  fail = false;
  f();
  if(fail || position != n)
    answer = "Error occurred";
}

void WriteData()
{
  cout << answer << endl;
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}