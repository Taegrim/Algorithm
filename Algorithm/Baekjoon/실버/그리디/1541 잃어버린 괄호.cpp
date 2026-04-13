#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s{}, num{};
	int result{};
	bool is_minus{ false };

	cin >> s;

	for (int i = 0; i <= s.size(); ++i) {
		if (i == s.size() || s[i] == '-' || s[i] == '+') {	// 문자열의 끝, 사칙연산일 경우 체크
			if (is_minus) {									// or 문의 경우 앞의 조건이 만족하면 뒤를 검사 X
				result -= stoi(num);						// 따라서 i 가 s.size() 이면 원칙상 문자열의 범위를 넘지만
			}												// 이를 검사하지 않고 넘어갈 수 있음
			else {
				result += stoi(num);
			}
			num = "";

			if (s[i] == '-') {			// 맨 처음 - 가 나올 때 앞 숫자는 + 여야 하므로 계산식 뒤에 - 처리
				is_minus = true;
			}
		}
		else {							
			num += s[i];
		}

	}

	cout << result << "\n";
}

//
// 10 - 20 + 30 - 40 + 60 - 50 + 20 + 5 - 1
//
//
// - 가 있다면 뒤에 숫자를 괄호 쳐서 더한 뒤 빼면 됨
//   -> 음수로 바꾸고 더하기
// 
// - 가 나왔는지를 판단할 수 있어야 함
// 
// - 가 한번이라도 나왔다면 뒤의 숫자는 전부 음수로 바꿔서 더하면 됨
//   -> - 이후를 묶어서 생각하므로 한번 나오는것이랑 여러번 나오는 것이랑 상관 없음
// 
// 