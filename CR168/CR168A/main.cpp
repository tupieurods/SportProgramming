#include <stdio.h>

using namespace std;
/*
Govnokod
da ia mudak kotoromu vlom delat matricu perehodov
*/
int main()
{
  bool** data = new bool*[3];
  for(int i = 0; i < 3; i++)
  {
    data[i] = new bool[3];
    for(int j = 0; j < 3; j++)
    {
      data[i][j] = true;
    }
  }
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      int t;
      scanf("%d", &t);
      if((t % 2) == 0)
        continue;
      int current = i * 3 + j + 1;
      data[i][j] = !data[i][j];
      switch(current)
      {
        case 1:
        {
          data[i + 1][j] = !data[i + 1][j];
          data[i][j+1] = !data[i][j+1];
          break;
        }
        case 2:
        {
          data[i + 1][j] = !data[i + 1][j];
          data[i][j+1] = !data[i][j+1];
          data[i][j-1] = !data[i][j-1];
          break;
        }
        case 3:
        {
          data[i + 1][j] = !data[i + 1][j];
          data[i][j-1] = !data[i][j-1];
          break;
        }
        case 4:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i + 1][j] = !data[i + 1][j];
          data[i][j+1] = !data[i][j+1];
          break;
        }
        case 5:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i + 1][j] = !data[i + 1][j];
          data[i][j+1] = !data[i][j+1];
          data[i][j-1] = !data[i][j-1];
          break;
        }
        case 6:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i + 1][j] = !data[i + 1][j];
          data[i][j-1] = !data[i][j-1];
          break;
        }
        case 7:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i][j+1] = !data[i][j+1];
          break;
        }
        case 8:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i][j+1] = !data[i][j+1];
          data[i][j-1] = !data[i][j-1];
          break;
        }
        case 9:
        {
          data[i - 1][j] = !data[i - 1][j];
          data[i][j-1] = !data[i][j-1];
          break;
        }
      }
    }
  }
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%d", (int)data[i][j]);
    }
    printf("\n");
  }
  return 0;
}
