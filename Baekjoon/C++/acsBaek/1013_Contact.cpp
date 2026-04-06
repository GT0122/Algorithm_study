#include <iostream>
#include <string>

using namespace std;

int search(string str, int index, int c100, int count0, int count1) {
	int sum = 0;

	if (str[index] == '0') {
		if (size(str) == index + 1) return 0;
		else {
			if (c100 == 1) {
				if (count1 == 0) sum += search(str, index + 1, 1, count0 + 1, 0);
				else sum += search(str, index + 1, 2, 0, 0);
			}
			else if (c100 == 2) {
				return 0;
			}
			else {
				sum += search(str, index + 1, 2, 0, 0);
			}
		}
	}
	else {
		if (c100 == 1) {
			if (count0 < 2) return 0;
			else {
				if (size(str) == index + 1) return 1;
				else {
					sum += search(str, index + 1, 1, count0, count1 + 1);
					sum += search(str, index + 1, 0, 0, 0);
				}
			}
		}
		else if (c100 == 2) {
			if (size(str) == index + 1) return 1;
			else sum += search(str, index + 1, 0, 0, 0);
		}
		else {
			if (size(str) == index + 1) return 0;
			else sum += search(str, index + 1, 1, 0, 0);
		}
	}

	return sum;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (search(str, 0, 0, 0, 0) == 0) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}

	return 0;
}