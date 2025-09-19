#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, q;
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
        char c;
        cin >> c;
        if (c == 'D')
        {
            int u;
            cin >> u;
            cout << acl[u].size() << "\n";
        }
        else if (c == 'N')
        {
            int u, v;
            cin >> u >> v;
            char c = 'N';
            for (int i = 0; i < acl[u].size() && c == 'N'; i++)
            {
                if (acl[u][i] == v)
                {
                    c = 'Y';
                }
            }
            cout << c << "\n";
        }
    }

    return 0;
}