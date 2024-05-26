#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x += y;
    if ((x / n) % 2 == 0)
    {
        cout << "paul";
        return 0;
    }
    cout << "opponent";
    return 0;
}
