#include <iostream>
#include <time.h>
#include <unordered_set>
#include <functional>

int main() {
  if(!true)
  {
     freopen("input.txt", "w", stdout);
     for(int i = 1; i <= 50000; i++)
     {
        long long tmp = (long long)i << 32;
        printf("%I64d ", tmp | i);
     }
  }
  else
  {
    freopen("input.txt", "r", stdin);
    //freopen("bench.txt", "w", stdout);
    clock_t t = clock();
    long long tmp;
    std::tr1::unordered_set<long long> hashset;
    int idx = 0;
    int j = 0;
    while (std::cin >> tmp)
    {
      hashset.insert(tmp);
      if(idx == 50000)
      {
        t = clock() - t;
        printf ("%d: It took me %d clicks. %f\n", j, t, ((float)t)/CLOCKS_PER_SEC);
        idx = 0;
        hashset.clear();
        t = clock();
        j++;
      }
      idx++;
    }
    printf ("%d: It took me %d clicks. %f\n", j, t, ((float)t)/CLOCKS_PER_SEC);
    printf("%d: done\n", idx);
  }
  return 0;
}
