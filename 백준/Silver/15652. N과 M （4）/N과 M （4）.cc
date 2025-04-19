#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int> &list, int n, int m, int count)
{
   if (count == m)
   {
      for (int num : list)
         cout << num << ' ';
      cout << '\n';
      return ;
   }

   int beforeNum = 1;
   if (!list.empty())
      beforeNum = list.back();

   for (int num = beforeNum; num <= n; num++)
   {
      list.push_back(num);
      backtracking(list, n, m, count+1);
      list.pop_back();
   }
}


int main()
{
   int n, m; cin >> n >> m;
   vector<int> list;
   backtracking(list, n, m, 0);
}