#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <string.h>

using namespace std;
using namespace std::tr1;

char blocks[9][4];
unordered_map<int, double> cache;

vector< int* > getConfigurations(int* current,double* prec)
{
  int count = 0;
  vector< int* > result;
  for(int i = 0; i < 9; i++)
  {
    if(current[i] == -1)
      continue;
    for(int j = i + 1; j < 9; j++)
    {
      if(current[j] == -1)
        continue;
      if(blocks[i][current[i]] == blocks[j][current[j]])
      {
        count++;
        int* newConfiguration = new int[9];
        memcpy(newConfiguration, current, sizeof(int) * 9);
        newConfiguration[i]--;
        newConfiguration[j]--;
        result.push_back(newConfiguration);
      }
    }
  }
  *prec = 1 / (double)count;
  return result;
}

double f(int* arr)
{
  /*if(cache.size() > 900000)
    cout<<"ALARM!";*/
  int sumMinusOne = 0;
  int cacheValue = 0;
  for(int i = 0; i < 9; i++)
  {
    if(arr[i] == -1)
      sumMinusOne++;
    //cacheValue += (arr[i] + 1) * (1<<(i+));
    cacheValue = cacheValue*8+arr[i]+1;///(arr[i] + 1) * (1<<(i+));
  }
  if(sumMinusOne == 9)
      return 1;
  if(cache.count(cacheValue) == 0)
  {
    double prec;
    vector< int* > configurations = getConfigurations(arr, &prec);
    double result = 0;
    for(vector< int* >::iterator i = configurations.begin(); i != configurations.end(); i++)
    {
      result += prec * f((*i));
      delete (*i);
    }
    cache.insert(make_pair(cacheValue, result));
  }
  return cache[cacheValue];
}

int main()
{
  fstream strm("input.txt");
  int* arr = new int[9];
  for(int i = 0; i < 9; i++)
  {
    char line[12];
    strm.getline(line,12);
    blocks[i][0] = line[0];
    blocks[i][1] = line[3];
    blocks[i][2] = line[6];
    blocks[i][3] = line[9];
    arr[i] = 3;
  }
  cout << setprecision(7) << f(arr) << endl;
  return 0;
}