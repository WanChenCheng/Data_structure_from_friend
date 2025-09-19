#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, q;
        cin >> n >> q;
        vector<long> v;
        vector<pair<char, long>> vp;
        for (long i = 1; i <= n; i++)
        {
            v.emplace_back(i);
        }

        while (q--)
        {
            char c;
            long k;
            cin >> c >> k;
            pair<char, long> p(c, k);
            vp.emplace_back(p);
        }
        for (long i = vp.size() - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (vp[i].second == vp[j].second)
                {
                    vp.erase(vp.begin() + j);
                    i--;
                }
            }
        }

        for (long i = vp.size() - 1; i >=0; i--)
        {
            if (vp[i].first == 'H')
            {
                cout << vp[i].second << " ";
            }
            v[vp[i].second - 1] = 0;
        }
        for (long i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                cout << v[i] << " ";
            }
        }
        for (long i = 0; i < vp.size(); i++)
        {
            if (vp[i].first == 'T')
            {
                cout << vp[i].second << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}