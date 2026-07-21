#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int current = 1;
    int idx = 0;
    vector<char> chars;
    chars.reserve(2 * n);

    while (current <= n)
    {
        st.push(current);
        chars.push_back('+');
        ++current;

        // 스택 위에서부터 만들수 있는지 확인
        while (idx < n && !st.empty() && st.top() == v[idx])
        {
            st.pop();
            chars.push_back('-');
            ++idx;
        }
    }

    if (idx < n)
    {
        cout << "NO\n";
    }
    else
    {
        for (char c : chars)
        {
            cout << c << "\n";
        }
    }
}

