#include <iostream>
#include <vector>

using namespace std;

int n, k;   // n개 도시, k번째 표지판

vector<int> L;  // L[i] : i번째 도시까지의 거리
vector<int> M;  // M[i] : i번째 도시에서 Xm 떨어진 거리부터 표지판 있음
vector<int> G;  // G[i] : i번째 도시의 표지판 간격

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        L.assign(n, 0);
        M.assign(n, 0);
        G.assign(n, 0);

        int left = 0;
        int right = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> L[i] >> M[i] >> G[i];
            right = max(right, L[i]);
        }

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            long long count = 0;

            // 거리 mid 에서 각 도시별로 마주칠 수 있는 표지판의 수를 구하기
            for (int i = 0; i < n; ++i)
            {
                int start = L[i] - M[i];
                int last = min(mid, L[i]);  // 도시와 현재 거리 중 짧은것이 마지막
                
                // 가능한 마지막 표지판 위치가 시작점보다 멀리 있을 경우에만 가능
                if (last >= start)
                {
                    count += (last - start) / G[i] + 1;
                }
            }

            if (k <= count)
            {
                // mid 까지 이미 k개 이상이 있음
                // k번째 표지판은 mid 이하에 있음
                right = mid;
            }
            else
            {
                // 아직 k개 미만
                // k번째 표지판은 mid 뒤에 있음
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }
}
