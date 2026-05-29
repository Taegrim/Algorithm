#include <iostream>

#include <string>
#include <vector>

using namespace std;

// a부터 n-b 까지 정적분

// 적분은 윗 삼각형 + 아래 사각형, x 길이는 1
// 적분 = abs(a-b)/2 + min(a,b)
//  사다리꼴 -> (a + b) / 2 였음

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<double> rects;
    double rect{};
    int left{ k }, right{ k };
    int count{};

    // 콜라츠 수열을 따라가면서 정적분 결과 저장
    while (k != 1) {
        // 짝수일때
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
        right = k;

        rect = (double)abs(left - right) / 2.0 + (double)min(left, right);
        //rect = (double)(left + right) / 2.0;
        rects.push_back(rect);

        left = right;
        ++count;
    }

    for (const vector<int>& range : ranges) {
        int left = range[0];
        int right = count + range[1];
        rect = 0.0;

        if (left > right) {
            answer.push_back(-1.0);
            continue;
        }

        for (int i = left; i < right; ++i) {
            rect += rects[i];
        }
        answer.push_back(rect);
    }

    return answer;
}

int main()
{
    solution(5, { {0,0}, {0,-1}, {2,-3},{3,-3} });
    solution(3, { {0,0}, {1,-2}, {3,-3} });
}
