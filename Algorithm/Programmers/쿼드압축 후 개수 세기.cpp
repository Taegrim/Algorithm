#include <iostream>


#include <vector>
#include <algorithm>

using namespace std;

// 원본 배열, 정답, 행, 열, 사이즈
void QuadTree(const vector<vector<int>>& arr, vector<int>& answer, int row, int col, int size)
{
    // 한칸일때
    if (size == 1) {
        if (arr[row][col] == 0) {
            ++answer[0];
        }
        else {
            ++answer[1];
        }

        return;
    }

    // 압축 가능한지 체크
    int zero_count = 0;
    for (int i = 0; i < size; ++i) {
        zero_count += count(
            arr[row + i].begin() + col,
            arr[row + i].begin() + col + size,
            0);
    }

    // 전부 1
    if (zero_count == 0) {
        ++answer[1];
    }
    // 전부 0
    else if (zero_count == size * size) {
        ++answer[0];
    }
    // 압축 실패, 정사각형 나눠서 시도
    else {
        int half = size / 2;
        int rows[]{ row, row + half, row, row + half };
        int cols[]{ col, col, col + half, col + half };

        for (int i = 0; i < 4; ++i) {
            QuadTree(arr, answer, rows[i], cols[i], half);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    QuadTree(arr, answer, 0, 0, arr.size());

    return answer;
}

int main()
{
    solution({ {1,1,0,0} ,{1,0,0,0 }, { 1,0,0,1 }, { 1,1,1,1 }});
    solution({ {1,1,1,1,1,1,1,1} ,{0,1,1,1,1,1,1,1}, { 0,0,0,0,1,1,1,1},
        {0,1,0,0,1,1,1,1 }, {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1}, {0,0,0,0,1,1,1,1} });
}
