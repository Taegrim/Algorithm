#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t{}, n{};
	string num{};
	vector<string> v{};
	bool is_same{ false };

	cin >> t;

	v.reserve(10001);
	for (int i = 0; i < t; ++i) {
		cin >> n;

		for (int j = 0; j < n; ++j) {
			cin >> num;
			v.emplace_back(num);
		}

		sort(v.begin(), v.end());

		for (int j = 0; j < n - 1; ++j) {	// 사전 순으로 정렬된 전화 번호 탐색
			auto& curr = v[j];
			auto& next = v[j + 1];

			if (curr.size() <= next.size()) {		// 다음 번호의 접두사가 되려면 길이가 짧아야 함
				num = next.substr(0, curr.size());

				if (num == curr) {		// 일치하는걸 하나라도 발견한다면 탐색 종료
					is_same = true;
					break;
				}
			}
		}

		if (is_same) {				// 일치하는게 있다면 일관성 X
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}

		v.clear();
		is_same = false;
	}
}

// 
// 접두사인 경우는 한 번호가 다른 번호의 앞부분과 일치해야 함
//  -> 사전순으로 정렬하고 일치하는지 확인하면 됨
// 
//  substr 로 일부분을 따와서 비교할 수 있음
//
//