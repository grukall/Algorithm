#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
  int n, m; cin >> n >> m;

    vector<int> baguni(n+1);
    for (int i = 1; i <= n; i++)
        baguni[i] = i;

  for (int k = 0; k < m; k++)
  {
    int i, j; cin >> i >> j;
    int middle = (i + j) / 2;

    int count = 0;
    for (int st = i; st <= middle; st++)
    {
        int temp = baguni[st];
        baguni[st] = baguni[j-count];
        baguni[j-count] = temp;
        count++;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << baguni[i] << ' ';
}