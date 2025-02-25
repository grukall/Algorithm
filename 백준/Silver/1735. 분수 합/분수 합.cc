  #include <iostream>
  #include <algorithm>

  using namespace std;


  int main()
  {
    int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;

    //분모의 최소공배수를 구한다.
    int c1, c2;
    if (b1 < b2)
    {
      c1 = b2;
      c2 = b1;
    }
    else
    {
      c1 = b1;
      c2 = b2;
    }

    while (c1 % c2)
    {
     // printf("c1 = %d, c2 = %d\n", c1, c2);
      int temp = c2;
      c2 = c1 % c2;
      c1 = temp;
    }

   // cout << "c2 = " << c2 << '\n';
    int c3 = b1 * b2 / c2;

    //최소공배수에 맞추어 분자의 값을 구한다.
    int d1 = c3 / b1;
    a1 = d1 * a1;
    int d2 = c3 / b2;
    a2 = d2 * a2;

    a1 = a1 + a2;
    b1 = c3;
    a2 = a1; b2 = b1;

    //분자와 분모의 최대공약수를 구해 나눈다.
    while (a2 % b2)
    {
      int temp = b2;
      b2 = a2 % b2;
      a2 = temp;
    }

    a1 = a1 / b2;
    b1 = b1 / b2;

    cout << a1 << ' ' << b1;
  }