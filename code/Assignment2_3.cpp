#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> v(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<int> sort;
    while (m--)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            int x1, y;
            cin >> x1 >> y;
            v[x1] = y;
        }
        else if (c == 'B')
        {
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            v[x1] = y;
            G[x2].emplace_back(x1);
            indegree[x1]++;
        }
        else if (c == 'C')
        {
            int x1, x2, x3, y;
            cin >> x1 >> x2 >> x3 >> y;
            v[x1] = y;
            G[x2].emplace_back(x1);
            G[x3].emplace_back(x1);
            indegree[x1] += 2;
        }
        else if (c == 'D')
        {
            int x1, x2, x3, x4, y;
            cin >> x1 >> x2 >> x3 >> x4 >> y;
            v[x1] = y;
            G[x2].emplace_back(x1);
            G[x3].emplace_back(x1);
            G[x4].emplace_back(x1);
            indegree[x1] += 3;
        }
    }

    // topologocal_sort
    queue<int> q;
    vector<bool> b(n + 1, false);
    for (int i = 1; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.emplace(i);
            b[i] = true;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        sort.emplace_back(u);
        for (auto i : G[u])
        {
            indegree[i]--;
            v[i] += v[u];
            if (indegree[i] == 0)
            {
                q.emplace(i);
                b[i] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (b[i] == false)
        {
            cout << "#REF!\n";
        }
        else
        {
            cout << v[i] << "\n";
        }
    }

    return 0;
}