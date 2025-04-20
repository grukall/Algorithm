#include <iostream>

using namespace std;

int main()
{
  int a, b; cin >> a >> b;
  int res = a*b;
  int news[5];
  for (int i = 0; i < 5; i++)
   cin >> news[i];

   for (int n : news)
   {
      cout << n - res << ' ';
   }
}