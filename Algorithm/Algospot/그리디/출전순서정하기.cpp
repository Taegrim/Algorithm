#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> russian(n);
        multiset<int> korean;

        for (int& rating : russian)
        {
            cin >> rating;
        }
        for (int i = 0; i < n; ++i)
        {
            int rating;
            cin >> rating;

            korean.insert(rating);
        }

        int count = 0;

        for (int rating : russian)
        {
            auto it = korean.lower_bound(rating);

            if (it != korean.end())
            {
                ++count;
                korean.erase(it);
            }
            else
            {
                korean.erase(korean.begin());
            }
        }

        cout << count << "\n";
    }
}
