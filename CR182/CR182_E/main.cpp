#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Передвижение
  for(int i = 0; i < 10; i++)//10
  {
    printf("??%d>>%d??\n", i, i);
  }
  //Дошли до конца
  printf("??>>?\n");//1
  printf("?0?<>\n");//1
  printf("9?1?0>>?1?00\n");
  for(int i = 0; i < 9; i++)
  {
    printf("%d?1?>>?0?%d\n", i, i + 1);
  }
  printf("?1?0<>10\n");
  for(int i = 0; i < 9; i++)//8
  {
    printf("%d?>>?0?%d\n", i, i + 1);
  }
  printf("9?>>?1?0\n");//1
  //Первичная постановка
  for(int i = 0; i < 10; i++)//10
  {
    printf("%d>>??%d\n", i, i);
  }
  return 0;
}