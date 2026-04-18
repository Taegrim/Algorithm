#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t{}, n{}, x{}, y{};
	long long start_x{}, start_y{}, end_x{}, end_y{};
	double result{ numeric_limits<double>::max() }, dist{};
	vector<pair<int, int>> points{};
	vector<bool> mask{};

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n;

		for (int j = 0; j < n; ++j) {
			cin >> x >> y;
			points.emplace_back(make_pair(x, y));
			mask.emplace_back(false);
		}

		for (int j = 0; j < n / 2; ++j) {		// 절반만 true로, true 인 경우 끝점, false면 시작점 
			mask[j] = true;
		}
		
		do {
			start_x = start_y = end_x = end_y = 0;

			for (int j = 0; j < n; ++j) {
				if (mask[j]) {		// 끝점
					end_x += points[j].first;
					end_y += points[j].second;
				}
				else {				// 시작점
					start_x += points[j].first;
					start_y += points[j].second;
				}
			}

			end_x -= start_x;		// (끝점의 합) - (시작점의 합)
			end_y -= start_y;
			dist = sqrt(end_x * end_x + end_y * end_y);
			result = min(dist, result);

		} while (prev_permutation(mask.begin(), mask.end()));


		cout << fixed;
		cout.precision(12);
		cout << result << "\n";

		// 테스트 케이스 반복을 위한 초기화
		points.clear();	
		mask.clear();
		result = numeric_limits<double>::max();
	}
}



// (10,10) + (-10, 10) = (0,20)
//
// (-5,5) - (5, 5)   = (-10, 0)
// (5, -5) - (-5,-5) = (10, 0)
//   -> (0,0) -> sqrt(0^2 + 0^2)
// 
// (끝점1) - (시작점1) + (끝점2) - (시작점2) + ...
// ((끝점1) + (끝점2) + ...) - ((시작점1) + (시작점2) + ...) 
// 
// 집합P 에서 절반은 시작점 절반은 끝점이 됨
// 이를 반씩 분리할 수 있어야 함
// 
// nC(n/2) 조합으로 정점들을 분리해야 함
//  -> mask, prev_permutation 으로 nCr 처리
//
