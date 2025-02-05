  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    int n; cin >> n;
    int start;

    int plusPoint = 1;
    int a = 1, b = 2, c = 3, d = 1;
    start = 9;
    for (int i = 2; i <= n; i++)
    {
       a *= 2;
       b = c;
       d *= 2;
       c = c+d;

       start += a*b + c*d;
    }

   cout << start;

   // 1x2 3x1
   // 2x3 5x2
   // 4x5 9x4
   // 8x9 17*8
  }