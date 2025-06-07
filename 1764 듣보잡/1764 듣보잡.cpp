#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> first_meeting;
map<string, int> names;

int main()
{
	int n{}, m{};
	string s{};

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> s;

		++names[s];
	}

	for (int j = 0; j < m; ++j) {
		cin >> s;

		++names[s];
		if (2 == names[s]) {
			first_meeting.emplace_back(s);
		}
	}

	sort(first_meeting.begin(), first_meeting.end());

	cout << first_meeting.size() << '\n';
	for (const auto& name : first_meeting) {
		cout << name << '\n';
	}
}