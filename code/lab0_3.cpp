#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "\n" << A << " " << C;
    }
    else
    {
        Hanoi(n - 1, A, C, B);
        Hanoi(1, A, B, C);
        Hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1;
    Hanoi(n, '1', '2', '3');
    return 0;
}