#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MOD 1000000007LL

int n;
int a[100009], cnt[100009];

void ReadData()
{
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

__int64 fact[100009], inv[100009];

inline __int64 getComb(int v1, int v2)
{
  return (((fact[v1 + v2] * inv[v1]) % MOD) * inv[v2]) % MOD;
}

//»спользуетс€ отрезок [l; r)
//“ак удобнее провер€ть во отрезок упираетс€ справа
__int64 f(int l, int r)
{
  __int64 result = 0;
  if(cnt[l] == cnt[r])// онец рекурсии, поле пустое
  {
    result = 1LL;
    //ƒлина рассматриваемого отрезка r - l
    //“.к. количество вариантов заполнить пр€мую где одни нули 2^(len - 1), мы вычитаем единицу
    for(int i = 0; i < r - l - 1; i++)
    {
      result = (result * 2LL) % MOD;
    }
    return result;
  }
  int p, q;
  for(p = l; p < r; p++)
  {
    if(a[p] != 0)
    {
      break;
    }
  }
  for(q = r - 1; q >= l; q--)
  {
    if(a[q] != 0)
    {
      break;
    }
  }
  if(p == q && a[q] == 1)// онец рекурсии, только один старт дл€ посадки
  {
    return getComb(p - l, r - p - 1);
  }
  if(a[p] >= a[q])
  {
    int nl, nr;
    nl = p + 1;
    nr = nl + a[p] - 1;
    if(nr <= r && nr > q)
    {
      result = (f(nl, nr) * getComb(nl - l - 1, r - nr)) % MOD;
    }
  }
  if(a[p] <= a[q])
  {
    int nl, nr;
    nr = q;
    nl = nr - a[q] + 1;
    if(nl >= l && nl <= p)
    {
      result = (result + f(nl, nr) * getComb(nl - l, r - nr - 1)) % MOD;
    }
  }
  return result;
}

__int64 answer;

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    cnt[i + 1] = cnt[i] + (a[i] == 0 ? 0 : 1);
  }
  answer = f(0, n);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

__int64 binPow(__int64 val, int power)
{
  if(power == 0)
  {
    return 1LL;
  }
  __int64 result = binPow(val, power / 2);
  result = (result * result) % MOD;
  return power % 2 == 0 ? result : (result * val) % MOD;
}

int main()
{
  fact[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < 100009; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = binPow(fact[i], MOD - 2);
  }
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}