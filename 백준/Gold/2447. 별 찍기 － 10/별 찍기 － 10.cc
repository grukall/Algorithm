#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>

using namespace std;

void stars(vector<vector<bool>> &map, pair<int, int> start, pair<int, int> end)
{
   int len = end.first - start.first;
   if (len < 2 || map[start.second][start.first] == false) return;
   //printf("start : (%d, %d), end : (%d, %d)\n", start.first, start.second, end.first, end.second);
   int a1 = len / 3 + 1;
   int a2 = len / 3 * 2 + 1;
   //printf("a1 = %d, a2 = %d\n", a1, a2);

   for (int i = start.first + a1; i <= start.first + a2; i++)
   {
      for (int j = start.second + a1; j <= start.second + a2; j++)
      {
         map[j][i] = false;
      }
   }

   // for (vector<bool> maps : map)
   // {
   //    for (bool star : maps)
   //    {
   //       printf("%c", star ? '*' : ' ');
   //    }
   //    printf("\n");
   // }
   // sleep(1);

   if (len/3 >= 2)
   {
      for (int i = start.first; i < end.first; i += a1)
      {
         for (int j = start.second; j < end.second; j += a1)
         {
            //printf("len = %d, before stars : {%d, %d}, {%d, %d}\n",len, i, j, i+len/3, j+len/3);
            stars(map, {i, j}, {i+(len/3), j+(len/3)});
         }
      }
   }
}

int main()
{
   int n; cin >> n;
   vector<vector<bool>> map(n);
   for (int i = 0; i < n; i++)
      map[i].resize(n, true);

   stars(map, {0, 0}, {n-1, n-1});
   for (vector<bool> maps : map)
   {
      for (bool star : maps)
      {
         printf("%c", star ? '*' : ' ');
      }
      printf("\n");
   }
}