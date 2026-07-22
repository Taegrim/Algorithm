#include <iostream>
#include <string>

using namespace std;

string GetTime(int time)
{
    string minute = to_string(time / 60);
    if (minute.size() == 1) {
        minute = "0" + minute;
    }

    string second = to_string(time % 60);
    if (second.size() == 1) {
        second = "0" + second;
    }

    return minute + ":" + second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int score1{}, score2{};
    int time1{}, time2{};
    int prev{};

    for (int i = 0; i < n; ++i) {
        int team;
        string s;

        cin >> team >> s;

        int current = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));

        // 이전에 다른 점수였다면 이기는 쪽으로 시간 더해주기
        if (score1 > score2) {
            time1 += current - prev;
        }
        else if(score1 < score2){
            time2 += current - prev;
        }

        if (team == 1) {
            score1++;
        }
        else if (team == 2) {
            score2++;
        }

        prev = current;
    }

    // 마지막 종료시간 확인
    if (score1 > score2) {
        time1 += 48 * 60 - prev;
    }
    else if (score1 < score2) {
        time2 += 48 * 60 - prev;
    }

    string t1 = GetTime(time1);
    string t2 = GetTime(time2);

    cout << t1 << "\n" << t2;
}
