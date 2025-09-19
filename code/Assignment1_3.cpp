#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, m, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;
        vector<vector<int>> acl(n + 1);

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            acl[u].emplace_back(v);
            acl[v].emplace_back(u);
        }

        while (q--)
        {
            int u, v;
            cin >> u >> v;
            char c = 'N';

            for (int i = 0; i < acl[u].size() && c == 'N'; i++)
            {
                sort(acl[acl[u][i]].begin(), acl[acl[u][i]].end());
                int L = 0, H = acl[acl[u][i]].size() - 1;

                while (L <= H && c == 'N')
                {
                    int M = (L + H) / 2;
                    if (acl[acl[u][i]][M] == v)
                    {
                        c = 'Y';
                    }
                    else if (acl[acl[u][i]][M] < v)
                    {
                        L = M + 1;
                    }
                    else
                    {
                        H = M - 1;
                    }
                }
            }
            cout << c << "\n";
        }
    }

    return 0;
}