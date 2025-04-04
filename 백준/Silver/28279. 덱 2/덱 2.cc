#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    vector<int> deck(n);
    int front = 1;
    int end = -1;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        int cmd; int number;
        cin >> cmd;
        if (cmd == 1)
        {
            front--;
            if (front < 0)
                front = n-1;

            cin >> number;
            deck[front] = number;
            
            size += 1;
            if (size == 1)
                end = front;
        }
        else if (cmd == 2)
        {
            end++;
            if (end == n)
                end = 0;
            
            cin >> number;
            deck[end] = number;
            
            size += 1;
            if (size == 1)
                front = end;
        }
        else if (cmd == 3)
        {
            if (size <= 0)
            {
                cout << "-1\n";
                continue;
            }

            cout << deck[front] << '\n';
            front++;
            if (front == n)
            {
                front = 0;
            }
    
            size--;
        }
        else if (cmd == 4)
        {
            if (size <= 0)
            {
                cout << "-1\n";
                continue;
            }

            cout << deck[end] << '\n';
            end--;
            if (end < 0)
            {
                end = n-1;
            }
    
            size--;
        }
        else if (cmd == 5)
        {
            cout << size << '\n';
        }
        else if (cmd == 6)
        {
            if (size == 0)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd == 7)
        {
            if (size == 0)
            {
                cout << "-1\n";
                continue;
            }

            cout << deck[front] << '\n';
        }
        else if (cmd == 8)
        {
            if (size == 0)
            {
                cout << "-1\n";
                continue;
            }

            cout << deck[end] << '\n';
        }

        // printf("front : %d, end : %d = [", front, end);
        // for (int num : deck)
        // {
        //     printf("%d,", num);
        // }
        // printf("]\n");
    }
}
