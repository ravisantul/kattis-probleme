#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    int n;
    bool ok = false;
    cin >> n;
    char l[1001][11], prp[200001];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin.getline(l[i], 11);
        l[i][strlen(l[i])] = '\0';
        for (int j = 0; j < strlen(l[i]); j++)
            l[i][j] = tolower(l[i][j]);
    }
    cin.getline(prp, 200001);
    char *cv = strtok(prp, " ");
    while (cv) {
        ok = false;
        for (int i = 0; i < strlen(cv); i++)
            cv[i] = tolower(cv[i]);
        cv[strlen(cv)] = '\0';
        for (int i = 0; i < n; i++)
            if (strcmp(cv, l[i]) == 0)
                ok = true;
        if (!ok) {
            cout << "Thore has left the chat";
            return 0;
        }
        cv = strtok(NULL, " ");
    }
    cout << "Hi, how do I look today?";
    return 0;
}
