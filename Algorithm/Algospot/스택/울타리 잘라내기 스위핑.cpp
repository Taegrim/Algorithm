#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> h;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        // h[n]을 높이가 0인 울타리로 채우기
        h.assign(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> h[i];
        }

        // 인덱스
        stack<int> st;

        // 특정 울타리가 있을때, 자신보다 작은 울타리가 경계가 됨
        // 앞에서부터 검사하면서 울타리들을 스택에 넣음
        // 작은 울타리를 만나면 스택의 top은 오른쪽 경계가 정해진 것
        //  -> 스택은 높이가 증가하는 순서대로 저장됨

        int ret = 0;

        for (int i = 0; i <= n; ++i)
        {
            // 이전보다 더 작은 울타리를 만났다면 i가 오른쪽 경계가 됨
            while (!st.empty() && h[st.top()] > h[i])
            {
                int width;
                int height = h[st.top()];
                st.pop();

                // 왼쪽에 더 낮은 판자가 없으므로 너비는 그대로 i
                if (st.empty())
                {
                    width = i;
                }
                else
                {
                    // 작은 울타리를 만나면 pop 하므로 높이가 증가하는 형태
                    width = i - st.top() - 1;
                }

                ret = max(ret, height * width);
            }

            // 현재 울타리 넣기
            st.push(i);
        }

        cout << ret << "\n";
    }
}
