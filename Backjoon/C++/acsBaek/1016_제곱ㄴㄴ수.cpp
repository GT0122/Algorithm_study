#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long min, max;

	cin >> min;
	cin >> max;

	int size = max - min + 1;

	bool* vctNum = new bool[size];
	for (int i = 0; i < size; i++) {
		vctNum[i] = 1;
	}

	long long sqrtMax = floor(sqrt(max));

	bool* vctIndex = new bool[sqrtMax];
	for (int i = 0; i < sqrtMax+1; i++) {
		vctIndex[i] = 1;
	}

	int answer = 0;

	long long num = 0;
	int t;
	long long power = 0;
	for (long long i = 2; i < sqrtMax+1; i++) {
		if (vctIndex[i - 2] == 1) {
			t = i * 2 - 2;
			power = i * i;
			
			if (min % power == 0) {
				num = min;
			}
			else {
				num = (min / power + 1) * power;
			}

			while (t <= sqrtMax) {
				vctIndex[t] = 0;
				t += i;
			}

			while (num <= max) {
				if (num - min >= 0) {
					vctNum[num - min] = 0;
				}
				num += power;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		answer += vctNum[i];
	}

	cout << answer;

	return 0;
}