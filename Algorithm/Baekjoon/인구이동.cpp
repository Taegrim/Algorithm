#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

// NxN 크기 땅, 땅에 나라 1개씩, 나라엔 인구수 저장, 인접하면 국경선 O

// 1. 국경선 공유, 인구차 L~R 이면 국경선 오픈
// 2. 국경선 모두 체크하고, 이동 시작
// 3. 국경선 열려있고, 이동가능하면 연합
// 4. (연합 인구수) / (연합 칸 개수), 정수나눗셈 
// 5. 연합 해체하고 닫기


int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0 ,1, 0, -1 };
int n;

vector<vector<bool>> visited;
vector<vector<pair<int, int>>> unions;

bool BFS(const vector<vector<int>>& population, int sr, int sc, int L, int R)
{
    queue<pair<int, int>> q;

    visited[sr][sc] = true;
    q.push({ sr,sc });

    // 하나로 묶는 용도의 벡터
    vector<pair<int, int>> v;
    v.push_back({ sr, sc });

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (visited[nr][nc]) continue;

            int diff = abs(population[row][col] - population[nr][nc]);
            if(diff >= L && diff <= R)
            {
                visited[nr][nc] = true;
                q.push({ nr, nc });

                v.push_back({ nr, nc });
            }
        }
    }

    // 자기자신 말고 묶인 나라가 있다면
    if (v.size() > 1)
    {
        unions.push_back(v);
        return true;
    }

    return false;
}

int solution(vector<vector<int>> population, int L, int R)
{
    int answer = 0;
    n = population.size();
    
    while (true)
    {
        bool moved = false;

        visited.assign(n, vector<bool>(n, false));
        unions.clear();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 방문하지 않은 나라 진입
                if (!visited[i][j])
                {
                    // BFS 처리 결과 묶인 나라가 있다면 이주 함 처리
                    if (BFS(population, i, j, L, R))
                    {
                        moved = true;
                    }
                }
            }
        }

        if (!moved)
        {
            break;
        }

        ++answer;

        for (const auto& vec : unions)
        {
            int total = 0;

            // 평균 구하기
            for (const auto& [row, col] : vec)
            {
                total += population[row][col];
            }
            total /= vec.size();

            // 통합된 나라 평균치로 설정
            for (const auto& [row, col] : vec)
            {
                population[row][col] = total;
            }
        }
    }

    return answer;
}

int main()
{
    solution({{50, 30}, {20, 40}}, 20, 50);
    solution({{50, 30}, {20, 40}}, 40, 50);
    solution({{10, 15, 20}, {20, 30, 25}, {40, 22, 10}}, 5, 10);
}
