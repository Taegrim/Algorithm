#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
	string s{};

	cin >> s;

	for (auto& alp : v) {
		while (true) {
			auto it = s.find(alp);
			if (it == string::npos) {
				break;
			}
			else {
				s.replace(it, alp.size(), "@");
			}
		}
	}
	
	cout << s.size() << endl;
}