#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    stack<char> st;

    for (int i = 0; i < t; ++i) {
        cin >> s;

        for (char c : s) {
            if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        if (st.empty()) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }

        while (!st.empty()) {
            st.pop();
        }
    }
}
