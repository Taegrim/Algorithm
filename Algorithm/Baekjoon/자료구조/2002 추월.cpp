#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int num{}, count{}, curr{};
	string car{};
	map<string, int> car_list;

	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> car;
		car_list[car] = i;
	}

	for (int j = 0; j < num; ++j) {
		cin >> car;
		curr = car_list[car];
		if (curr > j) {								// 추월 했다면 
			++count;

			for (auto& [name, order] : car_list) {	// 기존에 앞에 있던 차량들 순서 + 1
				if (order < curr) {
					++order;
				}
			}
		}
	}

	cout << count << '\n';
}

//int main()
//{
//	int num{}, count{};
//	string car{};
//	map<string, int> input_list;
//	vector<int> output_list;
//
//	cin >> num;
//	for (int i = 0; i < num; ++i) {
//		cin >> car;
//		input_list[car] = i;
//	}
//	
//	for (int i = 0; i < num; ++i) {						// 나오는 순서만 저장
//		cin >> car;
//		output_list.push_back(input_list[car]);
//	}
//
//	for (int i = 0; i < num - 1; ++i) {					// 나오는 순서를 검사했을 때
//		for (int j = i + 1; j < num; ++j) {				// 뒤에 있는 것 보다 숫자가 높으면 추월
//			if (output_list[i] > output_list[j]) {
//				++count;
//				break;
//			}
//		}
//	}
//
//
//	cout << count << '\n';
//}
