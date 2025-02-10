#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int route(int n, int k, int*& counts, int*& num) {
	if(n < counts[0]) {
		return 0;
	}
	if(num[n] != 0) {
		return num[n];
	}

	bool ise = false;
	int back_num = 0;
	int e = pow(10, 9), o = pow(10, 9);
	for(int i = k - 1; i >= 0; i--) {
		if(n > counts[i]) {
			if(num[n - counts[i]] != 0) {
				back_num = num[n - counts[i]] + 1;
			}
			else {
				back_num = route(n - counts[i], k, counts, num) + 1;
			}

			if(back_num & 1) {
				ise = true;
				o = min(o, back_num);
			}
			else {
				e = min(e, back_num);
			}
		}
	}

	if(ise) {
		return o;
	}
	else {
		return e;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	int k;
	cin >> m;
	cin >> k;

	if(m < 4000) {
		int* counts = new int[k];
		int* num = new int[m + 1] { 0, };
		for(int i = 0; i < k; i++) {
			cin >> counts[i];
			num[counts[i]] = 1;
		}

		for(int i = 1; i < m + 1; i++) {
			num[i] = route(i, k, counts, num);
		}
		int count = 0;
		for(int i = 1; i < m + 1; i++) {
			if(num[i] % 2 == 0) {
				count++;
			}
		}
		cout << count;
	}
	else {
		int* counts = new int[k];
		int* num = new int[3001] { 0, };
		for(int i = 0; i < k; i++) {
			cin >> counts[i];
			num[counts[i]] = 1;
		}

		for(int i = 1; i < 3001; i++) {
			num[i] = route(i, k, counts, num);
		}

		string pt = "";
		for(int i = 1; i < 3001; i++) {
			if(num[i] & 1) {
				pt += '0';
			}
			else {
				pt += '1';
			}
		}

		string pt1, pt2, pt3;
		int start, patt;
		bool isbreak = false;
		for(patt = 1000; patt > 0; patt--) {
			for(start = 0; start < 3000 - (patt * 3) + 1; start++) {
				pt1 = pt.substr(start, patt);
				pt2 = pt.substr(start + patt, patt);
				pt3 = pt.substr(start + 2 * patt, patt);
				if(pt1.compare(pt2) == 0 && pt2.compare(pt3) == 0) {
					isbreak = true;
					break;
				}
			}
			if(isbreak) {
				break;
			}
		}

		int count = 0;

		for(int i = 0; i < patt; i++) {
			if(pt1[i] == '1') {
				count++;
			}
		}

		int reps = (int)((m - start) / patt);
		count *= reps;

		for(int i = 0; i < start; i++) {
			if(pt[i] == '1') {
				count++;
			}
		}

		for(int i = 0; i < m - (patt * reps + start); i++) {
			if(pt1[i] == '1') {
				count++;
			}
		}
		cout << count;
	}
	return 0;
}