#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<double, double>> polygon;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x, y; cin >> x >> y;
        polygon.push_back(make_pair(x, y));
    }

    pair<double, double> first = polygon.front();
    polygon.push_back(first);

    double left = 0;
    double right = 0;
    for (int i = 0; i < polygon.size()-1; i++)
    {
        left += polygon[i].first * polygon[i+1].second;
        right += polygon[i+1].first * polygon[i].second;
    }

    double result = left - right;
    if (result < 0) result *= -1;

    cout << fixed;
    cout.precision(1);
    cout << result /2.f;
}