#include <iostream>
#include <cmath>

using namespace std;

int search(int min, int max, int length, int r, int c) {
	if (length == 1) {
		return min;
	}

	int q = (max - min) / 4;
	int half = length / 2;

	int num;

	if (r >= half and c >= half) {
		num = search(min + q * 3, min + q * 4, half, r - half, c - half);
	}
	else if (r >= half and c < half) {
		num = search(min + q * 2, min + q * 3, half, r - half, c);
	}
	else if (r < half and c >= half) {
		num = search(min + q, min + q * 2, half, r, c - half);
	}
	else {
		num = search(min, min + q, half, r, c);
	}

	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, c;

	cin >> n;
	cin >> r;
	cin >> c;

	int length = pow(2, n);

	cout << search(0, length * length, length, r, c) << endl;

	return 0;
}