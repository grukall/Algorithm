#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int n; cin >> n;

   vector<int> nums(n);
   for (int i = 0; i < n; i++)
   {
      cin >> nums[i];
   }

   sort(nums.begin(), nums.end());

   if (n % 2 == 0)
   {
      cout << nums[n / 2] * nums[n/2-1];
   }
   else
   {
      cout << nums[n/2] * nums[n/2];
   }
}
