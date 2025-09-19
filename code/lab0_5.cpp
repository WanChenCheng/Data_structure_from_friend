#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long F0 = 0, F1 = 1, Fn = F1 + F0;

    if(n == 0)
    {
        cout << F0;
    }
    else if (n == 1)
    {
        cout << F1;
    }
    else if (n != 0 && n != 1)
    {
        while (n >= 3)
        {
            F0 = F1;
            F1 = Fn;
            Fn = F1 + F0;
            F0 %= (long long)(pow(10, 9) + 7);
            F1 %= (long long)(pow(10, 9) + 7);
            Fn %= (long long)(pow(10, 9) + 7);
            n--;
        }
        cout << Fn;
    }

    return 0;
}