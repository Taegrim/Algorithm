#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int count{};
	long long sum{};
	string num{};

	cin >> num;

	for (const auto& n : num) {
		if (n == '0') {
			++count;
		}

		sum += n - '0';
	}

	if (count == 0) {			// 0이 없다면 30의 배수 X
		cout << "-1";
	}
	else {
		if ((sum % 3 != 0)) {		// 자릿수 합이 3의 배수가 아니면 3의 배수 X
			cout << "-1";
		}
		else {
			sort(num.begin(), num.end(), greater<>());

			cout << num;
		}
	}
}

// 3 x 10
// 0이 있어야함
// 3의 배수여야 함 -> 합이 3으로 나누어 떨어짐