#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long min, max;

	cin >> min;
	cin >> max;

	int size = max - min + 1;

	int* vctNum = new int[size];
	for (int i = 0; i < size; i++) {
		vctNum[i] = 1;
	}

	long long sqrtMax = floor(sqrt(max));
	cout << sqrtMax << '\n';

	int* vctIndex = new int[sqrtMax];
	for (long long i = 0; i < sqrtMax+1; i++) {
		vctIndex[i] = 1;
	}

	long long num;
	int t;
	for (long long i = 2; i < sqrtMax+1; i++) {
		if (vctIndex[i - 2] == 1) {
			t = i * 2 - 2;
			while (t <= sqrtMax) {
				vctIndex[t] = 0;
				t += i;
			}
		}
	}

	cout << "done\n";

	int index = 1;
	for (long long i = 2; i < sqrtMax+1; i++) {
		if (vctIndex[i - 2] == 1) {
			num = i * i;
			for (int j = 0; j < num; j++) {
				if ((min + j) % num == 0) {
					index = j;
					break;
				}
			}

			while (min + index <= max) {
				vctNum[index] = 0;
				index += num;
			}
		}
	}

	cout << "done\n";

	int answer = 0;
	for (int i = 0; i < size; i++) {
		answer += vctNum[i];
	}

	cout << answer;

	return 0;
}