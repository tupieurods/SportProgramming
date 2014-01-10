#include <iostream>
#include <string>
#include <fstream>
//#include <vector>
#include <set>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int* parse(string ip)
{
  int current = 0;
  int* result=new int[4];
  memset(result,0,sizeof(int)*4);
  for(unsigned int i=0; i<ip.size(); i++)
  {
    if(ip[i]!='.')
      result[current]=result[current]*10+(int)(ip[i]-'0');
    else
      current++;
  }
  return result;
}

bool isBitOn(int value, int pos)
{
  return ((value >> (pos - 1)) & 1) == 1;
}

unsigned int generateBitMap(int* ip)
{
  unsigned int result=0;
  for(int i=0; i<4; i++)
  {
    for(int j=8; j>=1; j--)
    {
      result <<= 1;
      if(isBitOn(ip[i],j))
        result |= 1;
    }
  }
  return result;
}

int getOutResult(int value,int n)
{
  if(n==32)
    return 0;
  return (value &(~((1<<n)-1)));
}

int main()
{
  ifstream strm("input.txt");
  int n;
  strm >> n;
  int maximal[4]={0,0,0,0};
  set<string> ips;
  set<int> bitmaps;
  for(int i = 0; i < n; i++)
  {
    string tmp;
    strm>>tmp;
    int* ipAdr=parse(tmp);
    bitmaps.insert(generateBitMap(ipAdr));
    ips.insert(tmp);
    for(int j=0; j<4; j++)
    {
      maximal[j] = max(maximal[j],ipAdr[j]);
    }
  }
  int AnyIp;
  int pos=32;
  for(; pos>=0; pos--)
  {
    int sum=0;
    for(set<int>::iterator j=bitmaps.begin(); j!=bitmaps.end(); j++)
    {
      AnyIp=*j;
      if(isBitOn(*j,pos))
        sum++;
    }
    if(sum!=bitmaps.size() && sum!=0)
      break;
  }
  if(pos==-1)
  {
    set<string>::iterator it=ips.begin();
    cout<<*it<<endl;
    cout<<"255.255.255.255"<<endl;
    return 0;
  }
  int current=3;
  int* mask=new int[4];
  int tmpPos=pos;
  while(pos/8!=0)
  {
    pos -= 8;
    mask[current]=0;
    current--;
  }
  mask[current]=256-(1<<pos);
  current--;
  for(int i=0; i<=current; i++)
  {
    mask[i]=255;
  }
  int* ipMinimal=new int[4];
  memset(ipMinimal,0,16);
  int tmp=getOutResult(AnyIp,tmpPos);
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<8; j++)
    {
      ipMinimal[i] <<= 1;
      if(isBitOn(tmp,32-i*8-j))
        ipMinimal[i] |= 1;
    }
  }
  cout<<ipMinimal[0]<<"."<<ipMinimal[1]<<"."<<ipMinimal[2]<<"."<<ipMinimal[3]<<endl;
  cout<<mask[0]<<"."<<mask[1]<<"."<<mask[2]<<"."<<mask[3]<<endl;
  return 0;
}