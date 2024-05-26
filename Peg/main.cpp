#include <iostream>
#include <vector>

using namespace std;

bool Valid(vector<vector<char>> matrice, int i, int j)
{
    if (i < 0 || i >= 7 || j < 0 || j >= 7)
        return false;
    if (matrice[i][j] == 'o')
        return true;
    return false;
}
int main()
{
    vector<vector<char>> matrice;
    matrice.resize(7);
    for (int i = 0; i < 7; ++i)
        matrice[i].resize(7, ' ');
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
            cin.get(matrice[i][j]);
        cin.ignore();
    }
    int total = 0;
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            if (matrice[i][j] == '.')
            {
                if (Valid(matrice, i + 2, j) && Valid(matrice, i + 1, j))
                    total++;
                if (Valid(matrice, i - 2, j) && Valid(matrice, i - 1, j))
                    total++;
                if (Valid(matrice, i, j + 2) && Valid(matrice, i, j + 1))
                    total++;
                if (Valid(matrice, i, j - 2) && Valid(matrice, i, j - 1))
                    total++;
            }
    cout << total;
    return 0;
}