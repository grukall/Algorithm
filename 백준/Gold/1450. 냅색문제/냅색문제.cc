#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, c;
vector<int> items(30);

void makeCombination(vector<int> &v, int i, int sum, int end)
{
    if (sum > c) return;
    if (i == end)
    {
        v.push_back(sum);
        return;
    }
    
    makeCombination(v, i+1, sum + items[i], end);
    makeCombination(v, i+1, sum, end);
}

int main()
{
    //  c <= 10억, n은 물건 갯수, c는 배낭 최대 무게
    cin >> n >> c;
    vector<int> lv, rv;

    for (int i = 0; i < n; i++) cin >> items[i];

    makeCombination(lv, 0, 0, n/2);
    makeCombination(rv, n/2, 0, n);

    sort(rv.begin(), rv.end());

    int res = 0;
    for (const int &x : lv)
    {
        res += upper_bound(rv.begin(), rv.end(), c-x) - rv.begin();
    }

    cout << res;
}