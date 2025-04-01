#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin.ignore();

    int stack[1000000];
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
                cin >> b;
                stack[size] = b;
                size += 1;
        }
        else if (a == 2)
        {
                if (size <= 0)
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << stack[size-1] << '\n';
                    size--;
                }
        }
        else if (a == 3)
                cout << size << '\n';
        else if (a == 4)
        {
            if (!size) cout << "1\n";
            else cout << "0\n";
        }
        else
        {
                if (size <= 0)
                {
                    cout << "-1\n";
                }
                else
                    cout << stack[size-1] << '\n';
        }
    }
}
