#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int q, k;
    priority_queue<long> pq;
    cin >> q;

    while (q--)
    {
        cin >> k;
        if (k == 1)
        {
            long x;
            cin >> x;
            pq.push(-x);
        }
        else if (k == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
            }
        }
        else if (k == 3)
        {
            if (!pq.empty())
            {
                cout << -pq.top() << "\n";
            }
            else
            {
                cout << "EMPTY\n";
            }
        }
    }

    return 0;
}