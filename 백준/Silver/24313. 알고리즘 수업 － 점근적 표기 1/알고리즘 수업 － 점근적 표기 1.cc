  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;


  int main()
  {
    int a1, a0; cin >> a1 >> a0;
    int c; cin >> c;
    int n0; cin >> n0;

    // a1n + a0 <= c * n이 n >=n0에서 모두 만족한다.
    // a0 <= (c - a1) * n 이므로
    // n의 최솟값인 n0에서 a0 <= (c-a1) * n0을 만족하면 모든 n에서 만족한다.
    
    if (c >= a1)
    {
      cout << (a0 <= (c-a1)*n0) ? 1 : 0;
    }
    else
    {
      cout << 0;
    }
  }