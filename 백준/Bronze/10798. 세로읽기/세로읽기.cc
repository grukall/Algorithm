#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    vector<char> list[5];

    for (int i = 0; i < 5; i++)
    {
        list[i].resize(15);
        string s;
        getline(cin, s);

        int count = 0;
        for (int j = 0; j < s.size(); j++)
        {
            list[i][j] = s[j];
            count++;
        }

        for (; count < 15; count++)
        {
            list[i][count] = ' ';
        }
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (list[j][i] != ' ')
                cout << list[j][i];
        }
    }
    
}