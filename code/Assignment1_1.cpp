#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

void find1(vector<ll> &v, int x, pair<ll, ll> &p)
{
    ll n = v.size();
    if (v[n - 2] + v[n - 1] < x || v[0] > x)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    for (ll i = 0; i < n; i++)
    {
        ll L = i, H = n - 1;
        ll y = x - v[i];
        while (L < H)
        {
            ll M = ll(L + H) / 2;
            if (v[M] == y)
            {
                p = make_pair(v[i], v[M]);
                return;
            }
            else if (v[H] == y)
            {
                p = make_pair(v[i], v[H]);
                return;
            }
            else if (v[M] > y)
            {
                H = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

void find2(vector<ll> &w, pair<ll, ll> p)
{
    ll n = w.size(), i = 0, j = 0;
    while (w[i] != p.first && w[j] != p.second)
    {
        i++;
        j++;
    }
    if (w[i] == p.first)
    {
        j++;
        while (w[j] != p.second)
        {
            j++;
        }
    }
    else if (w[j] == p.second)
    {
        i++;
        while (w[i] != p.first)
        {
            i++;
        }
    }
    if (i < j)
    {
        cout << i + 1 << " " << j + 1;
    }
    else
    {
        cout << j + 1 << " " << i + 1;
    }
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v, w;
    for (ll i = 0; i < n; i++)
    {
        ll n;
        cin >> n;
        v.push_back(n);
        w.push_back(n);
    }
    sort(v.begin(), v.end());

    pair<ll, ll> p;
    find1(v, x, p);
    if (p.first == 0 && p.second == 0)
    {
        return 0;
    }

    find2(w, p);

    return 0;
}