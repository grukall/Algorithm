#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> students(n);
    for (int i = 0; i < n; i++)
        cin >> students[i];

    int i = 0;
    int front = 0;
    vector<int> room;
    while (i < n)
    {
        if (students[i] == front + 1)
            front++;
        else if (!room.empty() && room.back() == front+1)
        {
            while (!room.empty() && room.back() == front+1)
            {
                front++;
                room.pop_back();
            }

            continue;
        }
        else
        {
            room.push_back(students[i]);
        }

        i++;
    }

    while (!room.empty())
    {
        if (room.back() != front+1)
        {
            cout << "Sad";
            return 0;
        }
        front++;
        room.pop_back();
    }

    cout << "Nice";
}
