#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Check {
	int checkin;
	int checkout;
};

bool compare(Check a, Check b) {
	if(a.checkin == b.checkin) {
		return a.checkout < b.checkout;
	}
	else {
		return a.checkin < b.checkin;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int iyear, imonth, iday, ihour, iminute, oyear, omonth, oday, ohour, ominute;
	int daysum[12];
	int sum = 0;
	for(int i = 0; i < 12; i++) {
		daysum[i] = sum;
		sum = sum + days[i];
	}
	
	int t, b, c;
	cin >> t;

	int* rooms = new int[t];

	for(int i = 0; i < t; i++) {
		cin >> b;
		cin >> c;
		cin.ignore();
		Check* cks = new Check[b];

		for(int j = 0; j < b; j++) {
			getline(cin, str);
			int index = 0;
			for(int k = 0; k < str.length(); k++) {
				if(str[k] == ' ') {
					index = k+1;
					break;
				}
			}
			str = str.substr(index, str.length() - index);
			iyear = stoi(str.substr(0, 4));
			imonth = stoi(str.substr(5, 2));
			iday = stoi(str.substr(8, 2));
			ihour = stoi(str.substr(11, 2));
			iminute = stoi(str.substr(14, 2));
			oyear = stoi(str.substr(17, 4));
			omonth = stoi(str.substr(22, 2));
			oday = stoi(str.substr(25, 2));
			ohour = stoi(str.substr(28, 2));
			ominute = stoi(str.substr(31, 2));

			Check ck;

			ck.checkin = ((iyear - 2013) * 365 + daysum[imonth - 1] + iday) * 1440;
			if(iyear == 2016 && imonth >= 3) {
				ck.checkin = ck.checkin + 1440;
			}
			ck.checkin = ck.checkin + (ihour * 60 + iminute);

			ck.checkout = ((oyear - 2013) * 365 + daysum[omonth - 1] + oday) * 1440;
			if(oyear == 2016 && omonth >= 3) {
				ck.checkout = ck.checkout + 1440;
			}
			ck.checkout = ck.checkout + (ohour * 60 + ominute + c);

			cks[j] = ck;
		}

		sort(cks, cks+b, compare);

		int* ex_rooms = new int[b];
		for(int j = 0; j < b; j++) {
			ex_rooms[j] = -1;
		}

		for(int j = 0; j < b; j++) {
			Check temp = cks[j];
			for(int k = 0; k < b; k++) {
				if(ex_rooms[k] == -1) {
					ex_rooms[k] = temp.checkout;
					break;
				} else {
					if(ex_rooms[k] <= temp.checkin) {
						ex_rooms[k] = temp.checkout;
						break;
					}
				}
			}
		}
		
		int room = 0;
		for(int j = 0; j < b; j++) {
			if(ex_rooms[j] > -1) {
				room++;
			}
		}
		rooms[i] = room;
	}

	for(int i = 0; i < t; i++) {
		cout << rooms[i] << '\n';
	}

	return 0;
}