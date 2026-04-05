#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x[4]{};
	int y[4]{};
	int tx[4]{};
	float a1, a2, b1, b2;

	cin >> x[0];
	cin >> y[0];
	cin >> x[1];
	cin >> y[1];

	a1 = (float)(y[1] - y[0]) / (float)(x[1] - x[0]);
	b1 = y[1] - (a1 * x[1]);

	cin >> x[2];
	cin >> y[2];
	cin >> x[3];
	cin >> y[3];

	a2 = (float)(y[3] - y[2]) / (float)(x[3] - x[2]);
	b2 = y[3] - (a2 * x[3]);

	if (x[0] > x[2] and x[1] > x[2] and x[0] > x[3] and x[1] > x[3]) cout << 0;
	else if (x[0] < x[2] and x[1] < x[2] and x[0] < x[3] and x[1] < x[3]) cout << 0;
	else {
		if (x[0] == x[1]) {
			int t = a2 * x[0] + b2;
			if (y[0] > t and y[1] > t) cout << 0;
			else if (y[0] < t and y[1] < t) cout << 0;
			else cout << 1;
		}
		else if (x[2] == x[3]) {
			int t = a1 * x[2] + b1;
			if (y[2] > t and y[3] > t) cout << 0;
			else if (y[2] < t and y[3] < t) cout << 0;
			else cout << 1;
		}
		else {
			for (int i = 0; i < 4; i++) tx[i] = x[i];

			sort(tx, tx + 4);

			float t1, t2;
			bool change = false;
			int cor = 0;
			for (int i = tx[1]; i <= tx[2]; i++) {
				t1 = a1 * i + b1;
				t2 = a2 * i + b2;

				if (t1 == t2) {
					cout << 1;
					change = true;
					break;
				}
				else {
					if (cor == 0) {
						if (t1 > t2) {
							cor = 1;
						}
						else {
							cor = 2;
						}
					}
					else if (cor == 1) {
						if (t1 < t2) {
							cout << 1;
							change = true;
							break;
						}
					}
					else {
						if (t1 > t2) {
							cout << 1;
							change = true;
							break;
						}
					}
				}
			}

			if (!change) cout << 0;
		}
	}

	return 0;
}