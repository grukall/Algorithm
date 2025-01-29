#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> bag(n+1);

    for (int i = 1; i <= n; i++)
    {
        bag[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        int temp = bag[a];
        bag[a] = bag[b];
        bag[b] = temp;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << bag[i] << ' ';
    }
}