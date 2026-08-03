#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0, 1, 0, -1 };

// 1차원 형태로 저장, 사용할땐 풀어서 
vector<int> selected;
unordered_set<int> us;
int n;
int ret = 1e9;

void CheckValue(const vector<vector<int>>& prices)
{
    int sum = 0;

    for (int pos : us)
    {
        int row = pos / n;
        int col = pos % n;

        sum += prices[row][col];
    }

    ret = min(ret, sum);
}

void FillFlower(int pos)
{
    us.insert(pos);

    int row = pos / n;
    int col = pos % n;

    for (int i = 0; i < 4; ++i)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        int num = nr * n + nc;
        us.insert(num);
    }
}

void EraseFlower(int pos)
{
    us.erase(pos);

    int row = pos / n;
    int col = pos % n;

    for (int i = 0; i < 4; ++i)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        int num = nr * n + nc;
        us.erase(num);
    }
}

bool CheckFlower(int pos)
{
    vector<int> v;
    v.push_back(pos);

    int row = pos / n;
    int col = pos % n;

    // 가능한지 체크
    for (int i = 0; i < 4; ++i)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        // 격자 넘어가면 false
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) return false;

        int num = nr * n + nc;
        v.push_back(num);
    }

    // 중복된지 체크
    for (int i : v)
    {
        if (us.count(i))
        {
            return false;
        }
    }

    return true;
}

void DFS(const vector<vector<int>>& prices, int current)
{
    if (selected.size() == 3)
    {
        CheckValue(prices);
        return;
    }

    for (int i = current; i < n * n; ++i)
    {
        if (!CheckFlower(i)) continue;

        selected.push_back(i);
        FillFlower(i);

        DFS(prices, i + 1);

        int num = selected.back();
        selected.pop_back();
        EraseFlower(num);
    }
}

// N이 작음 -> 백트래킹?
// 3개 선택하기
int solution(vector<vector<int>> prices)
{
    n = prices.size();
    
    DFS(prices, 0);

    //cout << ret << endl;

    return ret;
}

int main()
{
    solution({{1, 0, 2, 3, 3, 4}, {1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1}, {3, 9, 9, 0, 1, 99},
        {9, 11, 3, 1, 0, 3}, {12, 3, 0, 0, 0, 1}} );
}
