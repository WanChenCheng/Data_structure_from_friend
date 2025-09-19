#include <iostream>
#include <vector>

using namespace std;

void search(long long i, vector<pair<int, int>> &v, int &ans)
{
    if (v[i].second != -1) search(v[i].second, v, ans);
    else if (v[i].first != -1) // if v[i].first != -1 but v[i].second == -1
    {
        search(v[i].first, v, ans);
    }
    else // if v[i].first == -1 and v[i].second == -1
    {
        ans = i;
    }
}

int main()
{
    long long n;
    cin >> n;
    vector<pair<int, int>> v(n + 1, pair<int, int>(-1, -1));
    long long root = n*(n+1)/2; // root = sum

    for (long long i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            v[i].first = l;
            root -= l;
        }
        if (r != -1)
        {
            v[i].second = r;
            root -= r;  // sum - (index which is not root) = root
        }
    }

    int ans; 
    search (root, v, ans);
    cout << ans << "\n";
    return 0;
}