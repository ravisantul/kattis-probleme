#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int nr;
    cin >> nr;
    long double minute = 0, secunde = 0;
    for (int i = 0; i < nr; ++i)
    {
        int m, s;
        cin >> m >> s;
        minute += m;
        secunde += s;
    }
    long double rezultat = (secunde / (minute * 60));
    if (rezultat <= 1)
        cout << "measurement error";
    else
    {
        cout.precision(9);
        cout << fixed << rezultat;
    }
    return 0;
}