  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;

  struct STriangle
  {
    int a;
    int b;
    int c;
  };

  int main()
  {
    vector<STriangle> triangles;
    while (true)
    {
      int a, b, c;
      cin >> a >> b >> c;

      if (!a && !b && !c)
        break;

      triangles.push_back({a, b, c});
    }

    for (STriangle triangle : triangles)
    {
        vector<int> sides;
        sides.push_back(triangle.a);
        sides.push_back(triangle.b);
        sides.push_back(triangle.c);

        //절대 sort 노옵션은 오름차순인걸 잊지마
        sort(sides.begin(), sides.end());
        if (sides[0] + sides[1] <= sides[2])
          cout << "Invalid\n";
        else if (triangle.a == triangle.b && triangle.a == triangle.c)
          cout << "Equilateral\n";
        else if (triangle.a == triangle.b || triangle.a == triangle.c ||  triangle.b == triangle.c)
          cout << "Isosceles\n";
        else
          cout << "Scalene\n";
    }
    
  }