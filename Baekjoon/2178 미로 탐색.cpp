#include <iostream>
#include <queue>

using namespace std;

char map[101][101]{ 0, };
int dist[101][101]{ 0, };
bool visited[101][101]{ false, };
queue<pair<int, int>> q{};
int x_dir[4]{ 0, 1, 0, -1 };
int y_dir[4]{ 1, 0, -1, 0 };

void BFS(int max_x, int max_y)
{
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	
	int x{}, y{};
	int new_x{}, new_y{};

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			new_x = x + x_dir[i];
			new_y = y + y_dir[i];

			if (0 <= new_x && 0 <= new_y && dist[new_y][new_x] == 1 &&
				!visited[new_y][new_x]) 
			{
				q.push(make_pair(new_x, new_y));
				dist[new_y][new_x] = dist[y][x] + 1;
				visited[new_y][new_x] = true;
			}
		}
	}
}

int main()
{
	int max_x{}, max_y{};

	cin >> max_y >> max_x;

	for (int i = 0; i < max_y; ++i) {
		for (int j = 0; j < max_x; ++j) {
			cin >> map[i][j];
			dist[i][j] = map[i][j] - '0';
		}
	}

	BFS(max_x, max_y);

	cout << dist[max_y - 1][max_x - 1] << "\n";
}