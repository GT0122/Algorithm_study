#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int len1, len2;
	cin >> len1;
	cin >> len2;
	cin.ignore();

	int* arr1 = new int[len1];
	int* arr2 = new int[len2];
	int cur1 = 0;
	int cur2 = 0;

	string str1, str2;
	getline(cin, str1);
	int pre = 0;
	for(int i = 0; i < str1.length(); i++) {
		if(str1[i] == ' ') {
			arr1[cur1] = stoi(str1.substr(pre, i - pre));
			pre = i + 1;
			cur1++;
		}
	}
	arr1[cur1] = stoi(str1.substr(pre, str1.length() - pre));

	getline(cin, str2);
	pre = 0;
	for(int i = 0; i < str2.length(); i++) {
		if(str2[i] == ' ') {
			arr2[cur2] = stoi(str2.substr(pre, i - pre));
			pre = i + 1;
			cur2++;
		}
	}
	arr2[cur2] = stoi(str2.substr(pre, str2.length() - pre));

	string str = "";
	cur1 = 0;
	cur2 = 0;
	for(int i = 0; i < (len1 + len2); i++) {
		if(cur1 < len1 && cur2 < len2) {
			if(arr1[cur1] < arr2[cur2]) {
				str.append(to_string(arr1[cur1]));
				cur1++;
			}
			else {
				str.append(to_string(arr2[cur2]));
				cur2++;
			}
		}
		else if(cur1 < len1) {
			str.append(to_string(arr1[cur1]));
			cur1++;
		}
		else {
			str.append(to_string(arr2[cur2]));
			cur2++;
		}
		str.append(" ");
	}

	cout << str;

	return 0;
}