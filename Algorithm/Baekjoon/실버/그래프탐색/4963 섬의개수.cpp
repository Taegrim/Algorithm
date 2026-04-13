#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& m, int row, int col)
{
	// row, col 저장할 큐
	queue<pair<int, int>> q;

	// 시작점부터 탐색
	q.push({ row, col });
	m[row][col] = 0;

	// 상하좌우, 좌상 우상 좌하 우하
	int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		// 상하좌우 탐색
		for (int i = 0; i < 8; ++i) {
			int new_r = r + dy[i];
			int new_c = c + dx[i];
			
			// 유효한 범위 체크
			if (new_r >= 0 && new_c >= 0 && new_r < m.size() && new_c < m[0].size()) {

				// 이어진 땅이라면 큐에 넣고 방문처리
				if (m[new_r][new_c] == 1) {
					q.push({ new_r, new_c });
					m[new_r][new_c] = 0;
				}
			}
		}
		
	}
}

int main()
{
	int w{}, h{};
	
	// w,h 대입
	while (cin >> w >> h) {
		if (w == 0 && h == 0) {
			break;
		}

		// 지도
		vector<vector<int>> m(h, vector<int>(w, 0));
		int count = 0;

		// 지도 대입
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> m[i][j];
			}
		}

		// 탐색
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {

				// 땅 발견시 bfs로 방문처리
				if (m[i][j] == 1) {
					bfs(m, i, j);
					++count;
				}
			}
		}

		cout << count << endl;
	}
}