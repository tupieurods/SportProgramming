#include <iostream>

using namespace std;

//Если это решение пройдёт.
//И его кто-то читает
//Да я знаю что это говнокод
//Но это первое что пришлом мне в голову
int main()
{
  //строка столбец
  int** data = new int*[3];
  for(int i = 0; i < 3; i++)
  {
    data[i] = new int[3];
    for(int j = 0; j < 3; j++)
    {
      cin >> data[i][j];
    }
  }
  for(int i = 1; i <= 100000; i++)
  {
    int sum = data[1][0] + i + data[1][2];
    bool flag = false;
    //Крест сходится
    if(sum == (data[0][1] + i + data[2][1]))
    {
      //Второстепенная диагональ сходится
      if(sum == data[2][0] + i + data[0][2])
      {
        int a = sum - (data[2][0] + data[1][0]);
        int c = sum - (data[0][2] + data[1][2]);
        //Правый и левый столбцы сходятся
        if((a > 0) && (c > 0))
        {
          //Главная диагональ сходится
          if((a + c + i) == sum)
          {
            if((a <= 100000) && (c <= 100000))
            {
              //Верхняя и нижняя сходятся
              if(((a + data[0][1] + data[0][2]) == sum)
                  && ((c + data [2][0] + data[2][1]) == sum))
              {
                data[1][1] = i;
                data[0][0] = a;
                data[2][2] = c;
                flag = true;
              }
            }
          }
        }
      }
    }
    if(flag)
      break;
  }
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
