#include <iostream>
#include <vector>

using namespace std;

// n종류 재료를 r[i] 씩 넣기
// 이미 넣은 재료들의 양은 p[i]

int n;
vector<int> r;  // r[i] : i번째 재료의 비율
vector<int> p;  // p[i] : 이미 넣은 재료의 양

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// a/b 를 올림
int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        r.assign(n, 0);
        p.assign(n, 0);

        for (int& i : r)
        {
            cin >> i;
        }
        for (int& i : p)
        {
            cin >> i;
        }

        int b = r[0];
        for (int i : r)
        {
            b = gcd(b, i);
        }

        int a = b;
        for (int i = 0; i < n; ++i)
        {
            a = max(a, ceil(p[i] * b, r[i]));
        }

        vector<int> answer(n);
        for (int i = 0; i < n; ++i)
        {
            answer[i] = r[i] * a / b - p[i];
        }

        for (int ans : answer)
        {
            cout << ans << " ";
        }
        cout << "\n";
    }
}
