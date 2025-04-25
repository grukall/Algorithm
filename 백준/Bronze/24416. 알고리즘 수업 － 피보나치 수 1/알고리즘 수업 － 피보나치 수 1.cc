#include <iostream>
#include <vector>

using namespace std;

int fibcount = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        fibcount++;
        return 1;
    }
    else return fib(n-1) + fib(n-2);
}

int fibonacci(int n)
{
    vector<int> f(n+1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        fibcount++;
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}
int main()
{
    int n; cin >> n;
    fib(n);
    cout << fibcount << ' ';
    fibcount = 0;
    fibonacci(n);
    cout << fibcount;
}
