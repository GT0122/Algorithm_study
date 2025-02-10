#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const __float128 pi =
3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196q;

__float128 pow128(__float128 x, int n) {
	__float128 a = 1;

	for(int i = 0; i < n; i++) {
		a *= x;
	}

	return a;
}

__float128 sin128(__float128 x, __int128_t* fac) {
	__float128 y = 0;
	while(x >= 2 * pi) {
		x -= (2 * pi);
	}

	for(int i = 1; i < 34; i += 2) {
		if(((i - 1) / 2) & 1) {
			y -= pow128(x, i) / fac[i];
		}
		else {
			y += pow128(x, i) / fac[i];
		}
	}

	return y;
}

__float128 cos128(__float128 x, __int128_t* fac) {
	__float128 y = 1;
	while(x >= 2 * pi) {
		x -= (2 * pi);
	}

	for(int i = 2; i < 34; i += 2) {
		if((i / 2) & 1) {
			y -= pow128(x, i) / fac[i];
		}
		else {
			y += pow128(x, i) / fac[i];
		}
	}
	return y;
}

long long round128(__float128 x) {
	x += 0.5;
	return (long long)x;
}

__float128 abs128(__float128 x) {
	if(x < 0) {
		return -x;
	}
	else {
		return x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	__int128_t* fac = new __int128_t[35];
	fac[0] = 1;
	fac[1] = 1;
	for(int i = 2; i < 35; i++) {
		fac[i] = fac[i - 1] * i;
	}

	cout.precision(100);
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	__float128 x = (__float128)c / a;

	__float128 x_result = a * x + b * sin128(x, fac) - c;
	__float128 diff = x_result / (a + b * cos128(x, fac));
	while(abs128(diff) > pow(10, -25)) {
		x -= diff;
		x_result = a * x + b * sin128(x, fac) - c;
		diff = x_result / (a + b * cos128(x, fac));
	}
	string str = to_string(round128(x * pow(10, 6)) * pow(10, -6));
	str = str.substr(0, str.find('.') + 7);
	cout << str << '\n';
	return 0;
}