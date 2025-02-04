  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    int t; cin >> t;

    int dollar[4] = {25, 10, 5, 1};

    vector<vector<int>> result;

    for (int i = 0; i < t; i++)
    {
      int c; cin >> c;
      vector<int> res(4, 0);

      //쿼터 = 25센트, 다임 = 10센트, 니켈  = 5센트, 페니 = 1센트
      for (int coin = 0; coin < 4; coin++)
      {
        res[coin] = c / dollar[coin];
        c = c % dollar[coin];
      }

      result.push_back(res);
    }

    for (vector<int> v : result)
    {
      for (int cv : v)
      {
        cout << cv << ' ';
      }

      cout << '\n';
    }
  }