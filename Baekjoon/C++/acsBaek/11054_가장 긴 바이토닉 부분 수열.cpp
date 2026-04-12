#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maxValue;
	cin >> n;

	int v[1001]{}, up[1001]{}, down[1001]{};
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		up[i] = 1;
		maxValue = 0;
		for (int j = i; j >= 0; j--) {
			if (v[i] > v[j]) {
				if (maxValue < up[j]) maxValue = up[j];
			}
		}
		up[i] += maxValue;
	}

	for (int i = n - 1; i >= 0; i--) {
		down[i] = 1;
		maxValue = 0;
		for (int j = i; j < n; j++) {
			if (v[i] > v[j]) {
				if (maxValue < down[j]) maxValue = down[j];
			}
		}
		down[i] += maxValue;
	}

	maxValue = 0;
	for (int i = 0; i < n; i++) {
		if (maxValue < up[i] + down[i]) maxValue = up[i] + down[i];
	}

	cout << maxValue - 1;

	return 0;
}