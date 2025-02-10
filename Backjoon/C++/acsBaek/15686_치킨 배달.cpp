#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SelectChicken(vector<int>chicken, string remain, vector<string>* remains, int num, int index)
{
	if(num == 0)
	{
		remains->push_back(remain);
		return;
	}
	else if(index >= chicken.size())
		return;

	int temp;

	for(int i = index; i < chicken.size(); i++)
	{
		temp = chicken[i];
		SelectChicken(chicken, remain + " " + to_string(temp), remains, num - 1, i + 1);
	}

	return;
}

int CalcDis(vector<int> house, string chicken, int n, int m, int* mindis)
{
	int x, y, cx, cy;
	int distance = 0, h_distance;
	int temp;
	bool bb = false;
	string str;
	vector<int>::iterator iter;

	for(iter = house.begin(); iter < house.end(); iter++)
	{
		x = (*iter) / n;
		y = (*iter) % n;

		str = chicken;
		h_distance = 50 * 50;

		for(int i = 0; i < m; i++)
		{
			str = str.substr(str.find(' ') + 1);
			temp = stoi(str.substr(0, str.find(' ')));

			cx = temp / n;
			cy = temp % n;

			h_distance = min(h_distance, abs(cx - x) + abs(cy - y));
		}

		distance += h_distance;

		if(distance > *mindis)
			break;
	}

	if(distance < *mindis)
		*mindis = distance;

	return distance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp;
	int answer = 1000000000;
	vector<int> house;
	vector<int> chi;
	vector<string> c;

	cin >> n;
	cin >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> temp;

			if(temp == 1)
				house.push_back(i * n + j);
			else if(temp == 2)
				chi.push_back(i * n + j);
		}
	}

	SelectChicken(chi, "", &c, m, 0);

	vector<string>::iterator citer;

	for(citer = c.begin(); citer < c.end(); citer++)
	{
		CalcDis(house, (*citer), n, m, &answer);
	}

	cout << answer << endl;

	return 0;
}