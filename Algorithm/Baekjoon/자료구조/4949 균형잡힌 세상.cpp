#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool CheckString(const string& s)
{
    stack<char> st;

    for(char c : s){
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
        else if (c == '}') {
            if (st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    while (getline(cin, s)) {
        if (s == ".") {
            break;
        }

        if (CheckString(s)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
