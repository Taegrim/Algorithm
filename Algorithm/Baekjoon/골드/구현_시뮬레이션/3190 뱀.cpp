#include <iostream>
#include <vector>
#include <array>
//#include <Windows.h>

using namespace std;

enum OBJECT { EMPTY, SNAKE, APPLE, WALL };

array<array<int, 101>, 101> map{ EMPTY, };
array<int, 4> dir_x{1, 0, -1, 0};	// → ↓ ← ↑
array<int, 4> dir_y{0, 1, 0, -1};

//void PrintMap(int map_size, int count)
//{ 
//	system("cls");
//	for (int i = 1; i <= map_size; ++i) {
//		for (int j = 1; j <= map_size; ++j) {
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << count << "초 경과" << endl;
//	Sleep(500);
//}

int main()
{
	int size{}, n{}, dir{}, count{}, curr{};
	int row{}, col{};
	vector<pair<int, char>> directions{};
	vector<pair<int, int>> snakes{};
	pair<int, int> head{1, 1}, tail{ 1,1 };

	cin >> size;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> row >> col;
		map[row][col] = APPLE;
	}

	cin >> n;
	directions.resize(n);
	for (auto& [time, dir] : directions) {
		cin >> time >> dir;
	}

	map[1][1] = SNAKE;
	snakes.reserve(100);
	snakes.emplace_back(make_pair(head.first, head.second));

	while (true) {
		//PrintMap(size, count);
		++count;

		// 방향 전환
		if (curr < n) {
			auto& [time, c] = directions[curr];
			if (time == count - 1) {
				++curr;

				if (c == 'D') {
					dir = (dir + 1) % 4;	// 우회전
				}
				else {
					dir = (dir + 3) % 4;	// 좌회전
				}
			}
		}

		// 머리 이동
		// 이동할 때 맵 바깥 or 뱀 몸통이면 break
		head.second += dir_x[dir];
		head.first += dir_y[dir];

		if(head.first < 1 || head.first > size || head.second < 1 || head.second > size ||
			map[head.first][head.second] == SNAKE)
		{
			break;
		}
		else {
			map[tail.first][tail.second] = EMPTY;

			if (map[head.first][head.second] == APPLE) {
				snakes.emplace_back(make_pair(tail.first, tail.second));
			}

			// 뱀의 이동, 꼬리부터 앞을 따라가도록 함
			for (int j = snakes.size() - 1; j > 0; --j) {
				snakes[j].first = snakes[j - 1].first;
				snakes[j].second = snakes[j - 1].second;
				map[snakes[j].first][snakes[j].second] = SNAKE;
			}
			snakes[0].first = head.first;
			snakes[0].second = head.second;

			// tail 조정, head SNAKE 로 칠하기
			auto it = (snakes.end() - 1);
			tail.first = it->first;
			tail.second = it->second;
			map[head.first][head.second] = SNAKE;
		}
	}

	std::cout << count << "\n";
}
