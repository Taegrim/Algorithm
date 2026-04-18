#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>>& map, vector<int>& houses, int row, int col)
{
	queue<pair<int, int>> q;

	map[row][col] = 0;
	q.push({ row, col });

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int count = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop(); 

		for (int i = 0; i < 4; ++i) {
			int nr = r + dy[i];
			int nc = c + dx[i];

			if (nr >= 0 && nc >= 0 && nr < map.size() && nc < map[0].size()) {
				if (map[nr][nc] == 1) {
					++count;
					q.push({ nr, nc });
					map[nr][nc] = 0;
				}
			}
		}
	}

	houses.push_back(count);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int size{};
	cin >> size;

	vector<vector<int>> map(size, vector<int>(size, 0));

	// 입력이 연속된 숫자라 문자열로 받아서 쪼개기
	for (int i = 0; i < size; ++i) {
		string s{};
		cin >> s;

		for (int j = 0; j < size; ++j) {
			map[i][j] = s[j] - '0';
		}
	}


	// 단지수, 단지 오름차순
	int count{};
	vector<int> houses;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (map[i][j] == 1) {
				bfs(map, houses, i, j);
				++count;
			}
		}
	}
	sort(houses.begin(), houses.end());

	cout << count << '\n';
	for (int i : houses) {
		cout << i << '\n';
	}
}
