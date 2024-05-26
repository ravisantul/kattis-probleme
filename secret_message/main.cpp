#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string Codeaza(string sir, int lungime)
{
    vector<vector<char>> matrice;
    matrice.resize(lungime, vector<char>(lungime));
    for (int i = 0; i < lungime; ++i)
        for (int j = 0; j < lungime; ++j)
            matrice[i][j] = sir[i * lungime + j];
    string rezultat = "";
    for (int i = 0; i < lungime; ++i)
        for (int j = lungime - 1; j >= 0; j--)
        {
            char c = matrice[j][i];
            if (c != '*')
                rezultat += c;
        }
    return rezultat;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string sir;
        cin >> sir;
        int lungime = ceil(sqrt(sir.length()));
        while (sir.length() < lungime * lungime)
            sir += "*";
        cout << Codeaza(sir, lungime) << endl;
    }
    return 0;
}
