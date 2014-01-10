#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<__int64> sums;
vector<__int64> elems;

__int64 getSum(int start, int finish)
{
  if(start==1)
    return sums[finish - 1];
  return sums[finish - 1] - sums[start-2];
}

int main()
{
  ifstream strm("input.txt");
  int n;
  strm>>n;
  __int64 sum=0;
  for(int i=0; i<n; i++)
  {
    __int64 tmp;
    strm>>tmp;
    sum += tmp;
    sums.push_back(sum);
    cout<<sums[i]<<endl;
    elems.push_back(tmp);
  }
  //cout<<getSum(2,6)<<endl;
  return 0;
}