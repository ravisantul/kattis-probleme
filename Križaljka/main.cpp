#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string sir1, sir2;
    cin >> sir1 >> sir2;
    int ki, kj;
    bool gresit = false;
    for (int i = 0; i < sir1.size(); ++i)
    {
        for (int j = 0; j < sir2.size(); ++j)
            if (sir1[i] == sir2[j])
            {
                ki = i;
                kj = j;
                gresit = true;
                break;
            }
        if (gresit)
            break;
    }
    vector<vector<char>> matrice(sir1.size(), vector<char>(sir2.size(), '.'));
    for (int i = 0; i < sir1.size(); ++i)
        matrice[i][kj] = sir1[i];
    for (int j = 0; j < sir2.size(); ++j)
        matrice[ki][j] = sir2[j];
    for (int j = 0; j < sir2.size(); ++j)
    {
        for (int i = 0; i < sir1.size(); ++i)
            cout << matrice[i][j];
        cout << endl;
    }
    return 0;
}