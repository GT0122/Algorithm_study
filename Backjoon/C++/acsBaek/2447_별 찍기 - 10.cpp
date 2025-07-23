#include <iostream>

using namespace std;

void search(int s, int e, char* star) {
	if (s == e) return;

	int newl, newc;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0 and j == 0) continue;
			else if (i == 1 and j == 1) continue;
			else {
				for (int k = 0; k < s; k++) {
					for (int l = 0; l < s; l++) {
						newl = i * s + k;
						newc = j * s + l;
						star[newl * (e + 1) + newc] = star[k * (e + 1) + l];
					}
				}
			}
		}
	}

	search(s * 3, e, star);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	char* stars = new char[(n + 1) * n + 1];
	memset(stars, ' ', sizeof(char) * ((n + 1) * n + 1));
	stars[0] = '*';
	stars[(n + 1) * n] = 0;

	search(1, n, stars);


	for (int i = 0; i < n; i++) {
		stars[i * (n + 1) + n] = '\n';
	}

	cout << stars;

	return 0;
}