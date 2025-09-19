#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int> &father)
{
    if (father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x], father);
    }
}

void unite(int x, int y, vector<int> &father, vector<int> &size, int &num, int &m_size)
{
    int root_x = find(x, father), root_y = find(y, father);
    if (root_x == root_y)
    {
        return;
    }
    if (size[root_x] > size[root_y])
    {
        swap(root_x, root_y);
    }
    father[root_x] = root_y;
    size[root_y] += size[root_x];
    num--;
    if (m_size < size[root_y])
    {
        m_size = size[root_y];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> father, size;
    int num = n, m_size = 1;
    for (int i = 0; i <= n; i++)
    {
        father.emplace_back(i);
        size.emplace_back(1);
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        unite(u, v, father, size, num, m_size);
        cout << num << " " << m_size << "\n";
    }
    return 0;
}