#include <stdio.h>
#include <vector>
#include <math.h>
#include <cmath>

#define M_PI 3.14159265358979323846

double a, b, n, c, d, m;

void ReadData()
{
  scanf("%lf %lf %lf", &a, &b, &n);
  scanf("%lf %lf %lf", &c, &d, &m);
}

int answer;

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

inline bool compare(double v1, double v2)
{
  return abs(v1 - v2) <= 1e-8;
}

void Solve()
{
  answer = 0;
  double r1 = pow(a * a + b * b, 2.0 * m);
  double r2 = pow(c * c + d * d, 2.0 * n);
  if(!compare(r1, r2))
    return;
  r1 = pow(a * a + b * b, 0.5);
  r2 = pow(c * c + d * d, 0.5);
  double phi1 = acos(a / r1);
  double phi2 = acos(c / r2);
  if(_isnan(phi1) || _isnan(phi2))
    throw;
  std::vector<std::pair<double, double>> roots1;
  for(int i = 0; i < n; i++)
  {
    roots1.push_back(std::make_pair(cos((phi1 + 2 * M_PI * i) / n),
      sin((phi1 + 2 * M_PI * i) / n)));
  }
  for(int i = 0; i < m; i++)
  {
    double v1 = cos((phi2 + 2 * M_PI * i) / m);
    double v2 = sin((phi2 + 2 * M_PI * i) / m);
    for(int j = 0; j < roots1.size(); j++)
    {
      if(compare(roots1[j].first, v1)
          && compare(roots1[j].second, v2))
      {
        answer++;
        break;
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
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