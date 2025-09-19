#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> acl(n + 1);
    vector<int> indegree(n + 1, 0);
    queue<int> queue;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        acl[u].emplace_back(v);
        indegree[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            queue.emplace(i);
        }
    }

    vector<int> ans;
    while (!queue.empty())
    {
        int k = queue.front();
        queue.pop();
        ans.emplace_back(k);
        for (auto i : acl[k])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                queue.emplace(i);
            }
        }
    }

    if (ans.size() == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}