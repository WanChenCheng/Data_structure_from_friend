#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int s, vector<vector<int>> &acl, vector<bool> &vis, vector<int> &distant)
{
    queue<int> queue;
    vis[s] = true;
    queue.emplace(s);
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        for (auto i : acl[u])
        {
            if (vis[i] == false)
            {
                vis[i] = true;
                queue.emplace(i);
                distant[i] = distant[u] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> acl(n + 1);

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            acl[u].emplace_back(v);
            acl[v].emplace_back(u);
        }

        int s;
        cin >> s;
        int size;
        cin >> size;
        vector<int> S;
        while (size--)
        {
            int i;
            cin >> i;
            S.emplace_back(i);
        }

        vector<int> distant(n + 1, 0);
        vector<bool> vis(n + 1, false);

        bfs(s, acl, vis, distant);

        vector<int> dis;
        for (auto i : S)
        {
            if (distant[i] != 0 || i == s)
            {
                dis.emplace_back(distant[i]);
            }
        }

        if (!dis.empty())
        {
            sort(dis.begin(), dis.end());
            cout << dis[0] << "\n";
        }
        else
        {
            cout << "SAD\n";
        }
    }
    return 0;
}