#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	long x, y, cor, max;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x;
		cin >> y;

		cor = 0;
		max = 0;
		while (x < y) {
			cor++;
			x += ++max;

			if (x >= y) break;

			cor++;
			x += max;
		}

		cout << cor << '\n';
	}

	return 0;
}