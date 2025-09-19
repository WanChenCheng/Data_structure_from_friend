#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int> &v, int k)
{
    int index;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == k)
        {
            index = i;
        }
    }
    return index;
}

void build(int &cur, int &cur_index, vector<int> &pre, vector<int> &in, vector<pair<int, int>> &v)
{
    // vector<int> c_pre_left(pre.begin() + 2, pre.begin() + cur_index + 1),
    //             c_pre_right(pre.begin() + cur_index + 1, pre.end());
    // vector<int> c_in_left(in.begin() + 1, in.begin() + cur_index),
    //             c_in_right(in.begin() + cur_index + 1, in.end());

    vector<int> c_pre_left(1, 0), c_pre_right(1, 0), c_in_left(1, 0), c_in_right(1, 0);
    for (int i = 2; i <= cur_index && pre.size() != 1; i++)
    {
        c_pre_left.emplace_back(pre[i]);
    }
    for (int i = cur_index + 1; i < pre.size() && pre.size() != 1; i++)
    {
        c_pre_right.emplace_back(pre[i]);
    }
    for (int i = 1; i < cur_index && in.size() != 1; i++)
    {
        c_in_left.emplace_back(in[i]);
    }
    for (int i = cur_index + 1; i < in.size() && in.size() != 1; i++)
    {
        c_in_right.emplace_back(in[i]);
    }

    if (c_pre_left.size() != 2 && c_pre_left.size() != 1)
    {
        v[pre[1]].first = c_pre_left[1];
        cur = c_pre_left[1];
        cur_index = find_index(c_in_left, cur);
        build(cur, cur_index, c_pre_left, c_in_left, v);
    }
    else if (c_pre_left.size() == 2)
    {
        v[pre[1]].first = c_pre_left[1];
    }

    if (c_pre_right.size() != 2 && c_pre_right.size() != 1)
    {
        v[pre[1]].second = c_pre_right[1];
        cur = c_pre_right[1];
        cur_index = find_index(c_in_right, cur);
        build(cur, cur_index, c_pre_right, c_in_right, v);
    }
    else if (c_pre_right.size() == 2)
    {
        v[pre[1]].second = c_pre_right[1];
    }
}

void dfs(vector<pair<int, int>> &v, int root)
{
    if (v[root].first != -1)
    {
        dfs(v, v[root].first);
    }
    if (v[root].second != -1)
    {
        dfs(v, v[root].second);
    }
    cout << root << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n + 1, 0), in(n + 1, 0);
    vector<pair<int, int>> v(n + 1, pair<int, int>(-1, -1));
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        pre[i] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        in[i] = k;
    }

    int root = pre[1];
    int root_index = find_index(in, root);
    build(root, root_index, pre, in, v);

    dfs(v, pre[1]);

    return 0;
}