#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll fib(ll n, vector<ll> F)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    else if (n % 2 == 1 && n != 1 && n != 2)
    {
        ll k = (n - 1) / 2;
        F[n] = pow(fib(k + 1, F), 2) + pow(fib(k, F), 2);
        F[n] %= (ll)(pow(10, 9) + 7);
    }
    else if (n % 2 == 0 && n != 0 && n != 3)
    {
        ll k = n / 2;
        F[n] = fib(k, F) * (2 * fib(k + 1, F) - fib(k, F));
        F[n] %= (ll)(pow(10, 9) + 7);
    }
    return F[n];
}

int main()
{
    ll n;
    cin >> n;
    ll F0 = 0, F1 = 1;
    vector<ll> F(n + 1);

    for (int i = 0; i <= n; i++)
    {
        cout << fib(i, F) << ' ';
    }

    return 0;
}