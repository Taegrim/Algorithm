#include <iostream>
#include <vector>
#include <algorithm>
#include "timer.h"

using namespace std;
Timer timer;

void SumPuddle(const vector<int>& v, int left, int right, long long& result)
{
	int min_height = min(v[left], v[right]);

	for (int j = left + 1; j < right; ++j) {
		result += (min_height - v[j]);
	}
}

int main()
{
	int w{}, h{};
	int left{}, min_height{}, max_height{ -1 };
	long long result{};
	vector<int> v{};

	cin >> h >> w;

	timer.Start();

	v.reserve(w);
	for (int i = 0; i < w; ++i) {
		cin >> h;
		v.emplace_back(h);
	}

	left = 0;
	for (int i = 1; i < w; ++i) {
		if (v[i] >= v[left]) {					// 현재 높이가 좌측 기둥과 같거나 높다면
			min_height = min(v[left], v[i]);

			for (int j = left + 1; j < i; ++j) {
				result += (min_height - v[j]);
			}

			left = i;
			max_height = -1;				// 최고 높이 초기화
		}
		else {
			max_height = max(v[i], max_height);	// 왼쪽 기둥보다 낮은 높이 중 최고 높이를 저장

			if (i == w - 1) {				// 같은 높이의 기둥을 찾지 못한 채 끝 지점에 도달하면
				i = left;					// 좌측 기둥의 높이를 낮춘 채로 다시 검사함
				v[left] = max_height;
			}
		}
	}

	timer.Stop();
	cout << result << "\n";
}

// ---------------------
// 기존 블록의 높이를 바꾸지 않고 left 보다 작은 블록 중 가장 높은 블록을 right로 기록
// 같은 기둥을 못찾으면 left~right 사이의 빗물을 계산하고
// right 부터 다시 검사하도록 함
//  -> left 부터 다시 for 문 검사를 하는 것을 막음
// 
//int main()
//{
//	int w{}, h{};
//	int left{}, right{}, min_height{}, max_height{ -1 };
//	long long result{};
//	vector<int> v{};
//
//	cin >> h >> w;
//
//	timer.Start();
//
//	v.reserve(w);
//	for (int i = 0; i < w; ++i) {
//		cin >> h;
//		v.emplace_back(h);
//	}
//
//	left = 0;
//	for (int i = 1; i < w; ++i) {
//		if (v[i] >= v[left]) {					// 현재 높이가 좌측 기둥과 같거나 높다면
//			SumPuddle(v, left, i, result);
//
//			left = i;
//			max_height = -1;				// 최고 높이 초기화
//		}
//		else {
//			if (max_height < v[i]) {
//				max_height = v[i];
//				right = i;
//			}
//
//			if (i == w - 1) {
//				SumPuddle(v, left, right, result);
//
//				i = left = right;
//				max_height = -1;
//			}
//		}
//	}
//
//	timer.Stop();
//	cout << result << "\n";
//}

// 
// 맨 첫칸을 왼쪽 기둥으로 둠
// 
// 현재 블럭 높이가 왼쪽 기둥보다 높거나 같다면 사이에 빗물이 고일 수 있으므로 사이의 빗물을 계산함
// 왼쪽 기둥보다 작다면 최대 높이를 기록함
// 
// 맨 끝 블럭에 도달했는데 왼쪽 기둥과 같은 높이를 못찾았다면
//  - 왼쪽 기둥의 높이를 기록해둔 최대 높이로 변경하고 왼쪽 기둥부터 다시 검사함
// 
// 4 1 0 3 1 을 예시로 보면 
//  - 4보다 크거나 같은 높이를 못찾았으므로 이후 블럭 중 높이가 가장 큰 3으로 왼쪽 기둥의 높이를 변경
// 
// 3 1 0 3 1
//  - 3 1 0 3 사이의 빗물을 계산하고 4번째 블록을 왼쪽 기둥으로 삼음
//  - 4번째 블록인 3보다 크거나 같은 높이를 못찾았으므로 이후 블럭중 큰 1로 높이를 변경함
// 
// 3 1 0 1 1
//  - 4번째 5번째 블럭 높이가 같으므로 빗물을 계산하지만 사이가 없으므로 넘김
//  - 이후 끝에 도달하여 계산 종료
//  
