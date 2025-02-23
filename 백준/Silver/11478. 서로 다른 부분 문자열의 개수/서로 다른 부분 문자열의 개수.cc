  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <set>

  using namespace std;

  set<string> sets;

  void makeSet(string s)
  {
    for (int i = 0; i < s.size(); i++)
    {
      //count번째에 집합에 추가되는 부분집합은
      //바로 왼쪽에 숫자부터 포함하는 부분집합들이다.
      int befori = i;

      while (befori >= 0)
      {
        //cout << "substr : " << s.substr(befori, i-befori+1) << '\n';
        sets.insert(s.substr(befori, i-befori+1));
        befori--;
      }
    }
  }


  int main()
  {
    string s; cin >> s;

    makeSet(s);
    cout << sets.size();
  }