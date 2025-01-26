#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    string number;
    unsigned long long int n;
    unsigned long long int result = 0;

    cin >> number >> n;

    unsigned long long int where = 1;
    for (int i = number.size() - 1; i >= 0; i--)
    {
        unsigned long long int num = number[i];
        if (num <= '9')
            num = num - '0';
        else
            num = num - 'A' + 10;

        result += num * where;

        where *= n;
    }

    cout << result;
}