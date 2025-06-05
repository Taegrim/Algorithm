#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, string>> v;
int num{ 0 };

int main()
{
	while (cin >> num){
		if (0 == num) {
			break;
		}

		string word, temp;
		for (int i = 0; i < num; ++i) {
			cin >> word;
			temp = word;
			
			for (auto& c : temp) {
				c = tolower(c);
			}
			v.push_back(make_pair(temp, word));

			sort(v.begin(), v.end());
		}
		
		cout << v.begin()->second << "\n";
		v.clear();
	}
}