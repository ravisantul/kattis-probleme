#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
ld inf = (ld)1e7;

ld IaDistanta(pair<ld, ld> &a, pair<ld, ld> &b)
{
    ld dist1 = pow(a.first - b.first, 2);
    ld dist2 = pow(a.second - b.second, 2);
    return sqrt(dist1 + dist2);
}

void Rezolva(int n)
{
    vector<pair<ld, ld>> puncte;
    ld xs, ys;
    cin >> xs >> ys;
    puncte.push_back({xs, ys});
    for (int i = 0; i < n - 1; ++i)
    {
        ld y, x1, x2;
        cin >> y >> x1 >> x2;
        puncte.push_back({x1, y});
        puncte.push_back({x2, y});
    }
    ld ny, nx1, nx2;
    cin >> ny >> nx1 >> nx2;
    vector<ld> X_valori;
    X_valori.push_back(xs);
    X_valori.push_back(nx1);
    X_valori.push_back(nx2);
    for (auto &i : puncte)
        X_valori.push_back(i.first);
    sort(X_valori.begin(), X_valori.end());
    X_valori.erase(unique(X_valori.begin(), X_valori.end()), X_valori.end());
    for (auto &i : X_valori)
        if (nx1 <= i && i <= nx2)
            puncte.push_back({i, ny});
    vector<vector<pair<int, ld>>> graf(puncte.size());
    int r = (n - 1) * 2;
    for (int i = 0; i <= r; ++i)
    {
        ld d = -inf, u = inf, x1 = puncte[i].first, y1 = puncte[i].second;
        for (int j = (i % 2 == 1) ? i + 2 : i + 1; j <= r; ++j)
        {
            ld x2 = puncte[j].first, y2 = puncte[j].second, p = (x2 - x1) / (y2 - y1);
            if (d <= p && p <= u)
            {
                ld dist = IaDistanta(puncte[i], puncte[j]);
                graf[i].push_back({j, dist});
            }
            if (j % 2 == 1)
                u = min(u, p);
            else
                d = max(d, p);
            if (d > u)
                break;
        }
        for (int j = r + 1; j < puncte.size(); ++j)
        {
            ld x2 = puncte[j].first, y2 = puncte[j].second, p = (x2 - x1) / (y2 - y1);
            if (d <= p && p <= u)
            {
                ld dist = IaDistanta(puncte[i], puncte[j]);
                graf[i].push_back({j, dist});
            }
        }
    }
    vector<ld> dist(puncte.size(), inf);
    vector<int> g(puncte.size(), 0);
    for (int i = 0; i < puncte.size(); ++i)
        for (auto &j : graf[i])
            g[j.first]++;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto &i : graf[nod])
        {
            int u = i.first;
            ld w = i.second;
            dist[u] = min(dist[u], dist[nod] + w);
            g[u]--;
            if (g[u] == 0)
                q.push(u);
        }
    }
    ld rez = inf;
    for (int i = r + 1; i < puncte.size(); ++i)
        rez = min(rez, dist[i]);
    cout << fixed << setprecision(10) << rez << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n && n != 0)
        Rezolva(n);
    return 0;
}