  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;

  int main()
  {
    int n; cin >> n;
    vector<int> xp;
    vector<int> yp;

    for (int i = 0; i < n; i++)
    {
      int a, b; cin >> a >> b;
      xp.push_back(a);
      yp.push_back(b);
    }

    //내림차순 정렬렬
    sort(xp.begin(), xp.end());
    sort(yp.begin(), yp.end());

    // 동서남북으로 가장 멀리있는 점을 찾아 거리를 찾는다.
    // 동쪽에 가장 가까운 점은 x가 최대인 점이다. a
    int a = xp.back();
    // 서쪽에 가장 가까운 점은 x가 최소인 점이다. b
    int b = xp.front();
    // 남쪽에 가장 가까운 점은 y가 최소인 점이다. c
    int c = yp.front();
    // 북쪽에 가장 가까운 점은 y가 최대인 점이다. d
    int d = yp.back();

    //직사각형의 넓이는 a-b * d-c 이다.
    cout << (a-b)*(d-c);
  }