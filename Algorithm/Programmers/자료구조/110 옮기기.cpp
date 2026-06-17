#include <iostream>

#include <string>
#include <vector>

using namespace std;


vector<string> solution(vector<string> s) {
    vector<string> answer;
    answer.reserve(s.size());

    for (auto& str : s) {
        int count = 0;
        string temp = "";
        temp.reserve(str.size());

        // 110 찾아서 전부 제거
        for (char c : str) {
            temp += c;

            int n = temp.size() - 1;
            if (n >= 2 && temp[n - 2] == '1' && temp[n - 1] == '1' && temp[n] == '0') {
                for (int i = 0; i < 3; ++i) {
                    temp.pop_back();
                }
                ++count;
            }
        }

        // 마지막 0의 위치 찾기
        int index = -1;
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i] == '0') {
                index = i;
            }
        }

        string num = "";
        while (count > 0) {
            num += "110";
            --count;
        }

        // 0 뒤에 110들 붙이기
        temp.insert(index + 1, num);

        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    solution({ "1110","100111100","0111111010" });
}
