  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {

    vector<pair<int, int>> numbers;

    while (true)
    {
      int a, b; cin >> a >> b;
      if (a == 0 && b == 0)
        break;

      numbers.push_back({a, b});
    }

    for (pair<int, int> nums : numbers)
    {
      int a = nums.first;
      int b = nums.second;

      if (b % a == 0)
      {
        cout << "factor\n";
      }
      else if (a % b == 0)
      {
        cout << "multiple\n";
      }
      else
        cout << "neither\n";
    }
  }