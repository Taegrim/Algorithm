#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int start = 0;
    int sum = 0;

    vector<int> v;

    // 부호나 끝을 만나면 직전 숫자를 합치기
    // +를 만나면 계속 합치고
    // -를 만나면 여태까지 합친 숫자를 벡터에 넣음
    for (int i = 0; i <= s.size(); ++i)
    {
        if (i == s.size() || s[i] == '+' || s[i] == '-')
        {
            sum += stoi(s.substr(start, i - start));

            if (i == s.size() || s[i] == '-')
            {
                v.push_back(sum);
                sum = 0;
            }

            start = i + 1;
        }
    }

    int ret = v.front();
    for (int i = 1; i < v.size(); ++i)
    {
        ret -= v[i];
    }
    cout << ret << "\n";
}
