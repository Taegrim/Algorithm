#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<double> locations(m);

        for (double& location : locations)
        {
            cin >> location;
        }

        double dist = 0;

        // 거리 최소, 최대
        double left = 0.0;
        double right = locations.back() - locations.front();

        for (int i = 0; i < 100; ++i)
        {
            double mid = left + (right - left) / 2.0;

            // 맨 처음에 카메라를 설치하고
            // 다음부터 카메라를 설치할 수 있는지 확인
            int count = 1;
            int last = 0;

            for (int current = 1; current < m; ++current)
            {
                if (locations[current] - locations[last] >= mid)
                {
                    ++count;
                    last = current;

                    // 이미 다 설치했다면 조기 종료
                    if (count >= n)
                    {
                        break;
                    }
                }
            }

            
            if (count >= n)
            {
                // 설치가 가능했다면 기록하고 오른쪽 구간으로 (간격이 넓어지는 방향)
                left = mid;
            }
            else
            {
                // 설치가 불가능했다면 왼쪽 구간으로 (간격이 좁아지는 방향)
                right = mid;
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << left << "\n";
    }
}
