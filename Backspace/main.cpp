#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string x;
    cin >> x;
    string rez;
    for(auto it: x)
    {
        if(it == '<')
            rez.pop_back();
        else
            rez.push_back(it);
    }
    cout << rez;
    return 0;
}