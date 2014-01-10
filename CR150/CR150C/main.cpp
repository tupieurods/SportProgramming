#include <set>
#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
    set<__int64> test;
    for(__int64 i = 0; i < 1000000; i++)
    {
      test.insert(i);
    }
    printf("%I64d",(__int64)test.size());
    return 0;
}
