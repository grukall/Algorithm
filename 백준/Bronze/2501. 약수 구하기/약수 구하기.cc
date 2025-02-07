  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    int n, k; cin >> n >> k;

    vector<int> divisor;
    divisor.push_back(1);

    for (int i = 2; i <= n; i++)
    {
      if (n % i == 0)
        divisor.push_back(i);
    }

    //divisor.push_back(n);

    if (divisor.size() < k)
      cout << 0;
    else
      cout << divisor[k-1];
  }