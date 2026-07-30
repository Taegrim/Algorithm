#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1, 1e9);
    v[n] = 0;

    // n = min(n*3, n*2, n+1)
    for (int i = n - 1; i >= 1; --i)
    {
        int num = v[i + 1] + 1;

        if (i * 2 <= n)
        {
            num = min(num, v[i * 2] + 1);
        }

        if (i * 3 <= n)
        {
            num = min(num, v[i * 3] + 1);
        }

        v[i] = num;
    }

    cout << v[1] << "\n";
}
