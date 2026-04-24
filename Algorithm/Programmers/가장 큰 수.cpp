#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;
    v.reserve(numbers.size());

    for (int i : numbers) {
        v.push_back(to_string(i));
    }

    // 두 숫자를 붙였을 때 크게 되는 경우를 앞으로 당김
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
        });

    // 전부 0이라면 그냥 0 반환
    if (v[0] == "0") {
        return "0";
    }


    string answer{};
    for (const string& s : v) {
        answer += s;
    }

    return answer;
}

int main()
{
    solution({ 6,10,2 });
    solution({ 3, 30, 34, 5, 9 });
}
