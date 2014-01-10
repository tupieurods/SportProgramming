#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int m;
string str;

void ReadData()
{
  cin >> str;
  cin >> m;
}

int *arr;
void Solve()
{
  int n = str.length();
  arr = new int[n];
  memset(arr, 0, sizeof(int) * n);
  for(int i = 1; i < n; i++)
  {
    if(str[i] == str[i -1 ])
    {
      arr[i] = 1 + arr[i - 1];
    }
    else
    {
      arr[i] = arr[i - 1];
    }
    //printf("%d ", arr[i]);
  }
  for(int i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    cout << arr[r - 1] - arr[l - 1] << "\n";
  }
}

void WriteData()
{
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}