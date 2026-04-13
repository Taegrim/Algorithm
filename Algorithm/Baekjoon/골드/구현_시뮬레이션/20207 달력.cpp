#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

array<int, 367> schedule{0, };

int main()
{
	int n{};
	int start_day{}, end_day{};
	int length{}, depth{}, result{};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> start_day >> end_day;

		for (int j = start_day; j <= end_day; ++j) {
			++schedule[j];
		}
	}

	for (const auto& day : schedule) {
		if (day != 0) {
			++length;
			depth = max(depth, day);
		}
		else {
			if (length != 0) {				// 일정이 끝났다면
				result += (length * depth);	// 코팅지의 크기를 구함
				length = 0;					// 길이와 일정 중복값 초기화
				depth = 0;
			}
		}
	}

	cout << result << "\n";
}

//
// 코팅지의 크기 = 연속된 일정의 길이 * 중복된 일정의 수
//  -> 일정을 받으면 해당 날짜에 1을 더해 일정의 개수를 추가함
//     연속되는 일정의 길이와 해당 일정 중 가장 큰 값을 곱하면 코팅지의 크기가 됨
//   
// 일정이 끝난지 확인을 값이 0인것으로 확인하므로 365일 이후인 366도 있어야 함
//  -> 따라서 367 까지 array 할당
//