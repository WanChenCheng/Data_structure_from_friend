#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<unsigned long> v;
    string str1, str2;
    stringstream ss1, ss2;

    cin.ignore();
    getline(cin, str1);
    ss1 << str1;

    while (getline(ss1, str2, ' '))
    {
        if (!str2.empty())
        {
            unsigned long H;
            ss2 << str2;
            ss2 >> H;
            ss2.clear();
            v.push_back(H);
        }
    }

    if (v.size() != N)
    {
        return 0;
    }

    int num = 1, Max = v[0];
    for (int i = 0; i < N; i++)
    {
        if (Max <= v[i])
        {
            Max = v[i];
            num = i + 1;
        }
    }

    cout << num;

    return 0;
}
