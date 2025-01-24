#include <iostream>

using namespace std;

int main()
{
    double res;
    double scoreSum;
    for (int i = 0; i < 20; i++)
    {
        string name; double score; string a;
        cin >> name >> score >> a;

        if (a == "A+")
            res += score * 4.5f;
        else if (a == "A0")
            res += score * 4.0f;
        else if (a == "B+")
            res += score * 3.5f;
        else if (a == "B0")
            res += score * 3.0f;
        else if (a == "C+")
            res += score * 2.5f;
        else if (a == "C0")
            res += score * 2.0f;
        else if (a == "D+")
            res += score * 1.5f;
        else if (a == "D0")
            res += score * 1.0f;
        else if (a == "F")
            res += score * 0.f;
        else if (a == "P")
            continue;

        scoreSum += score;
        //printf("score : %f, a : %s, res = %f\n", score, a.c_str(), res);
    }

    cout << fixed;
    cout.precision(6);
    cout << res / scoreSum;
}