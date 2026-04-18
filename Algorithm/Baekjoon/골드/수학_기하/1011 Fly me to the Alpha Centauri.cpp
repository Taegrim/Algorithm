#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int test_case{};
	long long x{}, y{};
	int dist{}, result{};
	float max_step{};		// 전체 이동하는 동안 최대로 움직이는 거리 

	cin >> test_case;

	for (int i = 0; i < test_case; ++i) {
		cin >> x >> y;

		dist = y - x;
		max_step = static_cast<int>(sqrt(dist));

		if (sqrt(dist) - static_cast<float>(max_step) <= numeric_limits<float>::epsilon()) {
			result = 2 * max_step - 1;									
		}
		else if (dist <= (max_step * max_step) + max_step) {
			result = 2 * max_step;
		}
		else {
			result = 2 * max_step + 1;
		}
		
		cout << result << "\n";
	}

	// x = 0 y = 1				- 거리  1
	// 1						- 값	1
	// 
	// x = 0 y = 2				- 거리	2
	// 1 1						- 값	2
	// 
	// x = 0 y = 3				- 거리	3
	// 1 1 1					- 값	3
	// 
	// x = 0 y = 4				- 거리	4
	// 1 2 1					- 값	3
	// 
	// x = 0 y = 5				- 거리	5
	// 1 2 1 1					- 값	4
	// 
	// x = 0 y = 6				- 거리	6
	// 1 2 2 1					- 값	4
	// 
	// x = 0 y = 7				- 거리	7
	// 1 2 2 1 1				- 값	5
	// 
	// x = 0 y = 8				- 거리	8
	// 1 2 2 2 1				- 값	5
	// 
	// x = 0 y = 9				- 거리	9
	// 1 2 3 2 1				- 값	5
	// 
	// x = 0 y = 10				- 거리	10
	// 1 2 3 2 1 1				- 값	6
	// 
	// x = 0 y = 11				- 거리	11
	// 1 2 3 2 2 1				- 값	6
	// 
	// x = 0 y = 12				- 거리	12
	// 1 2 3 3 2 1				- 값	6
	// 
	// x = 0 y = 13				- 거리	13
	// 1 2 3 3 2 1 1			- 값	7
	// 
	// x = 0 y = 14				- 거리  14
	// 1 2 3 3 2 2 1			- 값	7
	//
	// x = 0 y = 15				- 거리  15
	// 1 2 3 3 3 2 1			- 값	7
	// 
	// x = 0 y = 16				- 거리  16
	// 1 2 3 4 3 2 1			- 값	7
	// 
	// 점진적으로 증가하다가 중간지점을 지나면 다시 감소해야 함
	//   -> 끝에선 1로 끝나야 하므로 증가했다 감소하는 추세
	// 
	// 거리의 제곱근이 정수일 때 중간값이 제곱근이 됨, 이후에 다음 거리에선 최솟값이 늘어남
	// 제곱근이 정수인 거리 다음부턴 해당 제곱근의 개수만큼 값이 일정함
	// 이후에 다시 제곱근의 개수만큼 1 늘어난 상태이고 다음엔 제곱근이 정수가 됨
	// 
	//	1 1 2 2 3 3 4 4 5 5 값이 늘어나는 방식
	// 
	// 제곱근만큼 한번에 최대 이동가능해짐 = value
	// 제곱근(value)이 정수면 2n - 1
	// value*value 가 dist 일 때 다음 value 개수만큼은 2n
	// 이후엔 2n + 1
}
