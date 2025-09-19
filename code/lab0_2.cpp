#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char S[N];

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 1; i < N; i++)
    {
        int l = 0;
        for (int j = 0; j < N; j++)
        {
            if (S[j] != S[i + j] && (i + j != N))
            {
                l++;
            }
            else
            {
                cout << l << endl;
                j = N + 1;
            }
        }
    }

    return 0;
}
