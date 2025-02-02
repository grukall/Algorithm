  #include <iostream>
  #include <vector>
  #include <string>
  #include <sstream>

  using namespace std;

  int Pelendrom(string s)
  {
    int start = 0, end = s.size()-1;
    
    while (start < end)
    {
      if (s[start] != s[end]) return 0;

      start++;
      end--;
    }

    return 1;
  }

  int main()
  {
    string s; cin >> s;

    cout << Pelendrom(s);
  }