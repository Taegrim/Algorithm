#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int> ms;

    for (const auto& operation : operations) {
        stringstream ss(operation);
        string mode{}, num{};

        ss >> mode >> num;

        if (mode == "I") {
            int n = stoi(num);
            ms.insert(n);
        }
        else {
            if (ms.empty()) {
                continue;
            }

            if (num == "-1") {
                ms.erase(ms.begin());
            }
            else {
                auto it = prev(ms.end());
                ms.erase(it);
            }
        }
    }

    if (ms.empty()) {
        return { 0, 0 };
    }

    return { *prev(ms.end()), *ms.begin() };
}

int main()
{
    solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
}
