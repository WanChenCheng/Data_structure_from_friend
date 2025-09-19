#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &acl, vector<bool> &visit, int i)
{
    visit[i] = true;
    for (int j : acl[i])
    {
        if (visit[j] == false)
        {
            dfs(acl, visit, j);
        }
    }
}

int main()
{
    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> acl(n + 1);
        vector<bool> visit(n + 1, false);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            acl[u].emplace_back(v);
            acl[v].emplace_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == false)
            {
                ans++;
                dfs(acl, visit, i);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}