#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_SLOPE = 1'000'000'001;
constexpr int MIN_SLOPE = -1'000'000'001;

int main()
{
	int n{}, height{};
	double min_slope{}, max_slope{}, slope{};	// + 방향 기울기, -방향 기울기 
	int result{}, count{};						// 결과
	vector<int> buildings{};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> height;
		buildings.emplace_back(height);
	}

	for (int i = 0; i < n; ++i) {
		max_slope = MIN_SLOPE;
		min_slope = MAX_SLOPE;
		count = 0;

		for (int j = i + 1; j < n; ++j) {	// 오른쪽에 위치한 빌딩, 기울기가 커야 보임
			slope = (double)(buildings[j] - buildings[i]) / (double)(j - i);

			if (slope > max_slope) {
				max_slope = slope;
				++count;
			}
		}

		for (int j = i - 1; j >= 0; --j) {	// 왼쪽에 위치한 빌딩, 기울기가 작야아 보임
			slope = (double)(buildings[j] - buildings[i]) / (double)(j - i);

			if (slope < min_slope) {
				min_slope = slope;
				++count;
			}
		}

		if (count >= result) {
			result = count;
		}
	}

	cout << result << "\n";
}
