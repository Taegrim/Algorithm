#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 차례 잘못되는 실수, 승리해도 계속하는 실수
// - O가 X보다 2개 많거나, X가 O보다 많으면 차례 실수함


enum { circle, cross, COUNT };
constexpr int SIZE = 3;

bool CheckWin(const vector<string>& board, char mark)
{
    // 가로 완성
    for (const string& s : board) {
        if (count(s.begin(), s.end(), mark) == SIZE) {
            return true;
        }
    }

    // 세로 완성
    for (int col = 0; col < SIZE; ++col) {
        if (board[0][col] == mark && board[1][col] == mark && board[2][col] == mark) {
            return true;
        }
    }

    // 대각선
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return true;
    }
    // 대각선
    if (board[2][0] == mark && board[1][1] == mark && board[0][2] == mark) {
        return true;
    }

    return false;
}

int solution(vector<string> board) {
    int counts[COUNT]{ 0, };

    // 놓여있는 표시 확인
    for (const string& s : board) {
        for (char c : s) {
            if (c == 'O') {
                ++counts[circle];
            }
            else if(c == 'X') {
                ++counts[cross];
            }
        }
    }

    bool wins[COUNT]{ false, };

    wins[circle] = CheckWin(board, 'O');
    wins[cross] = CheckWin(board, 'X');

    // 둘다 이겼다면 잘못둔것
    if (wins[circle] && wins[cross]) {
        return 0;
    }

    // O를 마지막으로 둠
    if (counts[circle] == counts[cross] + 1) {
        if (wins[cross]) {
            return 0;
        }
    }
    // X를 마지막으로 둠
    else if (counts[circle] == counts[cross]) {
        if (wins[circle]) {
            return 0;
        }
    }
    // 차례를 실수함
    else {
        return 0;
    }

    return 1;
}

int main()
{
    solution({ "O.X", ".O.", "..X" });
    solution({ "OOO", "...", "XXX" });
    solution({ "...", ".X.", "..." });
    solution({ "...", "...", "..." });
}
