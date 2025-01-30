#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

vector<long long int> liquid;
pair<long long int, long long int> res;

int main()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    liquid.push_back(temp);
  }
    if (liquid[0] >= 0 && liquid[n-1] >= 0)
    {
        cout << liquid[0] << ' ' << liquid[1];
        return 0;
    }
    else if (liquid[0] <= 0 && liquid[n-1] <= 0)
    {
        cout << liquid[n-2] << ' ' << liquid[n-1];
        return 0;
    }

    //왼쪽 끝과 오른쪽 끝부터 탐색한다.
    
    long long int min = __LONG_LONG_MAX__;
    int left = 0, right = n-1; 
    while (left < right)
    {
        long long int sum = liquid[left] + liquid[right];
        if  (abs(sum) < min)
        {
            min = abs(sum);
            res = {liquid[left], liquid[right]};
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << res.first << ' ' << res.second;
}