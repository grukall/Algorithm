  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;


  int main()
  {
    int n, m; cin >> n >> m;
    vector<string> strings;
    for (int i = 0; i < n; i++)
    {
      string temp; cin >> temp;
      strings.push_back(temp);
    }

    sort(strings.begin(), strings.end());

    vector<string> ss;
    for (int i = 0; i < m; i++)
    {
      string temp; cin >> temp;
      ss.push_back(temp);
    }

    int count = 0;
    for (string s : ss)
    {
      if (binary_search(strings.begin(), strings.end(), s))
        count++;
    }

    cout << count;
  }