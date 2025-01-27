#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> bag(101, 0);

    for (int t = 0; t < m; t++)
    {
        int i, j, k; cin >> i >> j >> k;
        for (int start = i; start <= j; start++)
            bag[start] = k;
    }

    for (int i = 1; i <= n; i++)
        cout << bag[i] << ' ';
}