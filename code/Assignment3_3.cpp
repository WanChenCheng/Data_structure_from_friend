#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int u, v;
    long long wei;
};

vector<int> father;
vector<Edge> edge;

bool compare(Edge a, Edge b)
{
    return a.wei < b.wei;
}

int find(int x)
{
    if (father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x]);
    }
}

void unite(int x, int y)
{
    int root_x = find(x), root_y = find(y);
    father[root_x] = root_y;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        father.emplace_back(i);
    }
    edge.resize(m);
    for (int i = 0; i <= m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].wei;
    }
    sort(edge.begin(), edge.end(), compare);
    long long sum = 0;

    for (int i = 0; i < m; i++)
    {
        if (find(edge[i].u) != find(edge[i].v)) // do not form a cycle
        {
            unite(edge[i].u, edge[i].v);
            sum += edge[i].wei;
        }
    }
    cout << sum;

    return 0;
}