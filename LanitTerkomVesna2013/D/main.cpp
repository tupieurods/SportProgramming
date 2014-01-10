#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//0-top, 1-right, 2-down, 3-left

int *table;
string *a;
int w, h;

bool GetFlag(unsigned char c, int p)
{
  if(c == ' ')
    return false;
  return (table[(int)c] & (1 << p)) != 0;
}

unsigned char GetCharFromArr(int row, int column)
{
  if(row < 0 || row >= h || column < 0 || column >= w)
    return ' ';
  return (unsigned char)a[row][column];
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> h >> w;
  a = new string[h];
  getline(cin, a[0]);
  for(int i = 0; i < h; i++)
  {
    getline(cin, a[i]);
    //cout << (int)((unsigned char)a[i][0]) << endl;
    //cout << a[i] << endl;
  }
  //Лень маленькую таблицу заводить, у нас аж 64 мегабайта
  table = new int[219];
  table[32] = 0;
  table[179] = 5;
  table[180] = 13;
  table[191] = 12;
  table[192] = 3;
  table[193] = 11;
  table[194] = 14;
  table[195] = 7;
  table[196] = 10;
  table[197] = 15;
  table[217] = 9;
  table[218] = 6;
  int cnt = 0;
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      if(a[i][j] == ' ')
      {
        cnt++;
        continue;
      }
      if(!(GetFlag(a[i][j], 0) == GetFlag(GetCharFromArr(i - 1, j), 2)
            && GetFlag(a[i][j], 1) == GetFlag(GetCharFromArr(i, j + 1), 3)
            && GetFlag(a[i][j], 2) == GetFlag(GetCharFromArr(i + 1, j), 0)
            && GetFlag(a[i][j], 3) == GetFlag(GetCharFromArr(i, j - 1), 1)))
      {
        /*cout << (GetFlag(a[i][j], 0) == GetFlag(GetCharFromArr(i - 1, j), 2)) << endl;
        cout << (GetFlag(a[i][j], 1) == GetFlag(GetCharFromArr(i, j + 1), 3)) << endl;
        cout << (GetFlag(a[i][j], 2) == GetFlag(GetCharFromArr(i + 1, j), 0)) << endl;
        cout << (GetFlag(a[i][j], 3) == GetFlag(GetCharFromArr(i, j - 1), 1)) << endl;*/
        cout << "UGLY" << endl;
        return 0;
      }
    }
  }
  if(cnt == h * w)
    cout << "UGLY" << endl;
  else
    cout << "BEAUTIFUL" << endl;
  return 0;
}