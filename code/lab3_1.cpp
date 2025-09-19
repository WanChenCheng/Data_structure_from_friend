#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> acm(n + 1, vector<int>(n + 1));

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        acm[u][v]++;
        acm[v][u]++;
    }

    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'D')
        {
            int u;
            cin >> u;
            int deg = 0;
            for (int i = 0; i < acm[u].size(); i++)
            {
                deg += acm[u][i];
            }
            cout << deg << "\n";
        }
        else if (c == 'N')
        {
            int u, v;
            cin >> u >> v;
            if (acm[u][v] == 1)
            {
                cout << "Y\n";
            }
            else
            {
                cout << "N\n";
            }
        }
    }

    return 0;
}