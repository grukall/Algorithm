#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// long long int combination(int n, int r)
// {
//   if (n <= 0 || r <= 0) return 0;
//   if (r > n) return 0;
//   if (r == 1) return n;
//   else if (n == r) return 1;

//   vector<vector<long long int>> num(n+1);
//   for (vector<long long int> &row : num)
//     row.resize(r+1, 0);

//   for (int i = 1; i <= n; i++)
//   {
//     num[i][1] = i;
//     num[i][i] = 1;
//   }

//   for (int i = 3; i <= n; i++)
//   {
//     for (int j = 2; j <= r; j++)
//     {
//       num[i][j] = num[i-1][j-1] + num[i-1][j];
//     }
//   }

//   return num[n][r];
// }

long long combination(int n, int r) {
    if (r > n) return 0;
    return (long long)n * (n - 1) / 2;
}


struct PrefixSum
{
  long long int sum;
  int mod;
};


int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<PrefixSum> PS(n+1);
  vector<int> count(m, 0);
  for (int i = 1; i <= n; i++)
  {
    int number; cin >> number;
    PS[i].sum = PS[i-1].sum + number;
    PS[i].mod = PS[i].sum % m;
    count[PS[i].mod] += 1;
  }

  long long int res = 0;
  res += count[0];
  for (int cnt : count)
  {
    if (cnt >= 2)
      res += combination(cnt, 2);
  }
  
  cout << res;
}