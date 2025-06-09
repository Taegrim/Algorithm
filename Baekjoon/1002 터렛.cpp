#include <iostream>
#include <cmath>

using namespace std;

#define ellapse 

struct Point {
	int x;
	int y;
};

bool get_zero(double a, double b)
{
	if (fabs(a - b) < numeric_limits<double>::epsilon())
		return true;
	return false;
}

int get_crosspoint(Point& a, Point& b, int& r1, int& r2)
{
	// 원이 같음 = 무한대
	
	if (a.x == b.x && a.y == b.y && r1 == r2)
		return -1;

	// 원이 다름 - 교점 구하기
	else {
		int diffx = b.x - a.x;
		int diffy = b.y - a.y;
		double d = sqrt(diffx * diffx + diffy * diffy);
		double sum_radius = (double)r1 + (double)r2;

		// 원이 만나지 않음
		if (d > sum_radius)
			return 0;
		// 원이 한점에서 만남
		if(get_zero(d, sum_radius) || get_zero(d, fabs(r2-r1)))
			return 1;
		// 원이 두 점에서 만남
		if (sum_radius > d && d > fabs(r2-r1))
			return 2;
		// 원이 내부에서 만나지 않음
		if (d < fabs(r2 - r1))
			return 0;

	}
	

}

int main()
{
	int cnt;
	cin >> cnt;

	Point a, b;
	int r1, r2;

	while (cnt) {
		cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2;
		
		cout << get_crosspoint(a, b, r1, r2) << endl;
		--cnt;
	}

}

// 원의 교점 구하는 문제