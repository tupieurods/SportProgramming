#include <stdio.h>
#include <strings.h>
#include <string>

using namespace std;

#define LEN 524288

int main()
{
  int n;
  scanf("%d", &n);
  bool checkArr[LEN];
  memset(checkArr, 0, sizeof(bool)*LEN);
  bool* data = new bool[n];
  getchar();//Чтобы wtf не выводился
  for(int i = 0; i < n; i++)
  {
    char c;
    scanf("%c", &c);
    if(c == 'a')
      data[i] = false;
    else if(c == 'b')
      data[i] = true;
    else
      printf("wtf");
  }
  int maximal = n < 19 ? n : 19;
  for(int i = 1; i <= maximal; i++)
  {
    unsigned int w = 0;
    for(int j = 1; j <= i; j++)
    {
      w <<= 1;
      if(data[j-1])
        w |= 1;
    }
    for(int j = 0; j < n - i + 1; j++)
    {
      //printf("%d ",w);
      checkArr[w] = true;
      w <<= 1;
      w &= (~(1 << i));
      if(data[j+i])
        w |= 1;
    }
    //printf("%d\n",1<<i);
    for(int j = 0; j < (1 << i); j++)
    {
      if(checkArr[j] == false)
      {
        printf("%d\n", i);
        string anwser = "";
        for(int k = 0; k < i; k++)
        {
          if((j & 1) == 1)
            anwser = 'b' + anwser;
          else
            anwser = 'a' + anwser;
          j >>= 1;
        }
        printf("%s", anwser.c_str());
        return 0;
      }
    }
    //printf("Go Next\n");
    memset(checkArr, 0, sizeof(bool)*LEN);
  }
  return 0;
}
