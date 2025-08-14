#include <iostream>
#include <algorithm>

using namespace std;

class Room {
public :
	unsigned long start, end;

public :
	Room() {
		this->start = 0;
		this->end = 0;
	}

	Room(unsigned long start, unsigned long end) {
		this->start = start;
		this->end = end;
	}

	bool operator < (Room &room) {
		return this->end == room.end ? this->start < room.start : this->end < room.end;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	unsigned long min = 999999;
	unsigned long max = 0;
	Room* arrRoom = new Room[n];

	unsigned long s, e;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cin >> e;
		arrRoom[i].start = s;
		arrRoom[i].end = e;
		if (min > s) min = s;
		if (max < e) max = e;
	}

	sort(arrRoom, arrRoom + n);

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (arrRoom[i].start >= min) {
			min = arrRoom[i].end;
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}