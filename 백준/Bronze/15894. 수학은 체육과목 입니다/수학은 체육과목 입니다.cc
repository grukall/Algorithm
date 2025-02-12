  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    unsigned long long int n; cin >> n;

    //1번째 4, 2번째 8 3번째 12 4번째 16..
    // n번째 4n

    //i번째는 i-1번째꺼에 i-1를 빼고 i+3을 더한거
    //f(n) = f(n-1) + 4 = f(n-2) + 8 = ... = f(1) + 4(n-1) = 4n-4+4 = 4n

    cout << 4*n;
  }