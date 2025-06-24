#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	vector<pair<long long, long long>> points{};
	long long n{}, x{}, y{};
	double result{};
	long long temp{};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		points.emplace_back(make_pair(x, y));
	}

	for (int i = 0; i < n; ++i) {
		temp = (i + 1) % n;
		result += points[i].first * points[temp].second -
			points[temp].first * points[i].second;
	}
	result = fabs(result / 2.0);
	// (x1y2 + x2y3 + x3y1 - x2y1 - x3y2 - x1y3) / 2

	// 둘째 자리에서 반올림
	result = round(result * 10.0) / 10.0;

	cout << fixed;
	cout.precision(1);
	cout << result << endl;
}
