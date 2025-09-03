#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

int main()
{
  int n, k;
  vector<int> coins;

  cin >> n >> k;
  coins.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }

  //결과값 10억~20억 -> O(n) = 10초 최소 logn
  vector<int> v(k+1, 0);
  v[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = coins[i]; j <= k; j++)
    {
      v[j] = v[j] + v[j-coins[i]];
    }
  }


  cout << v[k];

} 