#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> P;

    int N = n;
    while (N--)
    {
        int i;
        cin >> i;
        P.emplace_back(i);
    }

    vector<int> vec(P.begin(), P.begin() + k);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : vec)
    {
        pq.emplace(i);
    }
    int s = vec.size() - k;
    while (s--)
    {
        pq.pop();
    }

    cout << pq.top() << "\n";
    for (int i = k; i < n; i++)
    {
        if (P[i] < pq.top())
        {
            cout << pq.top() << "\n";
        }
        else
        {
            pq.pop();
            pq.emplace(P[i]);
            cout << pq.top() << "\n";
        }
    }

    return 0;
}