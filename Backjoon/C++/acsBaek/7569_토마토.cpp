#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Mature(int x, int y, int z, vector<int>* qX, vector<int>* qY, vector<int>* qZ, int* box, int r, int c, int h, int* zero)
{
	if(x - 1 >= 0 && box[z * r * c + (x - 1) * c + y] == 0)
	{
		box[z * r * c + (x - 1) * c + y] = 1;
		qX->push_back(x - 1);
		qY->push_back(y);
		qZ->push_back(z);
		*zero -= 1;
	}

	if(x + 1 < r && box[z * r * c + (x + 1) * c + y] == 0)
	{
		box[z * r * c + (x + 1) * c + y] = 1;
		qX->push_back(x + 1);
		qY->push_back(y);
		qZ->push_back(z);
		*zero -= 1;
	}

	if(y - 1 >= 0 && box[z * r * c + x * c + y - 1] == 0)
	{
		box[z * r * c + x * c + y - 1] = 1;
		qX->push_back(x);
		qY->push_back(y - 1);
		qZ->push_back(z);
		*zero -= 1;
	}

	if(y + 1 < c && box[z * r * c + x * c + y + 1] == 0)
	{
		box[z * r * c + x * c + y + 1] = 1;
		qX->push_back(x);
		qY->push_back(y + 1);
		qZ->push_back(z);
		*zero -= 1;
	}

	if(z - 1 >= 0 && box[(z - 1) * r * c + x * c + y] == 0)
	{
		box[(z - 1) * r * c + x * c + y] = 1;
		qX->push_back(x);
		qY->push_back(y);
		qZ->push_back(z - 1);
		*zero -= 1;
	}

	if(z + 1 < h && box[(z + 1) * r * c + x * c + y] == 0)
	{
		box[(z + 1) * r * c + x * c + y] = 1;
		qX->push_back(x);
		qY->push_back(y);
		qZ->push_back(z + 1);
		*zero -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, h, temp, day = 0, zeros = 0;
	int* pBox;
	vector<int> vctX;
	vector<int> vctY;
	vector<int> vctZ;
	vector<int> vctXTemp;
	vector<int> vctYTemp;
	vector<int> vctZTemp;
	vector<int>::iterator iter;

	cin >> m;
	cin >> n;
	cin >> h;

	pBox = new int[m * n * h];

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				cin >> temp;
				pBox[i * n * m + j * m + k] = temp;

				if(temp == 1)
				{
					vctX.push_back(j);
					vctY.push_back(k);
					vctZ.push_back(i);
				}
				else if(temp == 0)
					zeros++;
			}
		}
	}

	while(zeros > 0)
	{
		for(int i = 0; i < vctX.size(); i++)
			Mature(vctX[i], vctY[i], vctZ[i], &vctXTemp, &vctYTemp, &vctZTemp, pBox, n, m, h, &zeros);

		if(vctXTemp.size() == 0 && vctYTemp.size() == 0 && vctZTemp.size() == 0)
		{
			day = -1;
			break;
		}

		vctX.clear();
		vctY.clear();
		vctZ.clear();
		vctX = vctXTemp;
		vctY = vctYTemp;
		vctZ = vctZTemp;
		day++;

		vctXTemp.clear();
		vctYTemp.clear();
		vctZTemp.clear();
	}

	cout << day << endl;

	delete[] pBox;
	vctX.clear();
	vctY.clear();
	vctZ.clear();
	vctXTemp.clear();
	vctYTemp.clear();
	vctZTemp.clear();

	return 0;
}