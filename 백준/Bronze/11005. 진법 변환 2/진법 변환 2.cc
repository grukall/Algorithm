  #include <iostream>
  #include <vector>
  #include <stack>

  using namespace std;


  char findres(int i)
  {
    if (i >= 0 && i <= 9)
      return '0' + i;
    else if (i >= 10 && i <= 35)
      return 'A' + i - 10;
    else
      return '$';
  }

  int main()
  {
    int n, b; cin >> n >> b;
    stack<char> res;

    int cur = 0;
    while (n > 0)
    {
      int i = n % b;
      res.push(findres(i));
      n -= i;
      n /= b;
    }

    while (!res.empty())
    {
      char c = res.top();
      cout << c;
      res.pop();
    }
  }