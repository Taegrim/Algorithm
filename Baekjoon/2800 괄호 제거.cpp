#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	string s{}, result{}, temp{};
	int count{}, size{}, idx{};
	vector<pair<int, int>> v{};		// 괄호의 index를 저장, 순서는 벡터에 들어간 순서
	vector<string> mods{};
	stack<int> stk{};

	cin >> s;
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else if (s[i] == ')') {
			idx = stk.top();
			stk.pop();
			v.emplace_back(idx, i);
		}
	}
	
	size = v.size();
	count = static_cast<int>(pow(2, size)) - 1 - 1;	// 나올 수 있는 식의 개수는 (2^괄호 쌍 개수) -1
	bitset<10> number(count);						// 괄호 쌍을 아예 안지운 식 또한 포함이므로 1을 더 뺌

	while(count >= 0){
		result = s;
		temp = "";
		bitset<10> flag{ number };	// 1101 처럼 괄호를 2진법으로 표현

		for (int i = 0; i < size; ++i) {
			if (!flag[i]) {
				result.replace(v[size - 1 - i].first, 1, " ");
				result.replace(v[size - 1 - i].second, 1, " ");
			}
		}

		for (const auto& c : result) {
			if (c != ' ') {
				temp += c;
			}
		}
		mods.emplace_back(temp);

		number = --count;
	}

	sort(mods.begin(), mods.end());
	auto it = unique(mods.begin(), mods.end());	// 중복 제거
	mods.erase(it, mods.end());

	for (const auto& mod : mods) {
		cout << mod << "\n";
	}
}

//
// 괄호가 나오는 순서대로 이진법의 비트라고 볼 수 있음
// 괄호가 제거되면 0, 있다면 1
// 2의 n승 - 1(n = 괄호의 수) 개만큼 식이 나올 수 있음
// ( ( (  -> 1 1 1
// 1 1 0
// 1 0 1
// 1 0 0
// 0 1 1
// 0 1 0
// 0 0 1
// 0 0 0
// 
// 괄호의 위치, 순서를 알아야 함
//