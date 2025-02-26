  #include <iostream>
  #include <algorithm>
  #include <vector>

  using namespace std;

  int gcd(int a, int b)
  {
    if (a < b)
    {
      int temp = b;
      b = a;
      a = temp;
    }

    while (a % b)
    {
      int temp = b;
      b = a % b;
      a = temp;
    }

    return b;
  }


  int main()
  {
    int treeCount; cin >> treeCount;
    vector<int> trees(treeCount);

    for (int i = 0; i < treeCount; i++)
    {
      cin >> trees[i];
    }

    sort(trees.begin(), trees.end());

    int resi = 0;
    for (int i = 1; i < treeCount; i++)
    {
      int interval = trees[i] - trees[i-1];
      if (resi == 0)
      {
        resi = interval;
      }
      else
      {
        resi = gcd(resi, interval);
      }
    }

    cout << ((trees.back() - trees.front()) / resi) + 1 - treeCount;
  }