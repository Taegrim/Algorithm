#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_min(vector<int>& a, const vector<int>& b)
{
	sort(a.begin(), a.end(), less<int>());
	vector<int> c{ b };
	sort(c.begin(), c.end(), greater<int>());


	int result{};
	for (int i = 0; i < a.size(); ++i)
		result += a[i] * c[i];

	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;


	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		a.push_back(k);
	}
	for (int i = 0; i < n; ++i) {
		cin >> k;
		b.push_back(k);
	}


	cout << get_min(a, b) << endl;
	
}