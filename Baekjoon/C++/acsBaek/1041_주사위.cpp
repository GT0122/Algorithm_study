#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N; 
	long long sum = 0;
	int n;

	cin >> N;

	if (N == 1) {
		int max = 0;

		for (int i = 0; i < 6; i++) {
			cin >> n;
			sum += n;
			if (n > max) max = n;
		}

		cout << sum - max;
	}
	else {
		long long n1, n2;
		int a, b, c, min, min2, n3 = 4;

		n1 = (N - 2) * (N - 1) * 4 + (N - 2) * (N - 2);
		n2 = (N * 2 - 3) * 4;

		cin >> a;
		cin >> b;
		cin >> c;
		cin >> n;
		if (c > n) c = n;
		cin >> n;
		if (b > n) b = n;
		cin >> n;
		if (a > n) a = n;

		if (a < b) {
			if (a < c) {
				min = a;
				if (b < c) min2 = a + b;
				else min2 = a + c;
			}
			else {
				min = c;
				min2 = a + c;
			}
		}
		else {
			if (b < c) {
				min = b;
				if (a < c) min2 = b + a;
				else min2 = b + c;
			}
			else {
				min = c;
				min2 = b + c;
			}
		}
		sum = min * n1 + min2 * n2 + (a + b + c) * n3;

		cout << sum;
	}

	return 0;
}