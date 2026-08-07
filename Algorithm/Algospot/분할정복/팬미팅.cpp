#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 카라츠바 알고리즘 원형
int Karatsuba(int x, int y)
{
    // 둘 중 하나라도 10보다 작으면 두 수로 나눌 수 없으므로 바로 계산
    if (x < 10 || y < 10)
    {
        return x * y;
    }

    // 123456 -> 123*10^3 + 456

    int len = max(to_string(x).size(), to_string(y).size());
    int half = len / 2;
    int mul = static_cast<int>(pow(10, half));

    int a = x / mul;
    int b = x % mul;
    int c = y / mul;
    int d = y % mul;

    // (a * 10^half + b) * (c * 10^half + d) = ac * (10^half)^2 + (ad + bc) * 10^half + bd
    // (ad + bc) = (a+b)(c+d) - ac - bd;

    int ac = Karatsuba(a, c);
    int bd = Karatsuba(b, d);
    int ad_bc = Karatsuba(a + b, c + d) - ac - bd;

    return ac * mul * mul + ad_bc * mul + bd;
}

vector<int> Multiply(const vector<int>& a, const vector<int>& b)
{
    int n = a.size();
    int m = b.size();
    vector<int> ret(n + m - 1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ret[i + j] += a[i] * b[j];
        }
    }

    return ret;
}

// a += b * (10^offset)
void Add(vector<int>& a, vector<int>& b, int offset)
{
    if (a.size() < b.size() + offset)
    {
        a.resize(b.size() + offset, 0);
    }

    for (int i = 0; i < b.size(); ++i)
    {
        a[i + offset] += b[i];
    }
}

// a -= b
void Subtract(vector<int>& a, vector<int>& b)
{
    if (a.size() < b.size())
    {
        a.resize(b.size(), 0);
    }

    for (int i = 0; i < b.size(); ++i)
    {
        a[i] -= b[i];
    }
}

vector<int> Karatsuba(const vector<int>& x, const vector<int>& y)
{
    int n = x.size();
    int m = y.size();

    // 항상 x가 길도록 조절
    if (n < m)
    {
        return Karatsuba(y, x);
    }

    // 하나라도 길이가 0이면 빈 배열
    if (n == 0 || m == 0)
    {
        return {};
    }

    // 배열이 일정 길이 이하면 단순 곱셈으로
    if (n <= 20)
    {
        return Multiply(x, y);
    }

    int half = n / 2;

    vector<int> a(x.begin(), x.begin() + half);
    vector<int> b(x.begin() + half, x.end());

    int y_half = min(m, half);

    vector<int> c(y.begin(), y.begin() + y_half);
    vector<int> d(y.begin() + y_half, y.end());

    // (a * 10^half + b) * (c * 10^half + d) = ac * (10^half)^2 + (ad + bc) * 10^half + bd
    // (ad + bc) = (a+b)(c+d) - ac - bd;

    vector<int> ac = Karatsuba(a, c);
    vector<int> bd = Karatsuba(b, d);

    Add(a, b, 0);
    Add(c, d, 0);

    // (a+b) * (c+d)
    vector<int> ad_bc = Karatsuba(a, c);

    Subtract(ad_bc, ac); // -ac
    Subtract(ad_bc, bd); // -bd

    vector<int> ret;

    Add(ret, ac, 0);
    Add(ret, bd, half);
    Add(ret, ad_bc, half * 2);

    return ret;
}

int GetHug(const string& member, const string& fan)
{
    int n = member.size();
    int m = fan.size();

    vector<int> members(n, 0);
    for (int i = 0; i < n; ++i)
    {
        members[n - 1 - i] = (member[i] == 'M');
    }

    vector<int> fans(m, 0);
    for (int i = 0; i < m; ++i)
    {
        fans[i] = (fan[i] == 'M');
    }

    vector<int> ret = Karatsuba(members, fans);

    int answer = 0;

    for (int i = n - 1; i < m; ++i)
    {
        if (ret[i] == 0)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int loop;
    cin >> loop;

    while (loop--)
    {
        string member, fan;
        cin >> member >> fan;

        cout << GetHug(member, fan) << "\n";
    }
}
