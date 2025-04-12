#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int n; cin >> n;
   cin.ignore();


   stringstream ss;
   set<string> dance;
   dance.insert("ChongChong");
   for (int i = 0; i < n; i++)
   {
      string s; getline(cin, s);
      ss.clear();

      ss << s;
      string s1, s2; ss >> s1 >> s2;
      
      if (find(dance.begin(), dance.end(), s1) != dance.end())
      {
         dance.insert(s2);
      }

      else if (find(dance.begin(), dance.end(), s2) != dance.end())
      {
         dance.insert(s1);
      }
   }

   cout << dance.size();
}
