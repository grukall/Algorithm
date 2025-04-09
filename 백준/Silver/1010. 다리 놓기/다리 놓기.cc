#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int n; cin >> n;

   for (int i = 0; i < n; i++)
   {
      int w, e;
      cin >> w >> e;
      if (w > e - w) w = e - w;

      unsigned long long int res = 1;
      for (int i = 1; i <= w; ++i)
      {
         res *= e - w + i;
         res /= i;
      }

      cout << res << '\n';
   }
}
