#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int Build_Tree(vector<pair<int, int>> &T, vector<string> &P, vector<string> &I, unordered_map<string, int> &M, int l, int r, int &i)
{
    if (r < l)
    {
        return -1;
    }
    string here = P[i];
    int where = M[here];
    if (where > r || where < l)
    {
        return -1;
    }
    else
    {
        i++;
    }
    T[where].first = Build_Tree(T, P, I, M, l, where - 1, i);
    T[where].second = Build_Tree(T, P, I, M, where + 1, r, i);
    return M[here];
}

void Build_post(vector<pair<int, int>> &V, int root, vector<string> &ans, vector<string> &in)
{
    if (V[root].first != -1)
    {
        Build_post(V, V[root].first, ans, in);
    }
    if (V[root].second != -1)
    {
        Build_post(V, V[root].second, ans, in);
    }
    ans.emplace_back(in[root]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> pre, in, post;
        vector<pair<int, int>> V(n + 1, pair<int, int>(-1, -1));
        string tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            pre.emplace_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            in.emplace_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            post.emplace_back(tmp);
        }

        unordered_map<string, int> map_in;
        for (int i = 0; i < n; i++)
        {
            map_in[in[i]] = i;
        }
        int begin = 0;
        int root = Build_Tree(V, pre, in, map_in, 0, n - 1, begin);

        bool b = true;
        if (root == -1)
        {
            b = false;
        }

        vector<string> ans;
        Build_post(V, root, ans, in);

        if (ans.size() != n || root == -1)
        {
            b = false;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (ans[i] != post[i])
                {
                    b = false;
                }
            }
        }

        if (b == true)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
        ans.clear();
    }
    return 0;
}