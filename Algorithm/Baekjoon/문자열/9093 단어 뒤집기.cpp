#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

// --------------------  Stack 사용 X --------------- 

int main()
{
	int n{}, num{};
	string line{}, word{};
	char temp{};

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		getline(cin, line);

		istringstream iss(line);

		while (getline(iss, word, ' ')) {
			num = word.size();

			for (int j = 0; j < (num / 2); ++j) {
				temp = word[j];
				word[j] = word[num - j - 1];
				word[num - j - 1] = temp;
			}
			cout << word << " ";
		}
		cout << '\n';
	}
}

//// --------------------  Stack 사용 O ---------------
//
//int main()
//{
//	int n{};
//	string line{};
//	stack<char> words{};
//
//	cin >> n;
//	cin.ignore();
//
//	for (int i = 0; i < n; ++i) {
//		getline(cin, line);
//		line += ' ';
//
//		for (const char c : line) {
//			if (c == ' ') {				// 단어의 끝을 만나면
//				while (!words.empty()) {
//					cout << words.top();
//					words.pop();
//				}
//				cout << " ";
//			}
//			else {
//				words.push(c);
//			}
//		}
//		cout << '\n';
//	}
//}
