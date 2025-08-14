#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int maxstep = 1000;

	string* nums = new string[maxstep];
	string newStr;
	int num = 0;
	nums[0] = "0";
	const char int_to_char[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	bool first = false;
	bool rest = false;
	bool down = false;
	int leng;
	for(int i = 1; i < maxstep; i++) {
		leng = nums[i - 1].length();
		first = true;
		if(i & 1) {
			for(int k = (leng - 1); k >= 0; k--) {
				num = nums[i - 1][k] - '0';
				if(first) {
					num = num * 2 + 1;
					first = false;
				}
				else {
					num = num * 2;
				}
				if(rest) {
					num++;
				}

				if(num >= 10) {
					rest = true;
					num = num - 10;
				}
				else {
					rest = false;
				}
				newStr = int_to_char[num] + newStr;
			}
			if(rest) {
				newStr.assign('1' + newStr);
				rest = false;
			}
		}
		else {
			for(int k = (leng - 1); k >= 0; k--) {
				num = nums[i - 1][k] - '0';
				if(first) {
					num = num * 2 - 1;
					first = false;
				}
				else {
					num = num * 2;
				}

				if(rest) {
					num++;
				}
				if(down) {
					num--;
				}

				if(num < 0) {
					rest = false;
					down = true;
					num = num + 10;
				}
				else if(num >= 10) {
					rest = true;
					down = false;
					num = num - 10;
				}
				else {
					rest = false;
					down = false;
				}
				newStr.assign(int_to_char[num] + newStr);
			}
			if(rest) {
				newStr.assign('1' + newStr);
				rest = false;
			}
			down = false;
		}
		nums[i] = newStr;
		newStr.clear();
	}

	int n;
	while(!((cin >> n).eof())) {
		cout << nums[n - 1] << '\n';
	}

	return 0;
}