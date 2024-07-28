#include <fstream>
using namespace std;
ifstream fi("prodmax.in");
ofstream fo("prodmax.out");
int main()
{
    int n, m;
    int a[101][101];
    fi >> m >> n;
    int cnt2 = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        fi >> a[i][j];
    for(int j = 1; j <= n; ++j)
    {    
        cnt2 = 0;
        int i = 1;
        while(i <= m)
        {
            if(a[i][j] == 0)
            {
                cnt2 = -1;
                break;
            }
            if(a[i][j] == 2)
                ++cnt2;
            ++i;
        }
        a[0][j] = cnt2;
    }
    int maxx = 0;
    for(int j = 1; j <= n; ++j)
        if(a[0][j] > maxx)
            maxx = a[0][j];
    for(int j = 1; j <= n; ++j)
        if(a[0][j] == maxx)
            fo << j << " " ;
}
