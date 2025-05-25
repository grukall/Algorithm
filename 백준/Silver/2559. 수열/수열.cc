#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k; cin >> n >> k;
  vector<int> temp(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> temp[i];
  }

  int biggest = -10000000;
  for (int i = 0; i <= n-k; i++)
  {
    int res = 0;
    for (int j = i; j < i+k; j++)
    {
      res += temp[j];
    }
    if (res > biggest) biggest = res;
  }

  cout << biggest;
}