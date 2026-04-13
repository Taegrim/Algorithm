#include <iostream>

using namespace std;

long long set_load(long long a, long long b)
{
	long long result = 1;

	for (int i = 0; i < a; ++i) {
		result *= (b - i);
		result /= (i + 1);
	}

	return result;
}

int main()
{
	int t;
	cin >> t;
	long long n, m;

	while (t > 0) {
		cin >> n >> m;

		cout << set_load(n, m) << endl;
		--t;
	}

}