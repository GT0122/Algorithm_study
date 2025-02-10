#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Mature(int x, int y, vector<int>* qX, vector<int>* qY, int* box, int r, int c, int* zero)
{
	if(x - 1 >= 0 && box[(x - 1) * c + y] == 0)
	{
		box[(x - 1) * c + y] = 1;
		qX->push_back(x - 1);
		qY->push_back(y);
		*zero -= 1;
	}

	if(x + 1 < r && box[(x + 1) * c + y] == 0)
	{
		box[(x + 1) * c + y] = 1;
		qX->push_back(x + 1);
		qY->push_back(y);
		*zero -= 1;
	}

	if(y - 1 >= 0 && box[x * c + y - 1] == 0)
	{
		box[x * c + y - 1] = 1;
		qX->push_back(x);
		qY->push_back(y - 1);
		*zero -= 1;
	}

	if(y + 1 < c && box[x * c + y + 1] == 0)
	{
		box[x * c + y + 1] = 1;
		qX->push_back(x);
		qY->push_back(y + 1);
		*zero -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp, day = 0, zeros = 0;
	int* pBox;
	vector<int> vctX;
	vector<int> vctY;
	vector<int> vctXTemp;
	vector<int> vctYTemp;
	vector<int>::iterator iter;

	cin >> n;
	cin >> m;

	pBox = new int [m * n];

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> temp;
			pBox[i * n + j] = temp;

			if(temp == 1)
			{
				vctX.push_back(i);
				vctY.push_back(j);
			}
			else if(temp == 0)
				zeros++;
		}
	}

	while(zeros > 0)
	{
		for(int i = 0; i < vctX.size(); i++)
			Mature(vctX[i], vctY[i], &vctXTemp, &vctYTemp, pBox, m, n, &zeros);

		if(vctXTemp.size() == 0 && vctYTemp.size() == 0)
		{
			day = -1;
			break;
		}

		vctX.clear();
		vctY.clear();
		vctX = vctXTemp;
		vctY = vctYTemp;
		day++;

		vctXTemp.clear();
		vctYTemp.clear();
	}

	cout << day << endl;

	delete[] pBox;
	vctX.clear();
	vctY.clear();
	vctXTemp.clear();
	vctYTemp.clear();

	return 0;
}