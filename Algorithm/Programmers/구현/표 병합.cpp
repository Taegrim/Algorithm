#include <iostream>

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int GetPos(int r, int c)
{
    return (r - 1) * 50 + c;
}

int GetPosString(string r, string c)
{
    return GetPos(stoi(r), stoi(c));
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    vector<int> links(2503);
    vector<string> values(2503, "EMPTY");
    for (int i = 0; i < links.size(); ++i)
    {
        links[i] = i;
    }

    for (const auto& command : commands)
    {
        stringstream ss(command);
        string s;
        vector<string> v;
        v.reserve(5);

        // 문자열 파싱
        while (ss >> s)
        {
            v.push_back(s);
        }

        if (v[0] == "UPDATE")
        {
            // 선택한 위치 변경
            if (v.size() == 4)
            {
                int pos = GetPosString(v[1], v[2]);
                int link = links[pos];

                values[link] = v[3];
            }
            else
            {
                // 모든셀 value2로 변경
                for (string& val : values)
                {
                    if (val == v[1])
                    {
                        val = v[2];
                    }
                }
            }
        }
        else if (v[0] == "MERGE")
        {
            int pos1 = GetPosString(v[1], v[2]);
            int pos2 = GetPosString(v[3], v[4]);

            int link1 = links[pos1];
            int link2 = links[pos2];
            if (link1 == link2) continue;

            string val1 = values[link1];
            string val2 = values[link2];

            // parent2 를 전부 parent1로 변경
            for (int& link : links)
            {
                if (link == link2)
                {
                    link = link1;
                }
            }
            values[link2] = "EMPTY";

            // r1,c1 값이 비었다면 val2 적용, 
            values[link1] = val1;
            if (val1 == "EMPTY")
            {
                values[link1] = val2;
            }
        }
        else if (v[0] == "UNMERGE")
        {
            int pos = GetPosString(v[1], v[2]);
            int link = links[pos];
            string val = values[link];

            for (int i = 0; i < links.size(); ++i)
            {
                // 병합되어있었다면 해제하고 값 삭제
                if (links[i] == link)
                {
                    links[i] = i;
                    values[i] = "EMPTY";
                }
            }
            // r,c 에 값 저장
            values[pos] = val;
        }
        else if (v[0] == "PRINT")
        {
            int pos = GetPosString(v[1], v[2]);
            int link = links[pos];

            answer.push_back(values[link]);
        }
    }

    return answer;
}

int main()
{
    solution({ "UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap",
        "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean",
        "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian",
        "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik",
        "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4" });
    solution({ "UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2",
        "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1" });
}
