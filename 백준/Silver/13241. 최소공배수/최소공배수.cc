  #include <iostream>
  #include <algorithm>

  using namespace std;


  int main()
  {
    long long int a, b; cin >> a >> b;
    long long int multi = a * b;

    
    //유클리드 호제법
    // b = aq + r일 때,
    // gcd(b, a) = gcd(a, r) 이다.
    while (b % a)
    {
      int temp = a;
      a = b % a;
      b = temp;
    }

    //최소 공배수는 두 수의 곱을 최대공약수로 나눈 값과 같다.
    cout << multi / a;
  }