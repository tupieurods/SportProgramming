#include <stdio.h>
#include <stdlib.h>

//using namespace std;

static int CountOnes(int x)
{
  unsigned int result = x;
  result = (result & 0x55555555)+(( result & 0xAAAAAAAA) >> 1);
  result = (result & 0x33333333)+(( result & 0xCCCCCCCC) >> 2);
  result = (result & 0x0F0F0F0F)+(( result & 0xF0F0F0F0) >> 4);
  result = (result & 0x00FF00FF)+(( result & 0xFF00FF00) >> 8);
  result = (result & 0x0000FFFF)+(( result & 0xFFFF0000) >> 16);
  return (int)result;
}

int main()
{
  char buff[33];
  for(int i = 500; i < 520; i++)
  {
    itoa(i,buff,2);
    printf("%s %d %d\n", buff, i,CountOnes(i));
  }
  return 0;
}