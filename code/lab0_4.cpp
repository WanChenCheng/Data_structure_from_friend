#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long n, m;
    cin >> n >> m;
    long long A[n], Q[m];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> Q[i];
    }

    sort(A, A + n);

    string c = "N ";
    for (int i = 0; i < m; i++)
    {
        long low = 0;
        long high = n - 1;
        c = "N ";
        while (low <= high)
        {
            long mid = long((low + high) / 2);
            if (Q[i] == A[mid])
            {
                c = "Y ";
                low = high + 1;
            }
            else if (Q[i] > A[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << c;
    }

    return 0;
}
