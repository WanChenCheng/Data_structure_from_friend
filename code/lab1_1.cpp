#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

const ll k = pow(10, 16) + 1;

void merge(vector<ll> &vec, int L, int R)
{
    int mid = (L + R) / 2;
    vector<ll> left(vec.begin() + L, vec.begin() + mid + 1),
        right(vec.begin() + mid + 1, vec.begin() + R + 1);
    left.push_back(k);
    right.push_back(k);
    int l = 0, r = 0;

    for (int i = L; i <= R && l + r <= R - L + 1; i++)
    {
        if ((left[l] > right[r] && left[l] != k) || right[r] == k)
        {
            vec[i] = left[l];
            l++;
        }
        else if ((left[l] <= right[r] && right[r] != k) || left[l] == k)
        {
            vec[i] = right[r];
            r++;
        }
    }
}

void MergeSort(vector<ll> &vec, int L, int R)
{
    if (L < R)
    {
        int mid = (L + R) / 2;
        MergeSort(vec, L, mid);
        MergeSort(vec, mid + 1, R);
        merge(vec, L, R);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<ll> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    MergeSort(vec, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
