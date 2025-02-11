  #include <iostream>
  #include <vector>

  using namespace std;

  int main()
  {
    vector<pair<int, int>> point;

    int a, b;
    for (int i = 0; i < 3; i++)
    {
      cin >> a >> b;
      point.push_back({a, b});
    }
    pair<int, int> one, two, three;
    one = point[0];
    two = point[1];
    three = point[2];
    pair<int, int> result;

   //1. 두 점의 x좌표가 같다면 -> 왼쪽 두점 or 오른쪽 두점
    //  x좌표는 나머지 한점과 같은, 두 점중 나머지 한점의 y좌표가 아닌 점
    if (one.first == two.first)
    {
      result.first = three.first;
      if (three.second == one.second)
        result.second = two.second;
      else
        result.second = one.second;
    }
    //2. 두 점의 y좌표가 같다면 -> 아래 두점 or 위 두점
    //-> 두 점중 나머지 한점의 x좌표가 아닌 점 , y좌표는 나머지 한점과 같음
    else if (one.second == two.second)
    {
      result.second = three.second;
      if (three.first == one.first)
        result.first = two.first;
      else
        result.first = one.first;
    }
    //3. 두 점의 xy좌표가 다 다르다면 -> 대각선 두점
    // 나머지 한 점과 두 좌표의 반대
    else
    {
      if (three.first == one.first)
        result.first = two.first;
      else
        result.first = one.first;

      if (three.second == one.second)
        result.second = two.second;
      else
        result.second = one.second;
    }

    cout << result.first << ' ' << result.second;

  }