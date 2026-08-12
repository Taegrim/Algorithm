#include <iostream>
#include <vector>

using namespace std;


// 현재 맨 앞글자로 '-' 를 배치했을때 만들수 있는 경우의 수
//  -> C(n-1 + m, m),  전체 남은 부호 개수에서 장점을 배치할 수 있는 경우의 수
//     경우의 수가 현재 남은 k보다 작다면 만들수없으므로 'o'를 배치하고 다음 글자로 이동

vector<vector<int>> dp; // dp[n][m] 은 n,m을 이용해 만들 수 있는 경우의 수
vector<vector<int>> bino;   // bino[n][m] 은 C(n, m), 조합의 수
int n, m;

constexpr int MAX = 1000000003;

// n, m으로 만들 수 있는 경우의 수
// 현재 자리에 n 배치/ m 배치이므로 Count(n, m) = Count(n - 1, m) + Count(n, m - 1)
int Count(int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 1;
    }

    int& ret = dp[n][m];
    if (ret != -1)
    {
        return ret;
    }

    return ret = min(MAX, Count(n - 1, m) + Count(n, m - 1));
}

// 이항계수로 미리 전처리 하는 방식
void MakeBino()
{
    bino.assign(201, vector<int>(201, 0));

    for (int i = 0; i <= 200; ++i)
    {
        bino[i][0] = bino[i][i] = 1;

        for (int j = 1; j < i; ++j)
        {
            bino[i][j] = min(MAX, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }
}

// 현재 남은 장점, 단점 개수
// 이후 k번째 숫자가 정답 (k는 재귀할때마다 감소)
string Func(int n, int m, int k)
{
    // 장점이 없다면 나머진 전부 단점
    if (n == 0)
    {
        return string(m, 'o');
    }

    // 단점이 없다면 나머진 전부 장점
    if (m == 0)
    {
        return string(n, '-');
    }

    //// '-' 를 배치한다 가정했을때 만들수있는 조합의 수 계산, DP탑다운
    //int skip = Count(n - 1, m);

    // 전처리한 이항계수 그대로 사용
    // C(n + m, n) -> 전체 n+m 개의 위치 중 n개를 배치하는 조합
    int skip = bino[n + m - 1][n - 1];

    if (skip >= k)
    {
        // 만들수있는 경우 장점 '-' 배치
        return '-' + Func(n - 1, m, k);
    }
    else
    {
        // 만들수없다면 단점 'o' 배치하고 통째로 건너뜀
        return 'o' + Func(n, m - 1, k - skip);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // 이항계수 전처리
    MakeBino();

    while (t--)
    {
        int k;
        // n개 장점 -, m개 단점 o, 사전순 k번째는?
        cin >> n >> m >> k;

        //// 탑다운 처리시 DP 확보
        dp.assign(n + 1, vector<int>(m + 1, -1));

        cout << Func(n, m, k) << "\n";
    }
}
