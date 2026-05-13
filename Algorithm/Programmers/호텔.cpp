#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    constexpr int extra_time = 10;

    // 입실, 퇴실 기록
    vector<pair<int, int>> books;

    // 퇴실 시간을 기록하는 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> rooms;

    for (const auto& v : book_time) {
        // 분으로 환산
        string s1 = v[0];
        string s2 = v[1];

        int in = 60 * stoi(s1.substr(0, 2)) + stoi(s1.substr(3, 2));
        int out = 60 * stoi(s2.substr(0, 2)) + stoi(s2.substr(3, 2));

        books.push_back({ in, out });
    }
    sort(books.begin(), books.end());

    // 예약 확인
    for (const auto& [in, out] : books) {

        // 가장 빠른 퇴실시간을 확인해서 처리
        // 재사용 가능한지만 확인하면 됨
        if (!rooms.empty() && rooms.top() <= in) {
            rooms.pop();
        }

        rooms.push(out + extra_time);
    }
    

    return rooms.size();
}

//int solution(vector<vector<string>> book_time) {
//    constexpr int extra_time = 10;
//
//    // 입실, 퇴실 기록
//    multimap<int, int> books;
//
//    // 각 방마다 퇴실 시간 기록
//    vector<int> rooms;
//
//
//    for (const auto& v : book_time) {
//        // 분으로 환산
//        string s1 = v[0];
//        string s2 = v[1];
//
//        int in = 60 * stoi(s1.substr(0, 2)) + stoi(s1.substr(3, 2));
//        int out = 60 * stoi(s2.substr(0, 2)) + stoi(s2.substr(3, 2));
//        
//        books.insert({ in, out });
//    }
//
//    // 입실 시간을 기준으로 체크하면서 방이 있는지 확인
//    for (const auto& [in, out] : books) {
//        bool is_empty = false;
//
//        // 기존 퇴실 시간을 보면서 방 비울 수 있는지 체크
//        for (int i = 0; i < rooms.size(); ++i) {
//            int check_out = rooms[i];
//
//            // 기존 퇴실시간 + 청소시간이
//            // 입실 시간보다 작다면 빈방이므로 해당 방 사용
//            if (check_out + extra_time <= in) {
//                rooms[i] = out;
//                is_empty = true;
//                break;
//            }
//        }
//
//        if (!is_empty) {
//            rooms.push_back(out);
//        }
//    }
//
//    return rooms.size();
//}

int main()
{
    solution({ {"15:00", "17:00"},{"16:40", "18:20"},
        {"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"} });

    solution({ {"09:10", "10:10"}, {"10:20", "12:20"} });

    solution({ {"10:20", "12:30"},{"10:20", "12:30"},{"10:20", "12:30" } });
}
