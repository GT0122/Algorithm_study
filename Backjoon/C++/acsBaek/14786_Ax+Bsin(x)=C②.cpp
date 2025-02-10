#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout.precision(100);
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	double x;
	double range[2];
	range[0] = (c - b) / a;
	range[1] = (c + b) / a;
	x = (range[0] + range[1]) / 2;

	double diff = 1;
	double x_result = a * x + b * sin(x) - c;
	while(x_result < 0 || x_result > 0) {
		if(abs(diff) < pow(10, -6)) {
			break;
		}

		diff = x_result / (a + cos(x));
		x -= diff;
		x_result = a * x + b * sin(x) - c;
	}
	
	cout << x;

	return 0;
}