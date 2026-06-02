#include <iostream>

#include <vector>
#include <limits>

using namespace std;

// 정수로 표현되는 좌표에 별 그리기
// 모든 별을 포함하는 최소 크기 점찍기

// Ax + By + E = 0
// Cx + Dy + F = 0
//
// x = (BF - ED) / (AD - BC),  y = (EC - AF) / (AD - BC)

struct Point {
    long long x;
    long long y;
};

bool GetPoint(const vector<int>& line1, const vector<int>& line2, Point& p)
{
    long long A = line1[0];
    long long B = line1[1];
    long long E = line1[2];

    long long C = line2[0];
    long long D = line2[1];
    long long F = line2[2];

    // 0이라면 평행 or 겹침
    long long val = A * D - B * C;
    if (val == 0) {
        return false;
    }

    // 분자를 분모로 나눴을 때 나누어 떨어지면 정수
    long long x_upper = (B * F - E * D);
    long long y_upper = (E * C - A * F);

    if (x_upper % val != 0) {
        return false;
    }

    if (y_upper % val != 0) {
        return false;
    }

    p.x = x_upper / val;
    p.y =  y_upper / val;

    return true;
}

vector<string> solution(vector<vector<int>> line) {
    int n = line.size();

    long long min_x{ numeric_limits<long long>::max() }, min_y{ numeric_limits<long long>::max() };
    long long max_x{ numeric_limits<long long>::min() }, max_y{ numeric_limits<long long>::min() };

    vector<Point> v;
    v.reserve(n * (n - 1) / 2);

    // 직선을 이용해서 정수 쌍 점찍기
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Point p{};
            if (!GetPoint(line[i], line[j], p)) {
                continue;
            }

            v.push_back(p);

            min_x = min(min_x, p.x);
            min_y = min(min_y, p.y);
            max_x = max(max_x, p.x);
            max_y = max(max_y, p.y);
        }
    }

    // x, y 개수
    int x_count = static_cast<int>(max_x - min_x + 1);
    int y_count = static_cast<int>(max_y - min_y + 1);

    // .으로 채우기
    vector<string> answer(y_count, string(x_count, '.'));

    // 기존 점 위치에 별로 바꾸기
    for (const Point& p : v) {
        // 배열은 아래로 내려감, 점은 위로 올라감 -> 위 아래 뒤집어야 함
        // 0,0 으로 위치 보정
        answer[max_y - p.y][p.x - min_x] = '*';
    }

    return answer;
}

int main()
{
    solution({ {2, -1, 4} ,{-2, -1, 4},{0, -1, 1},{5, -8, -12},{5, 8, 12} });
    solution({ {0, 1, -1}, {1, 0, -1},{1, 0, 1} });
    solution({ {1, -1, 0}, {2, -1, 0} });
    solution({ {1, -1, 0} ,{2, -1, 0},{4, -1, 0} });
}
