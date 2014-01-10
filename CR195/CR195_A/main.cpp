#include <stdio.h>
#include <algorithm>

using namespace std;

inline __int64 myAbs(__int64 value)
{
  return value < 0 ? -value : value;
}

int main()
{
  __int64 xPos, yPos;
  scanf("%I64d %I64d", &xPos, &yPos);
  __int64 xPosAbs = myAbs(xPos);
  __int64 yPosAbs = myAbs(yPos);
  pair<__int64, __int64> dotA = make_pair(0, xPosAbs + yPosAbs);
  pair<__int64, __int64> dotB = make_pair(xPosAbs + yPosAbs, 0);
  if(xPos > 0 && yPos < 0)
  {
    dotA.second = -dotA.second;
  }
  if(xPos < 0)
  {
    swap(dotA, dotB);
    dotA.first = -dotA.first;
    if(yPos < 0)
    {
      dotB.second = -dotB.second;
    }
  }
  printf("%I64d %I64d %I64d %I64d\n", dotA.first, dotA.second, dotB.first, dotB.second);
  return 0;
}