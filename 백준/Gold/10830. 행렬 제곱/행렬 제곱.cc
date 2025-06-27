#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

unsigned long long int x = 1000;

void multi_matrix(unsigned long long mx[][5], unsigned long long my[][5], unsigned long long res[][5], int size)
{
  unsigned long long temp[5][5] = {0};
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      for (int k = 0; k < size; k++)
        temp[i][j] = (temp[i][j] + mx[i][k] * my[k][j]) % x;

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      res[i][j] = temp[i][j];
}

void mod_matrix(unsigned long long m[][5], unsigned long long y, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      m[i][j] %= y;
    }
  }
}

void copy_matrix(unsigned long long dest[][5], unsigned long long src[][5], int size)
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      dest[i][j] = src[i][j];

}

void pow_matrix(unsigned long long n[5][5], unsigned long long r, unsigned long long res[5][5], int size)
{
  // if (r <= 0) return;
  if (r == 1)
  {
    mod_matrix(n, x, size);
    copy_matrix(res, n, size);
    return;
  }
  
  //분할 거듭 제곱
  // n^(r/2) = h,
  //r가 짝수 이면 n^r = (n ^ (r/2))^2 % x =  h^2 % x = ((h % x) * (h % x)) % x = nh
  //r가 홀수 이면 n^r = (n^(r/2)) ^ 2 * n = h^2 * n % x = ((h^2 % x) * (n % x)) % x = (nh * (n%x)) % x
  unsigned long long h[5][5];
  pow_matrix(n, r/2, h, size);
  unsigned long long nh[5][5];
  multi_matrix(h, h, nh, size);

  if (r % 2 == 0)
  {
    copy_matrix(res, nh, size);
    return;
  }
  else
  {
    //return (nh * (n % x)) % x;
    multi_matrix(nh, n, res, size);
    return;
  }
  
}


int main()
{
  int n;
  unsigned long long b;
  unsigned long long p[5][5];
  unsigned long long res[5][5] = {0};

  cin >> n >> b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> p[i][j];

  pow_matrix(p, b, res, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << res[i][j] % x << ' ';
    }
    cout << '\n';
  }
}
