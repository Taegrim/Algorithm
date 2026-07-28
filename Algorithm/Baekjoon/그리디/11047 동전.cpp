#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int count = 0;
    long long sum = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (sum == k) break;

        int diff = k - sum;
        int div = diff / v[i];

        sum += div * v[i];
        count += div;
    }

    cout << count << "\n";
}
