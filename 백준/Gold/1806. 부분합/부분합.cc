#include <iostream>
#include <vector>

using namespace std;


int main()
{
   int n, s; cin >> n >> s;
   vector<int> num(n);
   int ts = __INT_MAX__;
   for (int i = 0; i < n; i++)
   {
        cin >> num[i];
   }

   if (num[0] >= s)
   {
        cout << 1;
        return 0;
   }

   int start = 0, end = 1;
   int sum = num[start] + num[end];
   while (start <= end && end < n)
   {
        if (sum >= s)
        {
            ts = min(ts, end-start+1);
            sum -= num[start];
            start++;
        }
        else
        {
            end++;
            sum += num[end];
        }
   }

   if (ts == __INT_MAX__)
    cout << 0;
   else
    cout << ts;
}