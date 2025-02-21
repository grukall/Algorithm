  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <map>

  using namespace std;


  int main()
  {
    map<string, bool, greater<string>> company;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
      string s, s2; cin >> s >> s2;
      if (s2 == "enter")
      {
        company[s] = true;
      }
      else
      {
        company[s] = false;
      }
    }

    for (auto &it : company)
    {
      if (it.second == true)
        cout << it.first << '\n';
    }
  }