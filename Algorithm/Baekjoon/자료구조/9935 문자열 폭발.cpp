#include <iostream>

using namespace std;

int main()
{
	string s{}, bomb{};
	string result{}, temp{};
	int bomb_size{};

	cin >> s >> bomb;

	bomb_size = bomb.size();

	for (const auto& c : s) {
		result += c;

		if (c == *(bomb.end() - 1) && result.size() >= bomb.size()) { 
			temp = result.substr(result.size() - bomb_size);

			if (temp == bomb) {
				result.erase(result.size() - bomb_size);
			}
		}
	}

	if (result.size() == 0) {
		result = "FRULA";
	}

	cout << result << "\n";
}


//
// 기존 find - replace 사용 시 시간 초과
//  -> 찾아서 지우면 다시 처음부터 검사하기 때문
//     지운 이후엔 그 뒤부터 검사할 수 있어야 함
// 
// 문자열을 result 에 앞에서부터 추가
// 추가하려는 문자가 폭탄의 끝 글자와 같으면 그 때 result 의 뒤에서부터 일치하는지 검사
//  -> string 의 substr 을 사용
// 
// 맞다면 string 의 erase 를 사용해서 지우고 추가하면서 위를 반복
// 
//
