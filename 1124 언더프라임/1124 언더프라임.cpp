#include <iostream>
#include <numeric>
#include <array>

// �Ҽ� ������ ���� �̿��ϸ� �ð��ʰ�
// �����佺�׳׽��� ü�� �̿��� ������ ���� �Ҽ��� ���� ��
// �ش簪�� �Ҽ������� Ȯ�θ� �ϵ��� �ؾ���

using namespace std;

int cnt = 0, len = 0;
array<int, 50> primeNum;

void setPrimeNum()
{
	iota(primeNum.begin(), primeNum.end(), 0);
	primeNum[1] = 0;

	for (int i = 2; i * i <= primeNum.size(); ++i) {
		if (primeNum[i] == 0)
			continue;
		for (int j = i * i; j <= primeNum.size(); j += i)
			primeNum[j] = 0;
	}
}

bool isPrime(int n)
{
	if (primeNum[n] == 0)
		return false;
	return true;
}

void solve(int n)
{
	int num = n;
	for (int i = 2; i * i <= num; ++i) {
		while (num % i == 0) {
			len++;
			num /= i;
		}
	}

	if (num > 1)
		len++;

	if (isPrime(len))
		++cnt;
	len = 0;
}

int main()
{
	setPrimeNum();

	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; ++i)
		solve(i);

	cout << cnt << endl;
}