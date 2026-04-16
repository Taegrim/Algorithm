#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>

using namespace std;

// 요금표, 입차/출차 기록
//  -> 요금표 식 : 기본요금 + [(총시간 - 기본시간) / 단위시간] * 단위요금, 올림처리

// 입차 후 출차가 없다면 23:59를 출차로 간주
//  -> records 를 확인 후 컨테이너에 남아있다면 일괄 정산

// 입차~출차를 기록하면 전부 끝나고 다시 정산해야함
//   -> 입차할때마다 23:59 까지를 미리 계산하고 출차할때 그 이후 시간을 빼는 방식으로 하면?

//vector<int> solution(vector<int> fees, vector<string> records) {
//    vector<int> answer;
//
//    // 차량번호, 주차 시간을 기록
//    map<int, int> total_time;
//
//    for (const auto& s : records) {
//        stringstream ss(s);
//        string time{}, state{};
//        int number;
//
//        ss >> time >> number >> state;
//
//        // 시간 -> 분으로 전환
//        int minute = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
//
//        // 입차하면 입차시간 ~ 23:59(1439분) 까지를 미리 누적 주차시간으로 봄
//        if (state == "IN") {
//            total_time[number] += (1439 - minute);
//        }
//        // 출차 시 출차시간 ~ 23:59 까지를 날림
//        else {
//            total_time[number] -= (1439 - minute);
//        }
//    }
//    
//    for (const auto& [number, time] : total_time) {
//        int fee = fees[1];
//        if (time > fees[0]) {
//            fee += ((time - fees[0]) + fees[2] - 1) / fees[2] * fees[3];
//        }
//        answer.push_back(fee);
//    }
//
//    // 차량번호가 작은 자동차부터 정산
//    return answer;
//}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    // (차량번호, 주차 시간), (차량번호, 총 시간) 기록
    map<int, int> in_time;
    map<int, int> total_time;

    for (const auto& s : records) {
        stringstream ss(s);
        string time{}, state{};
        int number;

        ss >> time >> number >> state;

        // 시간 -> 분으로 전환
        int minute = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));

        // 입차하면 기록
        if (state == "IN") {
            in_time[number] = minute;
        }
        // 출차 시 총 시간 기록, 입차 목록에서 날림
        else {
            total_time[number] += minute - in_time[number];
            in_time.erase(number);
        }
    }

    // 입차 기록 있다면 23:59 기준으로 한번에 정산
    for (const auto& [number, time] : in_time) {
        total_time[number] += 1439 - time;
    }

    // 0 : 기본시간, 1:기본요금, 2:단위시간, 3:단위요금
    // 기본요금 + [(총시간 - 기본시간) / 단위시간] * 단위요금, 올림처리
    for (const auto& [number, time] : total_time) {
        // 기본시간 이하라면 기본요금
        int fee = fees[1];
        if (time > fees[0]) {
            // 올림 (a + b - 1) / b
            fee += ((time - fees[0]) + fees[2] - 1) / fees[2] * fees[3];
        }
        answer.push_back(fee);
    }

    // 차량번호가 작은 자동차부터 정산
    return answer;
}

int main()
{
    solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN",
        "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
        "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });

    solution({ 120, 0, 60, 591 }, { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT",
        "18:00 0202 OUT","23:58 3961 IN" });

    solution({ 1, 461, 1, 10 }, { "00:00 1234 IN" });
}