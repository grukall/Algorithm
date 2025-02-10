  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    int x, y, w, h; cin >> x >> y >> w >> h;
    int a, b, c, d;
    // a는 왼쪽 거리 = x.
    a = x;
    // b는 아래쪽 거리 = y.
    b = y;
    // c는 오른쪽 거리 = w-x;
    c = w-x;
    //d는 위쪽 거리 = h-y;
    d = h-y;

    cout << min(a, min(b, min(c, d)));
  }