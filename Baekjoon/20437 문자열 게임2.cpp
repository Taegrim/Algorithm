#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr int MIN = 1;
constexpr int MAX = 10000;

map<char, pair<int, vector<int>>> m{};
// 문자열에서 특정 문자의 개수와 index를 저장하는 map

int main()
{
	// 문자 n개를 포함하는 짧은 연속 문자열 길이
	// 문자 n개를 포함하고 처음과 마지막이 해당 문자인 긴 문자열 길이
	//   -> 최소 문자열 길이 또한 처음과 마지막이 같을 수 밖에 없음
	 
	// loop 번 진행
	// index를 기억한다면?

	int game_loop{};
	string s{};
	int n{}, len{};
	int min_count{ MAX };
	int max_count{ MIN };

	// ex) s = abaaaba / n = 3
	// a가 등장하는 index 는 0 2 3 4 6
	// 앞에서부터 n개씩 읽어서 길이를 구하면 됨
	// 길이는 index 의 거리 + 1
	// (0 2 3) -> (3 - 0) + 1 = 4
	// (2 3 4) -> (4 - 2) + 1 = 3
	// (3 4 6) -> (6 - 3) + 1 = 4
	// 위의 예시에서 최소는 3  최대는 4

	cin >> game_loop;
	for (int i = 0; i < game_loop; ++i) {
		cin >> s >> n;

		for (int j = 0; j < s.size(); ++j) {		// 개수, index 저장
			++m[s[j]].first;
			m[s[j]].second.push_back(j);
		}

		for (const auto& [key, value] : m) {		// 해당 문자가 n개 이상 존재하면
			if (value.first >= n) {
				const auto& v = value.second;

				for (int k = 0; k < v.size() - (n - 1); ++k) {	// 자기 자신도 n개에 포함되므로 n-1 까지 검사
					len = v[k + (n - 1)] - v[k] + 1;			// 인덱스의 거리 검사

					if (len < min_count) {
						min_count = len;
					}
					if (len > max_count) {
						max_count = len;
					}
				}

			}
		}

		// 하나라도 만족하는 것이 있다면 min 과 max는 같아짐
		// 따라서 만족하는 경우가 없다면 min 과 max 둘다 초기값 그대로일 것
		// 결국 min or max 둘중 하나만 검사해도 됨
		if (min_count == MAX) {
			cout << "-1" << "\n";
		}
		else {
			cout << min_count << " " << max_count << "\n";
		}

		m.clear();
		min_count = MAX;
		max_count = MIN;
	}
}