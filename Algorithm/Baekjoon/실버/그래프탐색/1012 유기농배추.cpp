#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& map, int row, int col)
{
	map[row][col] = 0;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; ++i) {
		int r = row + dy[i];
		int c = col + dx[i];

		// 유효한 범위 체크, 배추인지 확인
		if (r >= 0 && c >= 0 && r < map.size() && c < map[0].size()) {
			if (map[r][c] == 1) {
				dfs(map, r, c);
			}
		}
	}
}

int main()
{
	int loop{};
	cin >> loop;
	
	// 테스트 케이스 수 만큼 반복
	while (--loop >= 0) {
		int width{}, height{}, k{};
		cin >> width >> height >> k;

		// 배추 지도, 지렁이 수
		vector<vector<int>> map(height, vector<int>(width, 0));
		int count = 0;

		// 배추 개수만큼 위치 받기
		int x{}, y{};
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		// 지렁이 체크
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (map[i][j] == 1) {
					dfs(map, i, j);
					++count;
				}
			}
		}

		cout << count << endl;
	}
}