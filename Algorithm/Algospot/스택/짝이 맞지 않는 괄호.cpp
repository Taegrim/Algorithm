#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;


        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                // 비어있는 스택에 괄호가 들어가면 실패
                if (st.empty())
                {
                    st.push(c);
                    break;
                }

                char top = st.top();

                if ((top == '(' && c == ')')
                    || (top == '{' && c == '}')
                    || (top == '[' && c == ']'))
                {
                    st.pop();
                }
                else
                {
                    // 짝이 맞지 않으면 제거할 수 없으므로 바로 실패
                    break;
                }
            }
        }

        if (st.empty())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
